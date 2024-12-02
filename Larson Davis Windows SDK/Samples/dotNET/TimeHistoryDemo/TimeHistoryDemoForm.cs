using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Text;
using LarsonDavis.SDK.LDCommonStd.Core;
using LarsonDavis.SDK.LDCommonStd.Extension;
using LarsonDavis.SDK.LDCommonStd.Interface;
using LarsonDavis.SDK.LDCommonStd.Legacy;
using LarsonDavis.SDK.LDCommonStd.Services;
using LarsonDavis.SDK.LDTranslatorStd;
using LarsonDavis.SDK.LDTranslatorStd.Interface;
using Newtonsoft.Json.Linq;

namespace LarsonDavis.Sdk.TimeHistoryDemo
{
	public partial class TimeHistoryDemoForm : Form
	{
		private readonly BindingSource _gridSource;
		private BindingList<IDataRecordInfo> DataRecords { get; set; }
		private DateTime StartTime { get; set; }
		//private string _path;
		//private string _fileName = "";

		public TimeHistoryDemoForm()
		{
			InitializeComponent();

			//_path = string.Empty;
			//_fileName = string.Empty;
			_gridSource = new BindingSource();
			THGrid.DataSource = _gridSource;
			DataRecords = new BindingList<IDataRecordInfo>();
		}

		private void TimeHistoryDemoForm_Load(object sender, EventArgs e)
		{

		}

		private void openToolStripMenuItem_Click(object sender, EventArgs e)
		{
			try
			{
				string path = Environment.GetFolderPath(Environment.SpecialFolder.CommonApplicationData);
				path = Path.Combine(path, "PCB Piezotronics", "LDSdk");

				if (!Directory.Exists(path))
				{
					Directory.CreateDirectory(path);
				}

				openFileDialog1.InitialDirectory = path;

				if (DialogResult.OK == openFileDialog1.ShowDialog())
				{
					TranslateFile(openFileDialog1.FileName);
					DisplayRecord();
				}
			}
			catch (Exception ex)
			{
				string msg = ex.ToFullExceptionString();
				Debug.WriteLine($"{DateTime.Now:dd HH:mm:ss.fffff}: from TimeHistoryDemoForm: openToolStripMenuItem_Click(): Exception: {msg} on thread: {Thread.CurrentThread.ManagedThreadId}");
			}
		}

		private void opensFolderToolStripMenuItem_Click(object sender, EventArgs e)
		{

		}

		private void exitToolStripMenuItem_Click(object sender, EventArgs e)
		{
			Application.Exit();
		}

		private Tuple<ServiceReply, IList<ILDRecord>> TranslateFile(string fileName)
		{
			IList<ILDRecord> recList = new List<ILDRecord>();
			ISlmTranslator trans = new SlmTranslator();
			Tuple<ServiceReply, IDataFileInfo> result = trans.TranslateFileComplete(fileName);
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
			}
		}

