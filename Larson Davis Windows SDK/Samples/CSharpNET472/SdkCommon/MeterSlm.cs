using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Net;
using System.Text;
using System.Threading;
using Newtonsoft.Json.Linq;

namespace LarsonDavis.Sdk.SdkCommon
{
	public partial class MeterSlm : IDisposable
	{
		private readonly string _defHostIp = "localhost";
		private readonly string _defConnString = "USB;0;300";

		private Process _hld;

		public Process LDDaemon
		{
			get { return _hld; }
			set { _hld = value; }
		}

		public string HostIp { get; set; }
		public int Port { get; set; }
		public string RootUri { get; set; }



		public MeterSlm()
			: this("localhost", 2525, "USB;0;300")
		{
		}

		public MeterSlm(string host, int port, string connString)
			: this(host, port, connString, "SLM", "831")
		{

		}

		public MeterSlm(string host, int port, string connString, string deviceType, string meterType)
		{
			if (string.IsNullOrWhiteSpace(host)) { host = "localhost"; }
			if (string.IsNullOrWhiteSpace(deviceType)) { deviceType = "SLM"; }

			LDDaemon = null;
			HostIp = host;
			Port = port;
			RootUri = string.Format("http://{0}:{1}", host, port);

			string connType = connString.Split(';')[0];
			if (host == _defHostIp && (connString == _defConnString || "USB" == connType.ToUpper()))
			{
				StringBuilder sb = new StringBuilder();
				sb.AppendFormat(" -p {0}", port);
				sb.AppendFormat(" -c {0}", connString);
				sb.AppendFormat(" -d {0}", /*("HVM" == deviceType.ToUpper()) ? 1 :*/ 0);

				connString = sb.ToString();

				LDDaemon = LaunchLDDaemon(connString);
			}

		}

		public JToken GetFileList()
		{
			JToken result = SendSdkRequest("startfilelistbuild&dpath=2")["Result"];

			result = SendSdkRequest("queryfileliststatus")["Progress"];

			while (!(bool)result["complete"])
			{
				Thread.Sleep(200);
				result = SendSdkRequest("queryfileliststatus")["Progress"];
			}

			result = SendSdkRequest("getDataFileList&sindex=0")["DataFiles"];

			return result;
		}

		// Deprecated method to start download by list index
		[Obsolete]
		public void DownloadFile(FileInfo localFile, int index, uint size)
		{
			try
			{
				long startOffset = Ld831cFileDownloader.CalcOffsetFromFileInfo(localFile);
				Console.WriteLine("Starting stream to download '{0}'", localFile.Name);
				_= SendSdkRequest("enddownload&downloadsessionid=0");

				string cmd = string.Format("{0}/download?index={1}&size={2}&offset={3}&addCrc=1", RootUri, index, size, startOffset);
				WebRequest request = WebRequest.Create(cmd);

				using (WebResponse response = request.GetResponse())
				{
					if (response.SupportsHeaders)
					{
						// Check for file size in response headers
						// Or check "X-PrepResult" on error
						string header = response.Headers?.GetValues("X-FileSize")?.FirstOrDefault();
						if (((header?.Length ?? 0) > 0)
							&& long.TryParse(header, out long headerFileSize)
							&& (headerFileSize < uint.MaxValue))
						{
							size = (uint)headerFileSize;
						}
					}

					using (Ld831cFileDownloader downloader = new Ld831cFileDownloader(response.GetResponseStream(), localFile, localFile.Name, size))
					{
						while (downloader.ProcessStream())
						{
							// Update progress, etc.
							Console.Write($"\r{downloader.Progress}% downloaded ");
						}

						if (downloader.FileOffset == downloader.FileSize)
						{
							Console.WriteLine($"\rSuccessfully downloaded {localFile.Name}");
						}
					}
				}
			}
			catch (Exception ex)
			{
				Console.WriteLine("\nError Downloading File: " + ex.Message);
			}
		}

		// Preferred method to start download by file name
		public void DownloadFile(FileInfo localFile, string name, int path, uint size)
		{
			try
			{
				long startOffset = Ld831cFileDownloader.CalcOffsetFromFileInfo(localFile);
				Console.WriteLine("Starting stream to download '{0}'", name);
				_= SendSdkRequest("enddownload&downloadsessionid=0");

				string cmd = string.Format("{0}/download?name={1}&path={2}&offset={3}&addCrc=1", RootUri, name, path, startOffset);
				WebRequest request = WebRequest.Create(cmd);

				using (WebResponse response = request.GetResponse())
				{
					if (response.SupportsHeaders)
					{
						// Check for returned headers with file size
						// On error check "X-PrepResult"
						string header = response.Headers?.GetValues("X-FileSize")?.FirstOrDefault();
						if (((header?.Length ?? 0) > 0)
							&& long.TryParse(header, out long headerFileSize)
							&& (headerFileSize < uint.MaxValue))
						{
							size = (uint)headerFileSize;
						}
					}

					using (Ld831cFileDownloader downloader = new Ld831cFileDownloader(response.GetResponseStream(), localFile, name, size, (uint)startOffset))
					{
						while (downloader.ProcessStream())
						{
							// Update progress, etc.
							Console.Write($"\r{downloader.Progress}% downloaded ");
						}

						if (downloader.FileOffset == downloader.FileSize)
						{
							Console.WriteLine($"\rSuccessfully downloaded {name}");
						}
					}
				}
			}
			catch (Exception ex)
			{
				Console.WriteLine("\nError Downloading File: " + ex.Message);
			}
		}

