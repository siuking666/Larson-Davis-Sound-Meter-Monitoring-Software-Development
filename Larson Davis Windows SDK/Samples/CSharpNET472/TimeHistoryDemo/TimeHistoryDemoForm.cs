using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using System.Windows.Forms;

using LarsonDavis.SDK.LDCommonStd.Core;
using LarsonDavis.SDK.LDCommonStd.Extension;
using LarsonDavis.SDK.LDCommonStd.Interface;
using LarsonDavis.SDK.LDCommonStd.Legacy;
using LarsonDavis.SDK.LDCommonStd.Services;
using LarsonDavis.SDK.LDTranslatorStd;
using LarsonDavis.SDK.LDTranslatorStd.Interface;
using Microsoft.WindowsAPICodePack.Dialogs;
using Newtonsoft.Json.Linq;


namespace LarsonDavis.Sdk.TimeHistoryDemo
{
	public partial class TimeHistoryDemoForm : Form
	{
		private BindingSource _gridSource = new BindingSource();
		public BindingList<IDataRecordInfo> DataRecords { get; set; }
		public DateTime StartTime { get; set; }
		public String sPath { get; set; }

		private double value;
		public double Value
		{
			get { return value; }
		}

		private string fileName = "";
		private Process mHLDProcess;

		public TimeHistoryDemoForm()
		{
			InitializeComponent();

			DataRecords = new BindingList<IDataRecordInfo>();

			THGrid.DataSource = _gridSource;
		}

		private void openToolStripMenuItem_Click(object sender, EventArgs e)
		{
			string path = Environment.GetFolderPath(Environment.SpecialFolder.CommonApplicationData);
			path += @"\PCB Piezotronics\LDSdk\";
			openFileDialog1.InitialDirectory = path;

			if (openFileDialog1.ShowDialog() == DialogResult.OK)
			{
				TranslateFile(openFileDialog1.FileName);
				DisplayRecord();
			}
		}

		private void opensFolderMI_Click(object sender, EventArgs e)
		{
			CommonOpenFileDialog dialog = new CommonOpenFileDialog
			{
				InitialDirectory = "C:\\Users",
				IsFolderPicker = true
			};

			if (dialog.ShowDialog() == CommonFileDialogResult.Ok)
			{
				if (dialog.FileName.ToLower().Contains(".ld7"))
				{
					TranslateFile(dialog.FileName);
					DisplayRecord();
				}
				else
				{
					DownloadFile(dialog.FileName, 2520);
					TranslateFile(sPath);
					DisplayRecord();
				}
			}
		}

		private void exitToolStripMenuItem_Click(object sender, EventArgs e)
		{
			Application.Exit();
		}

		private Tuple<ServiceReply, IList<ILDRecord>> TranslateFile(string fileName)
		{
			IList<ILDRecord> recList = new List<ILDRecord>();
			Tuple<ServiceReply, IDataFileInfo> result;

			if (fileName.ToLower().Contains(".ld7"))
			{
				ISpartanTranslator trans = new SpartanTranslator();
				result = trans.TranslateFileComplete(fileName, null);
			}
			else
			{
				ISlmTranslator trans = new SlmTranslator();
				result = trans.TranslateFileComplete(fileName);
			}

			ServiceReply sr = result.Item1;

			switch (sr.Response)
			{
				case ServiceResponse.Success:
				case ServiceResponse.SuccessWithParseError:
				case ServiceResponse.SuccessWithTruncation:
				case ServiceResponse.MultiRecord:
					DataRecords.Clear();
					foreach (var dataRec in result.Item2.RecordList)
					{
						if (dataRec.Record is SlmRecord rec)
						{
							rec.MetaRec.FileName = fileName;
							rec.FilePath = fileName;
							rec.LdbinFileName = Path.GetFileName(fileName);
							recList.Add(rec);
						}
						else if (dataRec.Record is SpartanRecord spaRec)
						{
							spaRec.MetaRec.FileName = fileName;
							spaRec.FilePath = fileName;
							spaRec.DataFileName = Path.GetFileName(fileName);
							recList.Add(spaRec);
						}

						DataRecords.Add(dataRec);
					}

					Records.DisplayMember = "Name";
					Records.ValueMember = null;
					Records.DataSource = DataRecords;
					Records.SelectedItem = 0;
					break;

				case ServiceResponse.BadFileFormat:
				case ServiceResponse.BadFileName:
				default:
					Debug.WriteLine($"{DateTime.Now:dd HH:mm:ss.fffff}: TimeHistoryDemoForm: TranslateFile(): Error: {sr.Response}: {sr.Message}");
					break;
			}

			return new Tuple<ServiceReply, IList<ILDRecord>>(sr, recList);
		}

