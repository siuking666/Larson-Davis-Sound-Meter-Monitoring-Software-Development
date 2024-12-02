/**************************************************************************//**
 * @file Sset_UnsignedInt.h
 * @brief Native Wrapper for Managed type set_UnsignedInt.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _SSET_UNSIGNED_INT_H
#define _SSET_UNSIGNED_INT_H
#include <ISupportByteArrayConversion.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI ISupportByteArrayConversion;

		struct LDAPI Sset_UnsignedInt : public virtual ISupportByteArrayConversion
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			Sset_UnsignedInt(const Sset_UnsignedInt& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~Sset_UnsignedInt(void);
			Sset_UnsignedInt(void);
			uint32_t data(void);
			void data(uint32_t value);
			int32_t teds(void);
			void teds(int32_t value);
			int32_t flags(void);
			void flags(int32_t value);
#ifdef MAKEDLL
		public: // This is for internal use
			Sset_UnsignedInt(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _SSET_UNSIGNED_INT_H
