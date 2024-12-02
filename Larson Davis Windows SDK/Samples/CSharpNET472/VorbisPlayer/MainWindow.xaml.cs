using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Diagnostics;
using System.IO;
using System.Net;
using System.Threading;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;
using LDAudioStreaming;
using Microsoft.Win32;
using NAudio.Wave;


namespace LarsonDavis.Sdk.VorbisPlayer
{
	/// <summary>
	/// Interaction logic for MainWindow.xaml
	/// </summary>
	public partial class MainWindow : Window, INotifyPropertyChanged
	{
		const double FACTOR = 1.0;

		DirectSoundOut _player = new DirectSoundOut();
		LDAudioStream _audioStream = null;
		List<Grid> _bars = new List<Grid>();
		Stream _fs = null;

		bool _stop = false;
		bool _autoGain = false;

		public string URL { get; set; }

		public bool Compress { get; set; }

		public bool AutoGain
		{
			get { return _autoGain; }
			set
			{
				if (_autoGain != value)
				{
					_autoGain = value;
					if (_audioStream != null)
					{
						_audioStream.DynamicGain = value;
					}
				}
			}
		}

		public event PropertyChangedEventHandler PropertyChanged;

		private void OnPropertyChanged(string propName)
		{
			PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propName));
		}

		public MainWindow()
		{
			InitializeComponent();

			URL = "10.103.122.184";
			foreach (Grid bar in BarsGrids.Children)
			{
				_bars.Add(bar);
			}
			_player.PlaybackStopped += Player_PlaybackStopped;
			DataContext = this;
		}

		private void Player_PlaybackStopped(object sender, EventArgs e)
		{
			_audioStream?.Dispose();
			_audioStream = null;
		}

		private void GetLegacyStream()
		{
			try
			{
				int sampleRate = 0;
				int streamID = 0;
				ToggleButtonState(true);
				HttpWebRequest req = (HttpWebRequest)HttpWebRequest.Create("http://" + URL + "/sdk?func=startaudiostream" + (Compress ? "&format=ogg" : ""));

				using (WebResponse res = req.GetResponse())
				{
					using (Stream s = res.GetResponseStream())
					{
						StreamReader sr = new StreamReader(s);
						string response = sr.ReadToEnd();
						if (response.Contains("SampleRate"))
						{
							string rate = response.Substring(response.IndexOf("SampleRate") + "SampleRate".Length + 2);
							rate = rate.Substring(0, rate.IndexOf(","));
							rate = rate.Trim();
							int.TryParse(rate, out sampleRate);
						}
						if (response.Contains("StreamID"))
						{
							string id = response.Substring(response.IndexOf("StreamID") + "StreamID".Length + 2);
							id = id.Substring(0, id.IndexOf(","));
							id = id.Trim();
							int.TryParse(id, out streamID);
						}
						Console.WriteLine(response);
					}
				}
				TimeSpan lastCurrentTime = TimeSpan.FromSeconds(0);
				byte[] buffer = new byte[1024];
				_audioStream = null;
				while (!_stop)
				{
					Thread.Sleep(250);
					if (_stop)
					{
						break;
					}
					try
					{
						req = (HttpWebRequest)HttpWebRequest.Create("http://" + URL + "/sdk?func=getaudiostream&id=" + streamID);

						using (WebResponse res = req.GetResponse())
						{
							Console.WriteLine($"Received {res.ContentLength} from the server");

							if (res.ContentLength > 0)
							{
								using (Stream s = res.GetResponseStream())
								{
									if (buffer.Length < res.ContentLength)
									{
										buffer = new byte[res.ContentLength];
									}
									int readBytes = 0;
									while (readBytes < res.ContentLength)
									{
										readBytes += s.Read(buffer, readBytes, buffer.Length - readBytes);
									}
									if (_fs != null)
									{
										_fs.Write(buffer, 0, readBytes);
									}

									ProcessBytes(buffer, readBytes, sampleRate, Compress);
								}

							}
							else
							{
								//Thread.Sleep(150);
							}
						}
						if (_audioStream != null)
						{
							if (_audioStream.TotalTime > TimeSpan.FromSeconds(4) && _player.PlaybackState != PlaybackState.Playing)
							{
								//SimpleCompressorStream scs = new SimpleCompressorStream(audioStream);
								_player.Init(_audioStream);
								_player.Play();
							}
							else if (_audioStream.TotalTime - _audioStream.CurrentTime < TimeSpan.FromSeconds(0.25) && _player.PlaybackState == PlaybackState.Playing)
							{
								_player.Pause();
							}
							else if (_audioStream.TotalTime - _audioStream.CurrentTime > TimeSpan.FromSeconds(1) && _player.PlaybackState == PlaybackState.Paused)
							{
								_player.Play();
							}
						}

						if (null != _audioStream)
						{
							lastCurrentTime = _audioStream.CurrentTime;
						}
						else
						{
							lastCurrentTime = TimeSpan.FromSeconds(0);
						}
					}
					catch (Exception e)
					{
						Dispatcher.Invoke(() => MessageBox.Show(this, e.Message));
					}
				}

				_player.Stop();

				req = (HttpWebRequest)HttpWebRequest.Create("http://" + URL + "/sdk?func=endaudiostream&id=" + streamID);

				using (WebResponse res = req.GetResponse())
				{

					using (Stream s = res.GetResponseStream())
					{
						StreamReader sr = new StreamReader(s);
						Console.WriteLine(sr.ReadToEnd());
					}
				}
				if (_fs != null)
				{
					_fs.Close();
					_fs = null;
				}
			}
			finally
			{
				ToggleButtonState(false);
			}
		}


		private void GetChunkedStream()
		{
			try
			{
				ToggleButtonState(true);
				_stop = false;
				TimeSpan lastCurrentTime = TimeSpan.FromSeconds(0);
				byte[] buffer = new byte[1024];
				_audioStream = null;
				HttpWebRequest req = (HttpWebRequest)HttpWebRequest.Create("http://" + URL + "/audiostream");
				using (WebResponse res = req.GetResponse())
				{
					string format = res.Headers["Content-Type"] ?? "audio/wav";
					string sampleRateStr = res.Headers["X-SampleRate"] ?? "8000";
					if (int.TryParse(sampleRateStr, out int sampleRate))
					{
						using (Stream s = res.GetResponseStream())
						{
							while (!_stop)
							{
								if (_stop)
								{
									break;
								}
								try
								{
									int readBytes = s.Read(buffer, 0, buffer.Length);

									Console.WriteLine($"Received {readBytes} from the server");
									if (_fs != null)
									{
										_fs.Write(buffer, 0, readBytes);
									}
									bool compressed = format == "audio/ogg";

									ProcessBytes(buffer, readBytes, sampleRate, compressed);

									if (_audioStream != null)
									{
										if (_audioStream.TotalTime > TimeSpan.FromSeconds(4) && _player.PlaybackState != PlaybackState.Playing)
										{
											//SimpleCompressorStream scs = new SimpleCompressorStream(audioStream);
											_player.Init(_audioStream);
											_player.Play();
										}
										else if (_audioStream.TotalTime - _audioStream.CurrentTime < TimeSpan.FromSeconds(0.25) && _player.PlaybackState == PlaybackState.Playing)
										{
											_player.Pause();
										}
										else if (_audioStream.TotalTime - _audioStream.CurrentTime > TimeSpan.FromSeconds(1) && _player.PlaybackState == PlaybackState.Paused)
										{
											_player.Play();
										}
									}

									if (null != _audioStream)
									{
										lastCurrentTime = _audioStream.CurrentTime;
									}
									else
									{
										lastCurrentTime = TimeSpan.FromSeconds(0);
									}
								}
								catch (Exception ex)
								{
									string msg = $"{ex.Message}, {ex.StackTrace}";
									Debug.WriteLine($"{DateTime.Now:dd HH:mm:ss.fffff}: MainWindow: GetChunkedStream(): Error: {msg}");

									Dispatcher.Invoke(() => MessageBox.Show(this, ex.Message));
									_stop = true;
								}
							}
						}
					}
				}
			}
			finally
			{
				_player.Stop();
				ToggleButtonState(false);
			}
		}

		private void ProcessBytes(byte[] buffer, int readBytes, int sampleRate, bool compressed)
		{
			if (_audioStream == null)
			{
				if (compressed)
				{
					_audioStream = new LDOggStream(buffer, readBytes);
					_audioStream.DynamicGain = AutoGain;
				}
				else
				{
					_audioStream = new LDWaveStream(buffer, readBytes, sampleRate, 1);
					_audioStream.DynamicGain = AutoGain;
				}
				_audioStream.Volume = 1.0f;
			}
			else
			{
				_audioStream.PushBytes(buffer, readBytes);
			}
		}

		protected override void OnClosed(EventArgs e)
		{
			_stop = true;
			_player.PlaybackStopped -= Player_PlaybackStopped;
			_player.Dispose();
			base.OnClosed(e);
		}

		private void UpdateUI()
		{
			while (!_stop)
			{
				Thread.Sleep(50);
				_ = Dispatcher.BeginInvoke((Action)(() =>
				  {
					  if (null != _audioStream)
					  {
						  try
						  {
							  buffered.Value = (_audioStream.TotalTime.TotalMilliseconds - _audioStream.CurrentTime.TotalMilliseconds) / 10000;
							  for (int i = 0; i < _audioStream.FFT.Length; ++i)
							  {
								  _bars[i].Height = _audioStream.FFT[i] * FACTOR + 1;
							  }
						  }
						  catch
						  {

						  }
					  }
					  else
					  {
						  buffered.Value = 0;
					  }

				  }));
			}
		}

		private void UpdateUIFile()
		{
			while (!_stop)
			{
				Thread.Sleep(50);
				_ = Dispatcher.BeginInvoke((Action)(() =>
				  {
					  if (null != _audioStream)
					  {
						  slider.Value = _audioStream.Position;
						  for (int i = 0; i < _audioStream.FFT.Length; ++i)
						  {
							  if (!float.IsInfinity(_audioStream.FFT[i]))
							  {
								  _bars[i].Height = _audioStream.FFT[i] * FACTOR + 1;
							  }
						  }
					  }
					  else
					  {
						  buffered.Value = 0;
					  }

				  }));
			}
		}

		private void ToggleButtonState(bool running)
		{
			try
			{
				if (Dispatcher.CheckAccess())
				{
					if (running)
					{
						btnStart.IsEnabled = false;
						btnStartChunked.IsEnabled = false;
						btnStop.IsEnabled = true;
					}
					else
					{
						btnStart.IsEnabled = true;
						btnStartChunked.IsEnabled = true;
						btnStop.IsEnabled = false;
					}
				}
				else
				{
					Dispatcher.Invoke(() => ToggleButtonState(running));
				}
			}
			catch (Exception ex)
			{
				string msg = $"{ex.Message}, {ex.StackTrace}";
				Debug.WriteLine($"{DateTime.Now:dd HH:mm:ss.fffff}: MainWindow: GetChunkedStream(): Error: {msg}");
			}
		}

		private void btnStart_Click(object sender, RoutedEventArgs e)
		{
			_audioStream?.Dispose();
			_audioStream = null;
			_stop = false;

			Thread t = new Thread(GetLegacyStream);
			t.Start();

			Thread t2 = new Thread(UpdateUI);
			t2.Start();
		}

		private void btnStop_Click(object sender, RoutedEventArgs e)
		{
			_stop = true;
		}

		private void button_Click(object sender, RoutedEventArgs e)
		{
			SaveFileDialog sfd = new SaveFileDialog();
			if (sfd.ShowDialog() ?? false)
			{
				_fs = sfd.OpenFile();
			}
		}

		private void checkBox_Checked(object sender, RoutedEventArgs e)
		{

		}

		private void btnOpen_Click(object sender, RoutedEventArgs e)
		{
			OpenFileDialog ofd = new OpenFileDialog();
			ofd.Filter = "Wave File|*.wav|Ogg File|*.ogg";
			
			if (ofd.ShowDialog() ?? false)
			{
				_player.Stop();
				if (_audioStream != null)
				{
					_audioStream.Dispose();
				}
				if (ofd.FileName.ToLower().EndsWith(".wav"))
				{
					_audioStream = new LDWaveStream(ofd.OpenFile(), true);
				}
				else
				{
					_audioStream = new LDOggStream(ofd.OpenFile(), true);
				}
				slider.Maximum = _audioStream.Length;
				_player.Init(_audioStream);
				_player.Play();
				_stop = false;

				Thread t2 = new Thread(UpdateUIFile);
				t2.Start();
			}
		}

		private void slider_ValueChanged(object sender, RoutedPropertyChangedEventArgs<double> e)
		{
			if (_audioStream != null && _audioStream.Position != (long)slider.Value)
			{
				_audioStream.Position = (long)slider.Value;
			}
		}

		private void slider_MouseDown(object sender, MouseButtonEventArgs e)
		{
			_player.Stop();
		}

		private void slider_MouseUp(object sender, MouseButtonEventArgs e)
		{
			_player.Play();
		}

		private void btnstopFile_Click(object sender, RoutedEventArgs e)
		{
			_player.Stop();
			_stop = true;
		}

		private void btnStartChunked_Click(object sender, RoutedEventArgs e)
		{
			_audioStream?.Dispose();
			_audioStream = null;
			_stop = false;

			Thread t = new Thread(GetChunkedStream);
			t.Start();

			Thread t2 = new Thread(UpdateUI);
			t2.Start();
		}
	}
}
