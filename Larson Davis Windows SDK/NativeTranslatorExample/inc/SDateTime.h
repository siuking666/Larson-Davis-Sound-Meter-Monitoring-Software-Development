/**************************************************************************//**
 * @file SDateTime.h
 * @brief Native Wrapper for Managed type DateTime.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _SDATE_TIME_H
#define _SDATE_TIME_H
#include <IConvertible.h>
#include <EDateTimeKind.h>
#include <ETypeCode.h>
#include <EDayOfWeek.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI IConvertible;
		struct LDAPI STimeSpan;
		class LDAPI Array_StringWrapper;

		struct LDAPI SDateTime : public virtual IConvertible
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			SDateTime(const SDateTime& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~SDateTime(void);
			SDateTime(void);
			std::shared_ptr<SDateTime> Add(std::shared_ptr<STimeSpan> value);
			std::shared_ptr<SDateTime> AddDays(double value);
			std::shared_ptr<SDateTime> AddHours(double value);
			std::shared_ptr<SDateTime> AddMilliseconds(double value);
			std::shared_ptr<SDateTime> AddMinutes(double value);
			std::shared_ptr<SDateTime> AddMonths(int32_t months);
			std::shared_ptr<SDateTime> AddSeconds(double value);
			std::shared_ptr<SDateTime> AddTicks(int64_t value);
			std::shared_ptr<SDateTime> AddYears(int32_t value);
			static int32_t Compare(std::shared_ptr<SDateTime> t1, std::shared_ptr<SDateTime> t2);
			int32_t CompareTo(std::shared_ptr<SDateTime> value);
			static int32_t DaysInMonth(int32_t year, int32_t month);
			static std::shared_ptr<SDateTime> FromBinary(int64_t dateData);
			static std::shared_ptr<SDateTime> FromFileTime(int64_t fileTime);
			static std::shared_ptr<SDateTime> FromFileTimeUtc(int64_t fileTime);
			static std::shared_ptr<SDateTime> FromOADate(double d);
			bool IsDaylightSavingTime(void);
			static std::shared_ptr<SDateTime> SpecifyKind(std::shared_ptr<SDateTime> value, EDateTimeKind kind);
			int64_t ToBinary(void);
			static bool IsLeapYear(int32_t year);
			static std::shared_ptr<SDateTime> Parse(StringWrapper s);
			std::shared_ptr<STimeSpan> Subtract(std::shared_ptr<SDateTime> value);
			std::shared_ptr<SDateTime> Subtract(std::shared_ptr<STimeSpan> value);
			double ToOADate(void);
			int64_t ToFileTime(void);
			int64_t ToFileTimeUtc(void);
			std::shared_ptr<SDateTime> ToLocalTime(void);
			std::shared_ptr<SDateTime> ToUniversalTime(void);
			static bool TryParse(StringWrapper s, std::shared_ptr<SDateTime>& result);
			std::shared_ptr<Array_StringWrapper> GetDateTimeFormats(void);
			std::shared_ptr<Array_StringWrapper> GetDateTimeFormats(wchar_t format);
			ETypeCode GetTypeCode(void);
			StringWrapper ToLongDateString(void);
			StringWrapper ToLongTimeString(void);
			StringWrapper ToShortTimeString(void);
			StringWrapper ToShortDateString(void);
			SDateTime(int64_t ticks);
			SDateTime(int64_t ticks, EDateTimeKind kind);
			SDateTime(int32_t year, int32_t month, int32_t day);
			SDateTime(int32_t year, int32_t month, int32_t day, int32_t hour, int32_t minute, int32_t second);
			SDateTime(int32_t year, int32_t month, int32_t day, int32_t hour, int32_t minute, int32_t second, EDateTimeKind kind);
			SDateTime(int32_t year, int32_t month, int32_t day, int32_t hour, int32_t minute, int32_t second, int32_t millisecond);
			SDateTime(int32_t year, int32_t month, int32_t day, int32_t hour, int32_t minute, int32_t second, int32_t millisecond, EDateTimeKind kind);
			std::shared_ptr<SDateTime> Date(void);
			int32_t Day(void);
			EDayOfWeek DayOfWeek(void);
			int32_t DayOfYear(void);
			int32_t Hour(void);
			EDateTimeKind Kind(void);
			int32_t Millisecond(void);
			int32_t Minute(void);
			int32_t Month(void);
			static std::shared_ptr<SDateTime> Now(void);
			static std::shared_ptr<SDateTime> UtcNow(void);
			int32_t Second(void);
			int64_t Ticks(void);
			std::shared_ptr<STimeSpan> TimeOfDay(void);
			static std::shared_ptr<SDateTime> Today(void);
			int32_t Year(void);
			static std::shared_ptr<SDateTime> MinValue(void);
			static std::shared_ptr<SDateTime> MaxValue(void);
#ifdef MAKEDLL
		public: // This is for internal use
			SDateTime(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _SDATE_TIME_H
