/**************************************************************************//**
 * @file Array_Sset_Enum.h
 * @brief Native Wrapper for Managed type cli::array<LarsonDavis::SDK::LDCommonStd::Legacy::set_Enum, 1>.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ARRAY_SSET_ENUM_H
#define _ARRAY_SSET_ENUM_H
#include <CArray.h>
#include <IList_Sset_Enum.h>
#include <Sset_Enum.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI CArray;
		class LDAPI IList_Sset_Enum;
		struct LDAPI Sset_Enum;

		class LDAPI Array_Sset_Enum : public CArray, public virtual IList_Sset_Enum
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			Array_Sset_Enum(const Array_Sset_Enum& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~Array_Sset_Enum(void);
			std::shared_ptr<Sset_Enum> Get(int32_t arg0);
			void Set(int32_t arg0, std::shared_ptr<Sset_Enum> arg1);
			Array_Sset_Enum(int32_t arg0);
#ifdef MAKEDLL
		public: // This is for internal use
			Array_Sset_Enum(){};
			Array_Sset_Enum(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _ARRAY_SSET_ENUM_H
