using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Net;
using System.Net.Http;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using Newtonsoft.Json.Linq;

namespace LarsonDavis.Sdk.DataStreamAndDownload
{
	/// <summary>
	/// Interaction logic for MainWindow.xaml
	/// </summary>
	public partial class MainWindow : Window
	{
		private bool _gettingStatus = false;
		private bool _streamingData = true;
		private HttpClient _client;
		private bool _allowUnsafe = true;
		private Task _statusLoop = Task.FromResult<bool>(true);
		private Dictionary<string, TextBlock> DataElements = new Dictionary<string, TextBlock>();
		private Dictionary<string, TextBlock> StatusElements = new Dictionary<string, TextBlock>();
		private Dictionary<string, Func<JObject, string>> StatusConverters = new Dictionary<string, Func<JObject, string>>();

		public MainWindow()
		{
			InitializeComponent();
			Environment.CurrentDirectory = Environment.GetFolderPath(Environment.SpecialFolder.MyDocuments);
			if (_allowUnsafe)
			{
				// The meter uses TLS 1.0
				ServicePointManager.SecurityProtocol = SecurityProtocolType.Tls;
				// Unless a signed cert has been installed on the meter it will fail default validation.
				// Here we override the default validation to accept all certs, this is unsafe, thus the
				// _allowUnsafe boolean.
				ServicePointManager.ServerCertificateValidationCallback = (sender, cert, chain, errors) =>
				{
					return true;
				};
			}

			// Adding the metrics to the list box
			MetricSelector.Items.Add(new ComboCheckBoxItem { IsSelected = false, Name = "APeak", Value = 2 });
			MetricSelector.Items.Add(new ComboCheckBoxItem { IsSelected = false, Name = "ALeq", Value = 1 });
			MetricSelector.Items.Add(new ComboCheckBoxItem { IsSelected = false, Name = "CPeak", Value = 64 });
			MetricSelector.Items.Add(new ComboCheckBoxItem { IsSelected = false, Name = "CLeq", Value = 32 });
			MetricSelector.Items.Add(new ComboCheckBoxItem { IsSelected = false, Name = "ZPeak", Value = 2048 });
			MetricSelector.Items.Add(new ComboCheckBoxItem { IsSelected = false, Name = "ZLeq", Value = 1024 });

			// Adding the rates to the dropdown box
			RateSelector.Items.Add(new ComboCheckBoxItem { Name = "500 ms", Value = Tuple.Create(4, TimeSpan.FromMilliseconds(500)) });
			RateSelector.Items.Add(new ComboCheckBoxItem { Name = "200 ms", Value = Tuple.Create(3, TimeSpan.FromMilliseconds(200)) });
			RateSelector.Items.Add(new ComboCheckBoxItem { Name = "100 ms", Value = Tuple.Create(2, TimeSpan.FromMilliseconds(100)) });
			RateSelector.Items.Add(new ComboCheckBoxItem { Name = "20 ms", Value =  Tuple.Create(0, TimeSpan.FromMilliseconds(20)) });
			RateSelector.Items.Add(new ComboCheckBoxItem { Name = "50 ms", Value =  Tuple.Create(1, TimeSpan.FromMilliseconds(50)) });
			RateSelector.Items.Add(new ComboCheckBoxItem { Name = "1 sec", Value =  Tuple.Create(5, TimeSpan.FromSeconds(1)) });
			RateSelector.Items.Add(new ComboCheckBoxItem { Name = "2 sec", Value = Tuple.Create(6, TimeSpan.FromSeconds(2)) });
			RateSelector.Items.Add(new ComboCheckBoxItem { Name = "10 ms", Value = Tuple.Create(15, TimeSpan.FromMilliseconds(10)) });
			RateSelector.Items.Add(new ComboCheckBoxItem { Name = "5 ms", Value = Tuple.Create(14, TimeSpan.FromMilliseconds(5)) });
			RateSelector.Items.Add(new ComboCheckBoxItem { Name = "2.5 ms", Value = Tuple.Create(13, TimeSpan.FromMilliseconds(2.5)) });
			RateSelector.SelectedIndex = 0;
			Loaded += DataStreamAndDownload_Loaded;
		}

		protected override void OnClosed(EventArgs e)
		{
			if (_client != null)
			{
				_client.DoLogout();
			}
			base.OnClosed(e);
		}

		private void DataStreamAndDownload_Loaded(object sender, RoutedEventArgs e)
		{
			// Scraping the controls inside the "DataControls" stack panel.
			PrepElements(DataControls, DataElements);

			// Scraping the controls inside the "StatusControls" stack panel.
			PrepElements(StatusControls, StatusElements);

			// Adding a special converter to convert the tv_sec and tv_usec to time and
			StatusConverters.Add("tv_sec", status =>
			{
				DateTime dt = new DateTime(1970, 1, 1);
				dt = dt.Add(TimeSpan.FromSeconds((int)status["tv_sec"]) + TimeSpan.FromMilliseconds(((int)status["tv_usec"]) / 1000));
				dt = dt.ToLocalTime();
				return dt.ToLongTimeString();
			});
		}

