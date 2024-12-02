// SdkTestApp.cpp : Defines the entry point for the console application.
//
#include <fstream>
#include "utils.h"

// From SDK include
#include "LxT831.h" // CMD_RUN, CMD_STOP, CMD_STORE

// From JsonCpp (amalgamation)
#include "json-forwards.h"
#include "json.h"

#ifdef _WIN32
#pragma comment(lib,"ws2_32.lib")
#endif

using Json::Value;
using Json::Reader;

using namespace std;

#define TAGS_FILE        "tags.json"
#define METER_FILE_NAME  "test_app.s"
#define PC_FILE_NAME     "test_app.ldbin"
#define STREAM_FILE_NAME "stream_test_app.ldbin"
#define LOCAL_HOST       "127.0.0.1"
#define IP_ADDRESS       "127.0.0.1"
#define PORT             (2001)

void   get_data_file_list(string ip_address, int port, stringstream& data);
bool   prep_download(string ip_address, int port, int file_index, int file_size, int offset, int& dlSessionId);
bool   download(string ip_address, int port, int file_index, int file_size, int offset, string pc_file_name);
bool   parse_data(Reader& reader, Value& root, stringstream& data);


int main()
{
	// HLD only runs on windows
#ifdef _WIN32
	PROCESS_INFORMATION proc_info;

	// If meter is connected over USB to the local machine, start the HLD
	if (IP_ADDRESS == LOCAL_HOST)
	{
		start_HLD(L"", proc_info);

		// Waiting for the HLD to connect to the meter
		Sleep(5000);
	}
#endif

	Reader       reader;
	Value        root;
	Value        cmd_tags;
	SOCKET       socket;
	string       http_header;
	stringstream data;

	//--------------------------------------------------------------------------
	// Read in the tags so we can use them to modify settings

	ifstream tags(TAGS_FILE);
	reader.parse(tags, cmd_tags);
	tags.close();

	//--------------------------------------------------------------------------
	// Changing settings on the meter

	cout << "Setting measurement description" << endl;
	int id = cmd_tags["PropertyTags"]["TAG_OVERALL_TITLE"]["ID"].asInt();

	socket = send_HLD_command(IP_ADDRESS, PORT, create_set_property_cmd(id, "This is an SDK example!"));
	get_HLD_response(socket, http_header, data);

	parse_data(reader, root, data);

	cout << "Setting Run Mode = Manual Stop" << endl;
	id = cmd_tags["PropertyTags"]["TAG_RUN_MODE"]["ID"].asInt();

	socket = send_HLD_command(IP_ADDRESS, PORT, create_set_property_cmd(id, 0)); // TODO: Use enumeration
	get_HLD_response(socket, http_header, data);

	parse_data(reader, root, data);

	cout << "Setting OBA bandwidth = 1/3 Octave" << endl;
	id = cmd_tags["PropertyTags"]["TAG_OBA_BANDWIDTH"]["ID"].asInt();

	socket = send_HLD_command(IP_ADDRESS, PORT, create_set_property_cmd(id, 2));
	get_HLD_response(socket, http_header, data);

	parse_data(reader, root, data);

	cout << "Waiting for filter reset (10 sec)" << endl;
	Sleep(10000);

	//--------------------------------------------------------------------------
	// Running the meter

	cout << "Running..." << endl;
	socket = send_HLD_command(IP_ADDRESS, PORT, create_send_command_cmd(CMD_RUN));
	get_HLD_response(socket, http_header, data);

	parse_data(reader, root, data);

	// Run for 15 seconds
	Sleep(15000);

	//--------------------------------------------------------------------------
	// Stopping the meter

	cout << "Stop." << endl;
	socket = send_HLD_command(IP_ADDRESS, PORT, create_send_command_cmd(CMD_STOP));
	get_HLD_response(socket, http_header, data);

	parse_data(reader, root, data);

	// We need to wait for the stop to complete before storing.
	Sleep(500);


	//--------------------------------------------------------------------------
	// Storing the file

	cout << "Storing file." << endl;

	socket = send_HLD_command(IP_ADDRESS, PORT, create_send_command_cmd(CMD_STORE, METER_FILE_NAME));
	get_HLD_response(socket, http_header, data);

	parse_data(reader, root, data);


	//--------------------------------------------------------------------------
	// Finding the file_index and size for the file we created so we can download it

	cout << "Getting data file list" << endl;

	get_data_file_list(IP_ADDRESS, PORT, data);

	reader.parse(data, root);
	data.clear();

	int file_index = -1;
	int file_size = -1;

	for (unsigned i = 0; i < root["DataFiles"].size(); ++i)
	{
		if (root["DataFiles"][i]["name"].asString() == METER_FILE_NAME)
		{
			file_index = root["DataFiles"][i]["index"].asInt();
			file_size = root["DataFiles"][i]["size"].asInt();
			break;
		}
	}

	if (file_index == -1)
	{
		cout << "File not found" << endl;
		sys_pause();
		exit(1);
	}


	//--------------------------------------------------------------------------
	// Downloading the data file by blocks

	stringstream file_data;
	int downloaded_size = 0;
	int dlSessionId;

	cout << "Starting download:" << endl;

	prep_download(IP_ADDRESS, PORT, file_index, file_size, downloaded_size, dlSessionId);
	// The files are split into multiple blocks
	while (downloaded_size < file_size)
	{
		cout << "Getting block..." << endl;

		socket = send_HLD_command(IP_ADDRESS, PORT, create_download_file_cmd(file_index, file_size, downloaded_size, dlSessionId));
		downloaded_size += get_HLD_response(socket, http_header, file_data);
	}

	//--------------------------------------------------------------------------
	// Creating ldbin file

	// To be analyzed in G3/G4 data files must have an ldbin header and extension
	ofstream ldbin_file(PC_FILE_NAME, ios::binary);

	ldbin_file << create_ldbin_header(file_size);
	ldbin_file << file_data.rdbuf();

	ldbin_file.close();

	cout << "File downloaded and stored." << endl;


	//--------------------------------------------------------------------------
	// Stream download data file

	download(IP_ADDRESS, PORT, file_index, file_size, 0, STREAM_FILE_NAME);


	//--------------------------------------------------------------------------
	// The HLD only runs in windows
#ifdef _WIN32

	// If we are connected locally then we started an HLD and need to shut it down.
	if (IP_ADDRESS == LOCAL_HOST)
	{
		stop_HLD(proc_info, IP_ADDRESS, PORT);
	}
#endif

	sys_pause();
}

