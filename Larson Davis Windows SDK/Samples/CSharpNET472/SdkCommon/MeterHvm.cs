using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Net;
using System.Text;
using System.Threading;
using System.Windows.Threading;
using Newtonsoft.Json.Linq;

namespace LarsonDavis.Sdk.SdkCommon
{
	public class MeterHvm : IDisposable
	{
		volatile bool _running;
		//string _connectionString;
		Thread _hldThread;
		Dispatcher _dispatcher;
		public event Action<object, string, string> SDKResponse;
		string _baseUrl;
		Process httpLd = null;

		//public event EventHandler Connected;
		//public event EventHandler ConnectionLost;

		public event EventHandler<JObject> LiveUpdate;
		public event EventHandler<bool> RunStatusUpdate;

		public MeterHvm(int port, string connectionString)
		{
			_baseUrl = "http://localhost:" + port;
			_dispatcher = Dispatcher.CurrentDispatcher;
		}

		public MeterHvm(int port, string path, string connectionString)
		{
			httpLd = new Process();
			httpLd.StartInfo.FileName = path;// @"C:\Dev\Software\Apps\SlmEnhanced\SlmUtility\G4\x86\bin\Debug\HttpLD.exe";
			httpLd.StartInfo.Arguments = string.Format("-c {0} -d 1 -p {1}", connectionString, port);
			httpLd.StartInfo.WindowStyle = ProcessWindowStyle.Normal;//ProcessWindowStyle.Normal;// 
			httpLd.Start();
			_baseUrl = "http://localhost:" + port;
			_dispatcher = Dispatcher.CurrentDispatcher;
		}

		public void Current_Exit(object sender, System.Windows.ExitEventArgs e)
		{
			Dispose();
			_running = false;
		}

		public Dispatcher RegisteredDispatcher { get { return _dispatcher; } }


		public void InitiateConnection()
		{
			_running = true;
			_hldThread = new Thread(new ThreadStart(ConnectionLoop));
			_hldThread.Start();
			SDKCall("getpagestatus"); // We are getting an initial status of the meter
		}

		public void Disconnect()
		{
			_running = false;
		}

		public void StartMeasurement()
		{
			SDKCall("m1");
		}

		public void StopMeasurement()
		{
			SDKCall("m2");
		}

		private void ConnectionLoop()
		{
			DateTime next = DateTime.Now;
			while (_running)
			{
				if (DateTime.Now > next)
				{
					SDKCall("streamdata");
					next = DateTime.Now.AddSeconds(1);
				}
				Thread.Sleep(10);
			}
		}

		public void SDKCall(string func, IEnumerable<KeyValuePair<string, object>> args = null)
		{
			var url = new StringBuilder();
			url.AppendFormat("{0}/sdk?func={1}", _baseUrl, func);

			if (args != null)
			{
				foreach (var pair in args)
				{
					url.AppendFormat("&{0}={1}", pair.Key, pair.Value);
				}
			}

			WebRequest req = WebRequest.Create(url.ToString());
			req.BeginGetResponse(new AsyncCallback(RequestCallback), Tuple.Create(req, func));
		}

		private void RequestCallback(IAsyncResult result)
		{
			var state = result.AsyncState as Tuple<WebRequest, string>;
			var response = state.Item1.EndGetResponse(result);
			if (state.Item2 == "closeDown")
			{
				SendSDKResponse(state.Item2, "{\"Result\": \"Success\"}");
			}
			else
			{
				byte[] buffer = new byte[response.ContentLength];
				using (var responseStream = response.GetResponseStream())
				{
					int totalRead = 0;
					int read = responseStream.Read(buffer, 0, buffer.Length);
					totalRead += read;
					while (read > 0)
					{
						read = responseStream.Read(buffer, totalRead, buffer.Length - totalRead);
						totalRead += read;
					}
				}
				string message = Encoding.UTF8.GetString(buffer);
				SendSDKResponse(state.Item2, message);
			}
		}

		private void SendSDKResponse(string func, string message)
		{
			var json = JObject.Parse(message);
			bool successful;
			switch (func)
			{
				case "streamdata":
					// The response to a streamdata request is a json object which contains the values collected from the meter.
					// When the meter is not taking a measurement the values that are measurement dependent are returned as 0.
					JObject liveData = (JObject)json["LiveData"][0];
					var liveUpdate = LiveUpdate;
					if (liveUpdate != null)
					{
						_dispatcher.BeginInvoke(new Action(() => { liveUpdate(this, liveData); })); // We are dispatching becuase we may be processing messages from a background thread
					}
					break;

				case "getpagestatus":

					break;

				case "m1":
				case "m2":
					successful = json["Result"].ToString().Contains("Success");
					var runStatusUpdate = RunStatusUpdate;
					if (runStatusUpdate != null)
					{
						_dispatcher.BeginInvoke(new Action(() => { runStatusUpdate(this, successful ^ (func != "m1")); }));
					}
					break;

				default:
					break;
			}

			var handler = SDKResponse;
			if (handler != null)
			{
				_dispatcher.BeginInvoke(new Action(() => { handler(this, func.ToLower(), message); }));
			}
		}


		#region IDisposable Support
		private bool isDisposed = false; // To detect redundant calls

		protected virtual void Dispose(bool disposing)
		{
			if (!isDisposed)
			{
				if (disposing)
				{
					// TODO: dispose managed state (managed objects).
				}

				// TODO: free unmanaged resources (unmanaged objects) and override a finalizer below.
				// TODO: set large fields to null.
				if (null != httpLd)
				{
					SDKCall("closeDown", null);
					httpLd.WaitForExit(2000);

					try
					{
						if (null != httpLd && !httpLd.HasExited) httpLd.Kill();
					}
					catch { }
				}

				isDisposed = true;
			}
		}

		// TODO: override a finalizer only if Dispose(bool disposing) above has code to free unmanaged resources.
		~MeterHvm()
		{
			// Do not change this code. Put cleanup code in Dispose(bool disposing) above.
			Dispose(false);
		}

		// This code added to correctly implement the disposable pattern.
		public void Dispose()
		{
			// Do not change this code. Put cleanup code in Dispose(bool disposing) above.
			Dispose(true);
			// TODO: uncomment the following line if the finalizer is overridden above.
			GC.SuppressFinalize(this);
		}
		#endregion
	}
}
