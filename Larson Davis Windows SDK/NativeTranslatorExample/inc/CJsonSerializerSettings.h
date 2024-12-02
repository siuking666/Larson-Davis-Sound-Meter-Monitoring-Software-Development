/**************************************************************************//**
 * @file CJsonSerializerSettings.h
 * @brief Native Wrapper for Managed type JsonSerializerSettings.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _CJSON_SERIALIZER_SETTINGS_H
#define _CJSON_SERIALIZER_SETTINGS_H
#include <EReferenceLoopHandling.h>
#include <EMissingMemberHandling.h>
#include <EObjectCreationHandling.h>
#include <ENullValueHandling.h>
#include <EDefaultValueHandling.h>
#include <EPreserveReferencesHandling.h>
#include <ETypeNameHandling.h>
#include <EMetadataPropertyHandling.h>
#include <EFormatterAssemblyStyle.h>
#include <ETypeNameAssemblyFormatHandling.h>
#include <EConstructorHandling.h>
#include <ETraceLevel.h>
#include <EFormatting.h>
#include <EDateFormatHandling.h>
#include <EDateTimeZoneHandling.h>
#include <EDateParseHandling.h>
#include <EFloatFormatHandling.h>
#include <EFloatParseHandling.h>
#include <EStringEscapeHandling.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI IList_CJsonConverter;
		class LDAPI CJsonConverter;
		class LDAPI IContractResolver;
		class LDAPI IEqualityComparer;
		class LDAPI IReferenceResolver;
		class LDAPI ITraceWriter;
		class LDAPI CSerializationBinder;
		class LDAPI ISerializationBinder;
		class LDAPI EventHandler_CErrorEventArgs;

		class LDAPI CJsonSerializerSettings
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			CJsonSerializerSettings(const CJsonSerializerSettings& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~CJsonSerializerSettings(void);
			CJsonSerializerSettings(void);
			EReferenceLoopHandling ReferenceLoopHandling(void);
			void ReferenceLoopHandling(EReferenceLoopHandling value);
			EMissingMemberHandling MissingMemberHandling(void);
			void MissingMemberHandling(EMissingMemberHandling value);
			EObjectCreationHandling ObjectCreationHandling(void);
			void ObjectCreationHandling(EObjectCreationHandling value);
			ENullValueHandling NullValueHandling(void);
			void NullValueHandling(ENullValueHandling value);
			EDefaultValueHandling DefaultValueHandling(void);
			void DefaultValueHandling(EDefaultValueHandling value);
			std::shared_ptr<IList_CJsonConverter> Converters(void);
			void Converters(std::shared_ptr<IList_CJsonConverter> value);
			EPreserveReferencesHandling PreserveReferencesHandling(void);
			void PreserveReferencesHandling(EPreserveReferencesHandling value);
			ETypeNameHandling TypeNameHandling(void);
			void TypeNameHandling(ETypeNameHandling value);
			EMetadataPropertyHandling MetadataPropertyHandling(void);
			void MetadataPropertyHandling(EMetadataPropertyHandling value);
			EFormatterAssemblyStyle TypeNameAssemblyFormat(void);
			void TypeNameAssemblyFormat(EFormatterAssemblyStyle value);
			ETypeNameAssemblyFormatHandling TypeNameAssemblyFormatHandling(void);
			void TypeNameAssemblyFormatHandling(ETypeNameAssemblyFormatHandling value);
			EConstructorHandling ConstructorHandling(void);
			void ConstructorHandling(EConstructorHandling value);
			std::shared_ptr<IContractResolver> ContractResolver(void);
			void ContractResolver(std::shared_ptr<IContractResolver> value);
			std::shared_ptr<IEqualityComparer> EqualityComparer(void);
			void EqualityComparer(std::shared_ptr<IEqualityComparer> value);
			std::shared_ptr<IReferenceResolver> ReferenceResolver(void);
			void ReferenceResolver(std::shared_ptr<IReferenceResolver> value);
			std::shared_ptr<ITraceWriter> TraceWriter(void);
			void TraceWriter(std::shared_ptr<ITraceWriter> value);
			std::shared_ptr<CSerializationBinder> Binder(void);
			void Binder(std::shared_ptr<CSerializationBinder> value);
			std::shared_ptr<ISerializationBinder> SerializationBinder(void);
			void SerializationBinder(std::shared_ptr<ISerializationBinder> value);
			std::shared_ptr<EventHandler_CErrorEventArgs> Error(void);
			void Error(std::shared_ptr<EventHandler_CErrorEventArgs> value);
			StringWrapper DateFormatString(void);
			void DateFormatString(StringWrapper value);
			EFormatting Formatting(void);
			void Formatting(EFormatting value);
			EDateFormatHandling DateFormatHandling(void);
			void DateFormatHandling(EDateFormatHandling value);
			EDateTimeZoneHandling DateTimeZoneHandling(void);
			void DateTimeZoneHandling(EDateTimeZoneHandling value);
			EDateParseHandling DateParseHandling(void);
			void DateParseHandling(EDateParseHandling value);
			EFloatFormatHandling FloatFormatHandling(void);
			void FloatFormatHandling(EFloatFormatHandling value);
			EFloatParseHandling FloatParseHandling(void);
			void FloatParseHandling(EFloatParseHandling value);
			EStringEscapeHandling StringEscapeHandling(void);
			void StringEscapeHandling(EStringEscapeHandling value);
			bool CheckAdditionalContent(void);
			void CheckAdditionalContent(bool value);
#ifdef MAKEDLL
		public: // This is for internal use
			CJsonSerializerSettings(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _CJSON_SERIALIZER_SETTINGS_H
