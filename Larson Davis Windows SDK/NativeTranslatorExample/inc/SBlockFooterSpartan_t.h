/**************************************************************************//**
 * @file SBlockFooterSpartan_t.h
 * @brief Native Wrapper for Managed type BlockFooterSpartan_t.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _SBLOCK_FOOTER_SPARTAN_T_H
#define _SBLOCK_FOOTER_SPARTAN_T_H
#include <ISupportByteArrayConversion.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI ISupportByteArrayConversion;

		struct LDAPI SBlockFooterSpartan_t : public virtual ISupportByteArrayConversion
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			SBlockFooterSpartan_t(const SBlockFooterSpartan_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~SBlockFooterSpartan_t(void);
			SBlockFooterSpartan_t(void);
			int32_t crc(void);
			void crc(int32_t value);
			int32_t endtag(void);
			void endtag(int32_t value);
#ifdef MAKEDLL
		public: // This is for internal use
			SBlockFooterSpartan_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _SBLOCK_FOOTER_SPARTAN_T_H
