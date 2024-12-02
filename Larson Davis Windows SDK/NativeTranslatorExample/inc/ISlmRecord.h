/**************************************************************************//**
 * @file ISlmRecord.h
 * @brief Native Wrapper for Managed type ISlmRecord.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ISLM_RECORD_H
#define _ISLM_RECORD_H
#include <ILDRecordWithMetaRecord_CMetaDataRecord.h>
#include <EDetectorNdx.h>
#include <EDetectorId.h>
#include <EFftLevel.h>
#include <EVsqConvert.h>
#include <EFftRegressionRange.h>
#include <EFftToneSeekDelta.h>
#include <EFftWindow.h>
#include <EWeightingNdx.h>
#include <EPeakWeightId.h>
#include <ERmsWeightId.h>
#include <ERt60Bandwidth.h>
#include <ERt60RecType.h>
#include <ERt60Method.h>
#include <ERt60MeasurementGrade.h>
#include <ERt60GradeSetting.h>
#include <ERt60NoiseType.h>
#include <ERt60QualityIndicator.h>
#include <ERt60SamplePeriod.h>
#include <EFrequency.h>
#include <ETimeHistoryPeriod.h>
#include <ELabelFormat.h>
#include <EUnitType.h>
#include <ETHOptionId.h>
#include <ETHOptionType.h>
#include <EUnitConversion.h>
#include <EWeatherEnable.h>
#include <EWindDirection.h>
#include <ERt60DataPoint.h>
#include <EIntegrationMethod.h>
#include <EActionCause.h>
#include <EAudioFormat.h>
#include <EFftFrequencySpan.h>
#include <EFftLines.h>
#include <EFftRunMode.h>
#include <EFftTonalityStandard.h>
#include <EInstrumentMode.h>
#include <EPreampType.h>
#include <EObaBandwidth.h>
#include <EObaRange.h>
#include <EPartitionType.h>
#include <ERandomCorrection.h>
#include <ERt60RunTime.h>
#include <EHeaterState.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI ILDRecordWithMetaRecord_CMetaDataRecord;
		class LDAPI CMeasureRt60;
		class LDAPI Array_SDataLimitsEDT_t;
		class LDAPI Array_float;
		struct LDAPI SRt60DataLimits_t;
		struct LDAPI SDataLimitsEDT_t;
		struct LDAPI SRt60Data_t;
		class LDAPI Array_int32_t_2;
		struct LDAPI SRT60_QI_t;
		struct LDAPI SWeatherData_t;
		class LDAPI Array_StringWrapper;
		class LDAPI CCalibration;
		class LDAPI Array_int32_t;
		struct LDAPI SCalData2_t;
		struct LDAPI Sslm2;
		struct LDAPI SDetectorTs_t;
		class LDAPI Array_SDetector_t;
		struct LDAPI SSpectraInfo_t;
		class LDAPI CTimeHistoryManager;
		class LDAPI IList_SstTHItemInfo_t;
		class LDAPI IList_CTimeHistoryRecord;
		class LDAPI CTimeHistoryRecord;
		class LDAPI Array_float_2;
		class LDAPI CTimeHistoryOptions;
		class LDAPI Array_SstTHOptionInfo_t;
		struct LDAPI SstTHOptionInfo_t;
		class LDAPI List_int32_t;
		class LDAPI List_ValueTuple_int32_t_StringWrapper;
		class LDAPI Array_uint32_t;
		struct LDAPI SUserPreferences_t;
		struct LDAPI Sset_Enum;
		struct LDAPI Sset_UnsignedInt;
		struct LDAPI Sset_Int;
		struct LDAPI Sset_FloatArray11;
		struct LDAPI Sset_FloatArray13;
		struct LDAPI Sset_String;
		struct LDAPI Sset_Float;
		class LDAPI Array_Sset_Enum;
		class LDAPI Array_Sset_String;
		class LDAPI CMarineMammalsSummaryData;
		class LDAPI List_CMarineMammalsData;
		class LDAPI CMarineMammalsData;
		class LDAPI IComparer_CMarineMammalsData;
		class LDAPI Array_CMarineMammalsData;
		struct LDAPI SSystemSettings_t;
		struct LDAPI SFirwareVersion_t;
		class LDAPI Array_Sset_Float;
		struct LDAPI Sset_IPAddr;
		struct LDAPI Sset_ByteString;
		struct LDAPI SSystemMetrics_t;
		struct LDAPI SMetrics_t;
		class LDAPI IList_CEventInfo;
		class LDAPI CEventInfo;
		class LDAPI CEventTimeHistoryManager;
		class LDAPI Array_SEventTHRecord_t;
		struct LDAPI SEventTHRecord_t;
		struct LDAPI SRt60ByTime_t;
		class LDAPI Array_SRt60TimeSample_t;
		class LDAPI Array_SRt60DataLimits_t;
		struct LDAPI SRt60CalcLines_t;
		struct LDAPI SRt60Record_t;
		struct LDAPI SEventTriggerInfo_t;
		struct LDAPI SEventLevelInfo_t;
		struct LDAPI SEventWeatherInfo_t;
		struct LDAPI SEnvPreampInfo_t;
		struct LDAPI SEnvPreampData_t;
		class LDAPI Array_SDoseCriteria_t;
		struct LDAPI SDoseCriteria_t;
		struct LDAPI SGps_t;
		struct LDAPI Sdegmin;
		class LDAPI IList_CIntervalInfo;
		class LDAPI CIntervalInfo;
		class LDAPI CMeasureRta;
		struct LDAPI SRtaRecord_t;
		struct LDAPI SRaHeader_t;
		struct LDAPI SOverload_t;
		class LDAPI Array_SEventCounts_t;
		class LDAPI CSessionLog;
		struct LDAPI SSessionLog_t;
		class LDAPI CRunRecord;
		class LDAPI IList_CRunRecord;
		class LDAPI IList_CSoundRecord;
		class LDAPI CSoundRecord;
		class LDAPI Array_uint8_t;
		struct LDAPI SCalCheckHistory_t;
		class LDAPI Array_SCalData2_t;
		class LDAPI Array_Array_SCalData2_t;
		struct LDAPI SCalHistory2_t;
		class LDAPI Array_SCalHistoryTypes_t;
		struct LDAPI SDailyNoise_t;
		class LDAPI IList_SEventTriggerConfig_t;
		struct LDAPI SEventTriggerConfig_t;
		class LDAPI IList_CMeasureFft;
		class LDAPI CMeasureFft;
		struct LDAPI SFftRecord_t;
		struct LDAPI SFftInfo_t;
		struct LDAPI SFftLevels_t;
		struct LDAPI SFftTriggerInfo_t;
		class LDAPI IList_CToneInfo;
		class LDAPI CToneInfo;
		struct LDAPI SSlmLnInfo_t;
		struct LDAPI SMeasControls_t;
		struct LDAPI Sset_TableFloatsLNS;
		class LDAPI Array_Sset_EnumFloats;
		struct LDAPI SCalHistory_t;
		class LDAPI Array_SCalData_t;
		class LDAPI CPartition;
		class LDAPI CRoomRx;
		class LDAPI Array_CMeasureRt60;
		class LDAPI CRoomTx;

		class LDAPI ISlmRecord : public virtual ILDRecordWithMetaRecord_CMetaDataRecord
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			ISlmRecord(const ISlmRecord& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~ISlmRecord(void);
			virtual bool IsEventTimeHistoryAvailable(void);
			virtual bool IsFftHistoryAvailable(void);
			virtual bool IsFftTonalityAvailable(void);
			virtual bool IsLnTableValid(void);
			virtual bool IsLxT(void);
			virtual bool IsLxT(float ver);
			virtual bool IsOutdoorPreampAvailable(void);
			virtual bool IsSystemMetricsAvailable(void);
			virtual bool IsTimeHistoryAvailable(void);
			virtual bool IsValidCalCheckHistoryAvailable(void);
			virtual bool IsValidCalHistoryAvailable(void);
			virtual int32_t ReverseIntegrationImpulse(std::shared_ptr<CMeasureRt60>& mainPosition, std::shared_ptr<Array_SDataLimitsEDT_t>& edt_indices, std::shared_ptr<Array_float>& schroederSamples, int32_t numSamples, int32_t maxIndex, float maxVal, int32_t band, float noiseFloor, std::shared_ptr<Array_float> samples);
			virtual void Rt60CalcData(std::shared_ptr<ISlmRecord> rec, int32_t posIndex);
			virtual void rt60_calc_slopes(std::shared_ptr<Array_float> data, std::shared_ptr<SRt60DataLimits_t> decay_indices, std::shared_ptr<SDataLimitsEDT_t>& edt_indices, int32_t rt60_method, std::shared_ptr<SRt60Data_t>& rt60_data);
			virtual void UpdateDecaysPerPositionWithMetaData(void);
			virtual void UpdateDecaysWithMetaData(void);
			virtual float CalcLn(float val, std::shared_ptr<Array_int32_t_2> spectra, int32_t ndx);
			virtual void CalcQualityIndicators(std::shared_ptr<Array_float> data, std::shared_ptr<SRt60DataLimits_t> limits, std::shared_ptr<SRt60Data_t> rt60_data, std::shared_ptr<SRT60_QI_t>& quality_indicator);
			virtual int32_t FindIndexOfTimeHistEntry(int64_t timeMS);
			virtual EDetectorId GetDetectorId(EDetectorNdx nDx);
			virtual EDetectorNdx GetDetectorIndex(EDetectorId id);
			virtual StringWrapper GetDetectorString(EDetectorId id, bool longStr = false);
			virtual StringWrapper GetDetectorString(EDetectorNdx ndx, bool longStr = false);
			virtual uint32_t GetFftArraySize(void);
			virtual float GetFftData(EFftLevel levelId, int32_t ndx, EVsqConvert convert);
			virtual float GetFftDuration(void);
			virtual uint32_t GetFftFlags(void);
			virtual int32_t GetFftFrequencySpan(void);
			virtual int32_t GetFftHistCount(int32_t selectedHistory = 0);
			virtual float GetFftLeq(EVsqConvert convert);
			virtual float GetFftLpeak(EVsqConvert convert);
			virtual int32_t GetFftNumLines(void);
			virtual int32_t GetFftOverallCount(void);
			virtual int32_t GetFftOverloadCount(void);
			virtual float GetFftOverloadDuration(void);
			virtual float GetFftRegressionRange(void);
			virtual float GetFftRegressionRange(EFftRegressionRange range);
			virtual float GetFftResolution(void);
			virtual StringWrapper GetFftRunModeString(void);
			virtual uint32_t GetFftTimeMicro(void);
			virtual uint32_t GetFftTimeSeconds(void);
			virtual float GetFftToneSeekDelta(void);
			virtual float GetFftToneSeekDelta(EFftToneSeekDelta delta);
			virtual float GetFftWindowCorrection(void);
			virtual float GetFftWindowCorrection(EFftWindow window);
			virtual StringWrapper GetFftWindowString(void);
			virtual float GetFrequencyFromLine(int32_t line);
			virtual EPeakWeightId GetPeakWeightId(EWeightingNdx nDx);
			virtual EWeightingNdx GetPeakWeightIndex(EPeakWeightId id);
			virtual StringWrapper GetPeakWeightString(EPeakWeightId id);
			virtual StringWrapper GetPeakWeightString(EWeightingNdx ndx);
			virtual ERmsWeightId GetRmsWeightId(EWeightingNdx nDx);
			virtual EWeightingNdx GetRmsWeightIndex(ERmsWeightId id);
			virtual StringWrapper GetRmsWeightString(ERmsWeightId id);
			virtual StringWrapper GetRmsWeightString(EWeightingNdx ndx);
			virtual uint32_t GetRT60AverageCount(void);
			virtual ERt60Bandwidth GetRT60Bandwidth(void);
			virtual StringWrapper GetRT60BandwidthAsString(void);
			virtual StringWrapper GetRT60BandwidthAsString(std::shared_ptr<CMeasureRt60> t2);
			virtual float GetRT60Data(std::shared_ptr<CMeasureRt60> t2, ERt60RecType id, int32_t bin, ERt60Method rt60Method);
			virtual float GetRT60Data(ERt60RecType id, int32_t bin, ERt60Method method);
			virtual StringWrapper GetRT60DataAsString(std::shared_ptr<CMeasureRt60> t2, ERt60RecType id, int32_t bin, ERt60Method method);
			virtual StringWrapper GetRT60DataAsString(ERt60RecType id, int32_t bin, ERt60Method method);
			virtual int32_t GetRT60DecaysPerPosition(int32_t nDx);
			virtual int32_t GetRT60GradeIndex(ERt60MeasurementGrade gradeId);
			virtual int32_t GetRT60LeastDecaysFromPositions(void);
			virtual ERt60MeasurementGrade GetRT60MeasurementGrade(int32_t& qualPositions, int32_t& qualDecays, ERt60GradeSetting& settingId);
			virtual StringWrapper GetRT60NoiseSourceAsString(void);
			virtual StringWrapper GetRT60NoiseSourceAsString(ERt60NoiseType source);
			virtual uint32_t GetRT60Positions(void);
			virtual int32_t GetRT60QualifiedPositions(ERt60MeasurementGrade gradeId, int32_t& minDecays);
			virtual ERt60QualityIndicator GetRT60Quality(std::shared_ptr<CMeasureRt60> t2, ERt60RecType id, int32_t bin, ERt60Method method);
			virtual ERt60QualityIndicator GetRT60Quality(ERt60RecType id, int32_t bin, ERt60Method method);
			virtual int32_t GetRT60SampleCount(void);
			virtual float GetRT60SampleData(int32_t ndx, int32_t bin);
			virtual float GetRT60SampleData(std::shared_ptr<CMeasureRt60> t2, int32_t ndx, int32_t bin);
			virtual StringWrapper GetRT60SampleDataAsString(int32_t row, int32_t bin);
			virtual StringWrapper GetRT60SampleDataAsString(std::shared_ptr<CMeasureRt60> t2, int32_t row, int32_t bin);
			virtual float GetRT60SamplePeriod(void);
			virtual float GetRT60SamplePeriod(std::shared_ptr<CMeasureRt60> t2, ERt60SamplePeriod period);
			virtual float GetRT60SamplePeriod(ERt60SamplePeriod period);
			virtual StringWrapper GetRT60SamplePeriodAsString(bool incUnits = true);
			virtual StringWrapper GetRT60SamplePeriodAsString(std::shared_ptr<CMeasureRt60> t2, ERt60SamplePeriod period, bool incUnits = true);
			virtual StringWrapper GetRT60SamplePeriodAsString(ERt60SamplePeriod period, bool incUnits = true);
			virtual float GetRT60SampleTime(int32_t ndx);
			virtual float GetRT60SampleTime(std::shared_ptr<CMeasureRt60> t2, ERt60SamplePeriod period, int32_t ndx);
			virtual float GetRT60SampleTime(ERt60SamplePeriod period, int32_t ndx);
			virtual StringWrapper GetRT60SampleTimeAsString(int32_t row);
			virtual StringWrapper GetRT60SampleTimeAsString(std::shared_ptr<CMeasureRt60> t2, ERt60SamplePeriod period, int32_t row);
			virtual StringWrapper GetRT60SampleTimeAsString(ERt60SamplePeriod period, int32_t row);
			virtual uint32_t GetRT60TotalCount(void);
			virtual StringWrapper GetRT60TriggerMethodAsString(void);
			virtual StringWrapper GetRT60TriggerMethodAsString(ERt60Method method);
			virtual StringWrapper GetRT60TriggerSourceAsString(void);
			virtual StringWrapper GetRT60TriggerSourceAsString(EFrequency source);
			virtual int32_t GetTimeHistoryCount(void);
			virtual float GetTimeHistorySamplePeriod(void);
			virtual float GetTimeHistorySamplePeriod(ETimeHistoryPeriod period);
			virtual float GetWindyDirPercentage(int32_t ndx);
			virtual float GetWindyDirPercentage(std::shared_ptr<SWeatherData_t> weather, int32_t ndx);
			virtual void InitCalHistoryData(void);
			virtual void InitModifiedSlmRecord(std::shared_ptr<ISlmRecord> orgRec);
			virtual float GetLdnNight(void);
			virtual float GetLepd(int32_t ndx);
			virtual float GetLn(int32_t ndx);
			virtual std::shared_ptr<Array_StringWrapper> GetObaFrequencyLabels(int32_t bins, ELabelFormat labelFormat, bool localize = true);
			virtual float GetPaHrMagnitude(float sel, StringWrapper& format, StringWrapper& units, bool truncate = false);
			virtual StringWrapper GetPeakWeightString(void);
			virtual std::shared_ptr<CCalibration> GetPostCalData(void);
			virtual StringWrapper GetPreferredUnits(EUnitType type);
			virtual float GetProjectedDose(int32_t ndx);
			virtual StringWrapper GetRmsWeightString(void);
			virtual float GetSE(void);
			virtual float GetSE(int32_t hours);
			virtual float GetSE(int32_t hours, float leq, float duration);
			virtual float GetSEL(void);
			virtual float GetSEL(float leq, float runTime);
			virtual bool Is831(float ver);
			virtual bool Is831(void);
			virtual bool Is831C(void);
			virtual bool IsEventHistoryAvailable(void);
			virtual bool IsFrenchNf30Active(void);
			virtual bool IsMeasSpectralLnAvailable(void);
			virtual bool IsMeasurementHistoryAvailable(void);
			virtual bool IsObaAvailable(void);
			virtual bool IsSpectralLnAvailable(void);
			virtual bool IsStatisticsAvailable(void);
			virtual float CalcLn(float val, std::shared_ptr<Array_int32_t> table);
			virtual float CalcTonality(std::shared_ptr<Array_float> spectra);
			virtual float ConvertToPreferredUnits(EUnitType type, float val);
			virtual float GetCritTwa(int32_t ndx);
			virtual float GetdBFromBin(int32_t nBin);
			virtual StringWrapper GetDetectorString(bool longStr = false);
			virtual float GetDose(int32_t ndx);
			virtual void GetEACalCheck(std::shared_ptr<SCalData2_t> calData, float stdLevel, float& scale, float& diff);
			virtual int32_t GetEventTimeHistoryCount(void);
			virtual float GetLden(void);
			virtual float GetLdenDay(void);
			virtual float GetLdenEve(void);
			virtual float GetLdenNight(void);
			virtual float GetLdn(void);
			virtual float GetLdnDay(void);
			virtual std::shared_ptr<Sslm2> AnyData(void);
			virtual void AnyData(std::shared_ptr<Sslm2> value);
			virtual std::shared_ptr<SSpectraInfo_t> ThirdOctaveSpectra(void);
			virtual void ThirdOctaveSpectra(std::shared_ptr<SSpectraInfo_t> value);
			virtual std::shared_ptr<SSpectraInfo_t> FullOctaveSpectra(void);
			virtual void FullOctaveSpectra(std::shared_ptr<SSpectraInfo_t> value);
			virtual std::shared_ptr<CTimeHistoryManager> THMngr(void);
			virtual void THMngr(std::shared_ptr<CTimeHistoryManager> value);
			virtual std::shared_ptr<CTimeHistoryOptions> TimeHistOptions(void);
			virtual EUnitConversion UnitsSystem(void);
			virtual void UnitsSystem(EUnitConversion value);
			virtual std::shared_ptr<SWeatherData_t> Weather(void);
			virtual void Weather(std::shared_ptr<SWeatherData_t> value);
			virtual std::shared_ptr<SUserPreferences_t> UserProperties(void);
			virtual void UserProperties(std::shared_ptr<SUserPreferences_t> value);
			virtual EWeatherEnable WeatherOption(void);
			virtual void WeatherOption(EWeatherEnable value);
			virtual EWindDirection WindDirection(void);
			virtual void WindDirection(EWindDirection value);
			virtual std::shared_ptr<CMarineMammalsSummaryData> MarineMammalsSummary(void);
			virtual void MarineMammalsSummary(std::shared_ptr<CMarineMammalsSummaryData> value);
			virtual std::shared_ptr<List_CMarineMammalsData> MarineMammalsResults(void);
			virtual void MarineMammalsResults(std::shared_ptr<List_CMarineMammalsData> value);
			virtual EDetectorNdx DetectorIndex(void);
			virtual void DetectorIndex(EDetectorNdx value);
			virtual StringWrapper ADC1Description(void);
			virtual void ADC1Description(StringWrapper value);
			virtual StringWrapper ADC2Description(void);
			virtual void ADC2Description(StringWrapper value);
			virtual std::shared_ptr<SSystemSettings_t> SysProperties(void);
			virtual void SysProperties(std::shared_ptr<SSystemSettings_t> value);
			virtual std::shared_ptr<SSystemMetrics_t> SystemMetrics(void);
			virtual void SystemMetrics(std::shared_ptr<SSystemMetrics_t> value);
			virtual EWeightingNdx ObaWeightIndex(void);
			virtual void ObaWeightIndex(EWeightingNdx value);
			virtual std::shared_ptr<IList_CEventInfo> Events(void);
			virtual void Events(std::shared_ptr<IList_CEventInfo> value);
			virtual std::shared_ptr<SEnvPreampInfo_t> EnvPreampInfo(void);
			virtual void EnvPreampInfo(std::shared_ptr<SEnvPreampInfo_t> value);
			virtual std::shared_ptr<SEnvPreampData_t> EnvPreampData(void);
			virtual void EnvPreampData(std::shared_ptr<SEnvPreampData_t> value);
			virtual std::shared_ptr<Array_SDoseCriteria_t> Dose(void);
			virtual void Dose(std::shared_ptr<Array_SDoseCriteria_t> value);
			virtual std::shared_ptr<Array_float> FullOctaveReferenceSpectra1(void);
			virtual void FullOctaveReferenceSpectra1(std::shared_ptr<Array_float> value);
			virtual std::shared_ptr<Array_float> FullOctaveReferenceSpectra2(void);
			virtual void FullOctaveReferenceSpectra2(std::shared_ptr<Array_float> value);
			virtual StringWrapper FullOctaveReferenceSpectra1Name(void);
			virtual void FullOctaveReferenceSpectra1Name(StringWrapper value);
			virtual StringWrapper FullOctaveReferenceSpectra2Name(void);
			virtual void FullOctaveReferenceSpectra2Name(StringWrapper value);
			virtual StringWrapper FullOctaveReferenceSpectra3Name(void);
			virtual void FullOctaveReferenceSpectra3Name(StringWrapper value);
			virtual StringWrapper FullOctaveReferenceSpectra4Name(void);
			virtual void FullOctaveReferenceSpectra4Name(StringWrapper value);
			virtual std::shared_ptr<SGps_t> GPSData(void);
			virtual void GPSData(std::shared_ptr<SGps_t> value);
			virtual int32_t GustDirectionColumn(void);
			virtual void GustDirectionColumn(int32_t value);
			virtual std::shared_ptr<IList_CIntervalInfo> Intervals(void);
			virtual void Intervals(std::shared_ptr<IList_CIntervalInfo> value);
			virtual EIntegrationMethod Integration(void);
			virtual void Integration(EIntegrationMethod value);
			virtual std::shared_ptr<Array_StringWrapper> MarkerNames(void);
			virtual void MarkerNames(std::shared_ptr<Array_StringWrapper> value);
			virtual std::shared_ptr<CSessionLog> SessionLog(void);
			virtual void SessionLog(std::shared_ptr<CSessionLog> value);
			virtual int32_t WindDirectionColumn(void);
			virtual void WindDirectionColumn(int32_t value);
			virtual StringWrapper WindUnits(void);
			virtual void WindUnits(StringWrapper value);
			virtual std::shared_ptr<SCalCheckHistory_t> CalCheckHistory(void);
			virtual void CalCheckHistory(std::shared_ptr<SCalCheckHistory_t> value);
			virtual std::shared_ptr<Array_Array_SCalData2_t> CalData(void);
			virtual void CalData(std::shared_ptr<Array_Array_SCalData2_t> value);
			virtual uint32_t DayTime(void);
			virtual void DayTime(uint32_t value);
			virtual EDetectorId Detector(void);
			virtual void Detector(EDetectorId value);
			virtual bool EnableExceedAudioSnapshot(void);
			virtual void EnableExceedAudioSnapshot(bool value);
			virtual int64_t EndTime(void);
			virtual void EndTime(int64_t value);
			virtual uint32_t EveningTime(void);
			virtual void EveningTime(uint32_t value);
			virtual int32_t GPSControl(void);
			virtual void GPSControl(int32_t value);
			virtual std::shared_ptr<Array_int32_t_2> SpectralLns(void);
			virtual void SpectralLns(std::shared_ptr<Array_int32_t_2> value);
			virtual EWeightingNdx RmsWeightIndex(void);
			virtual void RmsWeightIndex(EWeightingNdx value);
			virtual EWeightingNdx PeakWeightIndex(void);
			virtual void PeakWeightIndex(EWeightingNdx value);
			virtual int32_t NumOBA(void);
			virtual void NumOBA(int32_t value);
			virtual bool MeasSnapShotEnable(void);
			virtual void MeasSnapShotEnable(bool value);
			virtual std::shared_ptr<Array_float> TWA(void);
			virtual void TWA(std::shared_ptr<Array_float> value);
			virtual float PauseTime(void);
			virtual void PauseTime(float value);
			virtual std::shared_ptr<SOverload_t> OverLoads(void);
			virtual void OverLoads(std::shared_ptr<SOverload_t> value);
			virtual ETimeHistoryPeriod ExcdTHPeriod(void);
			virtual void ExcdTHPeriod(ETimeHistoryPeriod value);
			virtual int32_t FirstStatisticsRow(void);
			virtual void FirstStatisticsRow(int32_t value);
			virtual ERmsWeightId FrequencyWeighting(void);
			virtual void FrequencyWeighting(ERmsWeightId value);
			virtual std::shared_ptr<Array_float> FullOctaveReferenceSpectra3(void);
			virtual void FullOctaveReferenceSpectra3(std::shared_ptr<Array_float> value);
			virtual std::shared_ptr<Array_float> FullOctaveReferenceSpectra4(void);
			virtual void FullOctaveReferenceSpectra4(std::shared_ptr<Array_float> value);
			virtual float ADC1Offset(void);
			virtual void ADC1Offset(float value);
			virtual float ADC1Scale(void);
			virtual void ADC1Scale(float value);
			virtual StringWrapper ADC1Units(void);
			virtual void ADC1Units(StringWrapper value);
			virtual float ADC2Offset(void);
			virtual void ADC2Offset(float value);
			virtual float ADC2Scale(void);
			virtual void ADC2Scale(float value);
			virtual StringWrapper ADC2Units(void);
			virtual void ADC2Units(StringWrapper value);
			virtual int32_t AudioCompression(void);
			virtual void AudioCompression(int32_t value);
			virtual std::shared_ptr<SCalHistory2_t> CalHistory(void);
			virtual void CalHistory(std::shared_ptr<SCalHistory2_t> value);
			virtual int32_t CalibrationLevelTenthsDB(void);
			virtual void CalibrationLevelTenthsDB(int32_t value);
			virtual float CminusA(void);
			virtual void CminusA(float value);
			virtual int32_t CurDose(void);
			virtual void CurDose(int32_t value);
			virtual std::shared_ptr<SDailyNoise_t> DailyNoise(void);
			virtual void DailyNoise(std::shared_ptr<SDailyNoise_t> value);
			virtual int32_t DateFormat(void);
			virtual void DateFormat(int32_t value);
			virtual int32_t DecimalFormat(void);
			virtual void DecimalFormat(int32_t value);
			virtual float EveningPenalty(void);
			virtual void EveningPenalty(float value);
			virtual bool EventTimeHistoryTruncated(void);
			virtual void EventTimeHistoryTruncated(bool value);
			virtual std::shared_ptr<IList_SEventTriggerConfig_t> EventTriggers(void);
			virtual void EventTriggers(std::shared_ptr<IList_SEventTriggerConfig_t> value);
			virtual uint32_t ExcdTHCount(void);
			virtual void ExcdTHCount(uint32_t value);
			virtual uint32_t ExcdTHPreCount(void);
			virtual void ExcdTHPreCount(uint32_t value);
			virtual int32_t ExcdTHSpectra(void);
			virtual void ExcdTHSpectra(int32_t value);
			virtual uint32_t ExcSnapShotPeriod(void);
			virtual void ExcSnapShotPeriod(uint32_t value);
			virtual int32_t ExitTime(void);
			virtual void ExitTime(int32_t value);
			virtual EFftFrequencySpan FftFreqSpan(void);
			virtual void FftFreqSpan(EFftFrequencySpan value);
			virtual std::shared_ptr<IList_CMeasureFft> FftHistory(void);
			virtual void FftHistory(std::shared_ptr<IList_CMeasureFft> value);
			virtual EFftLines FftLines(void);
			virtual void FftLines(EFftLines value);
			virtual std::shared_ptr<CMeasureFft> FftOverall(void);
			virtual void FftOverall(std::shared_ptr<CMeasureFft> value);
			virtual EFftRunMode FftRunMode(void);
			virtual void FftRunMode(EFftRunMode value);
			virtual EFftWindow FftWindow(void);
			virtual void FftWindow(EFftWindow value);
			virtual EFrequency HiBand(void);
			virtual void HiBand(EFrequency value);
			virtual float LAeq(void);
			virtual void LAeq(float value);
			virtual int32_t Language(void);
			virtual void Language(int32_t value);
			virtual float LCeq(void);
			virtual void LCeq(float value);
			virtual StringWrapper LdbinFileName(void);
			virtual void LdbinFileName(StringWrapper value);
			virtual float Leq(void);
			virtual void Leq(float value);
			virtual std::shared_ptr<SSlmLnInfo_t> LnInfo(void);
			virtual void LnInfo(std::shared_ptr<SSlmLnInfo_t> value);
			virtual std::shared_ptr<Array_float> LnValues(void);
			virtual void LnValues(std::shared_ptr<Array_float> value);
			virtual EFrequency LoBand(void);
			virtual void LoBand(EFrequency value);
			virtual float LTm5(void);
			virtual void LTm5(float value);
			virtual float Lweq(void);
			virtual void Lweq(float value);
			virtual float LwIeq(void);
			virtual void LwIeq(float value);
			virtual float Max(void);
			virtual void Max(float value);
			virtual int64_t MaxTime(void);
			virtual void MaxTime(int64_t value);
			virtual uint32_t MeasCounts(void);
			virtual void MeasCounts(uint32_t value);
			virtual int32_t MeasHistEnabled(void);
			virtual void MeasHistEnabled(int32_t value);
			virtual std::shared_ptr<SMeasControls_t> MeasProperties(void);
			virtual void MeasProperties(std::shared_ptr<SMeasControls_t> value);
			virtual int32_t MeasPropsStructSize(void);
			virtual void MeasPropsStructSize(int32_t value);
			virtual int32_t MeasPropsVersion(void);
			virtual void MeasPropsVersion(int32_t value);
			virtual uint32_t MeasSnapShotPeriod(void);
			virtual void MeasSnapShotPeriod(uint32_t value);
			virtual int32_t MeasSpectralLn(void);
			virtual void MeasSpectralLn(int32_t value);
			virtual uint32_t MeasurementPeriod(void);
			virtual void MeasurementPeriod(uint32_t value);
			virtual float Min(void);
			virtual void Min(float value);
			virtual int64_t MinTime(void);
			virtual void MinTime(int64_t value);
			virtual EInstrumentMode Mode(void);
			virtual void Mode(EInstrumentMode value);
			virtual EPreampType NFPreampType(void);
			virtual void NFPreampType(EPreampType value);
			virtual int32_t NFWeighting(void);
			virtual void NFWeighting(int32_t value);
			virtual float NightPenalty(void);
			virtual void NightPenalty(float value);
			virtual uint32_t NightTime(void);
			virtual void NightTime(uint32_t value);
			virtual int32_t NumberMeasurements(void);
			virtual void NumberMeasurements(int32_t value);
			virtual EObaBandwidth ObaBandWidth(void);
			virtual void ObaBandWidth(EObaBandwidth value);
			virtual int32_t ObaMaxSpectra(void);
			virtual void ObaMaxSpectra(int32_t value);
			virtual EObaRange ObaRange(void);
			virtual void ObaRange(EObaRange value);
			virtual std::shared_ptr<SCalHistory_t> OldCalData(void);
			virtual void OldCalData(std::shared_ptr<SCalHistory_t> value);
			virtual std::shared_ptr<Array_float> OverallLns(void);
			virtual StringWrapper OverallTitle(void);
			virtual void OverallTitle(StringWrapper value);
			virtual std::shared_ptr<CPartition> P1(void);
			virtual void P1(std::shared_ptr<CPartition> value);
			virtual float Peak(void);
			virtual void Peak(float value);
			virtual int32_t Peak1Count(void);
			virtual void Peak1Count(int32_t value);
			virtual float Peak1Duration(void);
			virtual void Peak1Duration(float value);
			virtual int32_t Peak2Count(void);
			virtual void Peak2Count(int32_t value);
			virtual float Peak2Duration(void);
			virtual void Peak2Duration(float value);
			virtual int32_t Peak3Count(void);
			virtual void Peak3Count(int32_t value);
			virtual float Peak3Duration(void);
			virtual void Peak3Duration(float value);
			virtual int64_t PeakMaxTime(void);
			virtual void PeakMaxTime(int64_t value);
			virtual float PeakTrig1(void);
			virtual void PeakTrig1(float value);
			virtual float PeakTrig2(void);
			virtual void PeakTrig2(float value);
			virtual float PeakTrig3(void);
			virtual void PeakTrig3(float value);
			virtual EPeakWeightId PeakWeighting(void);
			virtual void PeakWeighting(EPeakWeightId value);
			virtual EFftRegressionRange RegressionRange(void);
			virtual void RegressionRange(EFftRegressionRange value);
			virtual ERandomCorrection RICorrection(void);
			virtual void RICorrection(ERandomCorrection value);
			virtual float Rt60Attenuation(void);
			virtual void Rt60Attenuation(float value);
			virtual ERt60Bandwidth Rt60Bandwidth(void);
			virtual void Rt60Bandwidth(ERt60Bandwidth value);
			virtual int32_t Rt60BuildTime(void);
			virtual void Rt60BuildTime(int32_t value);
			virtual ERt60NoiseType Rt60NoiseType(void);
			virtual void Rt60NoiseType(ERt60NoiseType value);
			virtual float RunTime(void);
			virtual void RunTime(float value);
			virtual int32_t Rt60RunCount(void);
			virtual void Rt60RunCount(int32_t value);
			virtual ERt60RunTime Rt60RunTime(void);
			virtual void Rt60RunTime(ERt60RunTime value);
			virtual ERt60SamplePeriod Rt60SamplePeriod(void);
			virtual void Rt60SamplePeriod(ERt60SamplePeriod value);
			virtual int32_t Rt60SaveAll(void);
			virtual void Rt60SaveAll(int32_t value);
			virtual int32_t Rt60SaveAverage(void);
			virtual void Rt60SaveAverage(int32_t value);
			virtual float Rt60TriggerLevel(void);
			virtual void Rt60TriggerLevel(float value);
			virtual ERt60Method Rt60TriggerMethod(void);
			virtual void Rt60TriggerMethod(ERt60Method value);
			virtual EFrequency Rt60TriggerSource(void);
			virtual void Rt60TriggerSource(EFrequency value);
			virtual float RtaAttenuation(void);
			virtual void RtaAttenuation(float value);
			virtual int32_t RtaB2Range(void);
			virtual void RtaB2Range(int32_t value);
			virtual ERt60Bandwidth RtaBandwidth(void);
			virtual void RtaBandwidth(ERt60Bandwidth value);
			virtual int32_t RtaL1Range(void);
			virtual void RtaL1Range(int32_t value);
			virtual int32_t RtaL2Range(void);
			virtual void RtaL2Range(int32_t value);
			virtual ERt60NoiseType RtaNoiseType(void);
			virtual void RtaNoiseType(ERt60NoiseType value);
			virtual uint32_t RunTimer(void);
			virtual void RunTimer(uint32_t value);
			virtual ETimeHistoryPeriod SamplePeriod(void);
			virtual void SamplePeriod(ETimeHistoryPeriod value);
			virtual float SEA(void);
			virtual void SEA(float value);
			virtual int32_t SerialNum(void);
			virtual void SerialNum(int32_t value);
			virtual StringWrapper SetupName(void);
			virtual void SetupName(StringWrapper value);
			virtual int32_t SlmGain(void);
			virtual void SlmGain(int32_t value);
			virtual uint32_t SnapShotPreTrig(void);
			virtual void SnapShotPreTrig(uint32_t value);
			virtual float SplTrig1(void);
			virtual void SplTrig1(float value);
			virtual float SplTrig2(void);
			virtual void SplTrig2(float value);
			virtual int32_t SysPropsStructSize(void);
			virtual void SysPropsStructSize(int32_t value);
			virtual int32_t SysPropsVersion(void);
			virtual void SysPropsVersion(int32_t value);
			virtual int32_t TaktMetricEnable(void);
			virtual void TaktMetricEnable(int32_t value);
			virtual std::shared_ptr<Array_float> ThirdOctaveReferenceSpectra1(void);
			virtual void ThirdOctaveReferenceSpectra1(std::shared_ptr<Array_float> value);
			virtual StringWrapper ThirdOctaveReferenceSpectra1Name(void);
			virtual void ThirdOctaveReferenceSpectra1Name(StringWrapper value);
			virtual std::shared_ptr<Array_float> ThirdOctaveReferenceSpectra2(void);
			virtual void ThirdOctaveReferenceSpectra2(std::shared_ptr<Array_float> value);
			virtual StringWrapper ThirdOctaveReferenceSpectra2Name(void);
			virtual void ThirdOctaveReferenceSpectra2Name(StringWrapper value);
			virtual std::shared_ptr<Array_float> ThirdOctaveReferenceSpectra3(void);
			virtual void ThirdOctaveReferenceSpectra3(std::shared_ptr<Array_float> value);
			virtual StringWrapper ThirdOctaveReferenceSpectra3Name(void);
			virtual void ThirdOctaveReferenceSpectra3Name(StringWrapper value);
			virtual std::shared_ptr<Array_float> ThirdOctaveReferenceSpectra4(void);
			virtual void ThirdOctaveReferenceSpectra4(std::shared_ptr<Array_float> value);
			virtual StringWrapper ThirdOctaveReferenceSpectra4Name(void);
			virtual void ThirdOctaveReferenceSpectra4Name(StringWrapper value);
			virtual bool TimeHistoryTruncated(void);
			virtual void TimeHistoryTruncated(bool value);
			virtual EFftToneSeekDelta ToneSeekDelta(void);
			virtual void ToneSeekDelta(EFftToneSeekDelta value);
			virtual int32_t Trig1Count(void);
			virtual void Trig1Count(int32_t value);
			virtual float Trig1Duration(void);
			virtual void Trig1Duration(float value);
			virtual int32_t Trig2Count(void);
			virtual void Trig2Count(int32_t value);
			virtual float Trig2Duration(void);
			virtual void Trig2Duration(float value);
			virtual int32_t UserPropsStructSize(void);
			virtual void UserPropsStructSize(int32_t value);
			virtual int32_t UserPropsVersion(void);
			virtual void UserPropsVersion(int32_t value);
			virtual uint32_t VaisalaHeaterDisTime(void);
			virtual void VaisalaHeaterDisTime(uint32_t value);
			virtual uint32_t VaisalaHeaterEnaTime(void);
			virtual void VaisalaHeaterEnaTime(uint32_t value);
			virtual EHeaterState VaisalaHeaterState(void);
			virtual void VaisalaHeaterState(EHeaterState value);
			virtual float Wimplminusleq(void);
			virtual void Wimplminusleq(float value);
			virtual float WindExcdLevel(void);
			virtual void WindExcdLevel(float value);
			virtual float WindHysteresis(void);
			virtual void WindHysteresis(float value);
			virtual int32_t WindPause(void);
			virtual void WindPause(int32_t value);
			virtual float WindScale(void);
			virtual void WindScale(float value);
			virtual float WindThreshold(void);
			virtual void WindThreshold(float value);
			virtual bool XducerEnable(void);
			virtual int32_t XducerUnits(void);
			virtual EFftTonalityStandard FftTonality(void);
#ifdef MAKEDLL
		public: // This is for internal use
			ISlmRecord(){};
			ISlmRecord(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _ISLM_RECORD_H
