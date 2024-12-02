#pragma once

// Communicates over a TCP socket
// Accepting and returning JSON messages.
class JsonTcpChannel
{
public:
   // Default constructor for JsonTcpChannel
   // Will connect to a localhost TCP server on port 2501
   static JsonTcpChannel* Create();
   // Will connect to a localhost TCP server on the specified port
   static JsonTcpChannel* Create(uint16_t port);
   // Will connect to a TCP server on the specified host and port
   static JsonTcpChannel* Create(const char* host, uint16_t port);
   // Will stop processing and close the connection to the server
   virtual ~JsonTcpChannel();

   // Function: void Connect()
   // Summary: Attempts to connect to the end point specified during construction.
   //          Does not do anything if already connected.
   void Connect();

   // Function: void Connect(const char* host, uint16_t port)
   // Summary: Updates the sotred host and port to the provided values then 
   //          attempts to connect to the new host and port.
   //          Does not do anything if already connected.
   void Connect(const char* host, uint16_t port);

   // Function: void Disconnect()
   // Summary: Disconnects from the current endpoint
   void Disconnect();

   // Function: void Loop()
   // Summary: The message processing loop for the JsonTcpChannel
   //          Only call this directly if the default threading is
   //          not desired.
   //          Will not return until JsonTcpChannel::Stop is called.
   void Loop();
   // Function void Start()
   // Summary: Calls Loop on a new thread using std::thread.
   void Start();
   // Function: void Stop()
   // Summary: Will tell the message processing loop to stop and
   //          waits until it has stopped.
   void Stop();
   // Function: void SendJson(Document& message, Callback handler)
   // Summary: Sends a json document (message) and will call the handler
   //          when the server responds to it.
   void SendJson(rapidjson::Document& message, std::function<void(rapidjson::Document&)> responseHandler);
   // Function: void RegisterHandler(Callback handler)
   // Summary: Sets the function to call when a message is sent from the server
   //          This is only triggered is a command is sent from the server to a
   //          response, some commands sent to the server may result in the
   //          server sending a new command/message.
   void RegisterHandler(std::function<rapidjson::Document*(rapidjson::Document*)> handler);

   bool IsConnected();
   bool IsRunning();

private:
   // Default constructor for JsonTcpChannel
   // Will connect to a localhost TCP server on port 2501
   JsonTcpChannel();
   // Will connect to a localhost TCP server on the specified port
   JsonTcpChannel(uint16_t port);
   // Will connect to a TCP server on the specified host and port
   JsonTcpChannel(const char* host, uint16_t port);
   // Function: void ProcessMessage(const string& message)
   // Summary: Called when a complete message has been received to
   //          determine if the message is a response or a new message
   //          and trigger the appropriate handler.
   void ProcessMessage(const std::string& message);
   // Function: void SendJsonAsIs(Document& doc)
   // Summary:  Used to serialize a document and send it to the server.
   void SendJsonAsIs(rapidjson::Document& doc);

#ifdef DECLARE_JSON_TCP_CHANNEL_MEMBERS
private:
   boost::asio::io_service m_ioService;
   boost::asio::ip::tcp::resolver m_resolver;
   boost::asio::ip::tcp::socket m_connection;
   bool m_running;
   bool m_stopping;
   bool m_connected;
   bool m_disconnecting;
   std::map<int, std::function<void(rapidjson::Document&)> > m_awaitingResponses;
   int32_t m_nextMsgId;
   std::mutex m_msgIdMutex;
   std::function<rapidjson::Document*(rapidjson::Document*)> m_handler;
   std::thread* m_procLoop;
   std::stringstream m_stream;
   uint16_t m_port;
   std::string m_host;
#endif
};