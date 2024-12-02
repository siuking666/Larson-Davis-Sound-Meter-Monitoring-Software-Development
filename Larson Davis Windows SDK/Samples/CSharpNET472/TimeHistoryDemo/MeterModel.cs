using System;
using System.IO;
using System.Net;
using System.Threading;
using System.Threading.Tasks;
using LarsonDavis.SDK.LDCommonStd.Core;
using LarsonDavis.SDK.LDCommonStd.Legacy;
using Newtonsoft.Json.Linq;

namespace LarsonDavis.Sdk.TimeHistoryDemo
{
	public delegate bool DownloadStatusUpdate(DownloadState state, int bytesDownloaded, LDError error);

	public class MeterModel
	{
		public const int MAX_BLOCK_SIZE = 102400;
		public const int TIMEOUT_CNT = 20;
		public int fileDownloadStatus = 0;
		public string SessionCookie { get; private set; }
		public ConnectionType ConnectionType { get; private set; }
		public string HttpLdRootUri { get; internal set; }
		public int DownloadPort { get; internal set; }
		public string IpAddress { get; internal set; }

		public bool GetJSON(string command, byte[] body, string key, out JObject jsonObject)
		{
			bool result = true;
			string source = string.Format("{0}://{1}:{2}", (DownloadPort == 443 ? "https" : "http"), IpAddress, DownloadPort);
			byte[] data = null;
			jsonObject = null;

			if (!command.StartsWith("/"))
			{
				command = "/" + command;
			}

			try
			{
				SendCommandToHld(source + command, body, out data);
			}
			catch (Exception ex)
			{
				string msg = ex.Message;
				jsonObject = new JObject();
				jsonObject.Add("Message", "Failed to communicate with HLD." + Environment.NewLine + ex.Message);
				result = false;
			}

			// Parse JSON into dynamic object
			if (null != data && result)
			{
				try
				{
					string jsonMsg = System.Text.Encoding.UTF8.GetString(data);
					if (string.IsNullOrEmpty(jsonMsg))
					{
						jsonObject = new JObject();
						jsonObject.Add("Message", "Unable to parse JSON.");
						result = false;
					}

					if (result)
					{
						jsonObject = JObject.Parse(jsonMsg);

						if (!jsonMsg.Contains(key))
						{
							var slmError = LDError.Success;

							var errorCode = jsonObject["ResultCode"];
							if (errorCode != null)
							{
								try
								{
									slmError = (LDError)((int)errorCode);
									if (slmError == LDError.Success)
									{
										slmError = LDError.HttpLdKeyNotFound;
										jsonObject.Add("Message", "KeyNotFound");
									}
								}
								catch
								{
									slmError = LDError.HttpLdUnknownErrorCode;
									jsonObject.Add("Message", "HttpLdUnknownErrorCode");
								}
							}
							else
							{
								slmError = LDError.HttpLdNoErrorCode;
								if (ConnectionType == ConnectionType.TCPIP)
								{
									jsonObject.Add("Message", "Part of the communication channel was closed.  Your meter is not communicating correctly with the 831-INT-ET or you may have a password set and does not match the supplied password. (327 - HttpLdNoErrorCode)");
								}
								else
								{
									jsonObject.Add("Message", "Part of the communication channel was closed. (327 - HttpLdNoErrorCode)");
								}
							}
							result = false;
						}
					}
				}
				catch (Exception ex)
				{
					jsonObject = new JObject();
					jsonObject.Add("Message", "Unable to parse JSON. " + ex.Message);
				}
			}
			else
			{
				result = false;
			}

			if (null != data) data = null;

			return result;
		}

		private void SendCommandToHld(string cmd, out byte[] data)
		{
			SendCommandToHld(cmd, null, out data);
		}

