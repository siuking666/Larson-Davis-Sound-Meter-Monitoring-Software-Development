using System.Net.Http;
using System.Windows;

namespace LarsonDavis.Sdk.DataStreamAndDownload
{
	/// <summary>
	/// Interaction logic for LoginDialog.xaml
	/// </summary>
	public partial class LoginDialog : Window
	{
		HttpClient _client;
		public LoginDialog()
		{
			InitializeComponent();
			Loaded += LoginDialog_Loaded;
		}

		private void LoginDialog_Loaded(object sender, RoutedEventArgs e)
		{
			UserName.Focus();
		}

		public LoginDialog(HttpClient client)
			: this()
		{
			_client = client;
		}

		private async void Button_Click(object sender, RoutedEventArgs e)
		{
			var res = await _client.DoLogin(UserName.Text, Password.Password);
			if ((string)res["ResultName"] == "Success")
			{
				DialogResult = true;
				Close();
			}
		}

		private void Button_Click_1(object sender, RoutedEventArgs e)
		{
			DialogResult = false;
			Close();
		}
	}
}
