/**************************************************************************//**
 * @file CSpartanRecord.h
 * @brief Native Wrapper for Managed type SpartanRecord.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _CSPARTAN_RECORD_H
#define _CSPARTAN_RECORD_H
#include <CLDRecordBase.h>
#include <ISpartanRecord.h>
#include <EContModeInterval_t.h>
#include <EExchangeRateId_t.h>
#include <EDateFormatSpartan_t.h>
#include <ELanguage.h>
#include <EDecimalFormat.h>
#include <EDosAutoOff_t.h>
#include <EPropOnOff_t.h>
#include <EFreqWeighting_t.h>
#include <EDetectorSelect_t.h>
#include <EPeakWeighting_t.h>
#include <EDoseMode_t.h>
#include <EDosAlarmSrc_t.h>
#include <EPropObaSetting_t.h>
#include <ETimerMode_t.h>
#include <EMinMaxSelect_t.h>
#include <ETimeHistoryMetricFlags.h>
#include <ETimeHistoryMetricFlags_B2.h>
#include <ETimeHistoryMetricFlags_B3.h>
#include <ETimeHistoryMetricFlags_B4.h>
#include <EPreampType.h>
#include <ESpartanFileBlockVersion.h>
#include <ETimeHistoryFlags.h>
#include <ESpartanSLogType.h>
#include <ESpartanSLogCause.h>
#include <EEditBandAction.h>
#include <ECalibrationType.h>
#include <EMetricId.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI CLDRecordBase;
		class LDAPI ISpartanRecord;
		class LDAPI CCalibration;
		struct LDAPI STwa_t;
		struct LDAPI SDateTime;
		struct LDAPI SManifestBlockSpartan_t;
		struct LDAPI SFileInfoHeaderSpartan_t;
		struct LDAPI SBlockHeaderSpartan_t;
		struct LDAPI SManifestEntrySpartan_t;
		struct LDAPI SBlockFooterSpartan_t;
		struct LDAPI SSysSettingsSpartan_t;
		struct LDAPI SString16_t;
		struct LDAPI SString32_t;
		struct LDAPI SString256_t;
		struct LDAPI SMeasSettingsSpartan_t;
		struct LDAPI SString64_t;
		struct LDAPI SOverallDataSpartan_t;
		class LDAPI Array_SDetectorTs_t;
		class LDAPI Array_STwa_t;
		struct LDAPI SModifiedDataSpartan_t;
		struct LDAPI SDailyNoise_t;
		struct LDAPI SObaData48Bins_t;
		struct LDAPI SExcdDataSpartan_t;
		class LDAPI Array_SExceedanceDataRecordSpartan_t;
		struct LDAPI SLnDataSpartan_t;
		class LDAPI Array_float;
		struct LDAPI SPrePostCalSpartan_v2_t;
		class LDAPI Array_uint8_t;
		struct LDAPI SDeviceInfoSpartan_t;
		class LDAPI IList_CTimeHistoryEntry_t;
		class LDAPI CTimeHistoryEntry_t;
		class LDAPI IList_CX21MetricMeta;
		struct LDAPI Nullable_uint32_t;
		class LDAPI List_float;
		class LDAPI List_IConvertible;
		class LDAPI IList_CSessionLogEntry_t;
		class LDAPI CSessionLogEntry_t;
		class LDAPI IList_CSpartanInterval;
		class LDAPI CSpartanInterval;
		struct LDAPI SMeasHistSpartan_t;
		struct LDAPI SMeasAnyDataSpartan_t;
		class LDAPI Array_float_2;
		class LDAPI Array_int64_t_2;
		class LDAPI Array_int64_t;
		struct LDAPI SOverloadSpartan_t;
		class LDAPI IList_StringWrapper;
		class LDAPI IList_CSpartanSoundRecord;
		class LDAPI CSpartanSoundRecord;
		class LDAPI IAgencyApprovalInfo;
		class LDAPI IList_uint32_t;
		class LDAPI CSpartanMetaRecord;
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
		struct LDAPI SCalData2_t;
		struct LDAPI Nullable_float;
		class LDAPI CX21MetricMeta;

		class LDAPI CSpartanRecord : public CLDRecordBase, public virtual ISpartanRecord
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			CSpartanRecord(const CSpartanRecord& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~CSpartanRecord(void);
			StringWrapper GetMicrophoneInfo(void);
			void SetPreampName(void);
			std::shared_ptr<CCalibration> GetPreCalData(bool skipSessionLog = false);
			StringWrapper getDateTime(uint32_t t);
			StringWrapper getDate(uint32_t t);
			StringWrapper getAutoStoreInterval(EContModeInterval_t t);
			StringWrapper getHHMMSS(uint32_t t);
			StringWrapper getHHMMSS(double t);
			StringWrapper getHours(uint32_t t);
			float getQ(EExchangeRateId_t ExchangeRateId);
			void removeTwaSample(float In, std::shared_ptr<STwa_t>& pTwa, float Threshold, int32_t ExchangeRate);
			void addTwaSample(float In, std::shared_ptr<STwa_t>& pTwa, float Threshold, int32_t ExchangeRate);
			void addTwaSampleAccum(float In, std::shared_ptr<STwa_t>& pTwa, float Threshold, int32_t ExchangeRate, float period = 1);
			StringWrapper calcSel(float spl, float runtime);
			StringWrapper calcAndFormatLepd(float spl, float runtime, float criterion_time);
			float calcLepd(float spl, float runtime, float criterion_time);
			StringWrapper calcTwaX(float lavg, float runtime, float criterion_time, float q_ex_rate);
			StringWrapper calcDose(float lavg, float runtime, float criterionTime, float qExRate, float criterionLevel);
			float calcDoseFloat(float lavg, float runtime, float criterionTime, float qExRate, float criterionLevel);
			StringWrapper calcProjDose(float lavg, float qExRate, float criterionLevel, float criterionTime, float shiftTime);
			StringWrapper calcProjTwa(float lavg, float qExRate, float criterionTime, float shiftTime);
			void SetFileHadMetaRecordProp(bool state, StringWrapper callerName = L"");
			bool IsObaAvailable(void);
			bool IsMeasurementHistoryAvailable(void);
			bool IsLnAvailable(void);
			StringWrapper GetMetricType(void);
			float GetMetricValue(void);
			StringWrapper GetDesiredMetricSetting(void);
			int64_t GetTimeHistoryTimestamp(int32_t entryNum);
			void UpdateUserFields(StringWrapper newUser, StringWrapper newJobDesc, StringWrapper newLoc, StringWrapper newNotes);
			StringWrapper FormatValue(float fValue, int32_t limit = 999);
			float GetLdn(void);
			float GetLdnDay(void);
			float GetLdnNight(void);
			float GetLden(void);
			float GetLdenDay(void);
			float GetLdenEve(void);
			float GetLdenNight(void);
			void SetLnPercentiles(void);
			float GetDurationPeriod(int32_t timeHistoryPeriod);
			float GetTimeHistoryPeriod(void);
			void ModEditBandInRecord(int32_t startRow, int32_t stopRow, float offset = 0, bool exclude = false);
			void RecalculateModifiedSectionFromTimes(int64_t start, int64_t end);
			int32_t FindIndexOfTimeHistEntry(int64_t timeMS);
			void RecalculateModifiedSection(int32_t start = 0, int32_t end = 0);
			void FillEditBandsArray(void);
			std::shared_ptr<SDateTime> RoundToNearestTimeHistorySample(std::shared_ptr<SDateTime> targetDateTime);
			CSpartanRecord(int32_t skipThreshold = 100000);
			std::shared_ptr<SManifestBlockSpartan_t> FileManifest(void);
			void FileManifest(std::shared_ptr<SManifestBlockSpartan_t> value);
			std::shared_ptr<SSysSettingsSpartan_t> SysSettings(void);
			void SysSettings(std::shared_ptr<SSysSettingsSpartan_t> value);
			std::shared_ptr<SMeasSettingsSpartan_t> MeasSettings(void);
			void MeasSettings(std::shared_ptr<SMeasSettingsSpartan_t> value);
			std::shared_ptr<SOverallDataSpartan_t> OverallData(void);
			void OverallData(std::shared_ptr<SOverallDataSpartan_t> value);
			int32_t OverallDataVer(void);
			void OverallDataVer(int32_t value);
			std::shared_ptr<SModifiedDataSpartan_t> ModOverallData(void);
			void ModOverallData(std::shared_ptr<SModifiedDataSpartan_t> value);
			std::shared_ptr<SDailyNoise_t> DailyNoise(void);
			void DailyNoise(std::shared_ptr<SDailyNoise_t> value);
			std::shared_ptr<SObaData48Bins_t> ObaData(void);
			void ObaData(std::shared_ptr<SObaData48Bins_t> value);
			std::shared_ptr<SExcdDataSpartan_t> ExcdData(void);
			void ExcdData(std::shared_ptr<SExcdDataSpartan_t> value);
			std::shared_ptr<SLnDataSpartan_t> LnData(void);
			void LnData(std::shared_ptr<SLnDataSpartan_t> value);
			std::shared_ptr<SPrePostCalSpartan_v2_t> PreCal(void);
			void PreCal(std::shared_ptr<SPrePostCalSpartan_v2_t> value);
			std::shared_ptr<SPrePostCalSpartan_v2_t> PostCal(void);
			void PostCal(std::shared_ptr<SPrePostCalSpartan_v2_t> value);
			StringWrapper DeviceDesc(void);
			void DeviceDesc(StringWrapper value);
			std::shared_ptr<Array_float> ProfileData(void);
			void ProfileData(std::shared_ptr<Array_float> value);
			std::shared_ptr<Array_uint8_t> RangeData(void);
			void RangeData(std::shared_ptr<Array_uint8_t> value);
			std::shared_ptr<SDeviceInfoSpartan_t> DeviceInfo(void);
			void DeviceInfo(std::shared_ptr<SDeviceInfoSpartan_t> value);
			std::shared_ptr<IList_CTimeHistoryEntry_t> TimeHistory(void);
			void TimeHistory(std::shared_ptr<IList_CTimeHistoryEntry_t> value);
			std::shared_ptr<IList_CSessionLogEntry_t> SessionLog(void);
			void SessionLog(std::shared_ptr<IList_CSessionLogEntry_t> value);
			std::shared_ptr<IList_CSpartanInterval> Intervals(void);
			void Intervals(std::shared_ptr<IList_CSpartanInterval> value);
			std::shared_ptr<IList_StringWrapper> Notes(void);
			void Notes(std::shared_ptr<IList_StringWrapper> value);
			std::shared_ptr<IList_CSpartanSoundRecord> SoundRecords(void);
			void SoundRecords(std::shared_ptr<IList_CSpartanSoundRecord> value);
			std::shared_ptr<IAgencyApprovalInfo> AgencyInfo(void);
			void AgencyInfo(std::shared_ptr<IAgencyApprovalInfo> value);
			std::shared_ptr<IList_uint32_t> Options(void);
			void Options(std::shared_ptr<IList_uint32_t> value);
			bool IsOptionsValid(void);
			void IsOptionsValid(bool value);
			std::shared_ptr<CSpartanMetaRecord> MetaRec(void);
			void MetaRec(std::shared_ptr<CSpartanMetaRecord> value);
			bool FileHadMetaRecord(void);
			bool HasEditBands(void);
			bool HasComments(void);
			bool HasNotes(void);
			StringWrapper LocalDataFileName(void);
			void LocalDataFileName(StringWrapper value);
			uint32_t FWDateTime(void);
			void FWDateTime(uint32_t value);
			StringWrapper Manufacturer(void);
			void Manufacturer(StringWrapper value);
			StringWrapper User(void);
			void User(StringWrapper value);
			StringWrapper Location(void);
			void Location(StringWrapper value);
			StringWrapper JobDescription(void);
			void JobDescription(StringWrapper value);
			StringWrapper Note(void);
			void Note(StringWrapper value);
			int32_t NumberSessionLogEntries(void);
			float LAeq(void);
			float LCeq(void);
			float LCpk(void);
			float LZpk(void);
			float LAFmax(void);
			float Dose(void);
			float Lex(void);
			ETimeHistoryMetricFlags TimeHistoryMetricFlags(void);
			void TimeHistoryMetricFlags(ETimeHistoryMetricFlags value);
			ETimeHistoryMetricFlags_B2 TimeHistoryMetricFlags_B2(void);
			void TimeHistoryMetricFlags_B2(ETimeHistoryMetricFlags_B2 value);
			ETimeHistoryMetricFlags_B3 TimeHistoryMetricFlags_B3(void);
			void TimeHistoryMetricFlags_B3(ETimeHistoryMetricFlags_B3 value);
			ETimeHistoryMetricFlags_B4 TimeHistoryMetricFlags_B4(void);
			void TimeHistoryMetricFlags_B4(ETimeHistoryMetricFlags_B4 value);
			int32_t NumberTimeHistoryRecords(void);
			std::shared_ptr<Nullable_float> ThPeriod(void);
			void ThPeriod(std::shared_ptr<Nullable_float> value);
			int32_t NumThItems(void);
			int64_t FileSize(void);
			StringWrapper Metric1Type(void);
			float Metric1Level(void);
			uint32_t StartTimeSeconds(void);
			uint32_t RunTimeSeconds(void);
			float OverloadDuration(void);
			void OverloadDuration(float value);
			bool UsesTimeHistoryPeriodEnum(void);
			void UsesTimeHistoryPeriodEnum(bool value);
			bool TmsEnabled(void);
			std::shared_ptr<IList_CX21MetricMeta> MetricMetaMapping(void);
			void MetricMetaMapping(std::shared_ptr<IList_CX21MetricMeta> value);
			int32_t SkipThreshold(void);
			EPreampType NFPreampType(void);
			void NFPreampType(EPreampType value);
			std::shared_ptr<Array_float> LnPercentiles(void);
			void LnPercentiles(std::shared_ptr<Array_float> value);
#ifdef MAKEDLL
		public: // This is for internal use
			CSpartanRecord(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _CSPARTAN_RECORD_H
