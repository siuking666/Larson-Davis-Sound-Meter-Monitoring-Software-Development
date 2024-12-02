/**************************************************************************//**
 * @file IList_CTimeHistoryRecord.h
 * @brief Native Wrapper for Managed type IList<LarsonDavis::SDK::LDCommonStd::Legacy::TimeHistoryRecord^>.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ILIST_CTIME_HISTORY_RECORD_H
#define _ILIST_CTIME_HISTORY_RECORD_H
#include <CTimeHistoryRecord.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI CTimeHistoryRecord;
		class LDAPI Array_float;
		class LDAPI Array_float_2;

		class LDAPI IList_CTimeHistoryRecord
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			IList_CTimeHistoryRecord(const IList_CTimeHistoryRecord& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~IList_CTimeHistoryRecord(void);
			virtual int32_t IndexOf(std::shared_ptr<CTimeHistoryRecord> item);
			virtual void Insert(int32_t index, std::shared_ptr<CTimeHistoryRecord> item);
			virtual void RemoveAt(int32_t index);
			virtual std::shared_ptr<CTimeHistoryRecord> Item(int32_t index);
			virtual void Item(int32_t index, std::shared_ptr<CTimeHistoryRecord> value);
			virtual int32_t Count(void);
#ifdef MAKEDLL
		public: // This is for internal use
			IList_CTimeHistoryRecord(){};
			IList_CTimeHistoryRecord(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _ILIST_CTIME_HISTORY_RECORD_H
