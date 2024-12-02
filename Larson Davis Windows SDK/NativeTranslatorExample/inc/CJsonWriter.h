/**************************************************************************//**
 * @file CJsonWriter.h
 * @brief Native Wrapper for Managed type JsonWriter.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _CJSON_WRITER_H
#define _CJSON_WRITER_H
#include <EJsonToken.h>
#include <EWriteState.h>
#include <EFormatting.h>
#include <EDateFormatHandling.h>
#include <EDateTimeZoneHandling.h>
#include <EStringEscapeHandling.h>
#include <EFloatFormatHandling.h>
namespace LarsonDavis
{
	namespace Native
	{
		struct LDAPI SDateTime;
		struct LDAPI SDateTimeOffset;
		struct LDAPI STimeSpan;
		struct LDAPI Nullable_uint32_t;
		struct LDAPI Nullable_int64_t;
		struct LDAPI Nullable_uint64_t;
		struct LDAPI Nullable_float;
		struct LDAPI Nullable_double;
		struct LDAPI Nullable_bool;
		struct LDAPI Nullable_int16_t;
		struct LDAPI Nullable_uint16_t;
		struct LDAPI Nullable_wchar_t;
		struct LDAPI Nullable_uint8_t;
		struct LDAPI Nullable_int8_t;
		struct LDAPI Nullable_SDateTime;
		struct LDAPI Nullable_SDateTimeOffset;
		struct LDAPI Nullable_STimeSpan;
		class LDAPI Array_uint8_t;

		class LDAPI CJsonWriter
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			CJsonWriter(const CJsonWriter& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~CJsonWriter(void);
			void Flush(void);
			void Close(void);
			void WriteStartObject(void);
			void WriteEndObject(void);
			void WriteStartArray(void);
			void WriteEndArray(void);
			void WriteStartConstructor(StringWrapper name);
			void WriteEndConstructor(void);
			void WritePropertyName(StringWrapper name);
			void WritePropertyName(StringWrapper name, bool escape);
			void WriteEnd(void);
			void WriteToken(EJsonToken token);
			void WriteNull(void);
			void WriteUndefined(void);
			void WriteRaw(StringWrapper json);
			void WriteRawValue(StringWrapper json);
			void WriteValue(StringWrapper value);
			void WriteValue(int32_t value);
			void WriteValue(uint32_t value);
			void WriteValue(int64_t value);
			void WriteValue(uint64_t value);
			void WriteValue(float value);
			void WriteValue(double value);
			void WriteValue(bool value);
			void WriteValue(int16_t value);
			void WriteValue(uint16_t value);
			void WriteValue(wchar_t value);
			void WriteValue(uint8_t value);
			void WriteValue(int8_t value);
			void WriteValue(std::shared_ptr<SDateTime> value);
			void WriteValue(std::shared_ptr<SDateTimeOffset> value);
			void WriteValue(std::shared_ptr<STimeSpan> value);
			void WriteValue(std::shared_ptr<Nullable_uint32_t> value);
			void WriteValue(std::shared_ptr<Nullable_int64_t> value);
			void WriteValue(std::shared_ptr<Nullable_uint64_t> value);
			void WriteValue(std::shared_ptr<Nullable_float> value);
			void WriteValue(std::shared_ptr<Nullable_double> value);
			void WriteValue(std::shared_ptr<Nullable_bool> value);
			void WriteValue(std::shared_ptr<Nullable_int16_t> value);
			void WriteValue(std::shared_ptr<Nullable_uint16_t> value);
			void WriteValue(std::shared_ptr<Nullable_wchar_t> value);
			void WriteValue(std::shared_ptr<Nullable_uint8_t> value);
			void WriteValue(std::shared_ptr<Nullable_int8_t> value);
			void WriteValue(std::shared_ptr<Nullable_SDateTime> value);
			void WriteValue(std::shared_ptr<Nullable_SDateTimeOffset> value);
			void WriteValue(std::shared_ptr<Nullable_STimeSpan> value);
			void WriteValue(std::shared_ptr<Array_uint8_t> value);
			void WriteComment(StringWrapper text);
			void WriteWhitespace(StringWrapper ws);
			bool CloseOutput(void);
			void CloseOutput(bool value);
			bool AutoCompleteOnClose(void);
			void AutoCompleteOnClose(bool value);
			EWriteState WriteState(void);
			StringWrapper Path(void);
			EFormatting Formatting(void);
			void Formatting(EFormatting value);
			EDateFormatHandling DateFormatHandling(void);
			void DateFormatHandling(EDateFormatHandling value);
			EDateTimeZoneHandling DateTimeZoneHandling(void);
			void DateTimeZoneHandling(EDateTimeZoneHandling value);
			EStringEscapeHandling StringEscapeHandling(void);
			void StringEscapeHandling(EStringEscapeHandling value);
			EFloatFormatHandling FloatFormatHandling(void);
			void FloatFormatHandling(EFloatFormatHandling value);
			StringWrapper DateFormatString(void);
			void DateFormatString(StringWrapper value);
#ifdef MAKEDLL
		public: // This is for internal use
			CJsonWriter(){};
			CJsonWriter(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _CJSON_WRITER_H
