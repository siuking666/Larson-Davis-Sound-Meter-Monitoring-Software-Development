/**************************************************************************//**
 * @file Array_SGenericLookup_t.h
 * @brief Native Wrapper for Managed type cli::array<LarsonDavis::SDK::LDCommonStd::Legacy::GenericLookup_t, 1>.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ARRAY_SGENERIC_LOOKUP_T_H
#define _ARRAY_SGENERIC_LOOKUP_T_H
#include <CArray.h>
#include <IList_SGenericLookup_t.h>
#include <SGenericLookup_t.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI CArray;
		class LDAPI IList_SGenericLookup_t;
		struct LDAPI SGenericLookup_t;

		class LDAPI Array_SGenericLookup_t : public CArray, public virtual IList_SGenericLookup_t
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			Array_SGenericLookup_t(const Array_SGenericLookup_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~Array_SGenericLookup_t(void);
			std::shared_ptr<SGenericLookup_t> Get(int32_t arg0);
			void Set(int32_t arg0, std::shared_ptr<SGenericLookup_t> arg1);
			Array_SGenericLookup_t(int32_t arg0);
#ifdef MAKEDLL
		public: // This is for internal use
			Array_SGenericLookup_t(){};
			Array_SGenericLookup_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _ARRAY_SGENERIC_LOOKUP_T_H
