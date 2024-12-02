// ConnectionServerApiExample.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <rapidjson/rapidjson.h>
#include <rapidjson/document.h>
#include <rapidjson/stringbuffer.h>
#include <rapidjson/writer.h>
#include <functional>
#include <algorithm>

#include "JsonTcpChannel.h"
#include "ConnServerConnection.h"
#include "ConnServerApiDefines.h"

#include "ConnectionServerApiExample.h"

using namespace rapidjson;
using namespace std;

int main(int argc, char* argv[])
{
   uint16_t port = 2501;
   if (argc > 1)
   {
      port = (uint16_t)strtoul(argv[1], NULL, 10);
   }

   auto pConn = new ConnServerConnection(JsonTcpChannel::Create(port));
   RegisterHandlers(pConn);

   pConn->Start();

   while (pConn->IsRunning())
   {
      char buffer[512];
      cout << ">";
      cin.getline(buffer, sizeof(buffer));

      int32_t len = strlen(buffer);

      if (len > 0)
      {
         char* pNext = NULL;
         MenuEntry choice = (MenuEntry)strtol(buffer, &pNext, 10);
         char* pBuffer = buffer;

         transform(pBuffer, pBuffer + len, pBuffer, ::tolower);

         ParseTextEntry(pNext, buffer, choice);

         if (choice != MenuEntry::Invalid)
         {
            ProcessInput(choice, pConn, buffer);
         }
      }
      else
      {
         cout << ">";
      }
   }

   delete pConn;
   return 0;
}

void ProcessInput(MenuEntry choice, ConnServerConnection* conn, const char* buffer)
{
   int32_t id = -1;

   switch (choice)
   {
      case MenuEntry::Shutdown:
         conn->Shutdown([](Document& doc) {});
         conn->Stop();
      break;

      case MenuEntry::Resend:
         conn->RequestFullMeterList([](Document& doc) {});
      break;

      case MenuEntry::Add:
      {
         string host;
         uint16_t port;
         string secure;
         cout << "Enter Host: ";
         cin >> host;
         cout << "Enter Port: ";
         cin >> port;
         cout << "Secure? (yes/NO): ";
         cin >> secure;

         transform(secure.begin(), secure.end(), secure.begin(), ::tolower);

         bool isSecure = secure[0] == 'y';
         conn->AddHost(host, port, isSecure, [](Document& doc) {
            if (doc.HasMember("newId"))
            {
               cout << "Success" << endl;
            }
            else
            {
               cout << "Failure" << endl;
            }
            cout << ">";
            });
      }
      break;

      case MenuEntry::Exclude:
      {
         vector<int32_t> ids;
         id = GetId(buffer);
         ids.push_back(id);
         conn->Exclude(ids, [](Document& doc) {});
      }
      break;

      case MenuEntry::Include:
      {
         vector<int32_t> ids;
         id = GetId(buffer);
         ids.push_back(id);
         conn->Include(ids, [](Document& doc) {});
      }
      break;

      case MenuEntry::Scan:
         conn->PingUdp([](Document& doc) {});
      break;

      case MenuEntry::Forget:
         id = GetId(buffer);
         conn->ForgetItem(id, [](Document& doc) {});
      break;

      case MenuEntry::Hide:
         id = GetId(buffer);
         conn->HideItem(id, [](Document& doc) {});
      break;

      case MenuEntry::Unhide:
         id = GetId(buffer);
         conn->UnhideItem(id, [](Document& doc) {});
      break;

      case MenuEntry::Refresh:
         conn->RefreshMeters([](Document& doc) {});
      break;

      case MenuEntry::Close:
         conn->Stop();
      break;

      default:
         PrintHelp();
         break;
   }
}

