// This file is not to be included by any native modules
namespace LarsonDavis
{
	namespace Native
	{
		typedef void*(*ToNativeImpl)(System::Object^);
		extern std::map<const void*, msclr::gcroot<System::Object^>> g_instances;
		extern std::map<int, ToNativeImpl> g_toNativeImpls;

		StringWrapper ToNative(System::String^ managed);
		//std::shared_ptr<void> ToNative(System::Object^ managed);
		System::String^ GetFullName(System::Type^ managedType);
		template<typename T>
		std::shared_ptr<T> ToNative(System::Type^ managedType, System::Object^ managed)
		{
			if (managed == nullptr)
			{
				return nullptr;
			}

			if (g_toNativeImpls.size() == 0)
			{
				PopulateNativeImpls();
			}

			//auto name = GetFullName(managedType);
			//auto nativeName = wstring(*ToNative(name));
			auto handler = g_toNativeImpls.find(managedType->GetHashCode());
			if (handler != g_toNativeImpls.end())
			{
				void* pInstance = (handler->second)(managed);
				return std::shared_ptr<T>((T*)pInstance);
			}
			else
			{
				return nullptr;
			}
 		}
		System::String^ ToManaged(const StringWrapper& native);
		System::String^ ToManaged(const StringWrapper* native);
		System::Object^ ToManaged(std::shared_ptr<void> native);
		void PopulateNativeImpls();
	}
}
