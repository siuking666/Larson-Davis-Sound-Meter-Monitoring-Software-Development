/**************************************************************************//**
 * @file Array_Sset_Float.h
 * @brief Native Wrapper for Managed type cli::array<LarsonDavis::SDK::LDCommonStd::Legacy::set_Float, 1>.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ARRAY_SSET_FLOAT_H
#define _ARRAY_SSET_FLOAT_H
#include <CArray.h>
#include <IList_Sset_Float.h>
#include <Sset_Float.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI CArray;
		class LDAPI IList_Sset_Float;
		struct LDAPI Sset_Float;

		class LDAPI Array_Sset_Float : public CArray, public virtual IList_Sset_Float
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			Array_Sset_Float(const Array_Sset_Float& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~Array_Sset_Float(void);
			std::shared_ptr<Sset_Float> Get(int32_t arg0);
			void Set(int32_t arg0, std::shared_ptr<Sset_Float> arg1);
			Array_Sset_Float(int32_t arg0);
#ifdef MAKEDLL
		public: // This is for internal use
			Array_Sset_Float(){};
			Array_Sset_Float(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _ARRAY_SSET_FLOAT_H