		private void Records_SelectedIndexChanged(object sender, EventArgs e)
		{
			DisplayRecord();
		}

		private void DisplayRecord()
		{
			if (Records.SelectedValue != null)
			{
				IDataRecordInfo dataRec = (DataRecordInfo)Records.SelectedValue;

				if (dataRec.Record is SlmRecord rec)
				{
					DisplaySummaryData(rec);

					if (rec.THMngr.NumTHRecords > 0)
					{
						DisplayTimeHistoryData(rec);
					}
				}
				else if (dataRec.Record is SpartanRecord spaRec)
				{
					DisplaySummaryData(spaRec);

					if (spaRec.TimeHistory.Count > 0)
					{
						DisplayTimeHistoryData(spaRec);
					}
				}
			}
		}

		private void DisplaySummaryData(ILDRecord rec)
		{
			StringBuilder sb = new StringBuilder();
			sb.Append(string.Format("Serial Number: {0},  ", rec.SerialNumber));
			sb.Append(string.Format("Firmware Version: {0}\r\n", rec.FwVersion));
			if (rec is SpartanRecord spaRec)
			{
				sb.Append(spaRec.GetOverallDataJson());
			}
			Summary.Text = sb.ToString();
		}

		private void DisplayTimeHistoryData(SlmRecord rec)
		{
			int totalRecs = rec.THMngr.NumTHRecords;
			int col = 0;
			int gustCol = 0;
			float dur = 0;
			IList<string> gustVals = new List<string>();
			IList<stTHItemInfo_t> thItems = rec.TimeHistOptions.BuildTHItemInfoList(rec);
			DataTable dt = BuildTimeHistoryDataTable(rec, thItems, ref gustCol);

			StartTime = LDConstants.Epoch.AddSeconds(rec.StartTime);


			for (int curRec = 0; curRec < totalRecs && curRec < SlmConstants.ChunkSize; ++curRec)
			{
				TimeHistoryRecord thRec = rec.THMngr.THRecs[curRec];
				DataRow row = dt.NewRow();
				col = 0;

				row[col++] = curRec + 1;
				if ((thRec.Flag & (uint)TimeHistory.SessionLog) > 0)
				{
					BuildTimeHistorySessionLog(rec, thRec, row, ref col, ref dur);
				}
				else
				{
					BuildTimeHistoryDataRecord(rec, thRec, thItems, row, ref col, ref dur, gustVals);
				}
				dt.Rows.Add(row);
			}

			_gridSource.DataSource = dt;

			THGrid.AutoResizeColumns(DataGridViewAutoSizeColumnsMode.DisplayedCells);
			THGrid.Refresh();
		}

		private void DisplayTimeHistoryData(SpartanRecord rec)
		{
			int totalRecs = rec.TimeHistory.Count;
			int col = 0;
			DataTable dt = BuildTimeHistoryDataTable(rec);

			for (int curRec = 0; curRec < totalRecs; ++curRec)
			{
				TimeHistoryEntry_t thRec = rec.TimeHistory[curRec];
				DataRow row = dt.NewRow();
				col = 0;

				row[col++] = curRec + 1;
				BuildTimeHistoryDataRecord(rec, row, thRec);
				dt.Rows.Add(row);
			}

			_gridSource.DataSource = dt;

			THGrid.AutoResizeColumns(DataGridViewAutoSizeColumnsMode.DisplayedCells);
			THGrid.Refresh();
		}

