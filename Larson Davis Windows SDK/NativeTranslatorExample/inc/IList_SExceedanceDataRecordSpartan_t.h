/**************************************************************************//**
 * @file IList_SExceedanceDataRecordSpartan_t.h
 * @brief Native Wrapper for Managed type IList<LarsonDavis::SDK::LDCommonStd::Core::ExceedanceDataRecordSpartan_t>.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ILIST_SEXCEEDANCE_DATA_RECORD_SPARTAN_T_H
#define _ILIST_SEXCEEDANCE_DATA_RECORD_SPARTAN_T_H
#include <SExceedanceDataRecordSpartan_t.h>
namespace LarsonDavis
{
	namespace Native
	{
		struct LDAPI SExceedanceDataRecordSpartan_t;

		class LDAPI IList_SExceedanceDataRecordSpartan_t
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			IList_SExceedanceDataRecordSpartan_t(const IList_SExceedanceDataRecordSpartan_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~IList_SExceedanceDataRecordSpartan_t(void);
			virtual int32_t IndexOf(std::shared_ptr<SExceedanceDataRecordSpartan_t> item);
			virtual void Insert(int32_t index, std::shared_ptr<SExceedanceDataRecordSpartan_t> item);
			virtual void RemoveAt(int32_t index);
			virtual std::shared_ptr<SExceedanceDataRecordSpartan_t> Item(int32_t index);
			virtual void Item(int32_t index, std::shared_ptr<SExceedanceDataRecordSpartan_t> value);
			virtual int32_t Count(void);
#ifdef MAKEDLL
		public: // This is for internal use
			IList_SExceedanceDataRecordSpartan_t(){};
			IList_SExceedanceDataRecordSpartan_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _ILIST_SEXCEEDANCE_DATA_RECORD_SPARTAN_T_H
