/**************************************************************************//**
 * @file Array_StringWrapper.h
 * @brief Native Wrapper for Managed type cli::array<System::String^, 1>.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ARRAY_STRING_WRAPPER_H
#define _ARRAY_STRING_WRAPPER_H
#include <CArray.h>
#include <IList_StringWrapper.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI CArray;
		class LDAPI IList_StringWrapper;

		class LDAPI Array_StringWrapper : public CArray, public virtual IList_StringWrapper
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			Array_StringWrapper(const Array_StringWrapper& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~Array_StringWrapper(void);
			int32_t CopyTo(StringWrapper* pDest, uint32_t size, uint32_t fromOffset = 0);
			void Set(int32_t arg0, StringWrapper arg1);
			StringWrapper Get(int32_t arg0);
			Array_StringWrapper(int32_t arg0);
#ifdef MAKEDLL
		public: // This is for internal use
			Array_StringWrapper(){};
			Array_StringWrapper(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _ARRAY_STRING_WRAPPER_H