		public DataTable BuildTimeHistoryDataTable(ISpartanRecord spaRec)
		{
			DataTable result = new DataTable();

			string heading = "Record Type";
			result.Columns.Add(heading, typeof(string));

			heading = "Date / Time";
			result.Columns.Add(heading, typeof(DateTime));

			IList<X21MetricMeta> metaList = spaRec.MetricMetaMapping;

			if (null != metaList && metaList.Count > 0)
			{
				int oba11Ndx = 0;
				int oba13Ndx = 0;

				foreach (var elem in metaList.OrderBy(m => m.Column))
				{
					bool fullOba = elem.Id == MetricId.FullOba || elem.Id == MetricId.FullObaMin || elem.Id == MetricId.FullObaMax;
					bool thirdOba = elem.Id == MetricId.ThirdOba || elem.Id == MetricId.ThirdObaMin || elem.Id == MetricId.ThirdObaMax;

					string header = elem.Header;
					string label = fullOba
						? SlmConstants.GetObaFrequencyLabel(ObaBandwidth.FullOctave, oba11Ndx)
						: thirdOba
							? SlmConstants.GetObaFrequencyLabel(ObaBandwidth.ThirdOctave, oba13Ndx)
							: string.Empty;

					if (!string.IsNullOrEmpty(label))
					{
						int wgt = (int)spaRec.MeasSettings.OBAFreqWeight;
						int det = (int)spaRec.MeasSettings.OBATimeWeight;
						string format = $"L{{0}}{{1}}";

						switch (elem.Id)
						{
							case MetricId.FullObaMax:
								string fullObaMax = SlmLegacy.MakeLWeightDetectorString(wgt, det, "max", format);
								header = $"1/1 {fullObaMax} {label}";
								break;
							case MetricId.FullObaMin:
								string fullObaMin = SlmLegacy.MakeLWeightDetectorString(wgt, det, "min", format);
								header = $"1/1 {fullObaMin} {label}";
								break;
							case MetricId.FullOba:
								string fullObaEq = SlmLegacy.MakeLWeightDetectorString(wgt, -1, "eq", format);
								header = $"1/1 {fullObaEq} {label}";
								break;
							case MetricId.ThirdObaMax:
								string thirdObaMax = SlmLegacy.MakeLWeightDetectorString(wgt, det, "max", format);
								header = $"1/3 {thirdObaMax} {label}";
								break;
							case MetricId.ThirdObaMin:
								string thirdObaMin = SlmLegacy.MakeLWeightDetectorString(wgt, det, "min", format);
								header = $"1/3 {thirdObaMin} {label}";
								break;
							case MetricId.ThirdOba:
								string thirdObaEq = SlmLegacy.MakeLWeightDetectorString(wgt, -1, "eq", format);
								header = $"1/3 {thirdObaEq} {label}";
								break;
						}
					}

					result.Columns.Add(header, elem.DataType);

					if (fullOba)
					{
						++oba11Ndx;
					}

					if (thirdOba)
					{
						++oba13Ndx;
					}

					if (oba11Ndx >= LDConstants.FullOctaveBins)
					{
						oba11Ndx = 0;
					}
					if (oba13Ndx >= LDConstants.ThirdOctaveBins)
					{
						oba13Ndx = 0;
					}
				}
			}

			heading = "Markers";
			result.Columns.Add(heading, typeof(string));

			return result;
		}

