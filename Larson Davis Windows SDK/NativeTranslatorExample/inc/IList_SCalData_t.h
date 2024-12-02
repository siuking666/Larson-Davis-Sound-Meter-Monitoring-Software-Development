/**************************************************************************//**
 * @file IList_SCalData_t.h
 * @brief Native Wrapper for Managed type IList<LarsonDavis::SDK::LDCommonStd::Legacy::CalData_t>.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ILIST_SCAL_DATA_T_H
#define _ILIST_SCAL_DATA_T_H
#include <SCalData_t.h>
namespace LarsonDavis
{
	namespace Native
	{
		struct LDAPI SCalData_t;
		class LDAPI Array_uint32_t;
		class LDAPI Array_float;

		class LDAPI IList_SCalData_t
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			IList_SCalData_t(const IList_SCalData_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~IList_SCalData_t(void);
			virtual int32_t IndexOf(std::shared_ptr<SCalData_t> item);
			virtual void Insert(int32_t index, std::shared_ptr<SCalData_t> item);
			virtual void RemoveAt(int32_t index);
			virtual std::shared_ptr<SCalData_t> Item(int32_t index);
			virtual void Item(int32_t index, std::shared_ptr<SCalData_t> value);
			virtual int32_t Count(void);
#ifdef MAKEDLL
		public: // This is for internal use
			IList_SCalData_t(){};
			IList_SCalData_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _ILIST_SCAL_DATA_T_H