		public JObject SendSdkRequest(string function, IEnumerable<KeyValuePair<string, object>> args = null)
		{
			JObject result = null;
			StringBuilder sb = new StringBuilder();

			sb.AppendFormat("{0}/sdk?func={1}", RootUri, function);

			if (null != args)
			{
				foreach (var pair in args)
				{
					sb.AppendFormat("&{0}={1}", pair.Key, pair.Value);
				}
			}

			string cmd = sb.ToString();
			byte[] data = null;
			bool proceed = true;

			Console.WriteLine("Sending Request: " + cmd);

			try
			{
				SendCommand(cmd, out data);
			}
			catch (Exception)
			{
				result = new JObject();
				result.Add("Message", "Failed to communicate with HLD.");
				proceed = false;
			}

			if ("closedown" == function.ToLower())
			{
				result = JObject.Parse("{\"Result\": \"Success\"}");
				proceed = false;
			}

			// Parse JSON into dynamic object
			if (null != data && proceed)
			{
				try
				{
					string jsonMsg = Encoding.UTF8.GetString(data);
					if (string.IsNullOrEmpty(jsonMsg))
					{
						result = new JObject();
						result.Add("Message", "Unable to parse JSON.");
					}
					else
					{
						result = JObject.Parse(jsonMsg);
					}
				}
				catch (Exception ex)
				{
					result = new JObject();
					result.Add("Message", "Unable to parse JSON. " + ex.Message);
				}
			}

			if (null != data) data = null;

			return result;
		}

		private void SendCommand(string cmd, out byte[] data, int timeOut = 60000)
		{
			WebRequest request = WebRequest.Create(cmd);
			request.Method = "GET";
			request.Timeout = timeOut;

			using (WebResponse response = request.GetResponse())
			{
				using (Stream dataStream = response.GetResponseStream())
				{
					data = new byte[response.ContentLength];
					int offset = 0;
					while (offset < response.ContentLength)
					{
						offset += dataStream.Read(data, offset, (int)(response.ContentLength - offset));
					}

					//dataStream.Close();
				}
				//response.Close();
			}
		}

		public static Process LaunchLDDaemon(string connString)
		{
			Process result = null;
			string path = string.Empty;

			if (Environment.Is64BitProcess || Environment.Is64BitOperatingSystem)
			{
				path = Environment.GetEnvironmentVariable("ProgramFiles(x86)");
			}
			else
			{
				path = Environment.GetEnvironmentVariable("ProgramFiles");
			}
			path += @"\PCB Piezotronics\HLD";

			// Use ProcessStartInfo class
			ProcessStartInfo startInfo = new ProcessStartInfo();
			startInfo.WorkingDirectory = path;
			startInfo.CreateNoWindow = true;
			startInfo.UseShellExecute = true;
			startInfo.WindowStyle = ProcessWindowStyle.Normal;
			startInfo.Arguments = connString;
			startInfo.FileName = path + @"\HttpLD.exe";

			try
			{
				// Start the process with the info we specified.
				result = Process.Start(startInfo);
				result.WaitForExit(1000);
			}
			catch (Exception ex)
			{
				string msg = ex.Message;
#if DEBUG
				// Log error.
				//LogFile.WriteLog("LaunchLDDaemon Error: " + msg);
#endif
			}

			return result;
		}

		public void StreamData(out uint time, out float val)
		{
			//FileInfo localFile;
			Console.WriteLine("Starting to stream data.");
			//using (var targetFile = new BinaryWriter(localFile.Create()))
			{
				var cmd = string.Format("{0}/sdk?getStreamingData", RootUri);
				var request = WebRequest.Create(cmd);

				using (var response = request.GetResponse())
				{
					time = 0;
					val = 0;

					using (var sourceStream = response.GetResponseStream())
					{
						var buffer = new byte[16];
						var totalRead = 0;
						var read = 1;// sourceStream.Read(buffer, 0, buffer.Length);

						while (read > 0)
						{
							//targetFile.Write(buffer, 0, read);
							try
							{
								read = sourceStream.Read(buffer, 0, 8);
								if (read > 0)
								{
									float ret = 0;
									time = BitConverter.ToUInt32(buffer, 0);
									ret = BitConverter.ToSingle(buffer, 4);
									if (val < ret) val = ret;
								}
								totalRead += read;
							}
							catch { }
						}
						Console.WriteLine("{0} bytes downloaded", totalRead);
					}
				}
			}
		}

		#region IDisposable Support
		private bool isDisposed = false; // To detect redundant calls

		protected virtual void Dispose(bool disposing)
		{
			if (!isDisposed)
			{
				if (disposing)
				{
					// TODO: dispose managed state (managed objects).
				}

				// TODO: free unmanaged resources (unmanaged objects) and override a finalizer below.
				// TODO: set large fields to null.
				if (null != LDDaemon)
				{
					SendSdkRequest("closeDown");
					LDDaemon.WaitForExit(2000);

					try
					{
						if (null != LDDaemon) LDDaemon.Kill();
					}
					catch { }
				}

				isDisposed = true;
			}
		}

		// TODO: override a finalizer only if Dispose(bool disposing) above has code to free unmanaged resources.
		~MeterSlm()
		{
			// Do not change this code. Put cleanup code in Dispose(bool disposing) above.
			Dispose(false);
		}

		// This code added to correctly implement the disposable pattern.
		public void Dispose()
		{
			// Do not change this code. Put cleanup code in Dispose(bool disposing) above.
			Dispose(true);
			// TODO: uncomment the following line if the finalizer is overridden above.
			GC.SuppressFinalize(this);
		}
		#endregion
	}

}
