/**************************************************************************//**
 * @file IComparer_ValueTuple_int32_t_StringWrapper.h
 * @brief Native Wrapper for Managed type IComparer<System::ValueTuple<System::Int32, System::String^>>.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ICOMPARER_VALUE_TUPLE_INT32_T_STRING_WRAPPER_H
#define _ICOMPARER_VALUE_TUPLE_INT32_T_STRING_WRAPPER_H
#include <ValueTuple_int32_t_StringWrapper.h>
namespace LarsonDavis
{
	namespace Native
	{
		struct LDAPI ValueTuple_int32_t_StringWrapper;

		class LDAPI IComparer_ValueTuple_int32_t_StringWrapper
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			IComparer_ValueTuple_int32_t_StringWrapper(const IComparer_ValueTuple_int32_t_StringWrapper& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~IComparer_ValueTuple_int32_t_StringWrapper(void);
			virtual int32_t Compare(std::shared_ptr<ValueTuple_int32_t_StringWrapper> x, std::shared_ptr<ValueTuple_int32_t_StringWrapper> y);
#ifdef MAKEDLL
		public: // This is for internal use
			IComparer_ValueTuple_int32_t_StringWrapper(){};
			IComparer_ValueTuple_int32_t_StringWrapper(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _ICOMPARER_VALUE_TUPLE_INT32_T_STRING_WRAPPER_H