		private void PrepElements(Panel parent, Dictionary<string, TextBlock> uiElements)
		{
			// Recursively walk through all elements in "parent"
			// Text blocks link to a display value (calculated or otherwise)
			// Panels are drilled into looking for text blocks
			foreach (UIElement child in parent.Children)
			{
				if (child is TextBlock)
				{
					var tb = child as TextBlock;
					if (tb.Tag != null)
					{
						uiElements.Add((string)tb.Tag, tb);
					}
				}
				else if (child is Panel)
				{
					PrepElements(child as Panel, uiElements);
				}
			}
		}

		public async Task StatusLoop()
		{
			// The StatusLoop runs once every second, first out of every 5 are page statuses
			_gettingStatus = true;
			int counter = 0;
			while (_gettingStatus)
			{
				var status = counter == 0? await _client.GetPageStatus() : await _client.GetMinStatus();
				status = (JObject)status["Status"];
				await Dispatcher.BeginInvoke((Action)(() =>
				{
					// Walk through the UI elements that display status and extract
					// their values from the status object.
					foreach (var pair in StatusElements)
					{
						if (status.ContainsKey(pair.Key))
						{
							Func<JObject, string> converter;
							if (!StatusConverters.TryGetValue(pair.Key, out converter))
							{
								// If there is no special converter then just to string the value
								converter = j => j[pair.Key].ToString();
							}
							pair.Value.Text = converter(status);
						}
					}
				}));
				await Task.Delay(TimeSpan.FromSeconds(1));
				if (counter++ > 5)
				{
					counter = 0;
				}
			}
		}

		public async Task StreamingLoop(TimeSpan waitPeriod)
		{
			// Runs periodically, according to the selected rate
			while (_streamingData)
			{
				var data = await _client.GetJsonStreamingData();
				await Dispatcher.BeginInvoke((Action)(() =>
				{
					DisplayStreamingData(data);
				}));
				await Task.Delay(waitPeriod);
			}
		}

		private void DisplayStreamingData(JObject data)
		{
			// Each element in "DataElements" will check to see if there is data for it.
			JArray dataArr = (JArray)data["Data"];
			if (dataArr != null)
			{
				JObject last = (JObject)dataArr.LastOrDefault();
				if (last != null)
				{
					foreach (var pair in DataElements)
					{
						JToken value;
						if (last.TryGetValue(pair.Key, out value))
						{
							pair.Value.Text = value.ToString();
						}
					}
				}
			}
		}

		private void StartStreaming_Click(object sender, RoutedEventArgs e)
		{
			if (_client != null)
			{
				Tuple<int, TimeSpan> rate = (Tuple<int, TimeSpan>)RateSelector.SelectedValue;
				int flags = 0;
				foreach (ComboCheckBoxItem flag in MetricSelector.Items)
				{
					if (flag.IsSelected)
					{
						flags = flags | (int)flag.Value;
					}
				}
				var res = _client.StartStreaming(rate.Item1, flags);
				_streamingData = true;
				Task.Run(() => StreamingLoop(rate.Item2));
			}
		}

		private void StopStreaming_Click(object sender, RoutedEventArgs e)
		{
			_client.StopStreaming();
			_streamingData = false;
		}

		private void ViewFileList_Click(object sender, RoutedEventArgs e)
		{
			FileListWindow flw = new FileListWindow(_client);
			flw.Owner = this;
			flw.Show();
		}

		private void ApplyBaseUrl_Click(object sender, RoutedEventArgs e)
		{
			var _ = SetupClientAndStatusLoop();
		}

		private async Task SetupClientAndStatusLoop()
		{
			_gettingStatus = false;
			await _statusLoop;
			_client?.Dispose();
			_client = new HttpClient(new HttpClientHandler { UseCookies = true });
			_client.BaseAddress = new Uri(ConnStringTxt.Text);
			_client.Timeout = TimeSpan.FromSeconds(15);
			_statusLoop = Task.Run(StatusLoop);
		}

		private void Login_Click(object sender, RoutedEventArgs e)
		{
			if (_client != null)
			{
				LoginDialog ld = new LoginDialog(_client);
				ld.Owner = this;
				if (ld.ShowDialog() == true)
				{
					LoginBtn.Visibility = Visibility.Collapsed;
					LogoutBtn.Visibility = Visibility.Visible;
				}
			}
		}

		private void Logout_Click(object sender, RoutedEventArgs e)
		{
			_client.DoLogout();
			LoginBtn.Visibility = Visibility.Visible;
			LogoutBtn.Visibility = Visibility.Collapsed;
		}
	}

	public class ComboCheckBoxItem
	{
		public bool IsSelected { get; set; }
		public string Name { get; set; }
		public object Value { get; set; }
	}

	public static class MeterCommands
	{
		private static void ProcessCookies(this HttpClient client, HttpResponseMessage response)
		{
			foreach (var header in response.Headers.GetValues("Set-Cookie"))
			{
				// Cookies will automatically be handled by the HttpClient
				if (header.StartsWith("sessionid") && !header.Contains("Max-Age=0;"))
				{
					// Doing a keep alive when the session ages, this a behavior from HLD
					client.DoKeepAlive();
				}
			}
		}

