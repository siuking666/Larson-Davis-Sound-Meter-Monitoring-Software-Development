/**************************************************************************//**
 * @file ISpartanRecord.h
 * @brief Native Wrapper for Managed type ISpartanRecord.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ISPARTAN_RECORD_H
#define _ISPARTAN_RECORD_H
#include <ILDRecordWithMetaRecord_CSpartanMetaRecord.h>
#include <EMetricId.h>
#include <ETimeHistoryMetricFlags.h>
#include <ETimeHistoryMetricFlags_B2.h>
#include <ETimeHistoryMetricFlags_B3.h>
#include <ETimeHistoryMetricFlags_B4.h>
#include <ESpartanFileBlockVersion.h>
#include <ETimeHistoryFlags.h>
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
#include <EPreampType.h>
#include <ESpartanSLogType.h>
#include <ESpartanSLogCause.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI ILDRecordWithMetaRecord_CSpartanMetaRecord;
		class LDAPI IList_CX21MetricMeta;
		class LDAPI CX21MetricMeta;
		class LDAPI IList_CTimeHistoryEntry_t;
		class LDAPI CTimeHistoryEntry_t;
		class LDAPI Array_uint8_t;
		struct LDAPI Nullable_uint32_t;
		class LDAPI List_float;
		class LDAPI List_IConvertible;
		class LDAPI Array_float;
		struct LDAPI SMeasSettingsSpartan_t;
		struct LDAPI SString16_t;
		struct LDAPI SString64_t;
		struct LDAPI SObaData48Bins_t;
		class LDAPI Array_SDetectorTs_t;
		struct LDAPI SExcdDataSpartan_t;
		class LDAPI Array_SExceedanceDataRecordSpartan_t;
		struct LDAPI SLnDataSpartan_t;
		struct LDAPI SOverallDataSpartan_t;
		class LDAPI Array_STwa_t;
		class LDAPI IList_CSpartanInterval;
		class LDAPI CSpartanInterval;
		struct LDAPI SMeasHistSpartan_t;
		struct LDAPI SBlockHeaderSpartan_t;
		struct LDAPI SMeasAnyDataSpartan_t;
		struct LDAPI SBlockFooterSpartan_t;
		class LDAPI Array_float_2;
		class LDAPI Array_int64_t_2;
		class LDAPI Array_int64_t;
		struct LDAPI SOverloadSpartan_t;
		class LDAPI IList_uint32_t;
		class LDAPI IList_StringWrapper;
		class LDAPI IList_CSpartanSoundRecord;
		class LDAPI CSpartanSoundRecord;
		class LDAPI IList_CSessionLogEntry_t;
		class LDAPI CSessionLogEntry_t;
		struct LDAPI Nullable_float;

		class LDAPI ISpartanRecord : public virtual ILDRecordWithMetaRecord_CSpartanMetaRecord
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			ISpartanRecord(const ISpartanRecord& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~ISpartanRecord(void);
			virtual int32_t FindIndexOfTimeHistEntry(int64_t timeMS);
			virtual float GetLden(void);
			virtual float GetLdenDay(void);
			virtual float GetLdenEve(void);
			virtual float GetLdenNight(void);
			virtual float GetLdn(void);
			virtual float GetLdnDay(void);
			virtual float GetLdnNight(void);
			virtual bool IsMeasurementHistoryAvailable(void);
			virtual bool IsObaAvailable(void);
			virtual float GetTimeHistoryPeriod(void);
			virtual std::shared_ptr<IList_CX21MetricMeta> MetricMetaMapping(void);
			virtual void MetricMetaMapping(std::shared_ptr<IList_CX21MetricMeta> value);
			virtual std::shared_ptr<IList_CTimeHistoryEntry_t> TimeHistory(void);
			virtual void TimeHistory(std::shared_ptr<IList_CTimeHistoryEntry_t> value);
			virtual std::shared_ptr<SMeasSettingsSpartan_t> MeasSettings(void);
			virtual void MeasSettings(std::shared_ptr<SMeasSettingsSpartan_t> value);
			virtual std::shared_ptr<SObaData48Bins_t> ObaData(void);
			virtual void ObaData(std::shared_ptr<SObaData48Bins_t> value);
			virtual std::shared_ptr<SExcdDataSpartan_t> ExcdData(void);
			virtual void ExcdData(std::shared_ptr<SExcdDataSpartan_t> value);
			virtual std::shared_ptr<SLnDataSpartan_t> LnData(void);
			virtual void LnData(std::shared_ptr<SLnDataSpartan_t> value);
			virtual std::shared_ptr<SOverallDataSpartan_t> OverallData(void);
			virtual void OverallData(std::shared_ptr<SOverallDataSpartan_t> value);
			virtual bool HasComments(void);
			virtual bool HasNotes(void);
			virtual std::shared_ptr<IList_CSpartanInterval> Intervals(void);
			virtual int32_t NumThItems(void);
			virtual ETimeHistoryMetricFlags TimeHistoryMetricFlags(void);
			virtual void TimeHistoryMetricFlags(ETimeHistoryMetricFlags value);
			virtual std::shared_ptr<IList_uint32_t> Options(void);
			virtual void Options(std::shared_ptr<IList_uint32_t> value);
			virtual std::shared_ptr<IList_StringWrapper> Notes(void);
			virtual void Notes(std::shared_ptr<IList_StringWrapper> value);
			virtual std::shared_ptr<IList_CSpartanSoundRecord> SoundRecords(void);
			virtual void SoundRecords(std::shared_ptr<IList_CSpartanSoundRecord> value);
			virtual std::shared_ptr<IList_CSessionLogEntry_t> SessionLog(void);
			virtual void SessionLog(std::shared_ptr<IList_CSessionLogEntry_t> value);
			virtual bool UsesTimeHistoryPeriodEnum(void);
			virtual void UsesTimeHistoryPeriodEnum(bool value);
			virtual std::shared_ptr<Nullable_float> ThPeriod(void);
			virtual void ThPeriod(std::shared_ptr<Nullable_float> value);
#ifdef MAKEDLL
		public: // This is for internal use
			ISpartanRecord(){};
			ISpartanRecord(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _ISPARTAN_RECORD_H
