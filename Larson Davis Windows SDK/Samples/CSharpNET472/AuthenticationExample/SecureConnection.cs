using System;
using System.Diagnostics;
using System.Linq;
using System.Net.Http;
using System.Threading.Tasks;
using Newtonsoft.Json.Linq;

namespace LarsonDavis.Sdk.AuthenticationExample
{
	public class SecureConnection
	{
		/* User account functions:
		 *		As with other sdk calls follow the form https://<host and port>/sdk?func=<func>
		 *		parameters are passed in posted data as a json object
		 *		e.g. { "User": "user@domain.com", "Pass": "123Abc" }
		 * Create User: (example below)
		 *		func: createuser
		 *		description: If logged in as an admin additional users can be created with this call
		 *		post data: 
		 *			Id: uint64 (optional, only useful for copying users between systems)
		 *			User: string (the user name is expected to follow the email address pattern)
		 *			Pass: string (the password for the user, G4's interface shows complexity indicator)
		 *			Name: string (the display name for the user)
		 *			Perm: uint32 (a set of permissions for the user, Guest/Standard/Admin)
		 *			Text: string (the address/phone number to send alert texts to)
		 *			Alert: int32 (A bit field of which alerts to send)
		 * Update User:
		 *		func: updateuser
		 *		description: If logged in as an admin other users can be modified with this call
		 *		post data: 
		 *			User: string (the user name to identify which user is being updated)
		 *			Pass: string (optional, the new password for the user)
		 *			Name: string (optional, the new display name for the user)
		 *			Perm: uint32 (optional, the new set of permissions for the user, Guest/Standard/Admin)
		 *			Text: string (optional, the new address/phone number to send alert texts to)
		 *			Alert: int32 (optional, A new bit field of which alerts to send)
		 * Delete User:
		 *		func: deleteuser
		 *		description: If logged in as an admin other users can be deleted (not yourself)
		 *		post data: 
		 *			User: string (the username of the user to delete)
		 * List Users: (example below)
		 *		func: listusers
		 *		description: If logged in as an admin retrieves all users
		 * Login: (example below)
		 *		func: login
		 *		description: No existing session is required, will create a session using the provided user credentials
		 *			User: string (the user name to log in as)
		 *			Pass: string (the password for the given user)
		 * Logout: (example below)
		 *		func: logout
		 *		description: If logged in, will end the session.
		 * List Logins:
		 *		func: listlogins
		 *		description: If logged in as an admin, retrieves a list of all current sessions.
		 * Get Permissions:
		 *		func: listlogins
		 *		description: If logged in, retrieves the permissions for the current user.
		 * Recover Account:
		 *		func: listlogins
		 *		description: No existing session is required. Will initiate the account recovery process (requries internet access)
		 *		post data: 
		 *			User: string (the user name for the account that needs recovery)
		 * Change Password:
		 *		func: listlogins
		 *		description: If logged in as an admin, retrieves a list of all current sessions.
		 *		post data: 
		 *			User: string (the user name to identify which user is being updated)
		 *			Code: string (The code provided by the password recovery process)
		 *			Pass: string (The new password for the recovered user)
		 */
		HttpClient _client = new HttpClient();

		/// <summary>
		/// The cookie to 
		/// </summary>
		public string Cookie
		{
			get => _client.DefaultRequestHeaders.GetValues("Cookie").FirstOrDefault();
			set
			{
				if (string.IsNullOrEmpty(value))
				{
					_client.DefaultRequestHeaders.Remove("Cookie");
				}
				else
				{
					_client.DefaultRequestHeaders.Add("Cookie", value);
				}
			}
		}

		public bool Secure { get; set; } = true;
		public string Host { get; set; }

		public string Protocol => Secure ? "https" : "http";

		public async Task<JObject> Login(string username, string password)
		{
			JObject result = null;
			JObject postJson = new JObject { ["User"] = username, ["Pass"] = password };
			HttpContent content = new StringContent(postJson.ToString());
			try
			{
				var response = await _client.PostAsync($"{Protocol}://{Host}/sdk?func=login", content);

				if (response.IsSuccessStatusCode && response.Headers.TryGetValues("Set-Cookie", out var cookies))
				{
					// Login returns a cookie that must be sent with all secure requests
					// Just send the cookie with all requsts
					Cookie = cookies.FirstOrDefault();
					string res = await response.Content.ReadAsStringAsync();
					result = JObject.Parse(res);
				}
			}
			catch (Exception ex)
			{
				string msg = $"{ex.Message}{Environment.NewLine}{ex.StackTrace}";
				Debug.WriteLine($"{DateTime.Now:dd HH:mm:ss.fffff}: from SecureConnection: Login(): Exception: {msg}");
			}

			return result;
		}

		public async Task<JObject> Logout()
		{
			JObject result = null;
			if (!string.IsNullOrEmpty(Cookie))
			{
				var response = await _client.GetAsync($"{Protocol}://{Host}/sdk?func=logout");
				if (response.IsSuccessStatusCode)
				{
					Cookie = null;
					string res = await response.Content.ReadAsStringAsync();
					result = JObject.Parse(res);
				}
			}

			return result;
		}

		public async Task<JObject> CreateUser(string email, string password, string name, uint permissions)
		{
			JObject result = null;
			if (!string.IsNullOrEmpty(Cookie))
			{
				JObject postJson = new JObject {
					["User"] = email,
					["Pass"] = password,
					["Name"] = name,
					["Perm"] = permissions
				};
				HttpContent content = new StringContent(postJson.ToString());
				var response = await _client.PostAsync($"{Protocol}://{Host}/sdk?func=createuser", content);
				if (response.IsSuccessStatusCode)
				{
					string res = await response.Content.ReadAsStringAsync();
					result = JObject.Parse(res);
				}
			}

			return result;
		}

		public async Task<JObject> ListUsers()
		{
			JObject result = null;
			if (!string.IsNullOrEmpty(Cookie))
			{
				var response = await _client.GetAsync($"{Protocol}://{Host}/sdk?func=listusers");
				if (response.IsSuccessStatusCode)
				{
					string res = await response.Content.ReadAsStringAsync();
					result = JObject.Parse(res);
				}
			}

			return result;
		}
	}
}
