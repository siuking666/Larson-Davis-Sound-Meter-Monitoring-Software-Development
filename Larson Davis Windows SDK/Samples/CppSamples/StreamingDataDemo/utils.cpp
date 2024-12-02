#include "utils.h"

using namespace std;

#ifdef _WIN32
void start_HLD(wstring cmd, PROCESS_INFORMATION& proc_info)
{
	wstring hld_env_dir = L"C:\\Program Files (x86)\\PCB Piezotronics\\HLD\\";
	wstring app_name = hld_env_dir + L"HttpLD.exe";

	STARTUPINFO start_info;
	memset(&start_info, 0, sizeof(start_info));

	start_info.cb = sizeof(start_info);
	start_info.lpTitle = L"HLD";

	CreateProcess(app_name.c_str(), (wchar_t*)cmd.c_str(), NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &start_info, &proc_info);
}

void stop_HLD(PROCESS_INFORMATION& proc_info, string ip_address, int port)
{
	SOCKET socket;

	// Tell the HLD to close
	socket = send_HLD_command(ip_address, port, "closedown");
	close_socket(socket);

	// Wait for HLD to close itself nicely
	Sleep(2000);

	// If HLD is still running terminate it at this point
	TerminateProcess(proc_info.hProcess, 0);
}
#endif

SOCKET create_socket(string ip_address, int port)
{

#ifdef _WIN32
	WSADATA wsaData;

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
	{
		cout << "WSAStartup failed.\n";
		sys_pause();
		return 0;
	}
#endif

	SOCKET Socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	struct hostent *host;
	host = gethostbyname(ip_address.c_str());
	SOCKADDR_IN SockAddr;
	SockAddr.sin_port = htons(port);
	SockAddr.sin_family = AF_INET;
	SockAddr.sin_addr.s_addr = *((unsigned long*)host->h_addr);

	if (connect(Socket, (SOCKADDR*)(&SockAddr), sizeof(SockAddr)) != 0)
	{
		cout << "Could not connect";
		sys_pause();
		return 0;
	}

	return Socket;
}

void close_socket(SOCKET socket)
{

	closesocket(socket);

#ifdef _WIN32
	WSACleanup();
#endif

}

#define MAX_HLD_COMMAND (256)
SOCKET send_HLD_command(string ip_address, int port, string command)
{
	SOCKET socket;

	socket = create_socket(ip_address, port);

	char buf[MAX_HLD_COMMAND];

#ifdef _WIN32
	sprintf_s(buf, "GET /sdk?func=%s HTTP/1.1\r\nHost: %s:%d\r\nConnection: close\r\nAccept: */*\r\n\r\n", command.c_str(), ip_address.c_str(), port);
#else
	sprintf(buf, "GET /sdk?func=%s HTTP/1.1\r\nHost: %s:%d\r\nConnection: close\r\nAccept: */*\r\n\r\n", command.c_str(), ip_address.c_str(), port);
#endif

	send(socket, buf, strlen(buf), 0);

	return socket;
}

SOCKET send_HLD_command_alt(string ip_address, int port, string command)
{
	SOCKET socket;

	socket = create_socket(ip_address, port);

	char buf[MAX_HLD_COMMAND];

#ifdef _WIN32
	sprintf_s(buf, "GET /%s HTTP/1.1\r\nHost: %s:%d\r\nConnection: close\r\nAccept: */*\r\n\r\n", command.c_str(), ip_address.c_str(), port);
#else
	sprintf(buf, "GET /%s HTTP/1.1\r\nHost: %s:%d\r\nConnection: close\r\nAccept: */*\r\n\r\n", command.c_str(), ip_address.c_str(), port);
#endif

	send(socket, buf, strlen(buf), 0);

	return socket;
}

// Return value is the http response length, the data is stored in response_data and http_response_header
#define MAX_BUF_SIZE (1024)
int get_HLD_response(SOCKET socket, string &http_response_header, stringstream &response_data)
{
	http_response_header.clear();

	char buf[MAX_BUF_SIZE];
	int response_length = -1;

	if (http_header_recv(socket, http_response_header))
	{
		response_length = html_header_get_content_length(http_response_header);

		int remaining_response = response_length;

		while (remaining_response > 0)
		{
			int response = recv(socket, buf, MAX_BUF_SIZE, 0);

			if (response > 0)
			{
				response_data.write(buf, response);
				remaining_response -= response;
			}
			else
			{
				cout << "Wrong amount of data received, expected: " << remaining_response;
				cout << " more bytes" << endl;
				break;
			}
		}
	}

	if (-1 == response_length)
	{
		response_length = 0;
		cout << " Error - Http header: " << http_response_header << endl;
	}

	return response_length;
}

