using System;
using System.ComponentModel;
using System.Globalization;
using System.IO;
using System.Net.Http;
using System.Runtime.CompilerServices;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Data;
using System.Windows.Input;
using Microsoft.Win32;
using Newtonsoft.Json.Linq;

using LarsonDavis.Sdk.SdkCommon;
using System.Linq;
using System.Diagnostics;

namespace LarsonDavis.Sdk.DataStreamAndDownload
{
	/// <summary>
	/// Interaction logic for FileListWindow.xaml
	/// </summary>
	public partial class FileListWindow : Window
	{
		private HttpClient _client;
		bool _keepGetting = true;

		public FileListWindow()
		{
			InitializeComponent();
			Loaded += FileListWindow_Loaded;
		}

		public FileListWindow(HttpClient client)
			: this()
		{
			_client = client;
		}

		private void FileListWindow_Loaded(object sender, RoutedEventArgs e)
		{
			var _ = GetFileList();
		}

		protected override void OnClosed(EventArgs e)
		{
			_keepGetting = false;
			base.OnClosed(e);
		}

		private async Task GetFileList()
		{
			if (_client != null)
			{
				int start = 0;
				await _client.BuildFileList();
				do
				{
					try
					{
						var files = await _client.GetDataFileList(start, 500);
						var dataFiles = (JArray)files["DataFiles"];
						if (dataFiles.Count > 0)
						{
							DateTime epoch = new DateTime(1970, 1, 1);
							foreach (var file in dataFiles)
							{
								string startTime = epoch.AddSeconds((int)file["startTime"]).ToLocalTime().ToString();
								FileList.Items.Add(new FileListItem
								{
									Index = (int)file["index"],
									Name = (string)file["name"],
									Location = (int)file["location"],
									Start = startTime,
									Size = (uint)file["size"],
									Downloaded = CheckDownloadProgress((string)file["name"], (uint)file["size"])
								});
							}
						}
						start += dataFiles.Count;
						_keepGetting = dataFiles.Count == 500;
					}
					catch
					{

					}
				}
				while (_keepGetting);
			}
		}

		private float CheckDownloadProgress (string name, uint size)
		{
			float downloadProgress = 0;
			FileInfo file = new FileInfo(Path.ChangeExtension(name, ".ldbin"));

			if (file.Exists && file.Length > 20)
			{
				downloadProgress = (float)(file.Length - 20) / size;
			}

			return downloadProgress;
		}

		private void FileList_MouseDoubleClick(object sender, MouseButtonEventArgs e)
		{
			var file = (FileListItem)FileList.SelectedItem;
			FileStream saveLocation;
			if (file != null)
			{
				SaveFileDialog sfd = new SaveFileDialog();
				sfd.FileName = Path.GetFileNameWithoutExtension(file.Name) + ".ldbin";
				sfd.DefaultExt = ".ldbin";
				sfd.Filter = "G4 Data Files|*.ldbin";
				var res = sfd.ShowDialog();
				if (res == true)
				{
					try
					{
						saveLocation = File.Open(sfd.FileName, FileMode.OpenOrCreate);
						Task.Run(() => DownloadFile(file, saveLocation));
					}
					catch (Exception ex)
					{
						string msg = $"{ex.Message}{Environment.NewLine}{ex.StackTrace}";
						Debug.WriteLine($"{DateTime.Now:dd HH:mm:ss.fffff}: from FileListWindow: FileList_MouseDoubleClick(): Exception: {msg}");
					}
				}
			}
		}

		private async Task DownloadFile(FileListItem file, FileStream saveStream)
		{
			const int HEADER_SIZE = 20;
			await Dispatcher.BeginInvoke((Action)(() =>
			{
				file.Downloaded = 0.0f;
			}));

			Stream stream = null;


			try
			{
				int counter = 29;
				bool done = false;
				uint offset = 0;
				while (!done)
				{
					try
					{
						if (null == stream)
						{
							offset = (uint)Ld831cFileDownloader.CalcOffsetFromFileStream(saveStream);
							var msg = await _client.GetDownloadStream(file.Name, file.Location, file.Size, offset);
							if ( msg.IsSuccessStatusCode )
							{
								stream = await msg.Content.ReadAsStreamAsync();
								if (msg.Headers.TryGetValues("X-FileSize", out var values)
									&& long.TryParse(values?.FirstOrDefault(), out long headerFileSize)
									&& headerFileSize < uint.MaxValue)
								{ file.Size = (uint)headerFileSize; }
							}
							else if (msg.Headers.TryGetValues("X-PrepResult", out var values)
								&& values.Any())
							{
								throw new Exception($"Failed to start download: {values.FirstOrDefault()}");
							}
						}

						if (stream != null)
						{
							Ld831cFileDownloader downloader = new Ld831cFileDownloader(stream, saveStream, file.Name, file.Size, offset);
							{
								while (downloader.ProcessStream())
								{
									await Dispatcher.BeginInvoke((Action)(() =>
									{
										file.Downloaded = (float)downloader.FileOffset / file.Size;
									}));
								}

								await Dispatcher.BeginInvoke((Action)(() =>
								{
									file.Downloaded = (float)downloader.FileOffset / file.Size;
								}));
							}
						}
					}
					catch (Exception ex)
					{
						string msg = $"{ex.Message}{Environment.NewLine}{ex.StackTrace}";
						Debug.WriteLine($"{DateTime.Now:dd HH:mm:ss.fffff}: from FileListWindow: DownloadFile(): Exception: {msg}");
					}

					if (saveStream.Length == file.Size + HEADER_SIZE)
					{
						done = true;
					}
					else
					{
						counter--;
						stream?.Close();
						stream = null;
					}

					if (counter <= 0)
					{
						done = true;
					}
				}
			}
			catch (Exception ex)
			{
				string msg = $"{ex.Message}{Environment.NewLine}{ex.StackTrace}";
				Debug.WriteLine($"{DateTime.Now:dd HH:mm:ss.fffff}: from FileListWindow: DownloadFile(): Exception: {msg}");
			}
			finally
			{
				stream?.Close();
				saveStream.Flush();
				saveStream.Close();
			}
		}

		private void Button_Click(object sender, RoutedEventArgs e)
		{
			Close();
		}
	}

	public class FileListItem : INotifyPropertyChanged
	{
		private float _downloaded = 0;
		public int Index { get; set; }
		public string Name { get; set; }
		public int Location { get; set; }
		public string Start { get; set; }
		public uint Size { get; set; }
		public float Downloaded
		{
			get { return _downloaded; }
			set
			{
				_downloaded = value;
				RaisePropertyChanged();
			}
		}

		public event PropertyChangedEventHandler PropertyChanged;

		private void RaisePropertyChanged([CallerMemberName]string prop = null)
		{
			PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(prop));
		}
	}

	public class FileSizeConverter : IValueConverter
	{
		public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
		{
			string result = null;
			string[] units = new[] { "B", "KB", "MB", "GB" };
			int unitIndex = 0;
			if (value is uint)
			{
				double size = (uint)value;

				while (size > 1024)
				{
					unitIndex++;
					size /= 1024;
				}

				result = $"{size: #.##} {units[unitIndex]}";
			}
			return result ?? value;
		}

		public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
		{
			throw new NotImplementedException();
		}
	}
}
