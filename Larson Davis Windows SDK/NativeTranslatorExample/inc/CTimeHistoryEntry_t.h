/**************************************************************************//**
 * @file CTimeHistoryEntry_t.h
 * @brief Native Wrapper for Managed type TimeHistoryEntry_t.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _CTIME_HISTORY_ENTRY_T_H
#define _CTIME_HISTORY_ENTRY_T_H
#include <ETimeHistoryMetricFlags.h>
#include <ETimeHistoryMetricFlags_B2.h>
#include <ETimeHistoryMetricFlags_B3.h>
#include <ETimeHistoryMetricFlags_B4.h>
#include <ESpartanFileBlockVersion.h>
#include <ETimeHistoryFlags.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI IList_CX21MetricMeta;
		class LDAPI Array_uint8_t;
		struct LDAPI Nullable_uint32_t;
		class LDAPI List_float;
		class LDAPI List_IConvertible;
		class LDAPI Array_float;

		class LDAPI CTimeHistoryEntry_t
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			CTimeHistoryEntry_t(const CTimeHistoryEntry_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~CTimeHistoryEntry_t(void);
			static void ThrowIfBad(StringWrapper msg);
			static std::shared_ptr<IList_CX21MetricMeta> MapMetricData(ETimeHistoryMetricFlags enabledFlags, ETimeHistoryMetricFlags_B2 enabledFlags2 = ETimeHistoryMetricFlags_B2::None, ETimeHistoryMetricFlags_B3 enabledFlags3 = ETimeHistoryMetricFlags_B3::None, ETimeHistoryMetricFlags_B4 enabledFlags4 = ETimeHistoryMetricFlags_B4::None, bool tmsEnabled = false, ESpartanFileBlockVersion fileVersion = ESpartanFileBlockVersion::Unknown);
			CTimeHistoryEntry_t(uint32_t recTimestamp, std::shared_ptr<Array_uint8_t> data, std::shared_ptr<IList_CX21MetricMeta> metaList);
			CTimeHistoryEntry_t(void);
			CTimeHistoryEntry_t(uint32_t recTimestamp, std::shared_ptr<Array_uint8_t> data, bool isStop, std::shared_ptr<IList_CX21MetricMeta> metaList, int32_t index = 0);
			CTimeHistoryEntry_t(uint32_t recTimestamp, std::shared_ptr<Array_uint8_t> data, std::shared_ptr<IList_CX21MetricMeta> metaList, ETimeHistoryFlags thFlags, bool isStopOrPause, uint32_t fileVersion, bool tmsEnabled = false, uint32_t tmsVal = 0, int32_t index = 2);
			uint32_t Timestamp(void);
			void Timestamp(uint32_t value);
			uint64_t TimestampMs(void);
			void TimestampMs(uint64_t value);
			std::shared_ptr<Nullable_uint32_t> Tms(void);
			void Tms(std::shared_ptr<Nullable_uint32_t> value);
			ETimeHistoryFlags Flags(void);
			void Flags(ETimeHistoryFlags value);
			std::shared_ptr<List_float> X21MetricsList(void);
			void X21MetricsList(std::shared_ptr<List_float> value);
			std::shared_ptr<List_IConvertible> X21SpecialList(void);
			void X21SpecialList(std::shared_ptr<List_IConvertible> value);
			float Laeq(void);
			void Laeq(float value);
			float Lceq(void);
			void Lceq(float value);
			float LasMax(void);
			void LasMax(float value);
			float LafMax(void);
			void LafMax(float value);
			float Lcpk(void);
			void Lcpk(float value);
			float Lzpk(void);
			void Lzpk(float value);
			float Twa3(void);
			void Twa3(float value);
			float Twa5(void);
			void Twa5(float value);
			float LasMin(void);
			void LasMin(float value);
			float LafMin(void);
			void LafMin(float value);
			float LaiMin(void);
			void LaiMin(float value);
			float LaiMax(void);
			void LaiMax(float value);
			float Lapk(void);
			void Lapk(float value);
			float LcsMin(void);
			void LcsMin(float value);
			float LcsMax(void);
			void LcsMax(float value);
			float LcfMin(void);
			void LcfMin(float value);
			float LcfMax(void);
			void LcfMax(float value);
			float LciMin(void);
			void LciMin(float value);
			float LciMax(void);
			void LciMax(float value);
			float Lzeq(void);
			void Lzeq(float value);
			float IntTemp(void);
			void IntTemp(float value);
			float GaugeTemp(void);
			void GaugeTemp(float value);
			float BattVolt(void);
			void BattVolt(float value);
			float BattPerc(void);
			void BattPerc(float value);
			float PowerSource(void);
			void PowerSource(float value);
			float AvgCurrent(void);
			void AvgCurrent(float value);
			float EstimatedTime(void);
			void EstimatedTime(float value);
			std::shared_ptr<Array_float> Oba11(void);
			void Oba11(std::shared_ptr<Array_float> value);
			std::shared_ptr<Array_float> Oba13(void);
			void Oba13(std::shared_ptr<Array_float> value);
			std::shared_ptr<Array_float> ObaOctaveMin(void);
			void ObaOctaveMin(std::shared_ptr<Array_float> value);
			std::shared_ptr<Array_float> ObaOctaveMax(void);
			void ObaOctaveMax(std::shared_ptr<Array_float> value);
			std::shared_ptr<Array_float> ObaThirdMin(void);
			void ObaThirdMin(std::shared_ptr<Array_float> value);
			std::shared_ptr<Array_float> ObaThirdMax(void);
			void ObaThirdMax(std::shared_ptr<Array_float> value);
			float LzsMin(void);
			void LzsMin(float value);
			float LzsMax(void);
			void LzsMax(float value);
			float LzfMin(void);
			void LzfMin(float value);
			float LzfMax(void);
			void LzfMax(float value);
			float LziMin(void);
			void LziMin(float value);
			float LziMax(void);
			void LziMax(float value);
			float ExternalVolts(void);
			void ExternalVolts(float value);
			bool exclude(void);
			void exclude(bool value);
			float offset(void);
			void offset(float value);
#ifdef MAKEDLL
		public: // This is for internal use
			CTimeHistoryEntry_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _CTIME_HISTORY_ENTRY_T_H
