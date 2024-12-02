/**************************************************************************//**
 * @file Array_STwa_t.h
 * @brief Native Wrapper for Managed type cli::array<LarsonDavis::SDK::LDCommonStd::Legacy::Twa_t, 1>.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ARRAY_STWA_T_H
#define _ARRAY_STWA_T_H
#include <CArray.h>
#include <IList_STwa_t.h>
#include <STwa_t.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI CArray;
		class LDAPI IList_STwa_t;
		struct LDAPI STwa_t;

		class LDAPI Array_STwa_t : public CArray, public virtual IList_STwa_t
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			Array_STwa_t(const Array_STwa_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~Array_STwa_t(void);
			std::shared_ptr<STwa_t> Get(int32_t arg0);
			void Set(int32_t arg0, std::shared_ptr<STwa_t> arg1);
			Array_STwa_t(int32_t arg0);
#ifdef MAKEDLL
		public: // This is for internal use
			Array_STwa_t(){};
			Array_STwa_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _ARRAY_STWA_T_H
