using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using Newtonsoft.Json.Linq;

namespace LarsonDavis.Sdk.AuthenticationExample
{
	/// <summary>
	/// Interaction logic for MainWindow.xaml
	/// </summary>
	public partial class MainWindow : Window
	{
		SecureConnection _connection = new SecureConnection();
		bool loggedIn = false;
		public MainWindow()
		{
			InitializeComponent();
		}

		private void btnLogIn_Click(object sender, RoutedEventArgs e)
		{
			_ = ToggleLogin();
		}

		private void btnCreateUser_Click(object sender, RoutedEventArgs e)
		{

		}

		private async void btnListUsers_Click(object sender, RoutedEventArgs e)
		{
			await ListUsers();
		}

		private async Task ListUsers()
		{
			lstUsers.Items.Clear();
			var userList = await _connection.ListUsers().ConfigureAwait(true);
			if (userList != null &&
				 userList.TryGetValue("Results", out var resultsTok) &&
				 resultsTok is JObject results && 
				 results.TryGetValue("ListUsers", out var listTok) &&
				 listTok is JArray list)
			{
				foreach (var user in list)
				{
					lstUsers.Items.Add(new UserItem { Email = user["User"]?.ToString(), Username = user["Name"]?.ToString() });
				}
			}
			else
			{
				MessageBox.Show("Failed to get the user list");
			}
		}

		private async Task ToggleLogin()
		{
			if (loggedIn)
			{
				var res = await _connection.Logout().ConfigureAwait(true);
				if (res != null)
				{
					btnLogIn.Content = "Login";
					loggedIn = false;
				}
				else
				{
					MessageBox.Show("Logout Failed");
				}
			}
			else
			{
				var res = await _connection.Login(tbEmail.Text, tbPassword.Text).ConfigureAwait(true);
				if (res != null)
				{
					btnLogIn.Content = "Logout";
					loggedIn = true;
				}
				else
				{
					MessageBox.Show("Login Failed");
				}
			}
		}

		private void CheckBox_Checked(object sender, RoutedEventArgs e)
		{
			_connection.Secure = true;
		}

		private void CheckBox_Unchecked(object sender, RoutedEventArgs e)
		{
			_connection.Secure = false;
		}

		private void tbUrl_TextChanged(object sender, TextChangedEventArgs e)
		{
			_connection.Host = tbUrl.Text;
		}
	}
}
