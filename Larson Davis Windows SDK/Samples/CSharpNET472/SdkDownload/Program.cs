using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Threading;
using LarsonDavis.Sdk.SdkCommon;
using NDesk = LarsonDavis.Sdk.SdkCommon.NDesk;

namespace LarsonDavis.Sdk.SdkDownload
{
	internal class Program
	{
		public static string HostIp { get; private set; }
		public static int Port { get; private set; }
		public static string ConnString { get; private set; }
		public static string DeviceType { get; private set; }
		public static string MeterType { get; private set; }
		public static bool HelpAndExit { get; private set; }

		static void Main(string[] args)
		{
			HelpAndExit = false;

			ParseCommandLine(args);
			Environment.CurrentDirectory = Environment.GetFolderPath(Environment.SpecialFolder.MyDocuments);

			if (!HelpAndExit)
			{
				try
				{
					using (var meter = new MeterSlm(HostIp, Port, ConnString))
					{
						Console.WriteLine("\nGetting File List...");
						Thread.Sleep(1000);
						var fileList = meter.GetFileList();

						Console.WriteLine("\nFile List");
						Console.WriteLine("index path file              size (kB)");
						foreach (var file in fileList)
						{
							Console.WriteLine("{0,5:##0} {3} {1,15}   {2:#.##}", file["index"], file["name"], (int)file["size"] / 1024.0, ((int)file["location"]) == 3 ? "USB     " : "Internal");
						}

						if (fileList.Count() > 0)
						{
							Console.WriteLine();
							var first = fileList.First();
							var fileName = Path.GetFileNameWithoutExtension((string)first["name"]);
							fileName += ".ldbin";

							FileInfo file = new FileInfo(fileName);
							try { file.Delete(); } catch { }

							while (!file.Exists || file.Length < (uint)first["size"] )
							{
								Console.WriteLine(string.Format("\nDownloading '{0}' to '{1}' from {2}...\n", first["name"], file.FullName, file.Exists ? Math.Max(file.Length - 20, 0) : 0));
								meter.DownloadFile(file, (string)first["name"], (int)first["location"], (uint)first["size"]);
								file.Refresh();
								Console.WriteLine("Downloaded {0} bytes.\n", file.Exists ? file.Length : 0);

								if (!file.Exists || file.Length < (uint)first["size"])
								{
									Thread.Sleep(TimeSpan.FromSeconds(5));
								}
							}
						}
					}
				}
				catch (Exception e)
				{
					Console.WriteLine("Error: " + e.Message);
				}
			}

			Console.WriteLine("Press a key to close...");

			Console.Read();
		}

		private static IList<string> ParseCommandLine(string[] args)
		{
			IList<string> result = new List<string>();
			bool showHelp = false;

			HostIp = string.Empty;
			Port = 0;
			ConnString = string.Empty;
			DeviceType = string.Empty;
			MeterType = string.Empty;

			var p = new NDesk.OptionSet()
			{
				{ "i|ip|hostip:", "[IP address of the host HLD] - (default = localhost)", v => HostIp = (null != v) ? v.Trim() : "" },
				{ "p|port:", "[port of the host HLD] - (default = 2525)", (int v) => Port = v },
				{ "c|constr:", "[USB;(<deviceId>|S<serial>M<model>);<timeout>] - Connection string. (default = (USB;0;300)", v => ConnString = (null != v) ? v.Trim() : "" },
				//{ "d|device:", "[<SLM|HVM>] - Device type. (default = SLM)", v => DeviceType = v.Trim() },
				//{ "m|meter:", "[831C|831|LxT|LxTse|HVM200] - Meter type. (default = 831)", v => MeterType = v.Trim() },
				{ "h|?|help", "Show this message and exit.", v => showHelp = (null != v) },
			};

			string[] defArgs = { "-i localhost", "-p 2525", "-c USB;0;300", "-d slm", "-m 831" };
			if (args.Length > 0)
			{
				result = p.Parse(args);
			}
			else
			{
				result = p.Parse(defArgs);
			}

			if (result.Count > 0)
			{
				foreach (var item in result)
				{
					Console.WriteLine(item);
				}
			}

			if (showHelp) ShowHelp(p);

			return result;
		}

		private static void ShowHelp(NDesk.OptionSet p)
		{
			Console.WriteLine("Usage: SdkDownload [options]");
			Console.WriteLine("Example console program to download a file.");
			Console.WriteLine();
			Console.WriteLine("Options:");
			p.WriteOptionDescriptions(Console.Out);
			HelpAndExit = true;
		}

	}
}
