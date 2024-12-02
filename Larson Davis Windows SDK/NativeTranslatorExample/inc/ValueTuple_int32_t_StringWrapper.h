/**************************************************************************//**
 * @file ValueTuple_int32_t_StringWrapper.h
 * @brief Native Wrapper for Managed type ValueTuple<System::Int32, System::String^>.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _VALUE_TUPLE_INT32_T_STRING_WRAPPER_H
#define _VALUE_TUPLE_INT32_T_STRING_WRAPPER_H
#include <ITuple.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI ITuple;

		struct LDAPI ValueTuple_int32_t_StringWrapper : public virtual ITuple
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			ValueTuple_int32_t_StringWrapper(const ValueTuple_int32_t_StringWrapper& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~ValueTuple_int32_t_StringWrapper(void);
			ValueTuple_int32_t_StringWrapper(void);
			int32_t CompareTo(std::shared_ptr<ValueTuple_int32_t_StringWrapper> other);
			ValueTuple_int32_t_StringWrapper(int32_t item1, StringWrapper item2);
			int32_t Item1(void);
			void Item1(int32_t value);
			StringWrapper Item2(void);
			void Item2(StringWrapper value);
#ifdef MAKEDLL
		public: // This is for internal use
			ValueTuple_int32_t_StringWrapper(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _VALUE_TUPLE_INT32_T_STRING_WRAPPER_H
