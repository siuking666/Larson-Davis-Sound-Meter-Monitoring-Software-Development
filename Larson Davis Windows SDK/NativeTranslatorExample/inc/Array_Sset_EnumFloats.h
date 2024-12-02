/**************************************************************************//**
 * @file Array_Sset_EnumFloats.h
 * @brief Native Wrapper for Managed type cli::array<LarsonDavis::SDK::LDCommonStd::Legacy::set_EnumFloats, 1>.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ARRAY_SSET_ENUM_FLOATS_H
#define _ARRAY_SSET_ENUM_FLOATS_H
#include <CArray.h>
#include <IList_Sset_EnumFloats.h>
#include <Sset_EnumFloats.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI CArray;
		class LDAPI IList_Sset_EnumFloats;
		struct LDAPI Sset_EnumFloats;

		class LDAPI Array_Sset_EnumFloats : public CArray, public virtual IList_Sset_EnumFloats
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			Array_Sset_EnumFloats(const Array_Sset_EnumFloats& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~Array_Sset_EnumFloats(void);
			std::shared_ptr<Sset_EnumFloats> Get(int32_t arg0);
			void Set(int32_t arg0, std::shared_ptr<Sset_EnumFloats> arg1);
			Array_Sset_EnumFloats(int32_t arg0);
#ifdef MAKEDLL
		public: // This is for internal use
			Array_Sset_EnumFloats(){};
			Array_Sset_EnumFloats(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _ARRAY_SSET_ENUM_FLOATS_H