		private void SendCommandToHld(string cmd, byte[] body, out byte[] data)
		{
			//LogFile.WriteLog("SendCommandToHld:" + cmd);

			WebRequest request = WebRequest.Create(cmd);
			if (!string.IsNullOrEmpty(SessionCookie))
			{
				request.Headers.Add("Cookie", SessionCookie);
			}
			if (cmd.ToLower().Contains("speed"))
			{
				request.Timeout = 5000;
			}
			else if (cmd.Contains("Startup"))
			{
				request.Timeout = 20000;
			}
			else if (request.Timeout == 100000)
			{
				request.Timeout = 60000;
			}

			if (body == null || body.Length == 0)
			{
				request.Method = "GET";
			}
			else
			{
				request.Method = "POST";
				request.ContentLength = body.Length;
				using (var stream = request.GetRequestStream())
				{
					stream.Write(body, 0, body.Length);
				}
			}

			using (WebResponse response = request.GetResponse())
			{
				using (Stream dataStream = response.GetResponseStream())
				{
					if (!string.IsNullOrEmpty(response.Headers["Set-Cookie"]))
					{
						string cook = response.Headers["Set-Cookie"];
						SessionCookie = cook.Substring(0, cook.IndexOf("==") + 2);
					}
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

		public LDError ParseJsonResponse(WebResponse response, out JObject json)
		{
			json = null;
			var data = new byte[response.ContentLength];
			try
			{
				using (var stream = response.GetResponseStream())
				{

					int offset = 0;
					while (offset < response.ContentLength)
					{
						int read = stream.Read(data, offset, (int)(response.ContentLength - offset));
						if (read == 0)
						{
							return LDError.HttpLdIncompleteResponse;
						}
						offset += read;
					}
				}
			}
			catch
			{
				return LDError.HttpLdIncompleteResponse;
			}
			var jsonMsg = System.Text.Encoding.UTF8.GetString(data);
			try
			{
				json = JObject.Parse(jsonMsg);
			}
			catch
			{
				return LDError.HttpLdInvalidJson;
			}

			return (LDError)(int)json["ResultCode"];
		}


		public Task StreamDownload(int fileIndex, int fileSize, Stream outStream, DownloadStatusUpdate updateProgressBar)
		{
			var task = new Task(() =>
			{
				int bytesDownloaded = 0;
				int errTimeoutTtl = TIMEOUT_CNT;
				int connectionTimeout = 30000;
				WebResponse response = null;

				while (errTimeoutTtl-- > 0 && bytesDownloaded < fileSize)
				{
					bool failed = false;
					bool cancel = false;
					try
					{
						var result = LDError.Success;
						string command;
						if (bytesDownloaded == 0)
						{
							command = string.Format("{0}/download?index={1}&size={2}&offset=0", HttpLdRootUri, fileIndex, fileSize);
						}
						else
						{
							// we are going to back up to the previous block to ensure that we get what we want.
							long pos = outStream.Position;
							if (pos != bytesDownloaded)
							{
								// We may want to handle this differently but for now we are only logging this.
								Console.WriteLine("While downloading the Position:" + pos + " didn't equal bytes downloaded: " + bytesDownloaded);
							}
							// calculate the new offset value to ensure that we don't miss anything.
							//int newOffset = ((bytesDownloaded / MAX_BLOCK_SIZE)) * MAX_BLOCK_SIZE;
							//newOffset = newOffset < 0 ? 0 : newOffset;
							//bytesDownloaded = newOffset;
							//outStream.Seek(newOffset, SeekOrigin.Begin);
							//state = 2 means continue

							//Thread.Sleep(2000);
							command = string.Format("{0}/download?index={1}&size={2}&offset={3}&state=2", HttpLdRootUri, fileIndex, fileSize, bytesDownloaded);
						}

						var request = (HttpWebRequest)HttpWebRequest.Create(command);
						request.Timeout = connectionTimeout;
						if (!string.IsNullOrEmpty(SessionCookie))
						{
							request.Headers.Add("Cookie", SessionCookie);
						}

						//request.AddRange(bytesDownloaded, fileSize);

						if (bytesDownloaded > 0)
						{
							updateProgressBar(DownloadState.Restarting, 0, result);
						}
						else
						{
							updateProgressBar(DownloadState.Starting, 0, result);
						}

						bool waiting = true;
						var bgrRes = request.BeginGetResponse((state) => {
							try
							{
								response = request.EndGetResponse(state);
							}
							catch (WebException ex)
							{
								string msg = ex.Message;
								request.Abort();
								failed = true;
							}
							waiting = false;
						}, request);

						int timeout = 1000;
						int timer = 0;
						while (!cancel && (!bgrRes.IsCompleted || waiting))
						{
							bgrRes.AsyncWaitHandle.WaitOne(timeout);
							timer += timeout;
							if (!bgrRes.IsCompleted)
							{
								if (timer < 5000)
								{
									cancel = !updateProgressBar(DownloadState.Starting, 0, result);
								}
								else
								{
									cancel = !updateProgressBar(DownloadState.Waiting, bytesDownloaded, result);
								}
							}
						}

						if (failed)
						{
							continue;
						}

						if (cancel)
						{
							updateProgressBar(DownloadState.Cancelled, bytesDownloaded, result);
							try
							{
								request.Abort();
							}
							catch { }
							return;
						}

						if (response.Headers["Content-Type"].Contains("json"))
						{
							JObject json;
							result = ParseJsonResponse(response, out json);
							updateProgressBar(DownloadState.Fail, 0, result);
							return;
						}

						using (var socket = response.GetResponseStream())
						{
							var buffer = new byte[MAX_BLOCK_SIZE];
							IAsyncResult callbackResult = null;

							socket.ReadTimeout = connectionTimeout;
							while (bytesDownloaded < fileSize && response.ContentLength > 0)
							{
								var toRead = Math.Min(MAX_BLOCK_SIZE, fileSize - bytesDownloaded);
								var read = socket.Read(buffer, 0, toRead);
								if (read == 0)
								{
									Thread.Sleep(200);
								}
								else
								{
									outStream.Write(buffer, 0, read);

									errTimeoutTtl = MeterModel.TIMEOUT_CNT;

									bytesDownloaded += read;
								}

								if (callbackResult == null || callbackResult.IsCompleted)
								{
									callbackResult = updateProgressBar.BeginInvoke(DownloadState.Downloading, bytesDownloaded, result, r =>
									{
										cancel = !updateProgressBar.EndInvoke(r);
									}, null);
								}

								if (cancel)
								{
									updateProgressBar(DownloadState.Cancelled, bytesDownloaded, result);
									return;
								}

							}
							updateProgressBar(DownloadState.Done, bytesDownloaded, result);
							if (bytesDownloaded < fileSize)
							{
								continue;
							}
							else
							{
								return;
							}
						}
					}
					catch (Exception ex)
					{
						string msg = "Error: " + ex.Message;
#if DEBUG
						Console.WriteLine(msg);
#endif
						if (null != response)
						{
							response.Close();
						}

						if (!updateProgressBar(DownloadState.Restarting, bytesDownloaded, LDError.Success))
						{
							updateProgressBar(DownloadState.Cancelled, bytesDownloaded, LDError.IoErrorCancelByUser);

							return;
						}
						//errTimeoutTtl--;
						//if (errTimeoutTtl == 1)
						//{
						//	updateProgressBar(DownloadState.Fail, bytesDownloaded, SLMError.DWNLDErrorDownloadTimedOut);
						//	return;
						//}
					}
				}
				updateProgressBar(DownloadState.Fail, bytesDownloaded, LDError.DWNLDErrorDownloadTimedOut);
			});
			task.Start();

			return task;
		}

		public bool StartBuildingFileList(out JObject fileList)
		{
			int pathType = 0;

			return !GetJSON("/sdk?func=startfilelistbuild&dpath=" + pathType, null, "Success", out fileList);
		}

		public bool CheckIfFileListReady(ref bool isClosing, bool prevTaskErred)
		{
			bool err = prevTaskErred;

			if (!err)
			{
				int timeout = 120000;
				JObject jsonReturn = null;
				bool done = false;

				while (!done && timeout > 0)
				{
					if (isClosing)
					{
						break;
					}

					if (GetJSON("/sdk?func=queryfileliststatus", null, "Success", out jsonReturn))
					{
						if (jsonReturn != null && jsonReturn["Progress"] != null && jsonReturn["Progress"]["ReturnValue"] != null)
						{
							string value = (string)jsonReturn["Progress"]["ReturnValue"];
							if (value == "2468")
							{
								done = true;
								continue;
							}
						}

						timeout -= 1000;
						Thread.Sleep(1000);
					}
				}

				if (timeout == 0) err = true;
				Thread.Sleep(1000);
			}

			return err;
		}


	}
}