		/// <summary>
		/// Build Time History Data Row to be used by SAX and non-SAX implementations potentially.
		/// </summary>
		/// <param name="rec"></param>
		/// <param name="row"></param>
		/// <param name="entry"></param>
		public int BuildTimeHistoryDataRecord(SpartanRecord Record, DataRow row, TimeHistoryEntry_t entry)
		{
			string val;

			switch (entry.Flags)
			{
				case var x when x.HasFlag(TimeHistoryFlags.START):
					val = "Start";
					break;
				case var x when x.HasFlag(TimeHistoryFlags.STOP):
					val = "Stop";
					break;
				case var x when x.HasFlag(TimeHistoryFlags.PAUSED):
					val = "Pause";
					break;
				default:
					val = string.Empty;
					break;
			}

			int col = 0;
			row[col++] = val;

			try
			{
				if ((entry.X21MetricsList.Count + entry.X21SpecialList.Count) > 0)
				{
					row[col++] = LDConstants.Epoch.AddSeconds(entry.Timestamp);
				}

				int metricThreashold = Record.TmsEnabled ? 2 : 1;
				// any remaining metrics (including Tms) are handled by MetricMetaMapping
				if ((entry.X21MetricsList.Count + entry.X21SpecialList.Count) > metricThreashold)
				{
					var metaList = Record.MetricMetaMapping;

					foreach (var meta in metaList.OrderBy(m => m.Column))
					{
						if (meta.DataType.IsNumericHash() && entry.X21MetricsList.Count > meta.MetricListIndex)
						{
							row[(int)meta.Column] = entry.X21MetricsList[meta.MetricListIndex];
						}
						else if (!meta.DataType.IsNumericHash() && entry.X21SpecialList.Count > meta.MetricListIndex)
						{
							row[(int)meta.Column] = entry.X21SpecialList[meta.MetricListIndex];
						}
						++col;
					}
				}
			}
			catch (Exception ex)
			{
				string msg = ex.ToString();
				Debug.WriteLine($"{DateTime.Now:dd HH:mm:ss.fffff}: Exception: {msg}");
			}

			return col;
		}

		public DataTable BuildTimeHistoryDataTable(SlmRecord rec, IList<stTHItemInfo_t> thItems, ref int gustCol)
		{
			DataTable result = new DataTable();
			string heading = String.Empty;

			heading = "Record #";
			result.Columns.Add(heading, typeof(int));

			heading = "Record Type";
			result.Columns.Add(heading, typeof(string));

			heading = "Date";
			//result.Columns.Add(heading, typeof(DateTime));
			result.Columns.Add(heading, typeof(string));

			heading = "Time";
			//result.Columns.Add(heading, typeof(DateTime));
			result.Columns.Add(heading, typeof(string));

			int numItems = rec.THMngr.NumTimeHistoryItems;
			for (int i = 0; i < numItems; ++i)
			{
				var item = thItems[i];
				Type colType = typeof(float);
				string freq = String.Empty;
				string buff = String.Empty;
				int ndx = item.ndx;
				THOptionId id = item.id;
				THOptionType type = item.type;
				string label = item.label;

				switch (type)
				{
					case THOptionType.FullOctave:
						colType = typeof(float);
						for (int j = 0; j < LDConstants.FullOctaveBins; ++j)
						{
							freq = SlmConstants.GetObaFrequencyLabel(ObaBandwidth.FullOctave, j);
							heading = string.Format("{0} {1}", label, freq);

							result.Columns.Add(heading, colType);
						}
						break;

					case THOptionType.ThirdOctave:
						colType = typeof(float);
						for (int j = 0; j < LDConstants.ThirdOctaveBins; ++j)
						{
							freq = SlmConstants.GetObaFrequencyLabel(ObaBandwidth.ThirdOctave, j);
							heading = string.Format("{0} {1}", label, freq);

							result.Columns.Add(heading, colType);
						}
						break;

					default:
						colType = typeof(float);
						if (THOptionId.GustDir == id)
						{
							string units = String.Empty;
							switch (rec.WindDirection)
							{
								case WindDirection.Compass:
									units = "(Compass)";
									colType = typeof(string);
									break;
								case WindDirection.Percent:
									units = "(% Percent)";
									break;
								case WindDirection.Volts:
									units = "(V Volts)";
									break;
								case WindDirection.Degrees:
								default:
									units = "(° Degrees)";
									break;
							}

							buff = string.Format("{0} {1}", label, units);
						}
						else if (THOptionId.IntTemp == id || THOptionId.PreampTemperature == id)
						{
							string units = "(°C)";
							if (UnitConversion.English == rec.UnitsSystem)
							{
								units = "(°F)";
							}

							buff = string.Format("{0} {1}", label, units);
						}
						else if (id >= THOptionId.Ln1 && id <= THOptionId.Ln6)
						{
							// get a zero based index into the LnValues array
							int ln = (int)TimeHistoryOptions.THOptions[ndx].id - (int)THOptionId.Ln1;
							int wgt = (int)rec.RmsWeightIndex;
							int det = (rec.Integration == IntegrationMethod.Linear) ? -1 : (int)rec.DetectorIndex;
							string lwd = SlmLegacy.MakeLWeightDetectorString(wgt, det, "");

							buff = string.Format("{0}{1:F2}", lwd, rec.LnValues[ln]);
						}
						else if ((WeatherEnable.Vaisala == rec.WeatherOption) && (id >= THOptionId.ADC1Avg && id <= THOptionId.ADC2Min))
						{
							switch (id)
							{
								case THOptionId.ADC1Avg:
									label = "Avg Temp";
									break;
								case THOptionId.ADC1Max:
									label = "Max Temp";
									break;
								case THOptionId.ADC1Min:
									label = "Min Temp";
									break;
								case THOptionId.ADC2Avg:
									label = "Avg Humidity";
									break;
								case THOptionId.ADC2Max:
									label = "Max Humidity";
									break;
								case THOptionId.ADC2Min:
									label = "Min Humidity";
									break;
							}
							buff = label;
						}
						else
						{
							buff = label;
						}

						heading = buff;

						bool done = false;
						do
						{
							done = true;
							try
							{
								result.Columns.Add(heading, colType);
							}
							catch (DuplicateNameException)
							{
								heading = " " + heading;
								done = false;
							}
						} while (!done);

						if (THOptionId.GustDir == id)
						{
							gustCol = result.Columns.Count;
						}

						break;
				}
			}

			heading = "Ovrld.";
			result.Columns.Add(heading, typeof(string));
			heading = "OBA Ovrld.";
			result.Columns.Add(heading, typeof(string));
			heading = "Marker";
			result.Columns.Add(heading, typeof(string));

			return result;
		}


