using System;
using System.ComponentModel;
using System.Drawing;
using System.IO;
using System.Threading;
using System.Windows.Forms;
using LarsonDavis.SDK.LDCommonStd.Core;
using LarsonDavis.SDK.LDCommonStd.Interface;
using LarsonDavis.SDK.LDCommonStd.Utilities;
using LarsonDavis.Sdk.SdkCommon;
using System.Reflection;
using LarsonDavis.SDK.LDCommonStd.Extension;
using System.Diagnostics;

namespace LarsonDavis.Sdk.LiveStreamDemo
{
	public partial class DataStream : Form
	{
		private const string LOG_FILE = "log.txt";
		private string connectionString = "USB;0;300";
		private bool running = true;
		private MeterSlm connection;

		private string[] lines;
		private string fileLocation = "XMLOutput.xml";

		//stream length in ms
		enum StreamInterval
		{
			P20ms = 100,
			P50ms = 100,
			P100ms = 100,
			P200ms = 400,
			P500ms = 600,
			P1s = 1000,
			P2s = 2000,
			P5s = 5000,
			P10s = 10000,
			P15s = 15000,
			P20s = 20000,
			P30s = 30000,
			P1m = 60000,
			P2500us = 70,
			P5ms = 100,
			P10ms = 100
		};

		private StreamInterval streamInt = StreamInterval.P1s;
		private int cnt = 1;

		private IPersistenceManager _options;

		private void WriteLog(string mess)
		{
			string path = tbLogFile.Text;
			if (string.IsNullOrWhiteSpace(path))
			{
				path = LOG_FILE;
			}

			try
			{
				using (var stream = File.Open(path, FileMode.OpenOrCreate, FileAccess.Write))
				{
					stream.Seek(0, SeekOrigin.End);
					using (var fs = new StreamWriter(stream))
					{
						fs.WriteLine(DateTime.Now.ToString() + ": " + mess);
					}
				}
			}
			catch { }
		}

		public DataStream()
		{
			InitializeComponent();

			try
			{
				string optionsPath = Path.Combine(Path.GetDirectoryName(Assembly.GetExecutingAssembly().Location), @"\Options.json");

				IDataStore dataStore = new DataStore(optionsPath);

				_options = new OptionsFileManager(dataStore, null);

				tbConnectionString.Text = connectionString = _options?.Get("Options", "ConnectionString", connectionString);
				tbFileName.Text = fileLocation = _options?.Get("Options", "FileLocation", fileLocation);
				tbLogFile.Text = _options?.Get("Options", "LogLocation", LOG_FILE);
				cbJustValue.Checked = _options?.Get("Options", "JustValue", false) ?? false;
				cbMoveFile.Checked = _options?.Get("Options", "MoveFile", false) ?? false;
				cbStayOpen.Checked = _options?.Get("Options", "StayOpen", false) ?? false;

				//add items to the combos
				cmbFlags.DisplayMember = "Text";
				cmbFlags.ValueMember = "Value";

				var items = new[] {
				new { Text = "APeak", Value = 2 },
				new { Text = "ALeq", Value = 1 },
				new { Text = "CPeak", Value = 64 },
				new { Text = "CLeq", Value = 32 },
				new { Text = "ZPeak", Value = 2048 },
				new { Text = "ZLeq", Value = 1024 },
				new { Text = "All", Value = 134217727 }
			};
				cmbFlags.DataSource = items;

				cmbRate.DisplayMember = "Text";
				cmbRate.ValueMember = "Value";

				var rates = new[] {
				new { Text = "500 ms", Value = 4 },
				new { Text = "200 ms", Value = 3 },
				new { Text = "100 ms", Value = 2 },
				new { Text = "20 ms", Value = 0 },
				new { Text = "50 ms", Value = 1 },
				new { Text = "1 sec", Value = 5 },
				new { Text = "2 sec", Value = 6 },
				new { Text = "10 ms", Value = 15 },
				new { Text = "5 ms", Value = 14 },
				new { Text = "2.5 ms", Value = 13 },
			};
				cmbRate.DataSource = rates;

				lines = File.ReadAllLines("stageFile.xml");
			}
			catch (Exception ex)
			{
				string msg = ex.ToFullExceptionString();
				Debug.WriteLine($"{DateTime.Now:dd HH:mm:ss.fffff}: from DataStream: ctor: Exception: {msg}");
			}
		}

