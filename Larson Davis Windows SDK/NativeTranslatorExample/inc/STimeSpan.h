/**************************************************************************//**
 * @file STimeSpan.h
 * @brief Native Wrapper for Managed type TimeSpan.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _STIME_SPAN_H
#define _STIME_SPAN_H
namespace LarsonDavis
{
	namespace Native
	{

		struct LDAPI STimeSpan
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			STimeSpan(const STimeSpan& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~STimeSpan(void);
			STimeSpan(void);
			std::shared_ptr<STimeSpan> Add(std::shared_ptr<STimeSpan> ts);
			static int32_t Compare(std::shared_ptr<STimeSpan> t1, std::shared_ptr<STimeSpan> t2);
			int32_t CompareTo(std::shared_ptr<STimeSpan> value);
			static std::shared_ptr<STimeSpan> FromDays(double value);
			std::shared_ptr<STimeSpan> Duration(void);
			static std::shared_ptr<STimeSpan> FromHours(double value);
			static std::shared_ptr<STimeSpan> FromMilliseconds(double value);
			static std::shared_ptr<STimeSpan> FromMinutes(double value);
			std::shared_ptr<STimeSpan> Negate(void);
			static std::shared_ptr<STimeSpan> FromSeconds(double value);
			std::shared_ptr<STimeSpan> Subtract(std::shared_ptr<STimeSpan> ts);
			static std::shared_ptr<STimeSpan> FromTicks(int64_t value);
			static std::shared_ptr<STimeSpan> Parse(StringWrapper s);
			static bool TryParse(StringWrapper s, std::shared_ptr<STimeSpan>& result);
			STimeSpan(int64_t ticks);
			STimeSpan(int32_t hours, int32_t minutes, int32_t seconds);
			STimeSpan(int32_t days, int32_t hours, int32_t minutes, int32_t seconds);
			STimeSpan(int32_t days, int32_t hours, int32_t minutes, int32_t seconds, int32_t milliseconds);
			int64_t Ticks(void);
			int32_t Days(void);
			int32_t Hours(void);
			int32_t Milliseconds(void);
			int32_t Minutes(void);
			int32_t Seconds(void);
			double TotalDays(void);
			double TotalHours(void);
			double TotalMilliseconds(void);
			double TotalMinutes(void);
			double TotalSeconds(void);
			static std::shared_ptr<STimeSpan> Zero(void);
			static std::shared_ptr<STimeSpan> MaxValue(void);
			static std::shared_ptr<STimeSpan> MinValue(void);
			static int64_t TicksPerMillisecond(void);
			static int64_t TicksPerSecond(void);
			static int64_t TicksPerMinute(void);
			static int64_t TicksPerHour(void);
			static int64_t TicksPerDay(void);
#ifdef MAKEDLL
		public: // This is for internal use
			STimeSpan(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _STIME_SPAN_H
