/**************************************************************************//**
 * @file SExcdDataSpartan_t.h
 * @brief Native Wrapper for Managed type ExcdDataSpartan_t.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _SEXCD_DATA_SPARTAN_T_H
#define _SEXCD_DATA_SPARTAN_T_H
#include <ISupportByteArrayConversion.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI ISupportByteArrayConversion;
		class LDAPI Array_SExceedanceDataRecordSpartan_t;

		struct LDAPI SExcdDataSpartan_t : public virtual ISupportByteArrayConversion
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			SExcdDataSpartan_t(const SExcdDataSpartan_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~SExcdDataSpartan_t(void);
			SExcdDataSpartan_t(void);
			std::shared_ptr<Array_SExceedanceDataRecordSpartan_t> excd(void);
			void excd(std::shared_ptr<Array_SExceedanceDataRecordSpartan_t> value);
#ifdef MAKEDLL
		public: // This is for internal use
			SExcdDataSpartan_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _SEXCD_DATA_SPARTAN_T_H