		~DataStream()
		{
			if (connection != null)
			{
				connection.Dispose();
				connection = null;
			}
		}

		protected override void OnClosing(CancelEventArgs e)
		{
			running = false;
			base.OnClosing(e);
		}

		public void StreamTask(MeterSlm connection)
		{
			UInt32 time = 0;
			float val = 1;
			TimeSpan span;
			FileInfo localFile = new FileInfo(fileLocation);

			while (running)
			{
				// getStreamingData
				DateTime maxDate = DateTime.Now;
				if (!cbNoConnection.Checked)
				{
					connection.StreamData(out time, out val);
				}
				if (val > 0) // && val < 10000000)
				{
					if (!cbNoConnection.Checked)
					{
						val = SlmConvert.ToDecibels(val);
						DateTime date = new DateTime().AddSeconds(time);
						Console.Write(date.ToString() + " - ");
					}
					else
					{
						val = cnt++;
						cnt = cnt > 100 ? 1 : cnt;
					}
					lblValue.Text = val.ToString("F1");
					lblValue.Refresh();
					//write to xml
					if (cbWriteToFile.Checked)
					{
						lines[4] = "<timestamp>" + maxDate.ToString() + "</timestamp>";
						lines[5] = "<apeak>" + val.ToString("0.0") + "</apeak>";
						try
						{
							using (var targetFile = localFile.CreateText())
							{
								if (cbJustValue.Checked)
								{
									targetFile.WriteLine(val.ToString("0.0"));
								}
								else
								{
									foreach (string line in lines)
									{
										targetFile.WriteLine(line);
									}
								}
								targetFile.Flush();
								targetFile.Close();
							}
						}
						catch (Exception ex)
						{
							WriteLog(ex.Message);
						}
					}
				}

				do
				{
					Application.DoEvents();
					//Thread.Sleep(10);
					span = DateTime.Now - maxDate;
				} while ((int)span.TotalMilliseconds < (int)streamInt);
			}
		}

		public void StreamTask3(MeterSlm connection)
		{
			UInt32 time = 0;
			float val = 1;
			TimeSpan span;
			string path = Path.GetDirectoryName(fileLocation) + "\\" + Path.GetFileNameWithoutExtension(fileLocation);
			string actualFile = (path + ".xml");
			string localPath = path + ".tmp";
			FileInfo localFile = new FileInfo(localPath);

			while (running)
			{
				// getStreamingData
				DateTime maxDate = DateTime.Now;
				if (!cbNoConnection.Checked)
				{
					connection.StreamData(out time, out val);
				}
				if (val > 0) // && val < 10000000)
				{
					if (!cbNoConnection.Checked)
					{
						val = SlmConvert.ToDecibels(val);
						DateTime date = new DateTime().AddSeconds(time);
						Console.Write(date.ToString() + " - ");
					}
					else
					{
						val = cnt++;
						cnt = cnt > 100 ? 1 : cnt;
					}
					lblValue.Text = val.ToString("F1");
					lblValue.Refresh();
					//write to xml
					if (cbWriteToFile.Checked)
					{
						lines[4] = "<timestamp>" + maxDate.ToString() + "</timestamp>";
						lines[5] = "<apeak>" + val.ToString("0.0") + "</apeak>";
						try
						{
							using (var targetFile = localFile.CreateText())
							{
								foreach (string line in lines)
								{
									targetFile.WriteLine(line);
								}
								targetFile.Flush();
								targetFile.Close();

							}
							if (File.Exists(actualFile))
							{
								File.Delete(actualFile);
							}
							File.Move(localPath, actualFile);
						}
						catch (Exception ex)
						{
							WriteLog(ex.Message);
						}
					}
				}

				do
				{
					Application.DoEvents();
					//Thread.Sleep(10);
					span = DateTime.Now - maxDate;
				} while ((int)span.TotalMilliseconds < (int)streamInt);
			}
		}

