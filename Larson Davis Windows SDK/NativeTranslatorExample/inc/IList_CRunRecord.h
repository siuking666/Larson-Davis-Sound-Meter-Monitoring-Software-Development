/**************************************************************************//**
 * @file IList_CRunRecord.h
 * @brief Native Wrapper for Managed type IList<LarsonDavis::SDK::LDCommonStd::Legacy::RunRecord^>.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ILIST_CRUN_RECORD_H
#define _ILIST_CRUN_RECORD_H
#include <CRunRecord.h>
#include <EActionCause.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI CRunRecord;
		struct LDAPI SSessionLog_t;

		class LDAPI IList_CRunRecord
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			IList_CRunRecord(const IList_CRunRecord& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~IList_CRunRecord(void);
			virtual int32_t IndexOf(std::shared_ptr<CRunRecord> item);
			virtual void Insert(int32_t index, std::shared_ptr<CRunRecord> item);
			virtual void RemoveAt(int32_t index);
			virtual std::shared_ptr<CRunRecord> Item(int32_t index);
			virtual void Item(int32_t index, std::shared_ptr<CRunRecord> value);
			virtual int32_t Count(void);
#ifdef MAKEDLL
		public: // This is for internal use
			IList_CRunRecord(){};
			IList_CRunRecord(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _ILIST_CRUN_RECORD_H
