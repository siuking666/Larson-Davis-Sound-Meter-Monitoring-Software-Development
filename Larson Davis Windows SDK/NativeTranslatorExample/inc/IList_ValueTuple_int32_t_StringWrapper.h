/**************************************************************************//**
 * @file IList_ValueTuple_int32_t_StringWrapper.h
 * @brief Native Wrapper for Managed type IList<System::ValueTuple<System::Int32, System::String^>>.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ILIST_VALUE_TUPLE_INT32_T_STRING_WRAPPER_H
#define _ILIST_VALUE_TUPLE_INT32_T_STRING_WRAPPER_H
#include <ValueTuple_int32_t_StringWrapper.h>
namespace LarsonDavis
{
	namespace Native
	{
		struct LDAPI ValueTuple_int32_t_StringWrapper;

		class LDAPI IList_ValueTuple_int32_t_StringWrapper
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			IList_ValueTuple_int32_t_StringWrapper(const IList_ValueTuple_int32_t_StringWrapper& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~IList_ValueTuple_int32_t_StringWrapper(void);
			virtual int32_t IndexOf(std::shared_ptr<ValueTuple_int32_t_StringWrapper> item);
			virtual void Insert(int32_t index, std::shared_ptr<ValueTuple_int32_t_StringWrapper> item);
			virtual void RemoveAt(int32_t index);
			virtual std::shared_ptr<ValueTuple_int32_t_StringWrapper> Item(int32_t index);
			virtual void Item(int32_t index, std::shared_ptr<ValueTuple_int32_t_StringWrapper> value);
			virtual int32_t Count(void);
#ifdef MAKEDLL
		public: // This is for internal use
			IList_ValueTuple_int32_t_StringWrapper(){};
			IList_ValueTuple_int32_t_StringWrapper(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _ILIST_VALUE_TUPLE_INT32_T_STRING_WRAPPER_H
