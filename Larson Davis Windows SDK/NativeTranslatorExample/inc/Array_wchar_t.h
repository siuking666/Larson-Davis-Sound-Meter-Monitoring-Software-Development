/**************************************************************************//**
 * @file Array_wchar_t.h
 * @brief Native Wrapper for Managed type cli::array<System::Char, 1>.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ARRAY_WCHAR_T_H
#define _ARRAY_WCHAR_T_H
#include <CArray.h>
#include <IList_wchar_t.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI CArray;
		class LDAPI IList_wchar_t;

		class LDAPI Array_wchar_t : public CArray, public virtual IList_wchar_t
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			Array_wchar_t(const Array_wchar_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~Array_wchar_t(void);
			int32_t CopyTo(wchar_t* pDest, uint32_t size, uint32_t fromOffset = 0);
			void Set(int32_t arg0, wchar_t arg1);
			wchar_t Get(int32_t arg0);
			Array_wchar_t(int32_t arg0);
#ifdef MAKEDLL
		public: // This is for internal use
			Array_wchar_t(){};
			Array_wchar_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _ARRAY_WCHAR_T_H