		public void StreamTask2(MeterSlm connection)
		{
			UInt32 time = 0;
			float val = 1;
			TimeSpan span;
			FileInfo localFile = new FileInfo(fileLocation);

			using (var targetFile = localFile.CreateText())
			{
				while (running)
				{
					// getStreamingData
					DateTime maxDate = DateTime.Now;
					if (!cbNoConnection.Checked)
					{
						connection.StreamData(out time, out val);
					}
					if (val > 0) // && val < 10000000)
					{
						if (!cbNoConnection.Checked)
						{
							val = SlmConvert.ToDecibels(val);
							DateTime date = new DateTime().AddSeconds(time);
							Console.Write(date.ToString() + " - ");
						}
						else
						{
							val = cnt++;
							cnt = cnt > 100 ? 1 : cnt;
						}
						lblValue.Text = val.ToString("F1");
						lblValue.Refresh();
						//write to xml
						if (cbWriteToFile.Checked)
						{
							lines[4] = "<timestamp>" + maxDate.ToString() + "</timestamp>";
							lines[5] = "<apeak>" + val.ToString("0.0") + "</apeak>";
							targetFile.BaseStream.Position = 0;
							try
							{
								foreach (string line in lines)
								{
									targetFile.WriteLine(line);
								}
								targetFile.Write("      ");
								targetFile.Flush();
							}
							catch (Exception ex)
							{
								WriteLog(ex.Message);
							}
						}
					}

					do
					{
						Application.DoEvents();
						//Thread.Sleep(10);
						span = DateTime.Now - maxDate;
					} while ((int)span.TotalMilliseconds < (int)streamInt);
				}
				targetFile.Close();
			}
		}

		public void StartConnection()
		{
			connectionString = tbConnectionString.Text;
			_options?.Set("Options", "ConnectionString", connectionString);
			_options?.Set("Options", "FileLocation", fileLocation);

			try
			{
				cmbFlags.Enabled = false;
				cmbRate.Enabled = false;
				//using (var connection = new MeterConnection(80, "TAPIEX;0;115200;11111111;4163"))
				if (!cbNoConnection.Checked)
				{
					if (connection == null)
					{
						if (connectionString.Contains("USB"))
						{
							ushort port = 80;
							try
							{
								string[] strSplit = connectionString.Split(':');
								if (strSplit.Length > 1)
								{
									port = ushort.Parse(strSplit[1]);
									connection = new MeterSlm("localhost", port, strSplit[0]);
								} else {
									//connection = new MeterSlm("localhost", 2525, connectionString);
									connection = new MeterSlm("localhost", port, connectionString);
								}
							}
							catch (Exception ex)
							{
								string msg = ex.Message;
								MessageBox.Show("Error trying to parse the port.  Please use a connection string similar to: USB;0;300:80 ");
								return;
							}
							Application.DoEvents();
							Thread.Sleep(2000);
							Application.DoEvents();
							Thread.Sleep(2000);
						}
						else
						{
							connection = new MeterSlm(connectionString, 80, "");
							Application.DoEvents();
							Thread.Sleep(2000);
						}
					}
				}
				Console.WriteLine("\nStarting Stream");

				//func: "startdatastreaming",
				//rate: iRate 5 => 1s,
				//flags: ALeq          : (0x00000001),   // ID_STH_ALEQ
				int flag = (int)cmbFlags.SelectedValue;
				int rate = (int)cmbRate.SelectedValue;
				switch (rate)
				{
					case 1:
						streamInt = StreamInterval.P50ms;
						break;
					case 2:
						streamInt = StreamInterval.P100ms;
						break;
					case 3:
						streamInt = StreamInterval.P200ms;
						break;
					case 4:
						streamInt = StreamInterval.P500ms;
						break;
					case 6:
						streamInt = StreamInterval.P2s;
						break;
					case 0:
					case 14:
					case 15:
						streamInt = StreamInterval.P5ms;
						break;
					case 13:
						streamInt = StreamInterval.P2500us;
						break;
					default:
					case 5:
						streamInt = StreamInterval.P1s;
						break;
				}
				if (!cbNoConnection.Checked)
				{
					LDArgs args = new LDArgs
					{
						{ "rate", rate },
						{ "flags", flag }
					};

					connection.SendSdkRequest("startDataStreaming", args);
				}

				Application.DoEvents();
				Thread.Sleep(500);

				running = true;
				//Task.Factory.StartNew(() => StreamTask(connection));
				if (cbMoveFile.Checked)
				{
					StreamTask3(connection);
				}
				else if (cbStayOpen.Checked)
				{
					StreamTask2(connection);
				}
				else
				{
					StreamTask(connection);
				}
			}
			catch (Exception e)
			{
				Console.WriteLine("Error: " + e.Message);
			}

		}

