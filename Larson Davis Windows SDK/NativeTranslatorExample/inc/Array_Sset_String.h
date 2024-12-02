/**************************************************************************//**
 * @file Array_Sset_String.h
 * @brief Native Wrapper for Managed type cli::array<LarsonDavis::SDK::LDCommonStd::Legacy::set_String, 1>.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ARRAY_SSET_STRING_H
#define _ARRAY_SSET_STRING_H
#include <CArray.h>
#include <IList_Sset_String.h>
#include <Sset_String.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI CArray;
		class LDAPI IList_Sset_String;
		struct LDAPI Sset_String;

		class LDAPI Array_Sset_String : public CArray, public virtual IList_Sset_String
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			Array_Sset_String(const Array_Sset_String& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~Array_Sset_String(void);
			std::shared_ptr<Sset_String> Get(int32_t arg0);
			void Set(int32_t arg0, std::shared_ptr<Sset_String> arg1);
			Array_Sset_String(int32_t arg0);
#ifdef MAKEDLL
		public: // This is for internal use
			Array_Sset_String(){};
			Array_Sset_String(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _ARRAY_SSET_STRING_H
