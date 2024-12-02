/**************************************************************************//**
 * @file SMeasSettingsSpartan_t.h
 * @brief Native Wrapper for Managed type MeasSettingsSpartan_t.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _SMEAS_SETTINGS_SPARTAN_T_H
#define _SMEAS_SETTINGS_SPARTAN_T_H
#include <ISupportByteArrayConversion.h>
#include <EFreqWeighting_t.h>
#include <EDetectorSelect_t.h>
#include <EPeakWeighting_t.h>
#include <EPropOnOff_t.h>
#include <EDoseMode_t.h>
#include <EExchangeRateId_t.h>
#include <EDosAlarmSrc_t.h>
#include <EPropObaSetting_t.h>
#include <ETimerMode_t.h>
#include <EContModeInterval_t.h>
#include <EMinMaxSelect_t.h>
#include <ETimeHistoryMetricFlags.h>
#include <ETimeHistoryMetricFlags_B2.h>
#include <ETimeHistoryMetricFlags_B3.h>
#include <ETimeHistoryMetricFlags_B4.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI ISupportByteArrayConversion;
		struct LDAPI SString16_t;
		struct LDAPI SString64_t;

		struct LDAPI SMeasSettingsSpartan_t : public virtual ISupportByteArrayConversion
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			SMeasSettingsSpartan_t(const SMeasSettingsSpartan_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~SMeasSettingsSpartan_t(void);
			SMeasSettingsSpartan_t(void);
			EFreqWeighting_t FrequencyWeighting(void);
			void FrequencyWeighting(EFreqWeighting_t value);
			EDetectorSelect_t TimeWeighting(void);
			void TimeWeighting(EDetectorSelect_t value);
			EPeakWeighting_t PeakWeighting(void);
			void PeakWeighting(EPeakWeighting_t value);
			EPropOnOff_t Dos1Enable(void);
			void Dos1Enable(EPropOnOff_t value);
			int32_t Dos1ConfigSelect(void);
			void Dos1ConfigSelect(int32_t value);
			EDoseMode_t Dos1Mode(void);
			void Dos1Mode(EDoseMode_t value);
			std::shared_ptr<SString16_t> Dos1Title(void);
			void Dos1Title(std::shared_ptr<SString16_t> value);
			EFreqWeighting_t Dos1FrequencyWeighting(void);
			void Dos1FrequencyWeighting(EFreqWeighting_t value);
			EDetectorSelect_t Dos1TimeWeighting(void);
			void Dos1TimeWeighting(EDetectorSelect_t value);
			EPeakWeighting_t Dos1PeakWeighting(void);
			void Dos1PeakWeighting(EPeakWeighting_t value);
			EExchangeRateId_t Dos1ExchangeRate(void);
			void Dos1ExchangeRate(EExchangeRateId_t value);
			EPropOnOff_t Dos1ThresholdEnable(void);
			void Dos1ThresholdEnable(EPropOnOff_t value);
			float Dos1ThresholdLevel(void);
			void Dos1ThresholdLevel(float value);
			float Dos1CriterionLevel(void);
			void Dos1CriterionLevel(float value);
			int32_t Dos1CriterionTime(void);
			void Dos1CriterionTime(int32_t value);
			float Dos1ShiftTime(void);
			void Dos1ShiftTime(float value);
			EPropOnOff_t Dos2Enable(void);
			void Dos2Enable(EPropOnOff_t value);
			int32_t Dos2ConfigSelect(void);
			void Dos2ConfigSelect(int32_t value);
			EDoseMode_t Dos2Mode(void);
			void Dos2Mode(EDoseMode_t value);
			std::shared_ptr<SString16_t> Dos2Title(void);
			void Dos2Title(std::shared_ptr<SString16_t> value);
			EFreqWeighting_t Dos2FrequencyWeighting(void);
			void Dos2FrequencyWeighting(EFreqWeighting_t value);
			EDetectorSelect_t Dos2TimeWeighting(void);
			void Dos2TimeWeighting(EDetectorSelect_t value);
			EPeakWeighting_t Dos2PeakWeighting(void);
			void Dos2PeakWeighting(EPeakWeighting_t value);
			EExchangeRateId_t Dos2ExchangeRate(void);
			void Dos2ExchangeRate(EExchangeRateId_t value);
			EPropOnOff_t Dos2ThresholdEnable(void);
			void Dos2ThresholdEnable(EPropOnOff_t value);
			float Dos2ThresholdLevel(void);
			void Dos2ThresholdLevel(float value);
			float Dos2CriterionLevel(void);
			void Dos2CriterionLevel(float value);
			int32_t Dos2CriterionTime(void);
			void Dos2CriterionTime(int32_t value);
			float Dos2ShiftTime(void);
			void Dos2ShiftTime(float value);
			EPropOnOff_t Dos3Enable(void);
			void Dos3Enable(EPropOnOff_t value);
			int32_t Dos3ConfigSelect(void);
			void Dos3ConfigSelect(int32_t value);
			EDoseMode_t Dos3Mode(void);
			void Dos3Mode(EDoseMode_t value);
			std::shared_ptr<SString16_t> Dos3Title(void);
			void Dos3Title(std::shared_ptr<SString16_t> value);
			EFreqWeighting_t Dos3FrequencyWeighting(void);
			void Dos3FrequencyWeighting(EFreqWeighting_t value);
			EDetectorSelect_t Dos3TimeWeighting(void);
			void Dos3TimeWeighting(EDetectorSelect_t value);
			EPeakWeighting_t Dos3PeakWeighting(void);
			void Dos3PeakWeighting(EPeakWeighting_t value);
			EExchangeRateId_t Dos3ExchangeRate(void);
			void Dos3ExchangeRate(EExchangeRateId_t value);
			EPropOnOff_t Dos3ThresholdEnable(void);
			void Dos3ThresholdEnable(EPropOnOff_t value);
			float Dos3ThresholdLevel(void);
			void Dos3ThresholdLevel(float value);
			float Dos3CriterionLevel(void);
			void Dos3CriterionLevel(float value);
			int32_t Dos3CriterionTime(void);
			void Dos3CriterionTime(int32_t value);
			float Dos3ShiftTime(void);
			void Dos3ShiftTime(float value);
			EPropOnOff_t Dos4Enable(void);
			void Dos4Enable(EPropOnOff_t value);
			int32_t Dos4ConfigSelect(void);
			void Dos4ConfigSelect(int32_t value);
			EDoseMode_t Dos4Mode(void);
			void Dos4Mode(EDoseMode_t value);
			std::shared_ptr<SString16_t> Dos4Title(void);
			void Dos4Title(std::shared_ptr<SString16_t> value);
			EFreqWeighting_t Dos4FrequencyWeighting(void);
			void Dos4FrequencyWeighting(EFreqWeighting_t value);
			EDetectorSelect_t Dos4TimeWeighting(void);
			void Dos4TimeWeighting(EDetectorSelect_t value);
			EPeakWeighting_t Dos4PeakWeighting(void);
			void Dos4PeakWeighting(EPeakWeighting_t value);
			EExchangeRateId_t Dos4ExchangeRate(void);
			void Dos4ExchangeRate(EExchangeRateId_t value);
			EPropOnOff_t Dos4ThresholdEnable(void);
			void Dos4ThresholdEnable(EPropOnOff_t value);
			float Dos4ThresholdLevel(void);
			void Dos4ThresholdLevel(float value);
			float Dos4CriterionLevel(void);
			void Dos4CriterionLevel(float value);
			int32_t Dos4CriterionTime(void);
			void Dos4CriterionTime(int32_t value);
			float Dos4ShiftTime(void);
			void Dos4ShiftTime(float value);
			EPropOnOff_t Alarm1Enable(void);
			void Alarm1Enable(EPropOnOff_t value);
			EPropOnOff_t Alarm1LEDIndicator(void);
			void Alarm1LEDIndicator(EPropOnOff_t value);
			EDosAlarmSrc_t Alarm1Source(void);
			void Alarm1Source(EDosAlarmSrc_t value);
			float Alarm1ActionLevel(void);
			void Alarm1ActionLevel(float value);
			float Alarm1LimitLevel(void);
			void Alarm1LimitLevel(float value);
			EPropOnOff_t Alarm2Enable(void);
			void Alarm2Enable(EPropOnOff_t value);
			EPropOnOff_t Alarm2LEDIndicator(void);
			void Alarm2LEDIndicator(EPropOnOff_t value);
			EDosAlarmSrc_t Alarm2Source(void);
			void Alarm2Source(EDosAlarmSrc_t value);
			float Alarm2ActionLevel(void);
			void Alarm2ActionLevel(float value);
			float Alarm2_LimitLevel(void);
			void Alarm2_LimitLevel(float value);
			EPropOnOff_t TimeHistoryEnable(void);
			void TimeHistoryEnable(EPropOnOff_t value);
			int32_t TimeHistoryPeriod(void);
			void TimeHistoryPeriod(int32_t value);
			uint32_t TimeHistoryFlags(void);
			void TimeHistoryFlags(uint32_t value);
			EPropObaSetting_t OBAEnable(void);
			void OBAEnable(EPropObaSetting_t value);
			EFreqWeighting_t OBAFreqWeight(void);
			void OBAFreqWeight(EFreqWeighting_t value);
			EPropOnOff_t EventSoundRecEnable(void);
			void EventSoundRecEnable(EPropOnOff_t value);
			uint32_t SoundRecTrigSrc(void);
			void SoundRecTrigSrc(uint32_t value);
			float SoundRecTrigLvl(void);
			void SoundRecTrigLvl(float value);
			uint32_t SoundRecMinInterval(void);
			void SoundRecMinInterval(uint32_t value);
			uint32_t SoundRecEventPeriod(void);
			void SoundRecEventPeriod(uint32_t value);
			uint32_t SoundRecPreEventPeriod(void);
			void SoundRecPreEventPeriod(uint32_t value);
			float SPL1(void);
			void SPL1(float value);
			float SPL2(void);
			void SPL2(float value);
			float Peak1(void);
			void Peak1(float value);
			float Peak2(void);
			void Peak2(float value);
			float Peak3(void);
			void Peak3(float value);
			EPropOnOff_t AutoCalEnable(void);
			void AutoCalEnable(EPropOnOff_t value);
			ETimerMode_t TimerMode(void);
			void TimerMode(ETimerMode_t value);
			uint32_t TimerStartDate(void);
			void TimerStartDate(uint32_t value);
			uint32_t TimerStopDate(void);
			void TimerStopDate(uint32_t value);
			int32_t Timer1StartTime(void);
			void Timer1StartTime(int32_t value);
			int32_t Timer1StopTime(void);
			void Timer1StopTime(int32_t value);
			EPropOnOff_t Timer2Enable(void);
			void Timer2Enable(EPropOnOff_t value);
			int32_t Timer2StartTime(void);
			void Timer2StartTime(int32_t value);
			int32_t Timer2StopTime(void);
			void Timer2StopTime(int32_t value);
			EPropOnOff_t Timer3Enable(void);
			void Timer3Enable(EPropOnOff_t value);
			int32_t Timer3StartTime(void);
			void Timer3StartTime(int32_t value);
			int32_t Timer3StopTime(void);
			void Timer3StopTime(int32_t value);
			int32_t TimedStopDuration(void);
			void TimedStopDuration(int32_t value);
			EPropOnOff_t DailyTimerMerge(void);
			void DailyTimerMerge(EPropOnOff_t value);
			EContModeInterval_t ContModeInterval(void);
			void ContModeInterval(EContModeInterval_t value);
			int32_t DayTime(void);
			void DayTime(int32_t value);
			int32_t EveningTime(void);
			void EveningTime(int32_t value);
			float EveningPenalty(void);
			void EveningPenalty(float value);
			int32_t NightTime(void);
			void NightTime(int32_t value);
			float NightPenalty(void);
			void NightPenalty(float value);
			EPropOnOff_t LNEnable(void);
			void LNEnable(EPropOnOff_t value);
			float LNPerc1(void);
			void LNPerc1(float value);
			float LNPerc2(void);
			void LNPerc2(float value);
			float LNPerc3(void);
			void LNPerc3(float value);
			float LNPerc4(void);
			void LNPerc4(float value);
			float LNPerc5(void);
			void LNPerc5(float value);
			float LNPerc6(void);
			void LNPerc6(float value);
			EFreqWeighting_t LNFrequencyWeighting(void);
			void LNFrequencyWeighting(EFreqWeighting_t value);
			EDetectorSelect_t LNTimeWeighting(void);
			void LNTimeWeighting(EDetectorSelect_t value);
			bool MeasHistEnable(void);
			void MeasHistEnable(bool value);
			int32_t MeasHistInterval(void);
			void MeasHistInterval(int32_t value);
			bool GainEnable(void);
			void GainEnable(bool value);
			EPropOnOff_t TimeHistOBAEnable(void);
			void TimeHistOBAEnable(EPropOnOff_t value);
			std::shared_ptr<SString64_t> Marker1(void);
			void Marker1(std::shared_ptr<SString64_t> value);
			std::shared_ptr<SString64_t> Marker2(void);
			void Marker2(std::shared_ptr<SString64_t> value);
			std::shared_ptr<SString64_t> Marker3(void);
			void Marker3(std::shared_ptr<SString64_t> value);
			std::shared_ptr<SString64_t> Marker4(void);
			void Marker4(std::shared_ptr<SString64_t> value);
			std::shared_ptr<SString64_t> Marker5(void);
			void Marker5(std::shared_ptr<SString64_t> value);
			std::shared_ptr<SString64_t> Marker6(void);
			void Marker6(std::shared_ptr<SString64_t> value);
			std::shared_ptr<SString64_t> Marker7(void);
			void Marker7(std::shared_ptr<SString64_t> value);
			std::shared_ptr<SString64_t> Marker8(void);
			void Marker8(std::shared_ptr<SString64_t> value);
			std::shared_ptr<SString64_t> Marker9(void);
			void Marker9(std::shared_ptr<SString64_t> value);
			std::shared_ptr<SString64_t> Marker10(void);
			void Marker10(std::shared_ptr<SString64_t> value);
			EPropOnOff_t TimeHistPwrEnable(void);
			void TimeHistPwrEnable(EPropOnOff_t value);
			EDetectorSelect_t OBATimeWeight(void);
			void OBATimeWeight(EDetectorSelect_t value);
			EMinMaxSelect_t TimeHistMinMax(void);
			void TimeHistMinMax(EMinMaxSelect_t value);
			ETimeHistoryMetricFlags TimeHistFlags1(void);
			void TimeHistFlags1(ETimeHistoryMetricFlags value);
			ETimeHistoryMetricFlags_B2 TimeHistFlags2(void);
			void TimeHistFlags2(ETimeHistoryMetricFlags_B2 value);
			ETimeHistoryMetricFlags_B3 TimeHistFlags3(void);
			void TimeHistFlags3(ETimeHistoryMetricFlags_B3 value);
			ETimeHistoryMetricFlags_B4 TimeHistFlags4(void);
			void TimeHistFlags4(ETimeHistoryMetricFlags_B4 value);
#ifdef MAKEDLL
		public: // This is for internal use
			SMeasSettingsSpartan_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _SMEAS_SETTINGS_SPARTAN_T_H
