/**************************************************************************//**
 * @file IList_Array_SCalData2_t.h
 * @brief Native Wrapper for Managed type IList<cli::array<LarsonDavis::SDK::LDCommonStd::Legacy::CalData2_t, 1>^>.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ILIST_ARRAY_SCAL_DATA2_T_H
#define _ILIST_ARRAY_SCAL_DATA2_T_H
#include <Array_SCalData2_t.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI Array_SCalData2_t;
		struct LDAPI SCalData2_t;

		class LDAPI IList_Array_SCalData2_t
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			IList_Array_SCalData2_t(const IList_Array_SCalData2_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~IList_Array_SCalData2_t(void);
			virtual int32_t IndexOf(std::shared_ptr<Array_SCalData2_t> item);
			virtual void Insert(int32_t index, std::shared_ptr<Array_SCalData2_t> item);
			virtual void RemoveAt(int32_t index);
			virtual std::shared_ptr<Array_SCalData2_t> Item(int32_t index);
			virtual void Item(int32_t index, std::shared_ptr<Array_SCalData2_t> value);
			virtual int32_t Count(void);
#ifdef MAKEDLL
		public: // This is for internal use
			IList_Array_SCalData2_t(){};
			IList_Array_SCalData2_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _ILIST_ARRAY_SCAL_DATA2_T_H
