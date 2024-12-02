/**************************************************************************//**
 * @file IList_CTimeHistoryEntry_t.h
 * @brief Native Wrapper for Managed type IList<LarsonDavis::SDK::LDCommonStd::Core::TimeHistoryEntry_t^>.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ILIST_CTIME_HISTORY_ENTRY_T_H
#define _ILIST_CTIME_HISTORY_ENTRY_T_H
#include <CTimeHistoryEntry_t.h>
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
		class LDAPI CTimeHistoryEntry_t;
		class LDAPI IList_CX21MetricMeta;
		class LDAPI Array_uint8_t;
		struct LDAPI Nullable_uint32_t;
		class LDAPI List_float;
		class LDAPI List_IConvertible;
		class LDAPI Array_float;

		class LDAPI IList_CTimeHistoryEntry_t
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			IList_CTimeHistoryEntry_t(const IList_CTimeHistoryEntry_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~IList_CTimeHistoryEntry_t(void);
			virtual int32_t IndexOf(std::shared_ptr<CTimeHistoryEntry_t> item);
			virtual void Insert(int32_t index, std::shared_ptr<CTimeHistoryEntry_t> item);
			virtual void RemoveAt(int32_t index);
			virtual std::shared_ptr<CTimeHistoryEntry_t> Item(int32_t index);
			virtual void Item(int32_t index, std::shared_ptr<CTimeHistoryEntry_t> value);
			virtual int32_t Count(void);
#ifdef MAKEDLL
		public: // This is for internal use
			IList_CTimeHistoryEntry_t(){};
			IList_CTimeHistoryEntry_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _ILIST_CTIME_HISTORY_ENTRY_T_H
