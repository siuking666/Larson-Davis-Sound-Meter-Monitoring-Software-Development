using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.IO;
using System.Media;
using System.Text;
using System.Windows.Forms;

using LarsonDavis.SDK.LDCommonStd.Core;
using LarsonDavis.SDK.LDCommonStd.Interface;
using LarsonDavis.SDK.LDCommonStd.Legacy;
using LarsonDavis.SDK.LDCommonStd.Services;
using LarsonDavis.SDK.LDTranslatorStd;
using LarsonDavis.SDK.LDTranslatorStd.Interface;

namespace LarsonDavis.Sdk.SoundRecordingDemo
{
	public partial class SoundRecordingDemoForm : Form
	{
		private BindingSource _gridSource = new BindingSource();
		public BindingList<IDataRecordInfo> DataRecords { get; set; }
		public SlmRecord CurrentRecord { get; set; }

		public SoundRecordingDemoForm()
		{
			InitializeComponent();

			DataRecords = new BindingList<IDataRecordInfo>();

			SLGrid.DataSource = _gridSource;
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

		private void exitToolStripMenuItem_Click(object sender, EventArgs e)
		{
			Application.Exit();
		}

		private Tuple<ServiceReply, IList<ILDRecord>> TranslateFile(string fileName)
		{
			//SlmTranslator trans = new SlmTranslator();
			//Tuple<ServiceReply, IList<ILDRecord>> result = trans.TranslateFileComplete(fileName);
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
					Debug.WriteLine($"{DateTime.Now:dd HH:mm:ss.fffff}: SoundRecordingDemoForm: TranslateFile(): Error: {sr.Response}: {sr.Message}");
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
					CurrentRecord = rec;
					DisplaySummaryData(CurrentRecord);

					if (CurrentRecord.SessionLog.RunRecords.Count > 0)
					{
						DisplaySessionLogData(CurrentRecord);
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

		private void DisplaySessionLogData(SlmRecord rec)
		{
			DataTable dt = BuildSessionLogDataTable(rec);

			int numRecs = rec.SessionLog.RunRecords.Count;
			int col = 0;

			for (int i = 0; i < numRecs; ++i)
			{
				RunRecord run = rec.SessionLog.RunRecords[i];
				DataRow row = dt.NewRow();
				col = 0;

				row[col++] = i + 1;
				BuildSessionLogDataRecord(rec, run, row, ref col);
				dt.Rows.Add(row);
			}

			_gridSource.DataSource = dt;

			SLGrid.AutoResizeColumns(DataGridViewAutoSizeColumnsMode.DisplayedCells);
			SLGrid.Refresh();
		}

		private DataTable BuildSessionLogDataTable(SlmRecord rec)
		{
			DataTable result = new DataTable();
			string heading = String.Empty;

			heading = "Record #";
			result.Columns.Add(heading, typeof(int));

			heading = "Date";
			//result.Columns.Add(heading, typeof(DateTime));
			result.Columns.Add(heading, typeof(string));

			heading = "Time";
			//result.Columns.Add(heading, typeof(DateTime));
			result.Columns.Add(heading, typeof(string));

			heading = "Record Type";
			result.Columns.Add(heading, typeof(string));

			heading = "Cause";
			result.Columns.Add(heading, typeof(string));

			heading = "#";
			result.Columns.Add(heading, typeof(string));

			heading = (InstrumentMode.Fft == rec.Mode) ? "Record" : "TH Record";
			result.Columns.Add(heading, typeof(string));

			heading = "Sound Record";
			result.Columns.Add(heading, typeof(string));

			return result;
		}

		private void BuildSessionLogDataRecord(SlmRecord rec, RunRecord run, DataRow row, ref int col)
		{
			DateTime recTime = LDConstants.Epoch.AddSeconds(run.RecordDate);

			row[col++] = recTime.ToString("yyyy-MM-dd");
			row[col++] = recTime.ToString("HH:mm:ss");
			row[col++] = SessionLog.GetLogAction(run.Type);
			row[col++] = SessionLog.GetLogCause(rec, run);

			// measurement count or cal change level
			string buff = string.Empty;
			switch (run.Type)
			{
				case ActionCause.ActionCal:                           //PRM_ACTION_CAL:
					buff = ((float)run.Count / 10.0).ToString("0.0") + " dB";
					break;
				case ActionCause.ActionCalChange:                     //PRM_ACTION_CALCHG:
					buff = ((float)run.Count / 100.0).ToString("0.00") + " dB";
					break;
				default:
					buff = run.Count.ToString();
					break;
			}
			row[col++] = buff;

			buff = string.Empty;
			if (ActionCause.ActionVoice == run.Type || (int)BlockTag.Voice == (int)run.Type) // TAG_VOICE
			{
				buff = "0";
			}
			else if (ActionCause.ActionAudio == run.Type)        //PRM_ACTION_AUDIO
			{
				buff = (run.THRecord + 1).ToString();
			}
			else if (InstrumentMode.Fft == rec.Mode)
			{
				buff = (run.THRecord + 1).ToString();
			}
			else
			{
				buff = (run.THRecord).ToString();
			}
			row[col++] = buff;

			//Sound Record
			buff = string.Empty;
			if (ActionCause.ActionAudio == run.Type)
			{
				buff = "Sound Record " + run.AudioDataIndex;
			}
			else if (ActionCause.ActionVoice == run.Type)
			{
				buff = "Voice Record " + run.VoiceDataIndex;
			}
			row[col++] = buff;

		}

		private void SLGrid_DataBindingComplete(object sender, DataGridViewBindingCompleteEventArgs e)
		{
			foreach (DataGridViewRow row in SLGrid.Rows)
			{
				if (row.Cells["Sound Record"].Value.ToString() != string.Empty)
				{
					row.Cells["Sound Record"] = new DataGridViewLinkCell();
				}
			}
		}

		private void SLGrid_CellContentClick(object sender, DataGridViewCellEventArgs e)
		{
			try
			{
				if (e.RowIndex < CurrentRecord.SessionLog.RunRecords.Count)
				{
					RunRecord run = CurrentRecord.SessionLog.RunRecords[e.RowIndex];
					if (run.AudioDataIndex > 0)
					{
						int nDx = run.AudioDataIndex - 1;
						SoundRecord snd = CurrentRecord.SessionLog.AudioData[nDx];
						using (SoundPlayer player = new SoundPlayer(snd.DataStream))
						{
							player.PlaySync();
						}
					}
				}
			}
			catch (Exception)
			{

				throw;
			}
		}
	}
}
