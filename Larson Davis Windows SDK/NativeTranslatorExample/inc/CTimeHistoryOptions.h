/**************************************************************************//**
 * @file CTimeHistoryOptions.h
 * @brief Native Wrapper for Managed type TimeHistoryOptions.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _CTIME_HISTORY_OPTIONS_H
#define _CTIME_HISTORY_OPTIONS_H
#include <ETHOptionId.h>
#include <ETHOptionType.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI CTimeHistoryManager;
		class LDAPI ISlmRecord;
		class LDAPI IList_SstTHItemInfo_t;
		class LDAPI Array_SstTHOptionInfo_t;
		struct LDAPI SstTHOptionInfo_t;
		class LDAPI List_int32_t;
		class LDAPI List_ValueTuple_int32_t_StringWrapper;

		class LDAPI CTimeHistoryOptions
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			CTimeHistoryOptions(const CTimeHistoryOptions& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~CTimeHistoryOptions(void);
			static int32_t GetSelectionIndex(std::shared_ptr<CTimeHistoryManager> thMngr, int32_t item);
			static int32_t GetItemIndex(ETHOptionId id);
			static ETHOptionType GetTHOptionType(int32_t ndx);
			static int32_t GetOrder(int32_t ndx);
			std::shared_ptr<IList_SstTHItemInfo_t> BuildTHItemInfoList(std::shared_ptr<ISlmRecord> rec, bool includeOba = true, bool ignoreGrouping = false);
			static int32_t IsTHLnStatistic(ETHOptionId id);
			static StringWrapper ConvertString(std::shared_ptr<ISlmRecord> rec, StringWrapper strIn);
			static StringWrapper GetTHOptionLabel(std::shared_ptr<ISlmRecord> rec, int32_t ndx, bool convert = true);
			static int32_t GetTHOptionLabelLength(int32_t ndx);
			CTimeHistoryOptions(void);
			static std::shared_ptr<Array_SstTHOptionInfo_t> THOptions(void);
			std::shared_ptr<List_int32_t> MetricsOrderMapping(void);
			void MetricsOrderMapping(std::shared_ptr<List_int32_t> value);
			std::shared_ptr<List_int32_t> MetricsArrayIndexes(void);
			void MetricsArrayIndexes(std::shared_ptr<List_int32_t> value);
			std::shared_ptr<List_ValueTuple_int32_t_StringWrapper> MetricsAllOrdered(void);
			void MetricsAllOrdered(std::shared_ptr<List_ValueTuple_int32_t_StringWrapper> value);
			static int32_t NUM_TH_COLUMNS(void);
#ifdef MAKEDLL
		public: // This is for internal use
			CTimeHistoryOptions(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _CTIME_HISTORY_OPTIONS_H
