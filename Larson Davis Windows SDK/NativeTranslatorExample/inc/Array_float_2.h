/**************************************************************************//**
 * @file Array_float_2.h
 * @brief Native Wrapper for Managed type cli::array<System::Single, 2>.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ARRAY_FLOAT_2_H
#define _ARRAY_FLOAT_2_H
#include <CArray.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI CArray;

		class LDAPI Array_float_2 : public CArray
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			Array_float_2(const Array_float_2& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~Array_float_2(void);
			float Get(int32_t arg0, int32_t arg1);
			void Set(int32_t arg0, int32_t arg1, float arg2);
			Array_float_2(int32_t arg0, int32_t arg1);
#ifdef MAKEDLL
		public: // This is for internal use
			Array_float_2(){};
			Array_float_2(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _ARRAY_FLOAT_2_H
