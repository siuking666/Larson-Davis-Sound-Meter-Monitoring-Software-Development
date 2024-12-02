using System.IO;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;
using System.Windows.Media;
using LarsonDavis.Sdk.SdkCommon;
using Microsoft.Win32;
using Newtonsoft.Json.Linq;

namespace LarsonDavis.Sdk.HvmStreamingData
{
	/// <summary>
	/// Interaction logic for MainWindow.xaml
	/// </summary>
	public partial class MainWindow : Window
	{
		public MainWindow()
		{
			InitializeComponent();
		}

		MeterHvm connection;
		string HLDPath = @"C:\Program Files (x86)\PCB Piezotronics\HLD\HttpLD.exe";

		private void Button_MouseEnter(object sender, MouseEventArgs e)
		{
			Button s = sender as Button;
			s.Foreground = Brushes.White;
		}

		private void Button_MouseLeave(object sender, MouseEventArgs e)
		{
			Button s = sender as Button;
			s.Foreground = Brushes.Cyan;
		}

		private void ConnectDisconnectClick(object sender, RoutedEventArgs e)
		{
			Button btn = sender as Button;
			if (connection == null)
			{
				if (File.Exists(HLDPath) || FindHLD())
				{
					connection = new MeterHvm(2509, HLDPath, txtConnString.Text);
					connection.LiveUpdate += ProcessLiveData;
					connection.RunStatusUpdate += connection_RunStatusUpdate;
					connection.InitiateConnection();
					Application.Current.Exit += connection.Current_Exit;

					if (btn != null)
					{
						btn.Content = "Disconnect";
					}
				}
			}
			else
			{
				connection.Disconnect();
				connection.Dispose();
				connection = null;
				if (btn != null)
				{
					btn.Content = "Connect";
				}
			}
		}

		void connection_RunStatusUpdate(object sender, bool e)
		{
			runLight.Visibility = e ? System.Windows.Visibility.Visible : System.Windows.Visibility.Hidden;
		}

		private void ProcessLiveData(object sender, JObject liveData)
		{
			// The datam are extracted from the json object using their keys.
			// RMS(x|y|z|Sum), Raw(x|y|z), ArawSum, Amin(x|y|z|Sum), Amax(x|y|z|Sum), Peak(x|y|z|Sum)
			// Amp(x|y|z|Sum), ASquared(x|y|z|Sum), VDV(x|y|z|Sum), A8(x|y|z|Sum), Aeq(x|y|z|Sum)
			// lastCount, lastOvlCount, uiRunFlags, RunStarted, Duration, BatLevel, BatState, OverBit, OverLatchBit
			// RMS and Peak are both available even when the meter is not running
			RMSxVal.Text = liveData["RMSx"].ToString();
			RMSyVal.Text = liveData["RMSy"].ToString();
			RMSzVal.Text = liveData["RMSz"].ToString();
			RMSsumVal.Text = liveData["RMSSum"].ToString();
			PeakxVal.Text = liveData["Peakx"].ToString();
			PeakyVal.Text = liveData["Peaky"].ToString();
			PeakzVal.Text = liveData["Peakz"].ToString();
			PeaksumVal.Text = liveData["PeakSum"].ToString();
			// Amp is only available when the meter is running
			// ASquared, VDV, A8, Aeq, Amin and Amax are all only available when the meter is running.
			AMPxVal.Text = liveData["Ampx"].ToString();
			AMPyVal.Text = liveData["Ampy"].ToString();
			AMPzVal.Text = liveData["Ampz"].ToString();
			AMPsumVal.Text = liveData["AmpSum"].ToString();
		}

		private void StartClick(object sender, RoutedEventArgs e)
		{
			if (connection != null)
			{
				connection.StartMeasurement();
			}
		}

		private void StopClick(object sender, RoutedEventArgs e)
		{
			if (connection != null)
			{
				connection.StopMeasurement();
			}
		}

		private void FindHLDClick(object sender, RoutedEventArgs e)
		{
			FindHLD();
		}

		private bool FindHLD()
		{
			OpenFileDialog ofd = new OpenFileDialog();
			ofd.Filter = "HLD Executable (HttpLd.exe)|HttpLd.exe";
			ofd.FileName = "HttpLd.exe";
			if (ofd.ShowDialog() ?? false)
			{
				HLDPath = ofd.FileName;
				return true;
			}
			return false;
		}

	}
}
