#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>

#ifdef _WIN32

#include <winsock2.h> 
#include <windows.h> 

#else

#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <netdb.h>
#include <string.h>
#include <time.h>

#define closesocket(s) close(s);
#define Sleep(s)       usleep(s * 1000);

typedef int         SOCKET;
typedef timeval     TIMEVAL;
typedef sockaddr_in SOCKADDR_IN;
typedef sockaddr    SOCKADDR;

#endif

//using namespace std;

SOCKET create_socket(std::string ip_address, int port);

SOCKET send_HLD_command(std::string ip_address, int port, std::string command);

SOCKET send_HLD_command_alt(std::string ip_address, int port, std::string command);

int get_HLD_response(SOCKET socket, std::string &http_response_header, std::stringstream &response_data );

int  get_HLD_response(SOCKET socket, std::string &http_response_header, char *response_data, int response_data_arrary_size);

int  wait_for_data(SOCKET socket);

bool http_header_recv(SOCKET socket, std::string &htmlHeaderBuf);

int  html_header_get_content_length(std::string html_header_buf);

std::string url_encode(const std::string &value);

std::string create_send_command_cmd(int id, std::string value);

std::string create_send_command_cmd(int id);

std::string create_set_property_cmd(int id, int value);

std::string create_set_property_cmd(int id, std::string value);

std::string create_download_file_cmd(int file_index, int file_size, int offset, int dlSessionId);

void close_socket(SOCKET socket);

std::string create_ldbin_header(int file_size);

std::string create_ldbin_header(int num_files, std::vector<int>& file_sizes);

void sys_pause();

#ifdef _WIN32
void start_HLD(std::wstring cmd, PROCESS_INFORMATION& proc_info);

void stop_HLD(PROCESS_INFORMATION& proc_info, std::string ip_address, int port);

#endif
