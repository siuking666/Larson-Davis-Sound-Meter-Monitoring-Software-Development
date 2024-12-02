#pragma once

class JsonTcpChannel;

template<typename T>
struct Element
{
   const char* name;
   T value;
};

template<typename T>
Element<T> Pair(const char* name, T value)
{
   return { name, value };
}

class ConnServerConnection
{
public:
   ConnServerConnection(JsonTcpChannel* pChannel);

   virtual ~ConnServerConnection();

   void RegisterHandler(const char* name, std::function<rapidjson::Document* (rapidjson::Document*)> handler);

   bool IsConnected() { return m_tcpChannel->IsConnected(); }
   bool IsRunning() { return m_tcpChannel->IsRunning(); }

   void Start() { m_tcpChannel->Start(); }
   void Stop() { m_tcpChannel->Stop(); }
   //API calls
public:

   void RequestFullMeterList(void (*callback)(rapidjson::Document&));

   void AddHost(std::string host, uint16_t port, bool secure, void (*callback)(rapidjson::Document&));

   void Shutdown(void (*callback)(rapidjson::Document&));

   void RefreshMeters(void (*callback)(rapidjson::Document&));

   void PingUdp(void (*callback)(rapidjson::Document&));

   void PingDevice(int32_t id, void (*callback)(rapidjson::Document&));

   void Exclude(std::vector<int32_t> ids, void (*callback)(rapidjson::Document&));

   void Include(std::vector<int32_t> ids, void (*callback)(rapidjson::Document&));

   void MoveItem(int32_t id, int32_t target, int32_t projId, void (*callback)(rapidjson::Document&));

   void ForgetItem(int32_t id, void (*callback)(rapidjson::Document&));

   void HideItem(int32_t id, void (*callback)(rapidjson::Document&));
   
   void UnhideItem(int32_t id, void (*callback)(rapidjson::Document&));

   void NicknameItem(int32_t id, std::string nickname, void (*callback)(rapidjson::Document&));

   void ChangeTcpSettings(int32_t id, std::string host, uint16_t port, bool secure, void (*callback)(rapidjson::Document&));

   void PingServer(void (*callback)(rapidjson::Document&));

private:
   void Init();

   rapidjson::Document* MessageHandler(rapidjson::Document* doc);

   // Utilties
public:

   // Base case for other GenerateJson calls
   static void GenerateJson(rapidjson::Document& doc) { }

   template<typename T, typename... Types>
   static void GenerateJson(rapidjson::Document& doc, Element<T> arg, Element<Types>... args)
   {
      rapidjson::GenericStringRef<char> nameElem(arg.name);
      //auto pNameElem = &nameElem;
      doc.AddMember<T>(
         nameElem,
         arg.value, 
         doc.GetAllocator());
      
      GenerateJson(doc, args...);
   }

   template<typename... Types>
   static void GenerateJson(rapidjson::Document& doc, Element<const char*> arg, Element<Types>... args)
   {
      rapidjson::GenericStringRef<char> nameElem(arg.name);
      //auto pNameElem = &nameElem;
      doc.AddMember(
         nameElem,
         rapidjson::GenericStringRef<char>(arg.value),
         doc.GetAllocator());

      GenerateJson(doc, args...);
   }

   template<typename T, typename... Types>
   static void GenerateJson(rapidjson::Document& doc, Element<std::vector<T>> arg, Element<Types>... args)
   {
      rapidjson::GenericStringRef<char> nameElem(arg.name);
      //auto pNameElem = &nameElem;
      rapidjson::Value arr(rapidjson::kArrayType);

      for (auto iter = arg.value.begin(); iter != arg.value.end(); ++iter)
      {
         arr.PushBack(*iter, doc.GetAllocator());
      }
      doc.AddMember(
         nameElem,
         arr,
         doc.GetAllocator());

      GenerateJson(doc, args...);
   }

private:
   JsonTcpChannel* m_tcpChannel;
   std::map<std::string, std::function<rapidjson::Document* (rapidjson::Document*)> > m_handlers;
};