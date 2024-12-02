using System;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Reflection;
using Microsoft.Win32;

namespace LarsonDavis.Sdk.TimeHistoryDemo
{
	public class CommandLineApp
	{
		public static Process LaunchLDDaemon(string connectionString, bool showHLD = false)
		{
			Process result = null;
			string path = string.Empty;

			bool useDebugPaths = Environment.GetCommandLineArgs().Select(x => x.ToLower()).Contains("-debug");

			if (useDebugPaths)
			{
				string keyName = Registry.LocalMachine + "\\SOFTWARE\\PCB Piezotronics\\DEBUG";
				path = (string)Registry.GetValue(keyName, "HLD", null);
				string resources = (string)Registry.GetValue(keyName, "Resources", null);
				if (path == null)
				{
					path = Path.GetDirectoryName(Assembly.GetExecutingAssembly().Location);
				}
				else if (resources != null)
				{
					connectionString = connectionString.Replace("-r Resources", $"-r {resources}");
				}
			}
			else
			{
				if (Environment.Is64BitProcess || Environment.Is64BitOperatingSystem)
				{
					path = Environment.GetEnvironmentVariable("ProgramFiles(x86)");
				}
				else
				{
					path = Environment.GetEnvironmentVariable("ProgramFiles");
				}
				path += @"\PCB Piezotronics\HLD";
			}

			// Use ProcessStartInfo class
			ProcessStartInfo startInfo = new ProcessStartInfo();
			startInfo.WorkingDirectory = path;
			startInfo.CreateNoWindow = true;
			startInfo.UseShellExecute = true;
			startInfo.FileName = path + @"\HttpLD.exe";

			//LogFile.WriteLog("Working: " + Assembly.GetExecutingAssembly().Location + " - " + startInfo.WorkingDirectory);

			if (useDebugPaths)
			{
				if (showHLD)
				{
					startInfo.WindowStyle = ProcessWindowStyle.Normal;
				}
				else
				{
					startInfo.WindowStyle = ProcessWindowStyle.Minimized;
				}

				// Allows editing of resource files while debugging.
				//connectionString = connectionString.Replace(@"-r ", @"-r ..\..\..\");
			}
			else
			{
				if (showHLD)
				{
					startInfo.WindowStyle = ProcessWindowStyle.Normal;
				}
				else
				{
					startInfo.WindowStyle = ProcessWindowStyle.Hidden;
				}
			}

			startInfo.Arguments = connectionString;
			try
			{
				// Start the process with the info we specified.
				// Call WaitForExit and then the using statement will close.
				result = Process.Start(startInfo);
				result.WaitForExit(1000);
				//App.JobManager.AddProcess(result.Handle);
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
	}
}
