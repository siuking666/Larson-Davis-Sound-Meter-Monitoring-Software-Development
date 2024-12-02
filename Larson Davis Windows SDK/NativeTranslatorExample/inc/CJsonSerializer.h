/**************************************************************************//**
 * @file CJsonSerializer.h
 * @brief Native Wrapper for Managed type JsonSerializer.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _CJSON_SERIALIZER_H
#define _CJSON_SERIALIZER_H
#include <ETraceLevel.h>
#include <ETypeNameHandling.h>
#include <EFormatterAssemblyStyle.h>
#include <ETypeNameAssemblyFormatHandling.h>
#include <EPreserveReferencesHandling.h>
#include <EReferenceLoopHandling.h>
#include <EMissingMemberHandling.h>
#include <ENullValueHandling.h>
#include <EDefaultValueHandling.h>
#include <EObjectCreationHandling.h>
#include <EConstructorHandling.h>
#include <EMetadataPropertyHandling.h>
#include <EFormatting.h>
#include <EDateFormatHandling.h>
#include <EDateTimeZoneHandling.h>
#include <EDateParseHandling.h>
#include <EFloatParseHandling.h>
#include <EFloatFormatHandling.h>
#include <EStringEscapeHandling.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI CJsonSerializerSettings;
		class LDAPI IReferenceResolver;
		class LDAPI CSerializationBinder;
		class LDAPI ISerializationBinder;
		class LDAPI ITraceWriter;
		class LDAPI IEqualityComparer;
		class LDAPI CJsonConverterCollection;
		class LDAPI IContractResolver;

		class LDAPI CJsonSerializer
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			CJsonSerializer(const CJsonSerializer& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~CJsonSerializer(void);
			static std::shared_ptr<CJsonSerializer> Create(void);
			static std::shared_ptr<CJsonSerializer> Create(std::shared_ptr<CJsonSerializerSettings> settings);
			static std::shared_ptr<CJsonSerializer> CreateDefault(void);
			static std::shared_ptr<CJsonSerializer> CreateDefault(std::shared_ptr<CJsonSerializerSettings> settings);
			CJsonSerializer(void);
			std::shared_ptr<IReferenceResolver> ReferenceResolver(void);
			void ReferenceResolver(std::shared_ptr<IReferenceResolver> value);
			std::shared_ptr<CSerializationBinder> Binder(void);
			void Binder(std::shared_ptr<CSerializationBinder> value);
			std::shared_ptr<ISerializationBinder> SerializationBinder(void);
			void SerializationBinder(std::shared_ptr<ISerializationBinder> value);
			std::shared_ptr<ITraceWriter> TraceWriter(void);
			void TraceWriter(std::shared_ptr<ITraceWriter> value);
			std::shared_ptr<IEqualityComparer> EqualityComparer(void);
			void EqualityComparer(std::shared_ptr<IEqualityComparer> value);
			ETypeNameHandling TypeNameHandling(void);
			void TypeNameHandling(ETypeNameHandling value);
			EFormatterAssemblyStyle TypeNameAssemblyFormat(void);
			void TypeNameAssemblyFormat(EFormatterAssemblyStyle value);
			ETypeNameAssemblyFormatHandling TypeNameAssemblyFormatHandling(void);
			void TypeNameAssemblyFormatHandling(ETypeNameAssemblyFormatHandling value);
			EPreserveReferencesHandling PreserveReferencesHandling(void);
			void PreserveReferencesHandling(EPreserveReferencesHandling value);
			EReferenceLoopHandling ReferenceLoopHandling(void);
			void ReferenceLoopHandling(EReferenceLoopHandling value);
			EMissingMemberHandling MissingMemberHandling(void);
			void MissingMemberHandling(EMissingMemberHandling value);
			ENullValueHandling NullValueHandling(void);
			void NullValueHandling(ENullValueHandling value);
			EDefaultValueHandling DefaultValueHandling(void);
			void DefaultValueHandling(EDefaultValueHandling value);
			EObjectCreationHandling ObjectCreationHandling(void);
			void ObjectCreationHandling(EObjectCreationHandling value);
			EConstructorHandling ConstructorHandling(void);
			void ConstructorHandling(EConstructorHandling value);
			EMetadataPropertyHandling MetadataPropertyHandling(void);
			void MetadataPropertyHandling(EMetadataPropertyHandling value);
			std::shared_ptr<CJsonConverterCollection> Converters(void);
			std::shared_ptr<IContractResolver> ContractResolver(void);
			void ContractResolver(std::shared_ptr<IContractResolver> value);
			EFormatting Formatting(void);
			void Formatting(EFormatting value);
			EDateFormatHandling DateFormatHandling(void);
			void DateFormatHandling(EDateFormatHandling value);
			EDateTimeZoneHandling DateTimeZoneHandling(void);
			void DateTimeZoneHandling(EDateTimeZoneHandling value);
			EDateParseHandling DateParseHandling(void);
			void DateParseHandling(EDateParseHandling value);
			EFloatParseHandling FloatParseHandling(void);
			void FloatParseHandling(EFloatParseHandling value);
			EFloatFormatHandling FloatFormatHandling(void);
			void FloatFormatHandling(EFloatFormatHandling value);
			EStringEscapeHandling StringEscapeHandling(void);
			void StringEscapeHandling(EStringEscapeHandling value);
			StringWrapper DateFormatString(void);
			void DateFormatString(StringWrapper value);
			bool CheckAdditionalContent(void);
			void CheckAdditionalContent(bool value);
#ifdef MAKEDLL
		public: // This is for internal use
			CJsonSerializer(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _CJSON_SERIALIZER_H