void get_data_file_list(string ip_address, int port, stringstream& data)
{
	stringstream tmp_data;
	string       http_header;
	SOCKET       socket;
	Reader       reader;
	Value        root;
	int          timeout = 12000;
	bool         result = false;

	socket = send_HLD_command(IP_ADDRESS, PORT, "startFileListBuild");
	get_HLD_response(socket, http_header, tmp_data);

	parse_data(reader, root, tmp_data);

	while (!result && timeout > 0)
	{
		Sleep(1000);
		timeout -= 1000;

		socket = send_HLD_command(IP_ADDRESS, PORT, "queryFileListStatus");
		get_HLD_response(socket, http_header, tmp_data);

		parse_data(reader, root, tmp_data);

		if (root["ResultName"].asString() == "Success")
		{
			result = root["Progress"]["ReturnValue"].asInt() == 2468; // TODO: Fix magic
		}
	}

	if (timeout <= 0)
	{
		cout << "Getting file list timed out" << endl;
		sys_pause();
		exit(1);
	}

	socket = send_HLD_command(IP_ADDRESS, PORT, "getDataFileList");
	get_HLD_response(socket, http_header, data);
}

bool download(string ip_address, int port, int file_index, int file_size, int offset, string pc_file_name)
{
	SOCKET      socket;
	string      download_cmd;
	string      http_header;
	int         downloaded_size = 0;
	int         content_length;
	bool        succeed = true;


	//open file for saving
	ofstream ldbin_file(pc_file_name, ios::binary);
	ldbin_file << create_ldbin_header(file_size);

	download_cmd = "download?index=" + to_string(file_index) + "&size=" + to_string(file_size) + "&offset=" + to_string(offset);
	socket = send_HLD_command_alt(ip_address, port, download_cmd);
	if (http_header_recv(socket, http_header))
	{
		content_length = html_header_get_content_length(http_header);
		//add hld headers to file

		char buffer[10240];
		//receive and write file until complete
		while (downloaded_size < content_length)
		{
			int read = recv(socket, buffer, sizeof(buffer), 0);
			if (read == 0)
			{
				succeed = false;
				break;
			}

			ldbin_file.write(buffer, read);
			downloaded_size += read;
			cout << to_string(downloaded_size) << " of " << to_string(content_length) << " Bytes\n";
		}
	}
	else
	{
		succeed = false;
	}
	closesocket(socket);
	ldbin_file.close();

	return succeed;
}

bool prep_download(string ip_address, int port, int file_index, int file_size, int offset, int& dlSessionId)
{
	SOCKET       socket;
	Reader       json_reader;
	Value        json_value;
	stringstream json_output;
	string       http_header;

	int  timeout = 10;

	string prep_download_cmd = "prepDownload&index=" + to_string(file_index) + "&offset=" + to_string(offset);
	string poll_download_cmd = "pollDownload";

	socket = send_HLD_command(ip_address, port, prep_download_cmd);
	get_HLD_response(socket, http_header, json_output);

	json_reader.parse(json_output, json_value);
	json_output.clear();

	bool success = json_value["ResultName"].asString() == "Success";

	while (!success && (timeout > 0))
	{
		socket = send_HLD_command(ip_address, port, poll_download_cmd);
		get_HLD_response(socket, http_header, json_output);

		json_reader.parse(json_output, json_value);
		json_output.clear();

		dlSessionId = json_value["DownloadSessionId"].asInt();

		success = json_value["ResultName"].asString() == "Success";

		if (!success)
		{
			Sleep(200);
			timeout--;
		}
	}

	return success;
}

bool parse_data(Reader& reader, Value& root, stringstream& data)
{
	root.clear();
	reader.parse(data, root);

	if (root["ResultName"].asString() != "Success")
	{
		cout << "Failure" << endl;
		sys_pause();
		exit(1);
		return false;
	}

	data.clear();

	return true;
}