		private void buttonEnter(object sender, EventArgs e)
		{
			((Button)sender).ForeColor = Color.White;
		}
		private void buttonLeave(object sender, EventArgs e)
		{
			((Button)sender).ForeColor = Color.Cyan;
		}

		private void btnStart_Click(object sender, EventArgs e)
		{
			btnStart.ForeColor = Color.Gray;
			StartConnection();
			//btnStart.Enabled = false;
			this.Activate();
		}

		private void btnStop_Click(object sender, EventArgs e)
		{
			btnStart.ForeColor = Color.Cyan;
			if (running)
			{
				running = false;
				if (!cbNoConnection.Checked)
				{
					connection.SendSdkRequest("stopDataStreaming");
				}
			}
			//btnStart.Enabled = true;
			cmbFlags.Enabled = true;
			cmbRate.Enabled = true;
		}

		private void btnDisconnect_Click(object sender, EventArgs e)
		{
			if (connection != null)
			{
				connection.Dispose();
				connection = null;
			}
			//this.Close();
		}

		private void tbFileName_Click(object sender, EventArgs e)
		{
			TextBox tb = ((TextBox)sender);
			sfdOutputFileDlg.FileName = tb.Text;
			if (tb.Name == "tbFileName")
			{
				// Output file name filter
				sfdOutputFileDlg.Filter = "XML File (.xml)|*.xml|Txt File (.txt)|*.txt";
			}
			else
			{
				// log file name filter
				sfdOutputFileDlg.Filter = "Txt File (.txt)|*.txt";
			}
			if (sfdOutputFileDlg.ShowDialog() == DialogResult.OK)
			{
				string path = sfdOutputFileDlg.FileName;
				//tbFileName.Text = fileLocation;
				tb.Text = path;
				if (tb.Name == "tbFileName")
				{
					fileLocation = path;
					_options?.Set("Options", "FileLocation", fileLocation);
				}
				else
				{
					_options?.Set("Options", "LogLocation", path);
				}
			}
		}

		private void cbMoveFile_CheckedChanged(object sender, EventArgs e)
		{
			cbStayOpen.Checked = false;
			_options?.Set("Options", "StayOpen", cbStayOpen.Checked);
			_options?.Set("Options", "MoveFile", cbMoveFile.Checked);
		}

		private void cbStayOpen_CheckedChanged(object sender, EventArgs e)
		{
			cbMoveFile.Checked = false;
			_options?.Set("Options", "StayOpen", cbStayOpen.Checked);
			_options?.Set("Options", "MoveFile", cbMoveFile.Checked);
		}

		private void cbJustValue_CheckedChanged(object sender, EventArgs e)
		{
			_options?.Set("Options", "JustValue", cbJustValue.Checked);
		}

	}
}
