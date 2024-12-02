/**************************************************************************//**
 * @file CEventInfo.h
 * @brief Native Wrapper for Managed type EventInfo.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _CEVENT_INFO_H
#define _CEVENT_INFO_H
#include <ERt60RecType.h>
#include <ERt60Method.h>
#include <ERt60QualityIndicator.h>
#include <ERt60SamplePeriod.h>
#include <ERt60DataPoint.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI Array_float;
		class LDAPI CEventTimeHistoryManager;
		class LDAPI Array_SEventTHRecord_t;
		struct LDAPI SEventTHRecord_t;
		class LDAPI CMeasureRt60;
		struct LDAPI SRt60ByTime_t;
		class LDAPI Array_SRt60TimeSample_t;
		class LDAPI Array_SRt60DataLimits_t;
		struct LDAPI SRt60CalcLines_t;
		struct LDAPI SRt60Record_t;
		struct LDAPI SEventTriggerInfo_t;
		struct LDAPI SEventLevelInfo_t;
		struct LDAPI SEventWeatherInfo_t;

		class LDAPI CEventInfo
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			CEventInfo(const CEventInfo& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~CEventInfo(void);
			CEventInfo(void);
			int64_t StartTime(void);
			void StartTime(int64_t value);
			int64_t MaxSPLTime(void);
			void MaxSPLTime(int64_t value);
			int32_t Id(void);
			void Id(int32_t value);
			uint32_t SRNumber(void);
			void SRNumber(uint32_t value);
			uint32_t THIndex(void);
			void THIndex(uint32_t value);
			uint32_t ExcTHIndex(void);
			void ExcTHIndex(uint32_t value);
			uint32_t NumTHSamples(void);
			void NumTHSamples(uint32_t value);
			uint32_t NumPreTrigTHSamples(void);
			void NumPreTrigTHSamples(uint32_t value);
			uint32_t NumPostTrigTHSamples(void);
			void NumPostTrigTHSamples(uint32_t value);
			float Duration(void);
			void Duration(float value);
			float Leq(void);
			void Leq(float value);
			float MaxSPL(void);
			void MaxSPL(float value);
			float PeakMax(void);
			void PeakMax(float value);
			float TrigLevel(void);
			void TrigLevel(float value);
			std::shared_ptr<Array_float> FullOctaveLeq(void);
			void FullOctaveLeq(std::shared_ptr<Array_float> value);
			std::shared_ptr<Array_float> FullOctaveLMax(void);
			void FullOctaveLMax(std::shared_ptr<Array_float> value);
			std::shared_ptr<Array_float> ThirdOctaveLeq(void);
			void ThirdOctaveLeq(std::shared_ptr<Array_float> value);
			std::shared_ptr<Array_float> ThirdOctaveLMax(void);
			void ThirdOctaveLMax(std::shared_ptr<Array_float> value);
			bool ObaOverLoad(void);
			void ObaOverLoad(bool value);
			bool OverLoad(void);
			void OverLoad(bool value);
			bool THOverLoad(void);
			void THOverLoad(bool value);
			bool ObaTHOverLoad(void);
			void ObaTHOverLoad(bool value);
			std::shared_ptr<CEventTimeHistoryManager> ETHData(void);
			void ETHData(std::shared_ptr<CEventTimeHistoryManager> value);
			std::shared_ptr<CMeasureRt60> T2(void);
			void T2(std::shared_ptr<CMeasureRt60> value);
			int32_t EventRecordVersion(void);
			void EventRecordVersion(int32_t value);
			uint32_t StartTimeMicro(void);
			void StartTimeMicro(uint32_t value);
			uint32_t MaxSPLTimeMicro(void);
			void MaxSPLTimeMicro(uint32_t value);
			std::shared_ptr<SEventTriggerInfo_t> EventTriggerInfo(void);
			void EventTriggerInfo(std::shared_ptr<SEventTriggerInfo_t> value);
			std::shared_ptr<SEventLevelInfo_t> EventLevelInfo(void);
			void EventLevelInfo(std::shared_ptr<SEventLevelInfo_t> value);
			std::shared_ptr<SEventWeatherInfo_t> EventWeatherInfo(void);
			void EventWeatherInfo(std::shared_ptr<SEventWeatherInfo_t> value);
			int32_t TriggerSource(void);
			void TriggerSource(int32_t value);
			float TriggerLevel(void);
			void TriggerLevel(float value);
			float LAeq(void);
			void LAeq(float value);
			float LAmax(void);
			void LAmax(float value);
			float LApeak(void);
			void LApeak(float value);
			float LCeq(void);
			void LCeq(float value);
			float LCmax(void);
			void LCmax(float value);
			float LCpeak(void);
			void LCpeak(float value);
			float LZeq(void);
			void LZeq(float value);
			float LZmax(void);
			void LZmax(float value);
			float LZpeak(void);
			void LZpeak(float value);
			float LMaxWindSpeed(void);
			void LMaxWindSpeed(float value);
			float LMaxWindDir(void);
			void LMaxWindDir(float value);
			float MaxWindSpeed(void);
			void MaxWindSpeed(float value);
			float MaxWindDir(void);
			void MaxWindDir(float value);
#ifdef MAKEDLL
		public: // This is for internal use
			CEventInfo(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _CEVENT_INFO_H
