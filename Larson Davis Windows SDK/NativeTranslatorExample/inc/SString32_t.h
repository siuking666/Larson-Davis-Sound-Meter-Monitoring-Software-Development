/**************************************************************************//**
 * @file SString32_t.h
 * @brief Native Wrapper for Managed type String32_t.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _SSTRING32_T_H
#define _SSTRING32_T_H
#include <ISupportByteArrayConversion.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI ISupportByteArrayConversion;
		class LDAPI Array_wchar_t;

		struct LDAPI SString32_t : public virtual ISupportByteArrayConversion
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			SString32_t(const SString32_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~SString32_t(void);
			SString32_t(void);
			std::shared_ptr<Array_wchar_t> value(void);
			void value(std::shared_ptr<Array_wchar_t> value);
#ifdef MAKEDLL
		public: // This is for internal use
			SString32_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _SSTRING32_T_H
