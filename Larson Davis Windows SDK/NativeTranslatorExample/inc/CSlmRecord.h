/**************************************************************************//**
 * @file CSlmRecord.h
 * @brief Native Wrapper for Managed type SlmRecord.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _CSLM_RECORD_H
#define _CSLM_RECORD_H
#include <CLDRecordBase.h>
#include <ISlmRecord.h>
#include <ERt60RecType.h>
#include <ERt60Method.h>
#include <ERt60SamplePeriod.h>
#include <EFrequency.h>
#include <ERt60NoiseType.h>
#include <ERt60QualityIndicator.h>
#include <ERt60MeasurementGrade.h>
#include <ERt60GradeSetting.h>
#include <EVsqConvert.h>
#include <EFftLevel.h>
#include <EFftToneSeekDelta.h>
#include <EFftRegressionRange.h>
#include <EFftWindow.h>
#include <EWeightingNdx.h>
#include <ERmsWeightId.h>
#include <EPeakWeightId.h>
#include <EDetectorNdx.h>
#include <EDetectorId.h>
#include <ETimeHistoryPeriod.h>
#include <EUnitType.h>
#include <ELabelFormat.h>
#include <ERt60Bandwidth.h>
#include <EIntegrationMethod.h>
#include <EObaBandwidth.h>
#include <ERandomCorrection.h>
#include <EUnitConversion.h>
#include <EPreampType.h>
#include <EActionCause.h>
#include <EAudioFormat.h>
#include <ERt60DataPoint.h>
#include <EWeatherEnable.h>
#include <EWindDirection.h>
#include <EInstrumentMode.h>
#include <ERt60RunTime.h>
#include <EPartitionType.h>
#include <EFftFrequencySpan.h>
#include <EFftLines.h>
#include <EFftRunMode.h>
#include <EFftTonalityStandard.h>
#include <EObaRange.h>
#include <EHeaterState.h>
#include <ETHOptionId.h>
#include <ETHOptionType.h>
#include <EEditBandAction.h>
#include <EBlockTag.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI CLDRecordBase;
		class LDAPI ISlmRecord;
		class LDAPI CMeasureRt60;
		class LDAPI Array_SDataLimitsEDT_t;
		class LDAPI Array_float;
		struct LDAPI SRt60DataLimits_t;
		struct LDAPI SDataLimitsEDT_t;
		struct LDAPI SRt60Data_t;
		struct LDAPI SRT60_QI_t;
		class LDAPI Array_int32_t_2;
		class LDAPI Array_int32_t;
		struct LDAPI SWeatherData_t;
		class LDAPI Array_StringWrapper;
		struct LDAPI SCalData2_t;
		class LDAPI CCalibration;
		struct LDAPI SMeasControls_t;
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
		struct LDAPI SUserPreferences_t;
		struct LDAPI Sset_FloatArray11;
		struct LDAPI Sset_FloatArray13;
		struct LDAPI SSystemSettings_t;
		struct LDAPI SFirwareVersion_t;
		struct LDAPI Sset_IPAddr;
		struct LDAPI Sset_ByteString;
		struct LDAPI SSystemMetrics_t;
		struct LDAPI SMetrics_t;
		struct LDAPI SCalHistory_t;
		class LDAPI Array_SCalData_t;
		struct LDAPI SDailyNoise_t;
		struct LDAPI SOverload_t;
		struct LDAPI SGps_t;
		struct LDAPI Sdegmin;
		struct LDAPI SSpectraInfo_t;
		struct LDAPI SSlmLnInfo_t;
		class LDAPI CTimeHistoryManager;
		class LDAPI IList_SstTHItemInfo_t;
		class LDAPI IList_CTimeHistoryRecord;
		class LDAPI CTimeHistoryRecord;
		class LDAPI Array_float_2;
		class LDAPI CSessionLog;
		struct LDAPI SSessionLog_t;
		class LDAPI CRunRecord;
		class LDAPI IList_CRunRecord;
		class LDAPI IList_CSoundRecord;
		class LDAPI CSoundRecord;
		class LDAPI Array_uint8_t;
		class LDAPI IList_CIntervalInfo;
		class LDAPI CIntervalInfo;
		class LDAPI CMeasureRta;
		struct LDAPI SRtaRecord_t;
		struct LDAPI SRaHeader_t;
		class LDAPI Array_SEventCounts_t;
		struct LDAPI SEnvPreampData_t;
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
		class LDAPI IList_SEventTriggerConfig_t;
		struct LDAPI SEventTriggerConfig_t;
		class LDAPI Array_SDoseCriteria_t;
		struct LDAPI SDoseCriteria_t;
		struct LDAPI SCalHistory2_t;
		class LDAPI Array_SCalHistoryTypes_t;
		struct LDAPI SCalCheckHistory_t;
		class LDAPI Array_SCalData2_t;
		class LDAPI Array_Array_SCalData2_t;
		class LDAPI Array_uint32_t;
		struct LDAPI SEnvPreampInfo_t;
		class LDAPI CPartition;
		class LDAPI CRoomRx;
		class LDAPI Array_CMeasureRt60;
		class LDAPI CRoomTx;
		class LDAPI CMeasureFft;
		struct LDAPI SFftRecord_t;
		struct LDAPI SFftInfo_t;
		struct LDAPI SFftLevels_t;
		struct LDAPI SFftTriggerInfo_t;
		class LDAPI IList_CToneInfo;
		class LDAPI CToneInfo;
		class LDAPI IList_CMeasureFft;
		struct LDAPI Sslm2;
		struct LDAPI SDetectorTs_t;
		class LDAPI Array_SDetector_t;
		class LDAPI CTimeHistoryOptions;
		class LDAPI Array_SstTHOptionInfo_t;
		struct LDAPI SstTHOptionInfo_t;
		class LDAPI List_int32_t;
		class LDAPI List_ValueTuple_int32_t_StringWrapper;
		class LDAPI CMarineMammalsSummaryData;
		class LDAPI List_CMarineMammalsData;
		class LDAPI CMarineMammalsData;
		class LDAPI IComparer_CMarineMammalsData;
		class LDAPI Array_CMarineMammalsData;
		class LDAPI CMetaDataRecord;
		class LDAPI IGeneralMetaBlock;
		class LDAPI CGeneralInfo;
		class LDAPI IEditBandMetaBlock;
		class LDAPI SortedList_int32_t_CEditBandInfo;
		class LDAPI CEditBandInfo;
		class LDAPI IComparer_int32_t;
		class LDAPI IDictionary_int32_t_CEditBandInfo;
		class LDAPI IList_int32_t;
		class LDAPI IList_CEditBandInfo;
		class LDAPI IChartMetaBlock;
		class LDAPI IList_CChartInfo;
		class LDAPI CChartInfo;
		class LDAPI ICommentMetaBlock;
		class LDAPI List_CMarkerInfo;
		class LDAPI CMarkerInfo;
		class LDAPI IComparer_CMarkerInfo;
		class LDAPI Array_CMarkerInfo;
		class LDAPI IRt60DecayMetaBlock;
		class LDAPI List_CRt60DecayInfo;
		class LDAPI CRt60DecayInfo;
		class LDAPI IComparer_CRt60DecayInfo;
		class LDAPI Array_CRt60DecayInfo;
		class LDAPI CSoundRecordMetaBlock;
		class LDAPI IList_CSoundRecordInfo;
		class LDAPI CSoundRecordInfo;
		class LDAPI CManifestMetaBlock;
		class LDAPI IList_CMetaBlockInfo;
		class LDAPI CMetaBlockInfo;
		class LDAPI IAgencyApprovalInfo;

		class LDAPI CSlmRecord : public CLDRecordBase, public virtual ISlmRecord
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			CSlmRecord(const CSlmRecord& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~CSlmRecord(void);
			StringWrapper GetRT60DataAsString(std::shared_ptr<CMeasureRt60> t2, ERt60RecType id, int32_t bin, ERt60Method method);
			StringWrapper GetRT60SampleTimeAsString(int32_t row);
			StringWrapper GetRT60SampleTimeAsString(ERt60SamplePeriod period, int32_t row);
			StringWrapper GetRT60SampleTimeAsString(std::shared_ptr<CMeasureRt60> t2, ERt60SamplePeriod period, int32_t row);
			StringWrapper GetRT60SampleDataAsString(int32_t row, int32_t bin);
			StringWrapper GetRT60SampleDataAsString(std::shared_ptr<CMeasureRt60> t2, int32_t row, int32_t bin);
			StringWrapper GetRT60SamplePeriodAsString(bool incUnits = true);
			StringWrapper GetRT60SamplePeriodAsString(ERt60SamplePeriod period, bool incUnits = true);
			StringWrapper GetRT60SamplePeriodAsString(std::shared_ptr<CMeasureRt60> t2, ERt60SamplePeriod period, bool incUnits = true);
			StringWrapper GetRT60TriggerSourceAsString(void);
			StringWrapper GetRT60TriggerSourceAsString(EFrequency source);
			StringWrapper GetRT60TriggerMethodAsString(void);
			StringWrapper GetRT60TriggerMethodAsString(ERt60Method method);
			StringWrapper GetRT60NoiseSourceAsString(void);
			StringWrapper GetRT60NoiseSourceAsString(ERt60NoiseType source);
			StringWrapper GetRT60BandwidthAsString(void);
			StringWrapper GetRT60BandwidthAsString(std::shared_ptr<CMeasureRt60> t2);
			ERt60QualityIndicator GetRT60Quality(ERt60RecType id, int32_t bin, ERt60Method method);
			ERt60QualityIndicator GetRT60Quality(std::shared_ptr<CMeasureRt60> t2, ERt60RecType id, int32_t bin, ERt60Method method);
			static StringWrapper GetRT60ColumnName(ERt60RecType id, bool addUnits = true, bool addTn = false);
			int32_t GetRT60GradeIndex(ERt60MeasurementGrade gradeId);
			int32_t GetRT60QualifiedPositions(ERt60MeasurementGrade gradeId, int32_t& minDecays);
			ERt60MeasurementGrade GetRT60MeasurementGrade(int32_t& qualPositions, int32_t& qualDecays, ERt60GradeSetting& settingId);
			uint32_t GetFftFlags(void);
			uint32_t GetFftTimeSeconds(void);
			uint32_t GetFftTimeMicro(void);
			float GetFftDuration(void);
			int32_t GetFftOverallCount(void);
			int32_t GetFftHistCount(int32_t selectedHistory = 0);
			int32_t GetFftOverloadCount(void);
			float GetFftOverloadDuration(void);
			float GetFftLeq(EVsqConvert convert);
			float GetFftLpeak(EVsqConvert convert);
			uint32_t GetFftArraySize(void);
			float GetFftData(EFftLevel levelId, int32_t ndx, EVsqConvert convert);
			int32_t GetFftFrequencySpan(void);
			int32_t GetFftNumLines(void);
			float GetFftResolution(void);
			StringWrapper GetFftWindowString(void);
			StringWrapper GetFftRunModeString(void);
			float GetFftToneSeekDelta(void);
			float GetFftToneSeekDelta(EFftToneSeekDelta delta);
			float GetFftRegressionRange(void);
			float GetFftRegressionRange(EFftRegressionRange range);
			float GetFftWindowCorrection(void);
			float GetFftWindowCorrection(EFftWindow window);
			float GetFrequencyFromLine(int32_t line);
			void UpdateDecaysPerPositionWithMetaData(void);
			void UpdateDecaysWithMetaData(void);
			void Rt60CalcData(std::shared_ptr<ISlmRecord> rec, int32_t posIndex);
			int32_t ReverseIntegrationImpulse(std::shared_ptr<CMeasureRt60>& mainPosition, std::shared_ptr<Array_SDataLimitsEDT_t>& edt_indices, std::shared_ptr<Array_float>& schroederSamples, int32_t numSamples, int32_t maxIndex, float maxVal, int32_t band, float noiseFloor, std::shared_ptr<Array_float> samples);
			void rt60_calc_slopes(std::shared_ptr<Array_float> data, std::shared_ptr<SRt60DataLimits_t> decay_indices, std::shared_ptr<SDataLimitsEDT_t>& edt_indices, int32_t rt60_method, std::shared_ptr<SRt60Data_t>& rt60_data);
			void CalcQualityIndicators(std::shared_ptr<Array_float> data, std::shared_ptr<SRt60DataLimits_t> limits, std::shared_ptr<SRt60Data_t> rt60_data, std::shared_ptr<SRT60_QI_t>& quality_indicator);
			static int32_t find_first_point_below(std::shared_ptr<Array_float> p_data_in, int32_t start_index, int32_t end_index, float search_level);
			void InitModifiedSlmRecord(std::shared_ptr<ISlmRecord> orgRec);
			int64_t GetTimeHistoryTimestamp(int32_t entryNum);
			int32_t FindIndexOfTimeHistEntry(int64_t timeMS);
			ERmsWeightId GetRmsWeightId(EWeightingNdx nDx);
			EPeakWeightId GetPeakWeightId(EWeightingNdx nDx);
			EDetectorId GetDetectorId(EDetectorNdx nDx);
			EWeightingNdx GetRmsWeightIndex(ERmsWeightId id);
			EWeightingNdx GetPeakWeightIndex(EPeakWeightId id);
			EDetectorNdx GetDetectorIndex(EDetectorId id);
			StringWrapper GetRmsWeightString(void);
			StringWrapper GetRmsWeightString(ERmsWeightId id);
			StringWrapper GetRmsWeightString(EWeightingNdx ndx);
			StringWrapper GetPeakWeightString(void);
			StringWrapper GetPeakWeightString(EPeakWeightId id);
			StringWrapper GetPeakWeightString(EWeightingNdx ndx);
			StringWrapper GetDetectorString(bool longStr = false);
			StringWrapper GetDetectorString(EDetectorId id, bool longStr = false);
			StringWrapper GetDetectorString(EDetectorNdx ndx, bool longStr = false);
			float GetLdn(void);
			float GetLdnDay(void);
			float GetLdnNight(void);
			float GetLden(void);
			float GetLdenDay(void);
			float GetLdenEve(void);
			float GetLdenNight(void);
			float GetSE(void);
			float GetSE(int32_t hours);
			float GetSE(int32_t hours, float leq, float duration);
			float GetSEL(void);
			float GetSEL(float leq, float runTime);
			float GetPaHrMagnitude(float sel, StringWrapper& format, StringWrapper& units, bool truncate = false);
			float GetLn(int32_t ndx);
			float GetdBFromBin(int32_t nBin);
			float CalcLn(float val, std::shared_ptr<Array_int32_t_2> spectra, int32_t ndx);
			float CalcLn(float val, std::shared_ptr<Array_int32_t> table);
			float CalcTonality(std::shared_ptr<Array_float> spectra);
			float GetDose(int32_t ndx);
			float GetProjectedDose(int32_t ndx);
			float GetLepd(int32_t ndx);
			float GetCritTwa(int32_t ndx);
			float GetTimeHistorySamplePeriod(void);
			float GetTimeHistorySamplePeriod(ETimeHistoryPeriod period);
			StringWrapper GetPreferredUnits(EUnitType type);
			float ConvertToPreferredUnits(EUnitType type, float val);
			float GetWindyDirPercentage(int32_t ndx);
			float GetWindyDirPercentage(std::shared_ptr<SWeatherData_t> weather, int32_t ndx);
			std::shared_ptr<Array_StringWrapper> GetObaFrequencyLabels(int32_t bins, ELabelFormat labelFormat, bool localize = true);
			bool IsLnTableValid(void);
			bool Is831(void);
			bool Is831C(void);
			bool Is831(float ver);
			bool IsLxT(void);
			bool IsLxT(float ver);
			bool IsObaAvailable(void);
			bool IsSpectralLnAvailable(void);
			bool IsMeasSpectralLnAvailable(void);
			bool IsStatisticsAvailable(void);
			bool IsTimeHistoryAvailable(void);
			int32_t GetTimeHistoryCount(void);
			bool IsMeasurementHistoryAvailable(void);
			bool IsEventHistoryAvailable(void);
			bool IsEventTimeHistoryAvailable(void);
			int32_t GetEventTimeHistoryCount(void);
			bool IsFrenchNf30Active(void);
			bool IsOutdoorPreampAvailable(void);
			bool IsValidCalHistoryAvailable(void);
			bool IsValidCalCheckHistoryAvailable(void);
			bool IsFftHistoryAvailable(void);
			bool IsFftTonalityAvailable(void);
			bool IsSystemMetricsAvailable(void);
			void InitCalHistoryData(void);
			void GetEACalCheck(std::shared_ptr<SCalData2_t> calData, float stdLevel, float& scale, float& diff);
			std::shared_ptr<CCalibration> GetPreCalData(bool skipSessionLog = false);
			std::shared_ptr<CCalibration> GetPostCalData(void);
			StringWrapper GetMicrophoneInfo(void);
			ERt60Bandwidth GetRT60Bandwidth(void);
			uint32_t GetRT60TotalCount(void);
			uint32_t GetRT60AverageCount(void);
			uint32_t GetRT60Positions(void);
			int32_t GetRT60DecaysPerPosition(int32_t nDx);
			int32_t GetRT60LeastDecaysFromPositions(void);
			int32_t GetRT60SampleCount(void);
			float GetRT60Data(ERt60RecType id, int32_t bin, ERt60Method method);
			float GetRT60Data(std::shared_ptr<CMeasureRt60> t2, ERt60RecType id, int32_t bin, ERt60Method rt60Method);
			float GetRT60SampleTime(int32_t ndx);
			float GetRT60SampleTime(ERt60SamplePeriod period, int32_t ndx);
			float GetRT60SampleTime(std::shared_ptr<CMeasureRt60> t2, ERt60SamplePeriod period, int32_t ndx);
			float GetRT60SamplePeriod(void);
			float GetRT60SamplePeriod(ERt60SamplePeriod period);
			float GetRT60SamplePeriod(std::shared_ptr<CMeasureRt60> t2, ERt60SamplePeriod period);
			float GetRT60SampleData(int32_t ndx, int32_t bin);
			float GetRT60SampleData(std::shared_ptr<CMeasureRt60> t2, int32_t ndx, int32_t bin);
			StringWrapper GetRT60DataAsString(ERt60RecType id, int32_t bin, ERt60Method method);
			StringWrapper GetMetricType(void);
			float GetMetricValue(void);
			StringWrapper GetDesiredMetricSetting(void);
			CSlmRecord(void);
			int32_t MeasPropsVersion(void);
			void MeasPropsVersion(int32_t value);
			int32_t MeasPropsStructSize(void);
			void MeasPropsStructSize(int32_t value);
			std::shared_ptr<SMeasControls_t> MeasProperties(void);
			void MeasProperties(std::shared_ptr<SMeasControls_t> value);
			int32_t UserPropsVersion(void);
			void UserPropsVersion(int32_t value);
			int32_t UserPropsStructSize(void);
			void UserPropsStructSize(int32_t value);
			std::shared_ptr<SUserPreferences_t> UserProperties(void);
			void UserProperties(std::shared_ptr<SUserPreferences_t> value);
			int32_t SysPropsVersion(void);
			void SysPropsVersion(int32_t value);
			int32_t SysPropsStructSize(void);
			void SysPropsStructSize(int32_t value);
			std::shared_ptr<SSystemSettings_t> SysProperties(void);
			void SysProperties(std::shared_ptr<SSystemSettings_t> value);
			std::shared_ptr<SSystemMetrics_t> SystemMetrics(void);
			void SystemMetrics(std::shared_ptr<SSystemMetrics_t> value);
			uint32_t StartTimeSeconds(void);
			int64_t StartTime(void);
			void StartTime(int64_t value);
			uint32_t RunTimeSeconds(void);
			float RunTime(void);
			void RunTime(float value);
			int64_t LastModifiedTime(void);
			int64_t FileSize(void);
			StringWrapper Metric1Type(void);
			float Metric1Level(void);
			StringWrapper LdbinFileName(void);
			void LdbinFileName(StringWrapper value);
			StringWrapper OverallTitle(void);
			void OverallTitle(StringWrapper value);
			StringWrapper SetupName(void);
			void SetupName(StringWrapper value);
			std::shared_ptr<Array_StringWrapper> MarkerNames(void);
			void MarkerNames(std::shared_ptr<Array_StringWrapper> value);
			ERmsWeightId FrequencyWeighting(void);
			void FrequencyWeighting(ERmsWeightId value);
			EPeakWeightId PeakWeighting(void);
			void PeakWeighting(EPeakWeightId value);
			EDetectorId Detector(void);
			void Detector(EDetectorId value);
			EWeightingNdx RmsWeightIndex(void);
			void RmsWeightIndex(EWeightingNdx value);
			EWeightingNdx PeakWeightIndex(void);
			void PeakWeightIndex(EWeightingNdx value);
			EDetectorNdx DetectorIndex(void);
			void DetectorIndex(EDetectorNdx value);
			EWeightingNdx ObaWeightIndex(void);
			void ObaWeightIndex(EWeightingNdx value);
			int32_t SerialNum(void);
			void SerialNum(int32_t value);
			int32_t CurDose(void);
			void CurDose(int32_t value);
			int32_t NumberMeasurements(void);
			void NumberMeasurements(int32_t value);
			int32_t CalibrationLevelTenthsDB(void);
			void CalibrationLevelTenthsDB(int32_t value);
			ETimeHistoryPeriod SamplePeriod(void);
			void SamplePeriod(ETimeHistoryPeriod value);
			EIntegrationMethod Integration(void);
			void Integration(EIntegrationMethod value);
			EObaBandwidth ObaBandWidth(void);
			void ObaBandWidth(EObaBandwidth value);
			int32_t ObaMaxSpectra(void);
			void ObaMaxSpectra(int32_t value);
			int32_t Language(void);
			void Language(int32_t value);
			int32_t DecimalFormat(void);
			void DecimalFormat(int32_t value);
			int32_t DateFormat(void);
			void DateFormat(int32_t value);
			int32_t TaktMetricEnable(void);
			void TaktMetricEnable(int32_t value);
			ERandomCorrection RICorrection(void);
			void RICorrection(ERandomCorrection value);
			int32_t AudioCompression(void);
			void AudioCompression(int32_t value);
			std::shared_ptr<Array_float> LnValues(void);
			void LnValues(std::shared_ptr<Array_float> value);
			float SplTrig1(void);
			void SplTrig1(float value);
			float SplTrig2(void);
			void SplTrig2(float value);
			float PeakTrig1(void);
			void PeakTrig1(float value);
			float PeakTrig2(void);
			void PeakTrig2(float value);
			float PeakTrig3(void);
			void PeakTrig3(float value);
			float Trig1Duration(void);
			void Trig1Duration(float value);
			float Trig2Duration(void);
			void Trig2Duration(float value);
			float Peak1Duration(void);
			void Peak1Duration(float value);
			float Peak2Duration(void);
			void Peak2Duration(float value);
			float Peak3Duration(void);
			void Peak3Duration(float value);
			int32_t Trig1Count(void);
			void Trig1Count(int32_t value);
			int32_t Trig2Count(void);
			void Trig2Count(int32_t value);
			int32_t Peak1Count(void);
			void Peak1Count(int32_t value);
			int32_t Peak2Count(void);
			void Peak2Count(int32_t value);
			int32_t Peak3Count(void);
			void Peak3Count(int32_t value);
			int32_t SlmGain(void);
			void SlmGain(int32_t value);
			float PauseTime(void);
			void PauseTime(float value);
			float Leq(void);
			void Leq(float value);
			float Max(void);
			void Max(float value);
			float Peak(void);
			void Peak(float value);
			float Min(void);
			void Min(float value);
			float LCeq(void);
			void LCeq(float value);
			float LAeq(void);
			void LAeq(float value);
			float SEA(void);
			void SEA(float value);
			float LTm5(void);
			void LTm5(float value);
			float LwIeq(void);
			void LwIeq(float value);
			float Lweq(void);
			void Lweq(float value);
			float CminusA(void);
			void CminusA(float value);
			float Wimplminusleq(void);
			void Wimplminusleq(float value);
			float EveningPenalty(void);
			void EveningPenalty(float value);
			float NightPenalty(void);
			void NightPenalty(float value);
			bool MeasSnapShotEnable(void);
			void MeasSnapShotEnable(bool value);
			bool EnableExceedAudioSnapshot(void);
			void EnableExceedAudioSnapshot(bool value);
			uint32_t MeasSnapShotPeriod(void);
			void MeasSnapShotPeriod(uint32_t value);
			uint32_t MeasurementPeriod(void);
			void MeasurementPeriod(uint32_t value);
			uint32_t DayTime(void);
			void DayTime(uint32_t value);
			uint32_t EveningTime(void);
			void EveningTime(uint32_t value);
			uint32_t NightTime(void);
			void NightTime(uint32_t value);
			uint32_t ExcSnapShotPeriod(void);
			void ExcSnapShotPeriod(uint32_t value);
			uint32_t SnapShotPreTrig(void);
			void SnapShotPreTrig(uint32_t value);
			EUnitConversion UnitsSystem(void);
			void UnitsSystem(EUnitConversion value);
			int32_t GPSControl(void);
			void GPSControl(int32_t value);
			uint32_t ExcdTHCount(void);
			void ExcdTHCount(uint32_t value);
			uint32_t ExcdTHPreCount(void);
			void ExcdTHPreCount(uint32_t value);
			int32_t ExcdTHSpectra(void);
			void ExcdTHSpectra(int32_t value);
			ETimeHistoryPeriod ExcdTHPeriod(void);
			void ExcdTHPeriod(ETimeHistoryPeriod value);
			EPreampType NFPreampType(void);
			void NFPreampType(EPreampType value);
			int32_t NFWeighting(void);
			void NFWeighting(int32_t value);
			int32_t MeasSpectralLn(void);
			void MeasSpectralLn(int32_t value);
			int32_t NumOBA(void);
			void NumOBA(int32_t value);
			std::shared_ptr<Array_int32_t_2> SpectralLns(void);
			void SpectralLns(std::shared_ptr<Array_int32_t_2> value);
			int64_t EndTime(void);
			void EndTime(int64_t value);
			int64_t PeakMaxTime(void);
			void PeakMaxTime(int64_t value);
			int64_t MaxTime(void);
			void MaxTime(int64_t value);
			int64_t MinTime(void);
			void MinTime(int64_t value);
			int32_t FirstStatisticsRow(void);
			void FirstStatisticsRow(int32_t value);
			std::shared_ptr<SCalHistory_t> OldCalData(void);
			void OldCalData(std::shared_ptr<SCalHistory_t> value);
			std::shared_ptr<SDailyNoise_t> DailyNoise(void);
			void DailyNoise(std::shared_ptr<SDailyNoise_t> value);
			std::shared_ptr<SOverload_t> OverLoads(void);
			void OverLoads(std::shared_ptr<SOverload_t> value);
			std::shared_ptr<SGps_t> GPSData(void);
			void GPSData(std::shared_ptr<SGps_t> value);
			std::shared_ptr<SSpectraInfo_t> FullOctaveSpectra(void);
			void FullOctaveSpectra(std::shared_ptr<SSpectraInfo_t> value);
			std::shared_ptr<SSpectraInfo_t> ThirdOctaveSpectra(void);
			void ThirdOctaveSpectra(std::shared_ptr<SSpectraInfo_t> value);
			std::shared_ptr<SSlmLnInfo_t> LnInfo(void);
			void LnInfo(std::shared_ptr<SSlmLnInfo_t> value);
			std::shared_ptr<CTimeHistoryManager> THMngr(void);
			void THMngr(std::shared_ptr<CTimeHistoryManager> value);
			std::shared_ptr<CSessionLog> SessionLog(void);
			void SessionLog(std::shared_ptr<CSessionLog> value);
			std::shared_ptr<IList_CIntervalInfo> Intervals(void);
			void Intervals(std::shared_ptr<IList_CIntervalInfo> value);
			std::shared_ptr<IList_CEventInfo> Events(void);
			void Events(std::shared_ptr<IList_CEventInfo> value);
			std::shared_ptr<IList_SEventTriggerConfig_t> EventTriggers(void);
			void EventTriggers(std::shared_ptr<IList_SEventTriggerConfig_t> value);
			std::shared_ptr<Array_SDoseCriteria_t> Dose(void);
			void Dose(std::shared_ptr<Array_SDoseCriteria_t> value);
			std::shared_ptr<Array_float> TWA(void);
			void TWA(std::shared_ptr<Array_float> value);
			std::shared_ptr<Array_float> FullOctaveReferenceSpectra1(void);
			void FullOctaveReferenceSpectra1(std::shared_ptr<Array_float> value);
			std::shared_ptr<Array_float> FullOctaveReferenceSpectra2(void);
			void FullOctaveReferenceSpectra2(std::shared_ptr<Array_float> value);
			std::shared_ptr<Array_float> FullOctaveReferenceSpectra3(void);
			void FullOctaveReferenceSpectra3(std::shared_ptr<Array_float> value);
			std::shared_ptr<Array_float> FullOctaveReferenceSpectra4(void);
			void FullOctaveReferenceSpectra4(std::shared_ptr<Array_float> value);
			std::shared_ptr<Array_float> ThirdOctaveReferenceSpectra1(void);
			void ThirdOctaveReferenceSpectra1(std::shared_ptr<Array_float> value);
			std::shared_ptr<Array_float> ThirdOctaveReferenceSpectra2(void);
			void ThirdOctaveReferenceSpectra2(std::shared_ptr<Array_float> value);
			std::shared_ptr<Array_float> ThirdOctaveReferenceSpectra3(void);
			void ThirdOctaveReferenceSpectra3(std::shared_ptr<Array_float> value);
			std::shared_ptr<Array_float> ThirdOctaveReferenceSpectra4(void);
			void ThirdOctaveReferenceSpectra4(std::shared_ptr<Array_float> value);
			StringWrapper FullOctaveReferenceSpectra1Name(void);
			void FullOctaveReferenceSpectra1Name(StringWrapper value);
			StringWrapper FullOctaveReferenceSpectra2Name(void);
			void FullOctaveReferenceSpectra2Name(StringWrapper value);
			StringWrapper FullOctaveReferenceSpectra3Name(void);
			void FullOctaveReferenceSpectra3Name(StringWrapper value);
			StringWrapper FullOctaveReferenceSpectra4Name(void);
			void FullOctaveReferenceSpectra4Name(StringWrapper value);
			StringWrapper ThirdOctaveReferenceSpectra1Name(void);
			void ThirdOctaveReferenceSpectra1Name(StringWrapper value);
			StringWrapper ThirdOctaveReferenceSpectra2Name(void);
			void ThirdOctaveReferenceSpectra2Name(StringWrapper value);
			StringWrapper ThirdOctaveReferenceSpectra3Name(void);
			void ThirdOctaveReferenceSpectra3Name(StringWrapper value);
			StringWrapper ThirdOctaveReferenceSpectra4Name(void);
			void ThirdOctaveReferenceSpectra4Name(StringWrapper value);
			std::shared_ptr<SCalHistory2_t> CalHistory(void);
			void CalHistory(std::shared_ptr<SCalHistory2_t> value);
			std::shared_ptr<SCalCheckHistory_t> CalCheckHistory(void);
			void CalCheckHistory(std::shared_ptr<SCalCheckHistory_t> value);
			std::shared_ptr<Array_Array_SCalData2_t> CalData(void);
			void CalData(std::shared_ptr<Array_Array_SCalData2_t> value);
			std::shared_ptr<SWeatherData_t> Weather(void);
			void Weather(std::shared_ptr<SWeatherData_t> value);
			std::shared_ptr<SEnvPreampInfo_t> EnvPreampInfo(void);
			void EnvPreampInfo(std::shared_ptr<SEnvPreampInfo_t> value);
			std::shared_ptr<SEnvPreampData_t> EnvPreampData(void);
			void EnvPreampData(std::shared_ptr<SEnvPreampData_t> value);
			EWeatherEnable WeatherOption(void);
			void WeatherOption(EWeatherEnable value);
			EWindDirection WindDirection(void);
			void WindDirection(EWindDirection value);
			int32_t WindPause(void);
			void WindPause(int32_t value);
			float WindScale(void);
			void WindScale(float value);
			float WindThreshold(void);
			void WindThreshold(float value);
			float WindExcdLevel(void);
			void WindExcdLevel(float value);
			float WindHysteresis(void);
			void WindHysteresis(float value);
			float ADC1Scale(void);
			void ADC1Scale(float value);
			float ADC1Offset(void);
			void ADC1Offset(float value);
			float ADC2Scale(void);
			void ADC2Scale(float value);
			float ADC2Offset(void);
			void ADC2Offset(float value);
			StringWrapper WindUnits(void);
			void WindUnits(StringWrapper value);
			StringWrapper ADC1Units(void);
			void ADC1Units(StringWrapper value);
			StringWrapper ADC1Description(void);
			void ADC1Description(StringWrapper value);
			StringWrapper ADC2Units(void);
			void ADC2Units(StringWrapper value);
			StringWrapper ADC2Description(void);
			void ADC2Description(StringWrapper value);
			EInstrumentMode Mode(void);
			void Mode(EInstrumentMode value);
			int32_t ExitTime(void);
			void ExitTime(int32_t value);
			EFrequency LoBand(void);
			void LoBand(EFrequency value);
			EFrequency HiBand(void);
			void HiBand(EFrequency value);
			ERt60NoiseType Rt60NoiseType(void);
			void Rt60NoiseType(ERt60NoiseType value);
			float Rt60Attenuation(void);
			void Rt60Attenuation(float value);
			ERt60Method Rt60TriggerMethod(void);
			void Rt60TriggerMethod(ERt60Method value);
			EFrequency Rt60TriggerSource(void);
			void Rt60TriggerSource(EFrequency value);
			float Rt60TriggerLevel(void);
			void Rt60TriggerLevel(float value);
			ERt60Bandwidth Rt60Bandwidth(void);
			void Rt60Bandwidth(ERt60Bandwidth value);
			int32_t Rt60BuildTime(void);
			void Rt60BuildTime(int32_t value);
			ERt60RunTime Rt60RunTime(void);
			void Rt60RunTime(ERt60RunTime value);
			int32_t Rt60RunCount(void);
			void Rt60RunCount(int32_t value);
			ERt60SamplePeriod Rt60SamplePeriod(void);
			void Rt60SamplePeriod(ERt60SamplePeriod value);
			int32_t Rt60SaveAverage(void);
			void Rt60SaveAverage(int32_t value);
			int32_t Rt60SaveAll(void);
			void Rt60SaveAll(int32_t value);
			ERt60NoiseType RtaNoiseType(void);
			void RtaNoiseType(ERt60NoiseType value);
			float RtaAttenuation(void);
			void RtaAttenuation(float value);
			ERt60Bandwidth RtaBandwidth(void);
			void RtaBandwidth(ERt60Bandwidth value);
			int32_t RtaL1Range(void);
			void RtaL1Range(int32_t value);
			int32_t RtaL2Range(void);
			void RtaL2Range(int32_t value);
			int32_t RtaB2Range(void);
			void RtaB2Range(int32_t value);
			std::shared_ptr<CPartition> P1(void);
			void P1(std::shared_ptr<CPartition> value);
			EFftWindow FftWindow(void);
			void FftWindow(EFftWindow value);
			EFftFrequencySpan FftFreqSpan(void);
			void FftFreqSpan(EFftFrequencySpan value);
			EFftLines FftLines(void);
			void FftLines(EFftLines value);
			EFftRunMode FftRunMode(void);
			void FftRunMode(EFftRunMode value);
			std::shared_ptr<CMeasureFft> FftOverall(void);
			void FftOverall(std::shared_ptr<CMeasureFft> value);
			std::shared_ptr<IList_CMeasureFft> FftHistory(void);
			void FftHistory(std::shared_ptr<IList_CMeasureFft> value);
			uint32_t RunTimer(void);
			void RunTimer(uint32_t value);
			int32_t MeasHistEnabled(void);
			void MeasHistEnabled(int32_t value);
			uint32_t MeasCounts(void);
			void MeasCounts(uint32_t value);
			EObaRange ObaRange(void);
			void ObaRange(EObaRange value);
			EHeaterState VaisalaHeaterState(void);
			void VaisalaHeaterState(EHeaterState value);
			uint32_t VaisalaHeaterEnaTime(void);
			void VaisalaHeaterEnaTime(uint32_t value);
			uint32_t VaisalaHeaterDisTime(void);
			void VaisalaHeaterDisTime(uint32_t value);
			EFftTonalityStandard FftTonality(void);
			void FftTonality(EFftTonalityStandard value);
			EFftToneSeekDelta ToneSeekDelta(void);
			void ToneSeekDelta(EFftToneSeekDelta value);
			EFftRegressionRange RegressionRange(void);
			void RegressionRange(EFftRegressionRange value);
			bool TimeHistoryTruncated(void);
			void TimeHistoryTruncated(bool value);
			bool EventTimeHistoryTruncated(void);
			void EventTimeHistoryTruncated(bool value);
			bool XducerEnable(void);
			void XducerEnable(bool value);
			int32_t XducerUnits(void);
			void XducerUnits(int32_t value);
			std::shared_ptr<Sslm2> AnyData(void);
			void AnyData(std::shared_ptr<Sslm2> value);
			std::shared_ptr<CTimeHistoryOptions> TimeHistOptions(void);
			int32_t GustDirectionColumn(void);
			void GustDirectionColumn(int32_t value);
			int32_t WindDirectionColumn(void);
			void WindDirectionColumn(int32_t value);
			std::shared_ptr<CMarineMammalsSummaryData> MarineMammalsSummary(void);
			void MarineMammalsSummary(std::shared_ptr<CMarineMammalsSummaryData> value);
			std::shared_ptr<List_CMarineMammalsData> MarineMammalsResults(void);
			void MarineMammalsResults(std::shared_ptr<List_CMarineMammalsData> value);
			std::shared_ptr<Array_float> OverallLns(void);
			std::shared_ptr<CMetaDataRecord> MetaRec(void);
			bool TmsEnabled(void);
			std::shared_ptr<IAgencyApprovalInfo> AgencyInfo(void);
			void AgencyInfo(std::shared_ptr<IAgencyApprovalInfo> value);
			int32_t MeasAlertTriggerSource(void);
			void MeasAlertTriggerSource(int32_t value);
			float MeasAlertTriggerLevel(void);
			void MeasAlertTriggerLevel(float value);
			StringWrapper XducerUnitsCustom(void);
			void XducerUnitsCustom(StringWrapper value);
			float XducerSensitivity(void);
			void XducerSensitivity(float value);
			float VoltageCalibration(void);
			void VoltageCalibration(float value);
			float RangeCalibration(void);
			void RangeCalibration(float value);
			float ObaLowRangeCalibration(void);
			void ObaLowRangeCalibration(float value);
			float GainCalibration(void);
			void GainCalibration(float value);
			std::shared_ptr<Array_float_2> whole_octave_info(void);
			void whole_octave_info(std::shared_ptr<Array_float_2> value);
			std::shared_ptr<Array_float_2> third_octave_info(void);
			void third_octave_info(std::shared_ptr<Array_float_2> value);
#ifdef MAKEDLL
		public: // This is for internal use
			CSlmRecord(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _CSLM_RECORD_H
