/**************************************************************************//**
 * @file SExceedanceDataRecordSpartan_t.h
 * @brief Native Wrapper for Managed type ExceedanceDataRecordSpartan_t.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _SEXCEEDANCE_DATA_RECORD_SPARTAN_T_H
#define _SEXCEEDANCE_DATA_RECORD_SPARTAN_T_H
#include <ISupportByteArrayConversion.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI ISupportByteArrayConversion;

		struct LDAPI SExceedanceDataRecordSpartan_t : public virtual ISupportByteArrayConversion
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			SExceedanceDataRecordSpartan_t(const SExceedanceDataRecordSpartan_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~SExceedanceDataRecordSpartan_t(void);
			SExceedanceDataRecordSpartan_t(void);
			uint32_t count(void);
			void count(uint32_t value);
			uint32_t duration(void);
			void duration(uint32_t value);
#ifdef MAKEDLL
		public: // This is for internal use
			SExceedanceDataRecordSpartan_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _SEXCEEDANCE_DATA_RECORD_SPARTAN_T_H