		public void BuildTimeHistorySessionLog(SlmRecord rec, TimeHistoryRecord thRec, DataRow row, ref int col, ref float dur)
		{
			if (thRec.RecordNum >= 0 && thRec.RecordNum < rec.SessionLog.RunRecords.Count)
			{
				RunRecord runRec = rec.SessionLog.RunRecords[thRec.RecordNum];
				DateTime recTime = LDConstants.Epoch.AddSeconds(thRec.TimeStamp);

				if (thRec.TimeStamp < 100)
				{
					if (ActionCause.ActionRun == runRec.Type || ActionCause.ActionResume == runRec.Type)
					{
						recTime = LDConstants.Epoch.AddSeconds(runRec.RecordDate);
						StartTime = recTime;
						dur = 0;
					}
				}

				row[col++] = SessionLog.GetLogAction(runRec.Type);
				row[col++] = recTime.ToString("yyyy-MM-dd");
				row[col++] = recTime.ToString("HH:mm:ss");
			}
		}


		public void BuildTimeHistoryDataRecord(SlmRecord rec, TimeHistoryRecord thRec, IList<stTHItemInfo_t> thItems, DataRow row, ref int col, ref float dur, IList<string> gustVals)
		{
			DateTime recTime = LDConstants.Epoch.AddSeconds(thRec.TimeStamp);

			if (thRec.TimeStamp < 100)
			{
				TimeSpan tsDur = new TimeSpan((long)(dur + .5) * 10000);  //
				recTime = StartTime + tsDur;
				if (Math.Abs(thRec.Duration - rec.GetTimeHistorySamplePeriod()) < .005f)
				{
					thRec.Duration = rec.GetTimeHistorySamplePeriod();
				}
				dur += thRec.Duration;
			}

			row[col++] = String.Empty;
			row[col++] = recTime.ToString("yyyy-MM-dd");
			row[col++] = recTime.ToString("HH:mm:ss");

			int src = 0;
			int items11 = 0;
			int items13 = 0;
			int numItems = rec.THMngr.NumTimeHistoryItems;
			for (int i = 0; i < numItems; ++i)
			{
				var item = thItems[i];
				float val = 0;
				string buff = String.Empty;
				int ndx = item.ndx;
				THOptionId id = item.id;
				THOptionType type = item.type;
				switch (type)
				{
					case THOptionType.FullOctave:
						for (int j = 0; j < LDConstants.FullOctaveBins; ++j)
						{
							val = thRec.THFullOctaveOba[items11, j];
							row[col++] = val;
						}
						++items11;
						break;

					case THOptionType.ThirdOctave:
						for (int j = 0; j < LDConstants.ThirdOctaveBins; ++j)
						{
							val = thRec.THThirdOctaveOba[items13, j];
							row[col++] = val;
						}
						++items13;
						break;

					case THOptionType.dB:
					case THOptionType.Normal:
					default:
						val = thRec.THFloatVals[src++];
						if (Math.Abs(val) > 10000.0f)
						{
							val = LDConstants.InvalidVal;
						}
						if (THOptionId.GustDir == id)
						{
							val = SlmConvert.ConvertWindDirection(val, rec.WindDirection, ref buff);
							gustVals.Add(buff);
						}
						else if (THOptionId.IntTemp == id || THOptionId.PreampTemperature == id)
						{
							val = SlmConvert.ConvertToPreferredUnits(rec.UnitsSystem, UnitType.Temp, rec.WeatherOption, val);
						}
						else if (WeatherEnable.Vaisala == rec.WeatherOption)
						{
							switch (id)
							{
								case THOptionId.AvgWindSpeed:
								case THOptionId.GustSpeed:
									val = SlmConvert.ConvertToPreferredUnits(rec.UnitsSystem, UnitType.Wind, rec.WeatherOption, val);
									break;
								case THOptionId.ADC1Avg:
								case THOptionId.ADC1Max:
								case THOptionId.ADC1Min:
									val = SlmConvert.ConvertToPreferredUnits(rec.UnitsSystem, UnitType.Temp, rec.WeatherOption, val);
									break;
								case THOptionId.ADC2Avg:
								case THOptionId.ADC2Max:
								case THOptionId.ADC2Min:
									val = SlmConvert.ConvertToPreferredUnits(rec.UnitsSystem, UnitType.Humidity, rec.WeatherOption, val);
									break;
							}
						}
						else
						{
							if (THOptionId.GustDir == id)
							{
								buff = string.Format("{0:F2}", val);
								gustVals.Add(buff);
							}
						}

						row[col] = val;

						if (THOptionId.GustDir == id && WindDirection.Compass == rec.WindDirection) row[col] = buff;

						++col;

						break;
				}
			}

			//bool overloadedRow = false;
			if ((thRec.Flag & (uint)TimeHistory.Overload) > 0)
			{
				row[col++] = "Yes";
				//overloadedRow = true;
			}
			else
			{
				row[col++] = "No";
			}

			if ((thRec.Flag & (uint)TimeHistory.ObaOverload) > 0)
			{
				row[col++] = "Yes";
				//overloadedRow = true;
			}
			else
			{
				row[col++] = "No";
			}

			uint mask = 1;
			StringBuilder sb = new StringBuilder();
			for (int i = 0; i < SlmConstants.NumMarkers; ++i)
			{
				if ((thRec.Flag & mask) > 0)
				{
					sb.Append(string.Format("{0};", rec.MarkerNames[i]));
				}
				mask <<= 1;
			}
			if ((thRec.Flag & (uint)TimeHistory.BackErase) > 0)
			{
				sb.Append(string.Format("{0};", "Back Erase"));
			}

			row[col++] = sb.ToString();
		}

