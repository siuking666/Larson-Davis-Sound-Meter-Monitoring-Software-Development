#include <stdint.h>
#include <vector>
#include <map>
#include <string>
#include <functional>

#include <rapidjson/rapidjson.h>
#include <rapidjson/document.h>

#include "JsonTcpChannel.h"
#include "ConnServerApiDefines.h"

#include "ConnServerConnection.h"

using namespace rapidjson;


ConnServerConnection::ConnServerConnection(JsonTcpChannel* pChannel)
   : m_tcpChannel(pChannel)
{
   Init();
}

ConnServerConnection::~ConnServerConnection()
{
   Stop();
}

void ConnServerConnection::RegisterHandler(const char* name, std::function<rapidjson::Document* (rapidjson::Document*)> handler)
{
   m_handlers[name] = handler;
}

void ConnServerConnection::RequestFullMeterList(void(*callback)(rapidjson::Document&))
{
   Document doc(kObjectType);
   GenerateJson(doc, Pair("cmd", CMD_RESEND_ITEMS));
   m_tcpChannel->SendJson(doc, callback);
}

void ConnServerConnection::AddHost(std::string host, uint16_t port, bool secure, void (*callback)(rapidjson::Document&))
{
   Document doc(kObjectType);
   GenerateJson(doc, Pair("cmd", CMD_ADD_HOST), Pair("host", host.c_str()), Pair("port", port), Pair("secure", secure));
   m_tcpChannel->SendJson(doc, callback);
}

void ConnServerConnection::Shutdown(void(*callback)(rapidjson::Document&))
{
   Document doc(kObjectType);
   GenerateJson(doc, Pair("cmd", CMD_SHUTDOWN));
   m_tcpChannel->SendJson(doc, [this, callback](Document& doc2) { m_tcpChannel->Disconnect(); return callback(doc2); });
}

void ConnServerConnection::RefreshMeters(void(*callback)(rapidjson::Document&))
{
   Document doc(kObjectType);
   GenerateJson(doc, Pair("cmd", CMD_REFRESH_METERS));
   m_tcpChannel->SendJson(doc, callback);
}

void ConnServerConnection::PingUdp(void(*callback)(rapidjson::Document&))
{
   Document doc(kObjectType);
   GenerateJson(doc, Pair("cmd", CMD_QUERY_UDP));
   m_tcpChannel->SendJson(doc, callback);
}

void ConnServerConnection::PingDevice(int32_t id, void(*callback)(rapidjson::Document&))
{
   Document doc(kObjectType);
   GenerateJson(doc, Pair("cmd", CMD_PING_DEVICE), Pair("id", id));
   m_tcpChannel->SendJson(doc, callback);
}

void ConnServerConnection::Exclude(std::vector<int32_t> ids, void(*callback)(rapidjson::Document&))
{
   Document doc(kObjectType);
   GenerateJson(doc, Pair("cmd", CMD_EXCLUDE), Pair("ids", ids));
   m_tcpChannel->SendJson(doc, callback);
}

void ConnServerConnection::Include(std::vector<int32_t> ids, void(*callback)(rapidjson::Document&))
{
   Document doc(kObjectType);
   GenerateJson(doc, Pair("cmd", CMD_INCLUDE), Pair("ids", ids));
   m_tcpChannel->SendJson(doc, callback);
}

void ConnServerConnection::MoveItem(int32_t id, int32_t target, int32_t projId, void(*callback)(rapidjson::Document&))
{
   Document doc(kObjectType);
   GenerateJson(doc, Pair("cmd", CMD_MOVE_ITEM), Pair("id", id), Pair("target", target), Pair("proj", projId));
   m_tcpChannel->SendJson(doc, callback);
}

void ConnServerConnection::ForgetItem(int32_t id, void(*callback)(rapidjson::Document&))
{
   Document doc(kObjectType);
   GenerateJson(doc, Pair("cmd", CMD_FORGET_ITEM), Pair("id", id));
   m_tcpChannel->SendJson(doc, callback);
}

void ConnServerConnection::HideItem(int32_t id, void(*callback)(rapidjson::Document&))
{
   Document doc(kObjectType);
   GenerateJson(doc, Pair("cmd", CMD_HIDE_ITEM), Pair("id", id));
   m_tcpChannel->SendJson(doc, callback);
}

void ConnServerConnection::UnhideItem(int32_t id, void(*callback)(rapidjson::Document&))
{
   Document doc(kObjectType);
   GenerateJson(doc, Pair("cmd", CMD_UNHIDE_ITEM), Pair("id", id));
   m_tcpChannel->SendJson(doc, callback);
}

void ConnServerConnection::NicknameItem(int32_t id, std::string nickname, void(*callback)(rapidjson::Document&))
{
   Document doc(kObjectType);
   GenerateJson(doc, Pair("cmd", CMD_NICKNAME_ITEM), Pair("id", id), Pair("nickname", nickname.c_str()));
   m_tcpChannel->SendJson(doc, callback);
}

void ConnServerConnection::ChangeTcpSettings(int32_t id, std::string host, uint16_t port, bool secure, void(*callback)(rapidjson::Document&))
{
   Document doc(kObjectType);
   GenerateJson(doc, Pair("cmd", CMD_CHANGE_TCP_SETTINGS), Pair("id", id), Pair("host", host.c_str()), Pair("port", port), Pair("secure", secure));
   m_tcpChannel->SendJson(doc, callback);
}

void ConnServerConnection::PingServer(void(*callback)(rapidjson::Document&))
{
   Document doc(kObjectType);
   GenerateJson(doc, Pair("cmd", CMD_PING));
   m_tcpChannel->SendJson(doc, callback);
}

void ConnServerConnection::Init()
{
   m_tcpChannel->RegisterHandler([this](rapidjson::Document* doc) { return this->MessageHandler(doc); });
}

rapidjson::Document* ConnServerConnection::MessageHandler(rapidjson::Document* doc)
{
   rapidjson::Document* d = NULL;
   
   auto first = doc->MemberBegin();
   if (first != doc->MemberEnd())
   {
      const char* name = first->name.GetString();
      auto match = m_handlers.find(name);
      if (match != m_handlers.end())
      {
         d = match->second(doc);
      }
      else
      {
         // No handler defined
         d = new rapidjson::Document(kObjectType);

         GenerateJson(*d, Pair("Result", "Success"));
      }
   }
   else
   {
      // Bad message;
   }

   return d;
}
