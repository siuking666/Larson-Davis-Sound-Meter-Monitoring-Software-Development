// StreamingDataDemo.cpp : Defines the entry point for the console application.
//

#ifdef _WIN32
#include <winsock2.h>
#else
#include <sys/types.h>
#include <sys/socket.h>
#endif

#include <stdint.h>
#include <iostream>
#include <iostream>
#include <fstream>
#include <time.h>
#include <math.h>
#include "utils.h"


#ifdef _WIN32
#pragma comment(lib,"ws2_32.lib")
#endif 

using namespace std;

typedef struct
{
	const char *flag_value;
	const char *value_label;
} streaming_data_flag_t;

enum e_streaming_data_flag_idx
{
	ALeq,
	APeak,
	ASlowSpl,
	AFastSpl,
	AImplSpl,
	CLeq,
	CPeak,
	SlowSpl,
	FastSpl,
	ImplSpl,
	ZLeq,
	ZPeak,
	ZSlowSpl,
	ZFastSpl,
	ZImplSpl,
	ObaLeq11,
	ObaSpl11,
	ObaLeq13,
	ObaSpl13,
	Flags,
	WSlowSpl,
	WFastSpl,
	WImplSpl,
	Tms
};

streaming_data_flag_t streaming_data_flag[] = {
	{ "1","ALeq" },
	{ "2", "APeak" },
	{ "4","ASlowSpl" },
	{ "8","AFastSpl" },
	{ "16","AImplSpl" },
	{ "32","CLeq" },
	{ "64","CPeak" },
	{ "128","CSlowSpl" },
	{ "256","CFastSpl" },
	{ "512","CImplSpl" },
	{ "1024","ZLeq" },
	{ "2048","ZPeak" },
	{ "4096","ZSlowSpl" },
	{ "8192","ZFastSpl" },
	{ "16384","ZImplSpl" },
	{ "32768","ObaLeq11" },
	{ "65536","ObaSpl11" },
	{ "131072","ObaLeq13" },
	{ "262144","ObaSpl13" },
	{ "524288","Flags" },
	{ "1048576","WSlowSpl" },
	{ "2097152","WFastSpl" },
	{ "4194304","WImplSpl" },
	{ "8388608","Tms" }
};

bool start_streaming_data_request(string ipAddress, int port, e_streaming_data_flag_idx idx);
void get_streaming_data(string ipAddress, int port, e_streaming_data_flag_idx idx);


int main()
{
	e_streaming_data_flag_idx idx = CLeq; // Set the data to stream.
	string command;
	stringstream response_data;
	string http_response_header;

	cout << "Streaming Data" << endl;

#ifdef _WIN32
	wstring cmd;
	PROCESS_INFORMATION proc_info;

	start_HLD(cmd, proc_info);

	cout << "Waiting for HttpLD to start..." << endl;

	Sleep(5000);

#endif

#ifdef _WIN32
#define  IP_ADDRESS "127.0.0.1"    //Windows build uses HTTPLD which requires local host address
#else
#define IP_ADDRESS "10.3.122.84"  //Set the address of you INT-ET here.
#endif

#define  IP_PORT 2001

	start_streaming_data_request(IP_ADDRESS, IP_PORT, idx);

	Sleep(1000); //Need to wait before doing first request.

	do
	{

		get_streaming_data(IP_ADDRESS, IP_PORT, idx);

		cout << "Press enter to do another request or n and enter to stop " << endl;

	} while (getc(stdin) != 'n');


	SOCKET Socket = send_HLD_command(IP_ADDRESS, IP_PORT, "stopDataStreaming");

	if (!get_HLD_response(Socket, http_response_header, response_data))
	{
		cout << "Failed to receive response" << endl;

		sys_pause();
	}

	Sleep(1000); //Need to wait before doing first request.
	close_socket(Socket);


#ifdef _WIN32
	stop_HLD(proc_info, IP_ADDRESS, IP_PORT);
#endif

	return 0;
}

bool start_streaming_data_request(string ipAddress, int port, e_streaming_data_flag_idx idx)
{
	bool b_ret_val = true;

	string command;

	command = "startDataStreaming&rate=5&flags=";

	command.append(streaming_data_flag[idx].flag_value);

	SOCKET Socket = send_HLD_command(ipAddress.c_str(), port, command);

	stringstream response_data;
	string http_response_header;

	if (!get_HLD_response(Socket, http_response_header, response_data))
	{
		cout << "Failed to receive response";
		sys_pause();

		b_ret_val = false;
	}

	close_socket(Socket);

	return b_ret_val;
}

#define MAX_RESPONSE_BUFF_SIZE      (1000)
#define STREAMING_DATA_ELEMENT_SIZE (4)
#define STREAMING_DATA_PAIR_SIZE    (STREAMING_DATA_ELEMENT_SIZE * 2)
void get_streaming_data(string ipAddress, int port, e_streaming_data_flag_idx idx)
{
	string http_response_header;
	bool b_ret_val = false;

	stringstream buf;
	//char buf[MAX_RESPONSE_BUFF_SIZE];

	cout << "Send getStreamData func to HLD" << endl;

	SOCKET Socket = send_HLD_command(ipAddress.c_str(), port, "getStreamingData");

	if (NULL == Socket)
	{
		cout << "Fail to send HLD command" << endl;
	}

	int response_size;
	if ((response_size = get_HLD_response(Socket, http_response_header, buf)) > 0)
	{

		close_socket(Socket);

		int stream_len = response_size / STREAMING_DATA_PAIR_SIZE;

		for (int i = 0; i < stream_len; i++)
		{
			string  temp_str;
			int32_t raw_time_stamp;
			float   value;

			buf.read((char*)&raw_time_stamp, STREAMING_DATA_ELEMENT_SIZE);
			buf.read((char*)&value, STREAMING_DATA_ELEMENT_SIZE);

			float fLevel = -999.99f;

			if (value > 0.0f)
			{
				fLevel = (float)(10 * log10(value));
			}

			cout << streaming_data_flag[idx].value_label << ": " << std::to_string(fLevel) << "  ";

			//Timestamp is time of meter...
			time_t timestamp = raw_time_stamp;

			//timestamp time doesn't need to be adjusted. just convert to tm so it can be printed.
			tm *time_of_sample = gmtime((const time_t *)&timestamp);

			temp_str = asctime(time_of_sample);

			cout << "Timestamp: " << temp_str;

		}
	}
	else
	{
		cout << " No data" << endl;
	}
}

