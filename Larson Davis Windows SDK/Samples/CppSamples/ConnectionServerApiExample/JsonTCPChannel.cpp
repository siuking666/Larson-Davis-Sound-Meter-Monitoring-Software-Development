#include <stdint.h>
#include <sstream>
#include <chrono>
#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <rapidjson/document.h>
#include <rapidjson/stringbuffer.h>
#include <rapidjson/writer.h>
#include <mutex>
#include <thread>
#include <functional>

#include "ConnServerApiDefines.h"

#define DECLARE_JSON_TCP_CHANNEL_MEMBERS
#include "JsonTcpChannel.h"

using boost::asio::ip::tcp;
using namespace boost::asio;
using namespace std;
using namespace std::chrono;
using namespace rapidjson;

JsonTcpChannel::JsonTcpChannel(const char* host, uint16_t port)
   : m_ioService()
   , m_resolver(m_ioService)
   , m_connection(m_ioService)
   , m_running(false)
   , m_stopping(false)
   , m_connected(false)
   , m_disconnecting(false)
   , m_awaitingResponses()
   , m_nextMsgId(1)
   , m_handler(NULL)
   , m_procLoop(NULL)
   , m_stream()
   , m_port(port)
   , m_host(host)
{
}

JsonTcpChannel::JsonTcpChannel(uint16_t port)
   : JsonTcpChannel("localhost", 2501)
{
   Connect();
}

JsonTcpChannel::JsonTcpChannel()
   : JsonTcpChannel(2501)
{
}

JsonTcpChannel* JsonTcpChannel::Create()
{
   return new JsonTcpChannel();
}

JsonTcpChannel* JsonTcpChannel::Create(uint16_t port)
{
   return new JsonTcpChannel(port);
}

JsonTcpChannel* JsonTcpChannel::Create(const char* host, uint16_t port)
{
   return new JsonTcpChannel(host, port);
}

JsonTcpChannel::~JsonTcpChannel()
{
   Disconnect();
   delete m_procLoop;
   m_procLoop = NULL;
}

void JsonTcpChannel::Connect()
{
   if (!m_connected)
   {
      try
      {
         char buffer[16];
         snprintf(buffer, sizeof(buffer), "%u", m_port);
         tcp::resolver::query connServerQuery(m_host, buffer);
         tcp::resolver::iterator endpoint_iterator = m_resolver.resolve(connServerQuery);
         connect(m_connection, endpoint_iterator);
         m_connected = true;
      }
      catch (...) {}
   }
}

void JsonTcpChannel::Connect(const char* host, uint16_t port)
{
   if (!m_connected)
   {
      m_host = host;
      m_port = port;
      Connect();
   }
}

void JsonTcpChannel::Disconnect()
{
   if (m_connected && !m_disconnecting)
   {
      m_disconnecting = true;
      Stop();
      m_connection.close();
      m_connected = false;
   }
}

void JsonTcpChannel::Loop()
{
   boost::array<char, 2049> buf;
   boost::system::error_code error;

   while (!m_stopping && m_connected)
   {
      size_t len = m_connection.read_some(buffer(buf, 2048), error);

      if (len > 0)
      {

         if (len < buf.size())
         {
            buf[len] = '\0';
            //len = len - 1;
         }
         uint32_t startOfLast = 0;
         for (uint32_t i = 0; i < len; ++i)
         {
            if (buf[i] == '\03')
            {
               buf[i] = '\0';
               m_stream << buf.data() + startOfLast;
               ProcessMessage(m_stream.str());
               m_stream = stringstream();
               startOfLast = i + 1;
            }
         }

         if (startOfLast < len)
         {
            m_stream << (buf.data() + startOfLast);
         }
      }
   }

   m_running = false;
   m_stopping = false;
}

void JsonTcpChannel::Start()
{
   if (m_connected && !m_disconnecting)
   {
      delete m_procLoop;
      m_running = true;
      m_procLoop = new thread([this]() {this->Loop(); });
   }
}

void JsonTcpChannel::Stop()
{
   m_stopping = true;
   if (this_thread::get_id() != m_procLoop->get_id())
   {
      Document doc(kObjectType);
      doc.AddMember(rapidjson::GenericStringRef<char> ("cmd"), rapidjson::GenericStringRef<char>(CMD_PING), doc.GetAllocator());
      SendJson(doc, [](Document& doc) {printf("Ponged"); });
      while (m_running) {};
   }
}

void JsonTcpChannel::ProcessMessage(const string& message)
{
   Document d;
   d.Parse(message.c_str());
   if (!d.HasParseError())
   {
      // Even if the message was valid JSON in order for it 
      // to be a valid message it must either have 
      // "__msgResId__" or "__msgId__"
      if (d.HasMember("__msgResId__"))
      {
         // This is a 
         Value& resId = d["__msgResId__"];
         if (resId.IsInt())
         {
            auto match = m_awaitingResponses.find(resId.GetInt());
            d.RemoveMember("__msgResId__");
            match->second(d);
            m_awaitingResponses.erase(match);
         }
      }
      else if (d.HasMember("__msgId__"))
      {
         boost::system::error_code error;
         Value& msgId = d["__msgId__"];
         auto res = m_handler(&d);
         res->AddMember("__msgResId__", msgId, res->GetAllocator());

         SendJsonAsIs(*res);
         delete res;
      }
   }
   else
   {
   }
}

void JsonTcpChannel::SendJson(Document& message, function<void(Document&)> responseHandler)
{
   int32_t msgId = 0;
   {
      lock_guard<mutex> guard(m_msgIdMutex);
      msgId = m_nextMsgId++;
      if (m_nextMsgId < 0)
      {
         m_nextMsgId = 1;
      }
   }

   message.AddMember("__msgId__", msgId, message.GetAllocator());
   m_awaitingResponses[msgId] = responseHandler;
   SendJsonAsIs(message);
}

void JsonTcpChannel::RegisterHandler(std::function<rapidjson::Document*(rapidjson::Document*)> handler)
{
   m_handler = handler;
}

bool JsonTcpChannel::IsConnected()
{ 
   return m_connected;
}

bool JsonTcpChannel::IsRunning()
{
   return m_running;
}

void JsonTcpChannel::SendJsonAsIs(rapidjson::Document& doc)
{
   StringBuffer buf;
   Writer<StringBuffer> writer(buf);
   doc.Accept(writer);
   char* bufBlock = new char[buf.GetSize() + 2];
   snprintf(bufBlock, buf.GetSize() + 2, "%s\03", buf.GetString());

   m_connection.async_send(buffer(bufBlock, buf.GetSize() + 1), [&bufBlock](const error_code& ec, size_t sent) {delete[] bufBlock; bufBlock = NULL; });
}
