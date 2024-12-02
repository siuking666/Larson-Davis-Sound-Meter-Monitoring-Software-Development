/**************************************************************************//**
 * @file SRt60TimeSample_t.h
 * @brief Native Wrapper for Managed type Rt60TimeSample_t.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _SRT60_TIME_SAMPLE_T_H
#define _SRT60_TIME_SAMPLE_T_H
#include <ISupportByteArrayConversion.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI ISupportByteArrayConversion;
		class LDAPI Array_float;

		struct LDAPI SRt60TimeSample_t : public virtual ISupportByteArrayConversion
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			SRt60TimeSample_t(const SRt60TimeSample_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~SRt60TimeSample_t(void);
			SRt60TimeSample_t(void);
			std::shared_ptr<Array_float> sample(void);
			void sample(std::shared_ptr<Array_float> value);
#ifdef MAKEDLL
		public: // This is for internal use
			SRt60TimeSample_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _SRT60_TIME_SAMPLE_T_H