int get_HLD_response( SOCKET socket,  string &http_response_header, char *response_data, int response_data_arrary_size)
{
	stringstream data;
	int response_length;

	response_length = get_HLD_response(socket, http_response_header, data);

	if (response_length < response_data_arrary_size)
	{
		strncpy_s(response_data, response_data_arrary_size , data.str().c_str(), response_length);
	}

	return response_length;
}

string create_send_command_cmd(int id, string value)
{
	string return_value;

	return_value = create_send_command_cmd(id);
	return_value += "&type=string&data=";
	return_value += url_encode(value);

	return return_value;
}

string create_send_command_cmd(int id)
{
	string return_value;

	return_value = "sendCommand&id=";
	return_value += to_string(id);

	return return_value;
}

string create_set_property_cmd(int id, int value)
{
	string return_value;

	return_value = "setProperty&tagId=";
	return_value += to_string(id);
	return_value += "&type=int&value=";
	return_value += to_string(value);

	return return_value;
}

string create_set_property_cmd(int id, string value)
{
	string return_value;

	return_value = "setProperty&tagId=";
	return_value += to_string(id);
	return_value += "&type=string&value=";
	return_value += url_encode(value);

	return return_value;
}

string create_download_file_cmd(int file_index, int file_size, int offset, int dlSessionId)
{
	string return_value;

	return_value = "getDataFileBlock&index=";
	return_value += to_string(file_index);
	return_value += "&offset=";
	return_value += to_string(offset);
	return_value += "&filesize=";
	return_value += to_string(file_size);
	return_value += "&downloadSessionId=";
	return_value += to_string(dlSessionId);

	return return_value;
}

// Strings that need to be sent to the HLD need to be url_encoded
string url_encode(const string &value)
{
	ostringstream escaped;
	escaped.fill('0');
	escaped << hex;

	for (string::const_iterator i = value.begin(), n = value.end(); i != n; ++i)
	{
		string::value_type c = (*i);
		if (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~')
		{
			escaped << c;
		}
		else if (c == ' ')
		{
			escaped << '+';
		}
		else
		{
			escaped << '%' << setw(2) << ((int)c) << setw(0);
		}
	}

	return escaped.str();
}

// Used when only one data file is used to create and ldbin file
string create_ldbin_header(int file_size)
{
	vector <int> temp;

	temp.push_back(file_size);

	return create_ldbin_header(1, temp);
}

// Must be put on any data file so it can be parsed in G3/G4
string create_ldbin_header(int num_files, vector<int>& file_sizes)
{
	ostringstream return_value;

	int hdr1 = 'LD';
	int hdr2 = 'BIN';
	int hdr3 = 1;
	int hdr4 = num_files;

	return_value.write((char*)&hdr1, 4);
	return_value.write((char*)&hdr2, 4);
	return_value.write((char*)&hdr3, 4);
	return_value.write((char*)&hdr4, 4);

	for (int i = 0; i < num_files; ++i)
	{
		return_value.write((char*)&file_sizes[i], 4);
	}

	return return_value.str();
}

#define MAX_HTML_HEADER_SIZE (1024)
bool http_header_recv(SOCKET socket, string &html_header_buf)
{
	char recv_buf[500];
	bool b_end_header_found = false;
	int recv_len = 0;

	html_header_buf.clear();

	if (0 < wait_for_data(socket))
	{
		do
		{
			if ((recv_len = recv(socket, recv_buf, 1, 0)) > 0)
			{
				recv_buf[recv_len] = 0;

				html_header_buf.append(recv_buf);

				if (html_header_buf.find("\r\n\r\n") != string::npos)
				{
					b_end_header_found = true;
				}
			}
		} while (recv_len && !b_end_header_found && (html_header_buf.size() < MAX_HTML_HEADER_SIZE));
	}

	return b_end_header_found;
}

int html_header_get_content_length(string html_header_buf)
{
	int length = 0;

	size_t content_len_pos = html_header_buf.find("Content-Length");

	if (content_len_pos != string::npos)
	{
		content_len_pos += strlen("Content-Length: ");

		size_t end_content_len_value = html_header_buf.find("\r", content_len_pos);
		size_t content_len_size = end_content_len_value - content_len_pos;
		string content_length_value_str = html_header_buf.substr(content_len_pos, content_len_size);
		int content_length_value = atoi(content_length_value_str.c_str());

		length = content_length_value;
	}

	return length;
}

int wait_for_data(SOCKET socket)
{
	fd_set fDS;
	TIMEVAL timeout;

	timeout.tv_sec = 5;
	timeout.tv_usec = 0;

	FD_ZERO(&fDS);
	FD_SET(socket, &fDS);

	return select(sizeof(fd_set) * 8, &fDS, NULL, NULL, &timeout);
}

// Cross platform pause
void sys_pause()
{
#ifdef _WIN32
	system("pause");
#else
	cout << "Press enter to continue..." << endl;
	cin.get();
#endif
}
