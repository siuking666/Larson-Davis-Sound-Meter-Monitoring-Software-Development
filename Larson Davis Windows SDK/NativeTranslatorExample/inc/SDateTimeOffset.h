/**************************************************************************//**
 * @file SDateTimeOffset.h
 * @brief Native Wrapper for Managed type DateTimeOffset.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _SDATE_TIME_OFFSET_H
#define _SDATE_TIME_OFFSET_H
#include <EDateTimeKind.h>
#include <ETypeCode.h>
#include <EDayOfWeek.h>
namespace LarsonDavis
{
	namespace Native
	{
		struct LDAPI STimeSpan;
		struct LDAPI SDateTime;
		class LDAPI Array_StringWrapper;

		struct LDAPI SDateTimeOffset
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			SDateTimeOffset(const SDateTimeOffset& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~SDateTimeOffset(void);
			SDateTimeOffset(void);
			std::shared_ptr<SDateTimeOffset> ToOffset(std::shared_ptr<STimeSpan> offset);
			std::shared_ptr<SDateTimeOffset> Add(std::shared_ptr<STimeSpan> timeSpan);
			std::shared_ptr<SDateTimeOffset> AddDays(double days);
			std::shared_ptr<SDateTimeOffset> AddHours(double hours);
			std::shared_ptr<SDateTimeOffset> AddMilliseconds(double milliseconds);
			std::shared_ptr<SDateTimeOffset> AddMinutes(double minutes);
			std::shared_ptr<SDateTimeOffset> AddMonths(int32_t months);
			std::shared_ptr<SDateTimeOffset> AddSeconds(double seconds);
			std::shared_ptr<SDateTimeOffset> AddTicks(int64_t ticks);
			std::shared_ptr<SDateTimeOffset> AddYears(int32_t years);
			static int32_t Compare(std::shared_ptr<SDateTimeOffset> first, std::shared_ptr<SDateTimeOffset> second);
			int32_t CompareTo(std::shared_ptr<SDateTimeOffset> other);
			bool EqualsExact(std::shared_ptr<SDateTimeOffset> other);
			static std::shared_ptr<SDateTimeOffset> FromFileTime(int64_t fileTime);
			static std::shared_ptr<SDateTimeOffset> Parse(StringWrapper input);
			std::shared_ptr<STimeSpan> Subtract(std::shared_ptr<SDateTimeOffset> value);
			std::shared_ptr<SDateTimeOffset> Subtract(std::shared_ptr<STimeSpan> value);
			int64_t ToFileTime(void);
			std::shared_ptr<SDateTimeOffset> ToLocalTime(void);
			std::shared_ptr<SDateTimeOffset> ToUniversalTime(void);
			static bool TryParse(StringWrapper input, std::shared_ptr<SDateTimeOffset>& result);
			static std::shared_ptr<SDateTimeOffset> FromUnixTimeSeconds(int64_t seconds);
			static std::shared_ptr<SDateTimeOffset> FromUnixTimeMilliseconds(int64_t milliseconds);
			int64_t ToUnixTimeSeconds(void);
			int64_t ToUnixTimeMilliseconds(void);
			SDateTimeOffset(int64_t ticks, std::shared_ptr<STimeSpan> offset);
			SDateTimeOffset(std::shared_ptr<SDateTime> dateTime);
			SDateTimeOffset(std::shared_ptr<SDateTime> dateTime, std::shared_ptr<STimeSpan> offset);
			SDateTimeOffset(int32_t year, int32_t month, int32_t day, int32_t hour, int32_t minute, int32_t second, std::shared_ptr<STimeSpan> offset);
			SDateTimeOffset(int32_t year, int32_t month, int32_t day, int32_t hour, int32_t minute, int32_t second, int32_t millisecond, std::shared_ptr<STimeSpan> offset);
			static std::shared_ptr<SDateTimeOffset> Now(void);
			static std::shared_ptr<SDateTimeOffset> UtcNow(void);
			std::shared_ptr<SDateTime> DateTime(void);
			std::shared_ptr<SDateTime> UtcDateTime(void);
			std::shared_ptr<SDateTime> LocalDateTime(void);
			std::shared_ptr<SDateTime> Date(void);
			int32_t Day(void);
			EDayOfWeek DayOfWeek(void);
			int32_t DayOfYear(void);
			int32_t Hour(void);
			int32_t Millisecond(void);
			int32_t Minute(void);
			int32_t Month(void);
			std::shared_ptr<STimeSpan> Offset(void);
			int32_t Second(void);
			int64_t Ticks(void);
			int64_t UtcTicks(void);
			std::shared_ptr<STimeSpan> TimeOfDay(void);
			int32_t Year(void);
			static std::shared_ptr<SDateTimeOffset> MinValue(void);
			static std::shared_ptr<SDateTimeOffset> MaxValue(void);
#ifdef MAKEDLL
		public: // This is for internal use
			SDateTimeOffset(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _SDATE_TIME_OFFSET_H