void ParseTextEntry(const char* pNext, const char*  buffer, MenuEntry& choice)
{

   if (pNext == buffer)
   {

      choice = MenuEntry::Invalid;

      if (strstr(buffer, "shutdown") == buffer)
      {
         choice = MenuEntry::Shutdown;
      }
      else if (strstr(buffer, "resend") == buffer)
      {
         choice = MenuEntry::Resend;
      }
      else if (strstr(buffer, "add") == buffer)
      {
         choice = MenuEntry::Add;
      }
      else if (strstr(buffer, "exclude") == buffer)
      {
         choice = MenuEntry::Exclude;
      }
      else if (strstr(buffer, "include") == buffer)
      {
         choice = MenuEntry::Include;
      }
      else if (strstr(buffer, "scan") == buffer)
      {
         choice = MenuEntry::Scan;
      }
      else if (strstr(buffer, "forget") == buffer)
      {
         choice = MenuEntry::Forget;
      }
      else if (strstr(buffer, "hide") == buffer)
      {
         choice = MenuEntry::Hide;
      }
      else if (strstr(buffer, "unhide") == buffer)
      {
         choice = MenuEntry::Unhide;
      }
      else if (strstr(buffer, "refresh") == buffer)
      {
         choice = MenuEntry::Refresh;
      }
      else if (strstr(buffer, "close") == buffer)
      {
         choice = MenuEntry::Close;
      }
      else
      {
         PrintHelp();
      }
   }
}

void RegisterHandlers(ConnServerConnection* pConn)
{
   pConn->RegisterHandler(RSP_FULL_METER_REPORT,
      [](Document* doc) {
         Document* d = new Document(kObjectType);

         ConnServerConnection::GenerateJson(*d, Pair("Result", "Success"));

         DisplayMeterList(doc, "Full meter report", RSP_FULL_METER_REPORT);

         return d;
      });
   pConn->RegisterHandler(RSP_METERS_ADDED,
      [](Document* doc) {
         Document* d = new Document(kObjectType);

         ConnServerConnection::GenerateJson(*d, Pair("Result", "Success"));

         DisplayMeterList(doc, "Added meter report", RSP_METERS_ADDED);

         return d;
      });
   pConn->RegisterHandler(RSP_METERS_REMOVED,
      [](Document* doc) {
         Document* d = new Document(kObjectType);

         ConnServerConnection::GenerateJson(*d, Pair("Result", "Success"));

         DisplayMeterList(doc, "Lost meter report", RSP_METERS_REMOVED);

         return d;
      });
}

const char* ToModelName(int meterType)
{
   // Only return static strings
   switch (meterType)
   {
   case 1:
      return "LxT";
   case 2:
      return "LxT SE";
   case 3:
      return "831";
   case 4:
      return "HVM100";
   case 5:
      return "HVM200";
   case 6:
      return "831C";
   case 7:
      return "730";
   case 0:
   default:
      return "Unknown";
   }
}

int GetId(const char* pBuffer)
{
   int32_t id = -1;
   const char* pValue = strstr(pBuffer, " ");
   char* pNext = NULL;

   if (NULL != pValue)
   {
      pValue += 1;
      id = strtol(pValue, &pNext, 10);
   }

   if (NULL == pNext)
   {
      cout << "Enter the Id: ";
      cin >> id;
   }

   return id;
}

void DisplayMeterList(Document* doc, const char* pHeaderText, const char* pMemberName)
{
   Value& full = (*doc)[pMemberName];
   cout << pHeaderText << endl;
   for (Value* iter = full.Begin(); iter != full.End(); ++iter)
   {
      cout << (*iter)["Id"].GetInt() << ": "
         << ToModelName((*iter)["MeterType"].GetInt()) << " "
         << (*iter)["SerialNumber"].GetString() <<
         "\t(" << (*iter)["Host"].GetString() << ":" << (*iter)["Port"].GetInt() << ")"
         << endl;
   }
}

void PrintHelp()
{
   cout
      << "0 or shutdown: shuts down the server and closes the client" << endl
      << "1 or resend: Has the server resend the full meter list" << endl
      << "2 or add: Adds a new tcp end point to monitor" << endl
      << "3 or exclude <id>: Excludes a given meter from future reporting during this session" << endl
      << "4 or include <id>: Includes a given meter in future reporting during this session" << endl
      << "5 or scan: Scans the local network for Larson Davis devices" << endl
      << "6 or forget <id>: Removes device from monitored lists, clearing it from server cache" << endl
      << "7 or hide <id>: Marks the device as hidden, similar to \"exclude\" but persists" << endl
      << "8 or unhide <id>: Remove the \"hidden\" mark on the device, similar to \"include\"" << endl
      << "9 or refresh: " << endl
      << "10 or close: Closes the client but leave the server running" << endl
      << "?: To get these instructions" << endl
      << "Replace \"<id>\" with the id you wish to manipulate." << endl
      << "Other commands exist but are not part of this demo." << endl;

   cout << ">";
}
