/**************************************************************************//**
 * @file SMeasControls_t.h
 * @brief Native Wrapper for Managed type MeasControls_t.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _SMEAS_CONTROLS_T_H
#define _SMEAS_CONTROLS_T_H
#include <ISupportByteArrayConversion.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI ISupportByteArrayConversion;
		struct LDAPI Sset_UnsignedInt;
		struct LDAPI Sset_String;
		struct LDAPI Sset_Enum;
		struct LDAPI Sset_Float;
		class LDAPI Array_Sset_String;
		class LDAPI Array_Sset_Enum;
		struct LDAPI Sset_Int;
		struct LDAPI Sset_TableFloatsLNS;
		class LDAPI Array_Sset_Float;
		class LDAPI Array_Sset_EnumFloats;

		struct LDAPI SMeasControls_t : public virtual ISupportByteArrayConversion
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			SMeasControls_t(const SMeasControls_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~SMeasControls_t(void);
			SMeasControls_t(void);
			std::shared_ptr<Sset_UnsignedInt> AlarmDateTime(void);
			void AlarmDateTime(std::shared_ptr<Sset_UnsignedInt> value);
			std::shared_ptr<Sset_String> OverallTitle(void);
			void OverallTitle(std::shared_ptr<Sset_String> value);
			std::shared_ptr<Sset_UnsignedInt> StableTimer(void);
			void StableTimer(std::shared_ptr<Sset_UnsignedInt> value);
			std::shared_ptr<Sset_UnsignedInt> RunTimer(void);
			void RunTimer(std::shared_ptr<Sset_UnsignedInt> value);
			std::shared_ptr<Sset_Enum> RunMode(void);
			void RunMode(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_Float> StableDB(void);
			void StableDB(std::shared_ptr<Sset_Float> value);
			std::shared_ptr<Sset_Enum> MeasurementHistoryEnable(void);
			void MeasurementHistoryEnable(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_UnsignedInt> MeasurementCounter(void);
			void MeasurementCounter(std::shared_ptr<Sset_UnsignedInt> value);
			std::shared_ptr<Sset_UnsignedInt> IntervalTime(void);
			void IntervalTime(std::shared_ptr<Sset_UnsignedInt> value);
			std::shared_ptr<Sset_Enum> ClockSync(void);
			void ClockSync(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_Enum> DailyAutoStore(void);
			void DailyAutoStore(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_UnsignedInt> AutoStoreTime(void);
			void AutoStoreTime(std::shared_ptr<Sset_UnsignedInt> value);
			std::shared_ptr<Sset_Enum> AutoCalCheck(void);
			void AutoCalCheck(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_UnsignedInt> AutoCalCheckTime(void);
			void AutoCalCheckTime(std::shared_ptr<Sset_UnsignedInt> value);
			std::shared_ptr<Sset_UnsignedInt> StartDate(void);
			void StartDate(std::shared_ptr<Sset_UnsignedInt> value);
			std::shared_ptr<Sset_UnsignedInt> EndDate(void);
			void EndDate(std::shared_ptr<Sset_UnsignedInt> value);
			std::shared_ptr<Sset_UnsignedInt> RunTime1(void);
			void RunTime1(std::shared_ptr<Sset_UnsignedInt> value);
			std::shared_ptr<Sset_UnsignedInt> StopTime1(void);
			void StopTime1(std::shared_ptr<Sset_UnsignedInt> value);
			std::shared_ptr<Sset_Enum> EnableTimer2(void);
			void EnableTimer2(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_UnsignedInt> RunTime2(void);
			void RunTime2(std::shared_ptr<Sset_UnsignedInt> value);
			std::shared_ptr<Sset_UnsignedInt> StopTime2(void);
			void StopTime2(std::shared_ptr<Sset_UnsignedInt> value);
			std::shared_ptr<Sset_Enum> EnableTimer3(void);
			void EnableTimer3(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_UnsignedInt> RunTime3(void);
			void RunTime3(std::shared_ptr<Sset_UnsignedInt> value);
			std::shared_ptr<Sset_UnsignedInt> StopTime3(void);
			void StopTime3(std::shared_ptr<Sset_UnsignedInt> value);
			std::shared_ptr<Sset_Enum> LnTableEnable(void);
			void LnTableEnable(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_Enum> TimeHistoryEnable(void);
			void TimeHistoryEnable(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_Enum> TimeHistoryPeriod(void);
			void TimeHistoryPeriod(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_UnsignedInt> TimeHistoryOptions1(void);
			void TimeHistoryOptions1(std::shared_ptr<Sset_UnsignedInt> value);
			std::shared_ptr<Sset_UnsignedInt> TimeHistoryOptions2(void);
			void TimeHistoryOptions2(std::shared_ptr<Sset_UnsignedInt> value);
			std::shared_ptr<Sset_Enum> StreamHistoryPeriod(void);
			void StreamHistoryPeriod(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_UnsignedInt> StreamHistoryOptions(void);
			void StreamHistoryOptions(std::shared_ptr<Sset_UnsignedInt> value);
			std::shared_ptr<Sset_Enum> ExceedanceHistoryEnable(void);
			void ExceedanceHistoryEnable(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_Enum> ExceedanceTimeHistoryEnable(void);
			void ExceedanceTimeHistoryEnable(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_Enum> ExceedanceSpectralTimeHistoryEnable(void);
			void ExceedanceSpectralTimeHistoryEnable(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_Float> MinimumDuration(void);
			void MinimumDuration(std::shared_ptr<Sset_Float> value);
			std::shared_ptr<Sset_Enum> TriggerMethod(void);
			void TriggerMethod(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_UnsignedInt> ContinuationPeriod(void);
			void ContinuationPeriod(std::shared_ptr<Sset_UnsignedInt> value);
			std::shared_ptr<Sset_Enum> ExceedanceTimeHistoryPeriod(void);
			void ExceedanceTimeHistoryPeriod(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Array_Sset_String> MarkerNames(void);
			void MarkerNames(std::shared_ptr<Array_Sset_String> value);
			std::shared_ptr<Array_Sset_Enum> MarkerAudioRecord(void);
			void MarkerAudioRecord(std::shared_ptr<Array_Sset_Enum> value);
			std::shared_ptr<Sset_UnsignedInt> MarkerRecordPeriod(void);
			void MarkerRecordPeriod(std::shared_ptr<Sset_UnsignedInt> value);
			std::shared_ptr<Sset_UnsignedInt> MarkerPreRecordPeriod(void);
			void MarkerPreRecordPeriod(std::shared_ptr<Sset_UnsignedInt> value);
			std::shared_ptr<Sset_UnsignedInt> DayTime(void);
			void DayTime(std::shared_ptr<Sset_UnsignedInt> value);
			std::shared_ptr<Sset_UnsignedInt> EveningTime(void);
			void EveningTime(std::shared_ptr<Sset_UnsignedInt> value);
			std::shared_ptr<Sset_UnsignedInt> NightTime(void);
			void NightTime(std::shared_ptr<Sset_UnsignedInt> value);
			std::shared_ptr<Sset_Float> EveningPenalty(void);
			void EveningPenalty(std::shared_ptr<Sset_Float> value);
			std::shared_ptr<Sset_Float> NightPenalty(void);
			void NightPenalty(std::shared_ptr<Sset_Float> value);
			std::shared_ptr<Sset_Enum> SaveExcdAudioSnapshot(void);
			void SaveExcdAudioSnapshot(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_UnsignedInt> ExcdAudioSnapshotPeriod(void);
			void ExcdAudioSnapshotPeriod(std::shared_ptr<Sset_UnsignedInt> value);
			std::shared_ptr<Sset_UnsignedInt> ExcdAudioSnapshotPreTriggerPeriod(void);
			void ExcdAudioSnapshotPreTriggerPeriod(std::shared_ptr<Sset_UnsignedInt> value);
			std::shared_ptr<Sset_Enum> SaveMsmtAudioSnapshot(void);
			void SaveMsmtAudioSnapshot(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_UnsignedInt> MsmtAudioSnapshotPeriod(void);
			void MsmtAudioSnapshotPeriod(std::shared_ptr<Sset_UnsignedInt> value);
			std::shared_ptr<Sset_Enum> AudioCompression(void);
			void AudioCompression(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_String> DefaultFileName(void);
			void DefaultFileName(std::shared_ptr<Sset_String> value);
			std::shared_ptr<Sset_Enum> SlmFrequencyWeighting(void);
			void SlmFrequencyWeighting(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_Enum> SlmPeakFrequencyWeighting(void);
			void SlmPeakFrequencyWeighting(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_Enum> SlmDetector(void);
			void SlmDetector(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_Enum> SlmGain(void);
			void SlmGain(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_Enum> IntegrationInput(void);
			void IntegrationInput(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_Int> HistPeriod(void);
			void HistPeriod(std::shared_ptr<Sset_Int> value);
			std::shared_ptr<Sset_TableFloatsLNS> Percentiles(void);
			void Percentiles(std::shared_ptr<Sset_TableFloatsLNS> value);
			std::shared_ptr<Sset_Enum> ObaRange(void);
			void ObaRange(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_Enum> ObaBandwidth(void);
			void ObaBandwidth(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_Enum> ObaMaxSpectrumMode(void);
			void ObaMaxSpectrumMode(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_Enum> ObaWeighting(void);
			void ObaWeighting(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Array_Sset_String> DoseName(void);
			void DoseName(std::shared_ptr<Array_Sset_String> value);
			std::shared_ptr<Array_Sset_Float> DoseThreshold(void);
			void DoseThreshold(std::shared_ptr<Array_Sset_Float> value);
			std::shared_ptr<Array_Sset_Enum> DoseThresholdEnable(void);
			void DoseThresholdEnable(std::shared_ptr<Array_Sset_Enum> value);
			std::shared_ptr<Array_Sset_EnumFloats> DoseExRate(void);
			void DoseExRate(std::shared_ptr<Array_Sset_EnumFloats> value);
			std::shared_ptr<Array_Sset_Float> DoseCriterionLevel(void);
			void DoseCriterionLevel(std::shared_ptr<Array_Sset_Float> value);
			std::shared_ptr<Array_Sset_Float> DoseCriterionTime(void);
			void DoseCriterionTime(std::shared_ptr<Array_Sset_Float> value);
			std::shared_ptr<Array_Sset_Enum> EventWeighting(void);
			void EventWeighting(std::shared_ptr<Array_Sset_Enum> value);
			std::shared_ptr<Array_Sset_Enum> EventDetector(void);
			void EventDetector(std::shared_ptr<Array_Sset_Enum> value);
			std::shared_ptr<Array_Sset_Float> EventLevel(void);
			void EventLevel(std::shared_ptr<Array_Sset_Float> value);
			std::shared_ptr<Sset_Float> DynamicTriggerOffsetLevel(void);
			void DynamicTriggerOffsetLevel(std::shared_ptr<Sset_Float> value);
			std::shared_ptr<Sset_Int> DynamicResponse(void);
			void DynamicResponse(std::shared_ptr<Sset_Int> value);
			std::shared_ptr<Sset_Float> WindScale(void);
			void WindScale(std::shared_ptr<Sset_Float> value);
			std::shared_ptr<Sset_String> WindUnits(void);
			void WindUnits(std::shared_ptr<Sset_String> value);
			std::shared_ptr<Sset_Enum> WindDirection(void);
			void WindDirection(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_Float> WindThreshold(void);
			void WindThreshold(std::shared_ptr<Sset_Float> value);
			std::shared_ptr<Sset_Float> WindExcdLevel(void);
			void WindExcdLevel(std::shared_ptr<Sset_Float> value);
			std::shared_ptr<Sset_Float> WindHysteresis(void);
			void WindHysteresis(std::shared_ptr<Sset_Float> value);
			std::shared_ptr<Sset_Enum> WindPause(void);
			void WindPause(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_Float> ADC1Scale(void);
			void ADC1Scale(std::shared_ptr<Sset_Float> value);
			std::shared_ptr<Sset_Float> ADC1Offset(void);
			void ADC1Offset(std::shared_ptr<Sset_Float> value);
			std::shared_ptr<Sset_String> ADC1Units(void);
			void ADC1Units(std::shared_ptr<Sset_String> value);
			std::shared_ptr<Sset_String> ADC1Description(void);
			void ADC1Description(std::shared_ptr<Sset_String> value);
			std::shared_ptr<Sset_Float> ADC2Scale(void);
			void ADC2Scale(std::shared_ptr<Sset_Float> value);
			std::shared_ptr<Sset_Float> ADC2Offset(void);
			void ADC2Offset(std::shared_ptr<Sset_Float> value);
			std::shared_ptr<Sset_String> ADC2Units(void);
			void ADC2Units(std::shared_ptr<Sset_String> value);
			std::shared_ptr<Sset_String> ADC2Description(void);
			void ADC2Description(std::shared_ptr<Sset_String> value);
			std::shared_ptr<Sset_Enum> SoundRecSampleRate(void);
			void SoundRecSampleRate(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_UnsignedInt> TimeHistoryOptions3(void);
			void TimeHistoryOptions3(std::shared_ptr<Sset_UnsignedInt> value);
			std::shared_ptr<Sset_Enum> SpectralLnMode(void);
			void SpectralLnMode(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_UnsignedInt> EventTHCount(void);
			void EventTHCount(std::shared_ptr<Sset_UnsignedInt> value);
			std::shared_ptr<Sset_UnsignedInt> EventTHPreCount(void);
			void EventTHPreCount(std::shared_ptr<Sset_UnsignedInt> value);
			std::shared_ptr<Sset_Enum> SRRange(void);
			void SRRange(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_Enum> GraphRelative(void);
			void GraphRelative(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_UnsignedInt> EventTHPostCount(void);
			void EventTHPostCount(std::shared_ptr<Sset_UnsignedInt> value);
			std::shared_ptr<Sset_Enum> EnableWeather(void);
			void EnableWeather(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_Enum> InstrumentMode(void);
			void InstrumentMode(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_Int> ExitTime(void);
			void ExitTime(std::shared_ptr<Sset_Int> value);
			std::shared_ptr<Sset_Enum> LowestFrequency(void);
			void LowestFrequency(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_Enum> HighestFrequency(void);
			void HighestFrequency(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_Enum> LinkSourceToControl(void);
			void LinkSourceToControl(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_Enum> RT60_NoiseType(void);
			void RT60_NoiseType(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_Enum> UNUSED_01(void);
			void UNUSED_01(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_Float> RT60_NoiseAttenuation(void);
			void RT60_NoiseAttenuation(std::shared_ptr<Sset_Float> value);
			std::shared_ptr<Sset_Enum> RT60_Method(void);
			void RT60_Method(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_Enum> RT60_TriggerSource(void);
			void RT60_TriggerSource(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_Float> RT60_TriggerLevel(void);
			void RT60_TriggerLevel(std::shared_ptr<Sset_Float> value);
			std::shared_ptr<Sset_Enum> RT60_Bandwidth(void);
			void RT60_Bandwidth(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_Int> RT60_BuildTime(void);
			void RT60_BuildTime(std::shared_ptr<Sset_Int> value);
			std::shared_ptr<Sset_Int> RT60_RunTime(void);
			void RT60_RunTime(std::shared_ptr<Sset_Int> value);
			std::shared_ptr<Sset_Int> RT60_RunCount(void);
			void RT60_RunCount(std::shared_ptr<Sset_Int> value);
			std::shared_ptr<Sset_Enum> RT60_ByTimeSamplePeriod(void);
			void RT60_ByTimeSamplePeriod(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_Enum> RT60_SaveAverageTimeSeries(void);
			void RT60_SaveAverageTimeSeries(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_Enum> RT60_SaveAllTimeSeries(void);
			void RT60_SaveAllTimeSeries(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_Enum> FFT_WindowType(void);
			void FFT_WindowType(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_Enum> FFT_FreqSpan(void);
			void FFT_FreqSpan(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_Enum> FFT_NumLines(void);
			void FFT_NumLines(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_Enum> FFT_RunMode(void);
			void FFT_RunMode(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_Enum> Tonality_1996_2(void);
			void Tonality_1996_2(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_Enum> ToneSeekDelta(void);
			void ToneSeekDelta(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_Enum> RegressionSpan(void);
			void RegressionSpan(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_Enum> VaisalaHeaterState(void);
			void VaisalaHeaterState(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_UnsignedInt> VaisalaHeaterEnaTime(void);
			void VaisalaHeaterEnaTime(std::shared_ptr<Sset_UnsignedInt> value);
			std::shared_ptr<Sset_UnsignedInt> VaisalaHeaterDisTime(void);
			void VaisalaHeaterDisTime(std::shared_ptr<Sset_UnsignedInt> value);
			std::shared_ptr<Sset_UnsignedInt> EventNotification(void);
			void EventNotification(std::shared_ptr<Sset_UnsignedInt> value);
			std::shared_ptr<Sset_UnsignedInt> RunningLeqPeriod(void);
			void RunningLeqPeriod(std::shared_ptr<Sset_UnsignedInt> value);
			std::shared_ptr<Sset_Enum> MeasAlertTriggerSource(void);
			void MeasAlertTriggerSource(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_Float> MeasAlertTriggerLevel(void);
			void MeasAlertTriggerLevel(std::shared_ptr<Sset_Float> value);
			std::shared_ptr<Sset_UnsignedInt> FftMeasurementCount(void);
			void FftMeasurementCount(std::shared_ptr<Sset_UnsignedInt> value);
			std::shared_ptr<Sset_UnsignedInt> FftHistoryControl(void);
			void FftHistoryControl(std::shared_ptr<Sset_UnsignedInt> value);
			std::shared_ptr<Sset_Int> FftIntegration(void);
			void FftIntegration(std::shared_ptr<Sset_Int> value);
			std::shared_ptr<Sset_Enum> RunOnTrigger(void);
			void RunOnTrigger(std::shared_ptr<Sset_Enum> value);
#ifdef MAKEDLL
		public: // This is for internal use
			SMeasControls_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _SMEAS_CONTROLS_T_H