		private void DisplaySummaryData(SlmRecord rec)
		{
			StringBuilder sb = new StringBuilder();
			sb.Append(string.Format("Serial Number: {0},  ", rec.SerialNumber));
			sb.Append(string.Format("Firmware Version: {0}", rec.FwVersion));

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

		private DataTable BuildTimeHistoryDataTable(SlmRecord rec, IList<stTHItemInfo_t> thItems, ref int gustCol)
		{
			DataTable result = new DataTable();

			string heading= "Record #";
			result.Columns.Add(heading, typeof(int));

			heading = "Record Type";
			result.Columns.Add(heading, typeof(string));

			heading = "Date";
			result.Columns.Add(heading, typeof(string));

			heading = "Time";
			result.Columns.Add(heading, typeof(string));

			int numItems = rec.THMngr.NumTimeHistoryItems;
			for (int i = 0; i < numItems; ++i)
			{
				Type colType;
				string freq;
				var item = thItems[i];
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
							heading = $"{label} {freq}";

							result.Columns.Add(heading, colType);
						}
						break;

					case THOptionType.ThirdOctave:
						colType = typeof(float);
						for (int j = 0; j < LDConstants.ThirdOctaveBins; ++j)
						{
							freq = SlmConstants.GetObaFrequencyLabel(ObaBandwidth.ThirdOctave, j);
							heading = $"{label} {freq}";

							result.Columns.Add(heading, colType);
						}
						break;

					default:
						colType = typeof(float);
						switch (id)
						{
							case THOptionId.GustDir:
								{
									string units;
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

									label = $"{label} {units}";
									break;
								}
							case THOptionId.IntTemp or THOptionId.PreampTemperature:
								{
									string units = UnitConversion.English == rec.UnitsSystem ? "(°F)" : "(°C)";

									label = $"{label} {units}";
									break;
								}
							case >= THOptionId.Ln1 and <= THOptionId.Ln6:
								{
									// get a zero based index into the LnValues array
									int ln = (int)TimeHistoryOptions.THOptions[ndx].id - (int)THOptionId.Ln1;
									int wgt = (int)rec.RmsWeightIndex;
									int det = (rec.Integration == IntegrationMethod.Linear) ? -1 : (int)rec.DetectorIndex;
									string lwd = SlmLegacy.MakeLWeightDetectorString(wgt, det, "");

									label = $"{lwd}{rec.LnValues[ln]:F2}";
									break;
								}
							default:
								{
									if (WeatherEnable.Vaisala == rec.WeatherOption && id is >= THOptionId.ADC1Avg and <= THOptionId.ADC2Min)
									{
										label = id switch
										{
											THOptionId.ADC1Avg => "Avg Temp",
											THOptionId.ADC1Max => "Max Temp",
											THOptionId.ADC1Min => "Min Temp",
											THOptionId.ADC2Avg => "Avg Humidity",
											THOptionId.ADC2Max => "Max Humidity",
											THOptionId.ADC2Min => "Min Humidity",
											_ => label
										};
									}

									break;
								}
						}

						heading = label;

						bool done;
						do
						{
							done = true;
							try
							{
								result.Columns.Add(heading, colType);
							}
							catch (DuplicateNameException)
							{
								heading = $" {heading}";
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


		private void BuildTimeHistorySessionLog(SlmRecord rec, TimeHistoryRecord thRec, DataRow row, ref int col, ref float dur)
		{
			switch (thRec.RecordNum)
			{
				case >= 0 when thRec.RecordNum < rec.SessionLog.RunRecords.Count:
					{
						RunRecord runRec = rec.SessionLog.RunRecords[thRec.RecordNum];
						DateTime recTime = LDConstants.Epoch.AddSeconds(thRec.TimeStamp);

						if (thRec.TimeStamp < 100)
						{
							if (runRec.Type is ActionCause.ActionRun or ActionCause.ActionResume)
							{
								recTime = LDConstants.Epoch.AddSeconds(runRec.RecordDate);
								StartTime = recTime;
								dur = 0;
							}
						}

						row[col++] = SessionLog.GetLogAction(runRec.Type);
						row[col++] = recTime.ToString("yyyy-MM-dd");
						row[col++] = recTime.ToString("HH:mm:ss");
						break;
					}
			}
		}


		private void BuildTimeHistoryDataRecord(SlmRecord rec, TimeHistoryRecord thRec, IList<stTHItemInfo_t> thItems, DataRow row, ref int col, ref float dur, IList<string> gustVals)
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

			row[col++] = string.Empty;
			row[col++] = recTime.ToString("yyyy-MM-dd");
			row[col++] = recTime.ToString("HH:mm:ss");

			int src = 0;
			int items11 = 0;
			int items13 = 0;
			int numItems = rec.THMngr.NumTimeHistoryItems;
			for (int i = 0; i < numItems; ++i)
			{
				float val = 0;
				string buff = string.Empty;
				var item = thItems[i];
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
						switch (id)
						{
							case THOptionId.GustDir:
								val = SlmConvert.ConvertWindDirection(val, rec.WindDirection, ref buff);
								gustVals.Add(buff);
								break;
							case THOptionId.IntTemp:
							case THOptionId.PreampTemperature:
								val = SlmConvert.ConvertToPreferredUnits(rec.UnitsSystem, UnitType.Temp, rec.WeatherOption, val);
								break;
							default:
								if (WeatherEnable.Vaisala == rec.WeatherOption)
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
								break;
						}

						row[col++] = THOptionId.GustDir == id && WindDirection.Compass == rec.WindDirection ? buff : $"{val:F1}";

						break;
				}
			}

			row[col++] = (thRec.Flag & (uint)TimeHistory.Overload) > 0 ? "Yes" : "No";
			row[col++] = (thRec.Flag & (uint)TimeHistory.ObaOverload) > 0 ? "Yes" : "No";

			uint mask = 1;
			StringBuilder sb = new StringBuilder();
			for (int i = 0; i < SlmConstants.NumMarkers; ++i)
			{
				if ((thRec.Flag & mask) > 0)
				{
					sb.Append($"{rec.MarkerNames[i]};");
				}
				mask <<= 1;
			}
			if ((thRec.Flag & (uint)TimeHistory.BackErase) > 0)
			{
				sb.Append($"Back Erase;");
			}

			row[col++] = sb.ToString();
		}
	}
}
