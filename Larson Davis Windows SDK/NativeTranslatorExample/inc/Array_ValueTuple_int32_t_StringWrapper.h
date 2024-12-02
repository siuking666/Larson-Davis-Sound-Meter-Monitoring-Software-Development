/**************************************************************************//**
 * @file Array_ValueTuple_int32_t_StringWrapper.h
 * @brief Native Wrapper for Managed type cli::array<System::ValueTuple<System::Int32, System::String^>, 1>.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ARRAY_VALUE_TUPLE_INT32_T_STRING_WRAPPER_H
#define _ARRAY_VALUE_TUPLE_INT32_T_STRING_WRAPPER_H
#include <CArray.h>
#include <IList_ValueTuple_int32_t_StringWrapper.h>
#include <ValueTuple_int32_t_StringWrapper.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI CArray;
		class LDAPI IList_ValueTuple_int32_t_StringWrapper;
		struct LDAPI ValueTuple_int32_t_StringWrapper;

		class LDAPI Array_ValueTuple_int32_t_StringWrapper : public CArray, public virtual IList_ValueTuple_int32_t_StringWrapper
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			Array_ValueTuple_int32_t_StringWrapper(const Array_ValueTuple_int32_t_StringWrapper& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~Array_ValueTuple_int32_t_StringWrapper(void);
			std::shared_ptr<ValueTuple_int32_t_StringWrapper> Get(int32_t arg0);
			void Set(int32_t arg0, std::shared_ptr<ValueTuple_int32_t_StringWrapper> arg1);
			Array_ValueTuple_int32_t_StringWrapper(int32_t arg0);
#ifdef MAKEDLL
		public: // This is for internal use
			Array_ValueTuple_int32_t_StringWrapper(){};
			Array_ValueTuple_int32_t_StringWrapper(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _ARRAY_VALUE_TUPLE_INT32_T_STRING_WRAPPER_H
