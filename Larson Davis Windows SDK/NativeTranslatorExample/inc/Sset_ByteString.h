/**************************************************************************//**
 * @file Sset_ByteString.h
 * @brief Native Wrapper for Managed type set_ByteString.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _SSET_BYTE_STRING_H
#define _SSET_BYTE_STRING_H
#include <ISupportByteArrayConversion.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI ISupportByteArrayConversion;
		class LDAPI Array_uint8_t;

		struct LDAPI Sset_ByteString : public virtual ISupportByteArrayConversion
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			Sset_ByteString(const Sset_ByteString& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~Sset_ByteString(void);
			Sset_ByteString(void);
			std::shared_ptr<Array_uint8_t> data(void);
			void data(std::shared_ptr<Array_uint8_t> value);
			int32_t teds(void);
			void teds(int32_t value);
			int32_t flags(void);
			void flags(int32_t value);
#ifdef MAKEDLL
		public: // This is for internal use
			Sset_ByteString(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _SSET_BYTE_STRING_H
