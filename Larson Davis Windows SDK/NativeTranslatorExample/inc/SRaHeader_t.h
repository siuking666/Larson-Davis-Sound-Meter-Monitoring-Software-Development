/**************************************************************************//**
 * @file SRaHeader_t.h
 * @brief Native Wrapper for Managed type RaHeader_t.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _SRA_HEADER_T_H
#define _SRA_HEADER_T_H
#include <ISupportByteArrayConversion.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI ISupportByteArrayConversion;

		struct LDAPI SRaHeader_t : public virtual ISupportByteArrayConversion
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			SRaHeader_t(const SRaHeader_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~SRaHeader_t(void);
			SRaHeader_t(void);
			uint32_t totalCount(void);
			void totalCount(uint32_t value);
			uint32_t avgCount(void);
			void avgCount(uint32_t value);
			uint32_t freqBands(void);
			void freqBands(uint32_t value);
			uint32_t flags(void);
			void flags(uint32_t value);
			uint32_t positions(void);
			void positions(uint32_t value);
#ifdef MAKEDLL
		public: // This is for internal use
			SRaHeader_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _SRA_HEADER_T_H
