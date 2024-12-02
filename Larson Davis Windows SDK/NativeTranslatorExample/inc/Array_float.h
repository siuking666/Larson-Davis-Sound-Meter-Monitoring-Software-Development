/**************************************************************************//**
 * @file Array_float.h
 * @brief Native Wrapper for Managed type cli::array<System::Single, 1>.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ARRAY_FLOAT_H
#define _ARRAY_FLOAT_H
#include <CArray.h>
#include <IList_float.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI CArray;
		class LDAPI IList_float;

		class LDAPI Array_float : public CArray, public virtual IList_float
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			Array_float(const Array_float& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~Array_float(void);
			int32_t CopyTo(float* pDest, uint32_t size, uint32_t fromOffset = 0);
			void Set(int32_t arg0, float arg1);
			float Get(int32_t arg0);
			Array_float(int32_t arg0);
#ifdef MAKEDLL
		public: // This is for internal use
			Array_float(){};
			Array_float(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _ARRAY_FLOAT_H
