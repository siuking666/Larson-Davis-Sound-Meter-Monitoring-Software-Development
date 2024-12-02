/**************************************************************************//**
 * @file Sset_FloatArray11.h
 * @brief Native Wrapper for Managed type set_FloatArray11.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _SSET_FLOAT_ARRAY11_H
#define _SSET_FLOAT_ARRAY11_H
#include <ISupportByteArrayConversion.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI ISupportByteArrayConversion;
		class LDAPI Array_float;

		struct LDAPI Sset_FloatArray11 : public virtual ISupportByteArrayConversion
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			Sset_FloatArray11(const Sset_FloatArray11& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~Sset_FloatArray11(void);
			Sset_FloatArray11(void);
			std::shared_ptr<Array_float> data(void);
			void data(std::shared_ptr<Array_float> value);
			int32_t teds(void);
			void teds(int32_t value);
			int32_t flags(void);
			void flags(int32_t value);
#ifdef MAKEDLL
		public: // This is for internal use
			Sset_FloatArray11(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _SSET_FLOAT_ARRAY11_H