		public static async Task<HttpResponseMessage> GetResponseAsync(this HttpClient client, string command)
		{
			var res = await client.GetAsync(command);

			if (res.IsSuccessStatusCode)
			{
				if (res.Headers.Contains("Set-Cookie"))
				{
					client.ProcessCookies(res);
				}
			}

			return res;
		}

		public static async Task<HttpResponseMessage> PostGetResponseAsync(this HttpClient client, string command, HttpContent content)
		{
			var res = await client.PostAsync(command, content);

			if (res.IsSuccessStatusCode)
			{
				if (res.Headers.Contains("Set-Cookie"))
				{
					client.ProcessCookies(res);
				}
			}

			return res;
		}

		public static async Task<JObject> PostGetJsonAsync(this HttpClient client, string command, HttpContent content)
		{
			JObject result = null;

			using (var res = await client.PostGetResponseAsync(command, content))
			{
				if (res.IsSuccessStatusCode)
				{
					var str = await res.Content.ReadAsStringAsync();
					result = JObject.Parse(str);
				}
			}

			return result;
		}

		public static async Task<HttpResponseMessage> GetStreamResponseAsync(this HttpClient client, string command)
		{
			return await client.GetResponseAsync(command);
		}

		public static async Task<JObject> GetJsonAsync(this HttpClient client, string command)
		{
			JObject result = null;

			using (var res = await client.GetResponseAsync(command))
			{
				if (res.IsSuccessStatusCode)
				{
					var str = await res.Content.ReadAsStringAsync();
					result = JObject.Parse(str);
				}
			}

			return result;
		}

		public static Task<JObject> GetPageStatus(this HttpClient client)
		{
			return client.GetJsonAsync("/sdk?func=getpageStatus");
		}

		public static Task<JObject> GetMinStatus(this HttpClient client)
		{
			return client.GetJsonAsync("/sdk?func=getminStatus");
		}

		public static Task<JObject> DoKeepAlive(this HttpClient client)
		{
			return client.GetJsonAsync("/sdk?func=keepalive");
		}
	}

	public static class SlmCommands
	{
		public enum Location
		{
			PathInternal = 0,
			PathUsb,

			None = 0,
			Primary,
			Internal,
			USB,
			Merged,
		}

		public enum PathType
		{
			Internal,
			USB,
			Merged,
		}

		public static PathType GetPathType (Location location)
		{
			switch (location)
			{
				default:
				case Location.PathInternal:
				case Location.Internal:
					return PathType.Internal;

				case Location.PathUsb:
				case Location.USB:
					return PathType.USB;
			}
		}

		public static Task<JObject> DoLogin(this HttpClient client, string username, string password)
		{
			JObject message = new JObject { { "User", username }, { "Pass", password } };
			return client.PostGetJsonAsync($"/sdk?func=login", new StringContent(message.ToString(Newtonsoft.Json.Formatting.None)));
		}

		public static Task<JObject> DoLogout(this HttpClient client)
		{
			return client.GetJsonAsync("/sdk?func=logout");
		}

		public static Task<HttpResponseMessage> GetDownloadStream(this HttpClient client, int index, uint size)
		{
			return client.GetAsync($"/download?index={index}&size={size}", HttpCompletionOption.ResponseHeadersRead);
		}

		public static Task<HttpResponseMessage> GetDownloadStream(this HttpClient client, string name, int location, uint size, uint offset = 0)
		{
			PathType path = GetPathType((Location)location);   // Convert from internal Location values to PathType values
			 string requestUri = $"/download?name={name}&path={(int)path}&size={size}&offset={offset}&addCrc=1&unique={DateTime.Now:HHmmssfff}";
			return client.GetAsync(requestUri, HttpCompletionOption.ResponseHeadersRead);
		}

		public static Task<JObject> StartStreaming(this HttpClient client, int rate, int flags)
		{
			return client.GetJsonAsync($"/sdk?func=startDataStreaming&rate={rate}&flags={flags}");
		}

		public static Task<JObject> StopStreaming(this HttpClient client)
		{
			return client.GetJsonAsync("/sdk?func=stopDataStreaming");
		}

		public static Task<JObject> GetJsonStreamingData(this HttpClient client)
		{
			return client.GetJsonAsync("/sdk?func=getjsonstream");
		}

		public static async Task<bool> BuildFileList(this HttpClient client, PathType path = PathType.Merged)
		{
			JObject result = await client.GetJsonAsync($"/sdk?func=startfilelistbuild&dpath={(int)path}");

			do
			{
				result = await client.GetJsonAsync("/sdk?func=queryfileliststatus");
			} while (!(bool)result?["Progress"]["complete"]);

			return (bool)result?["Progress"]["complete"];
		}

		public static async Task<JObject> GetDataFileList(this HttpClient client, int start, int count)
		{
			return await client.GetJsonAsync($"/sdk?func=getDataFileList&sindex={start}&count={count}");
		}
	}
}
