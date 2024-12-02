/**************************************************************************//**
 * @file SLnDataSpartan_t.h
 * @brief Native Wrapper for Managed type LnDataSpartan_t.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _SLN_DATA_SPARTAN_T_H
#define _SLN_DATA_SPARTAN_T_H
#include <ISupportByteArrayConversion.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI ISupportByteArrayConversion;
		class LDAPI Array_float;

		struct LDAPI SLnDataSpartan_t : public virtual ISupportByteArrayConversion
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			SLnDataSpartan_t(const SLnDataSpartan_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~SLnDataSpartan_t(void);
			SLnDataSpartan_t(void);
			std::shared_ptr<Array_float> lnData(void);
			void lnData(std::shared_ptr<Array_float> value);
#ifdef MAKEDLL
		public: // This is for internal use
			SLnDataSpartan_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _SLN_DATA_SPARTAN_T_H