		private IList<IntervalInfo> GetMeasurementHistory(SlmRecord rec)
		{
			IList<IntervalInfo> result = new List<IntervalInfo>();

			if (rec.Intervals.Count > 0)
			{
				result = rec.Intervals;

				foreach (var item in rec.Intervals)
				{
					ProcessMeasurementHistory(item);
				}
			}

			return result;
		}

		private void ProcessMeasurementHistory(IntervalInfo item)
		{
			throw new NotImplementedException();
		}

		private IList<EventInfo> GetEventHistory(SlmRecord rec)
		{
			IList<EventInfo> result = new List<EventInfo>();

			if (rec.Events.Count > 0)
			{
				result = rec.Events;

				foreach (var item in rec.Events)
				{
					ProcessEventHistory(item);
				}
			}

			return result;
		}

		private void ProcessEventHistory(EventInfo item)
		{
			throw new NotImplementedException();
		}

		private bool DownloadFile(string folderPath, int port)
		{
			bool result = true;
			var directory = new DirectoryInfo(folderPath);
			JObject jsonObj;
			string IpAddress = "localhost";

			int fileSize = 0;
			int fileIndex = 0;
			//var mode = InstrumentMode.Slm;

			//switch (directory.Name.Substring(directory.Name.Length-1).ToCharArray()[0])
			//{
			//	case 's': mode = InstrumentMode.Slm; break;
			//	case 'r': mode = InstrumentMode.RT60; break;
			//	case 'f': mode = InstrumentMode.Fft; break;
			//	default: mode = InstrumentMode.Slm; break;
			//}

			//Setup HLD
			var meter = new MeterModel();
			var connectionString = string.Format("-p {0} -r Resources -c DIRECT;0;800", port);
			mHLDProcess = CommandLineApp.LaunchLDDaemon(connectionString, false);
			meter.HttpLdRootUri = string.Format("{0}://{1}:{2}", (port == 443 ? "https" : "http"), IpAddress, port);
			meter.IpAddress = IpAddress;
			meter.DownloadPort = port;

			//Set Directory HLD Directory
			string path = directory.Parent.Parent.FullName;
			string dirName = directory.Parent.Name;

			fileName = Path.GetFileNameWithoutExtension(folderPath);
			fileName = fileName.Replace(".", "_");
			var outputFile = new FileInfo(directory.Parent.FullName + "\\" + fileName + ".ldbin");
			fileName = outputFile.FullName;
			sPath = fileName;

			result = meter.GetJSON(string.Format($"/sdk?func=setfilepath&root={path}&dirname={dirName}"), null, "Success", out jsonObj);

			//Find File to Download
			if (result)
			{
				JObject fileList = null;
				bool closing = false;
				result = (!meter.StartBuildingFileList(out fileList) &&
					!meter.CheckIfFileListReady(ref closing, false) &&
					meter.GetJSON("/sdk?func=getDataFileList", null, "DataFiles", out jsonObj));
			}


			//Find File to Download
			if (result)
			{
				Console.WriteLine("Failed to build file.");
			}

			if (result)
			{
				foreach (var file in jsonObj["DataFiles"])
				{
					if ((string)file["name"] == directory.Name)
					{
						fileSize = (int)file["size"];
						fileIndex = (short)file["index"];
						break;
					}
				}
				if (fileSize == 0)
				{
					result = false;
				}
			}


			// Create output Director;
			if (result)
			{
				if (!outputFile.Directory.Exists)
				{
					outputFile.Directory.Create();
				}
			}


			//Set Directory.

			//Write Headers
			if (result)
			{
				using (var ldbinFile = new BinaryWriter(outputFile.Open(FileMode.Create, FileAccess.ReadWrite, FileShare.Read)))
				{
					ldbinFile.Write((int)LDBinHeader.Ld);
					ldbinFile.Write((int)LDBinHeader.Bin);
					ldbinFile.Write((int)LDBinHeader.Ver);
					ldbinFile.Write((int)1); //Number of Files Always 1 for file Import.
					ldbinFile.Write((int)fileSize);

					//Download File
					var task = meter.StreamDownload(fileIndex, fileSize, ldbinFile.BaseStream, (state, downloaded, error) =>
					{
						value = downloaded / (double)fileSize;
						result = error == LDError.Success;
						return result;
					});
					task.Wait();
				}
			}
			if (!result)
			{
				try
				{
					outputFile.Delete();
				}
				catch { }
				fileName = "";
			}
			else
			{
				//Done
				value = 100.0;
				System.Threading.Thread.Sleep(0);
			}
			meter.GetJSON("/sdk?func=closeDown&speed=1", null, "fred", out jsonObj);

			return result;
		}

		private void TimeHistoryDemoForm_FormClosing(object sender, FormClosingEventArgs e)
		{
			if (null != mHLDProcess)
			{
				//checks to see if the process has closed before killing it.
				if (!mHLDProcess.WaitForExit(500))
				{
					try
					{
						mHLDProcess.Kill();
					}
					catch
					{
					}
				}

				if (mHLDProcess.HasExited)
				{
					mHLDProcess = null;
				}
			}
		}


	}
}
