/**************************************************************************//**
 * @file SRt60Sample_t.h
 * @brief Native Wrapper for Managed type Rt60Sample_t.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _SRT60_SAMPLE_T_H
#define _SRT60_SAMPLE_T_H
#include <ISupportByteArrayConversion.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI ISupportByteArrayConversion;
		class LDAPI Array_SRt60SampleData_t;

		struct LDAPI SRt60Sample_t : public virtual ISupportByteArrayConversion
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			SRt60Sample_t(const SRt60Sample_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~SRt60Sample_t(void);
			SRt60Sample_t(void);
			uint16_t includeInAvg(void);
			void includeInAvg(uint16_t value);
			uint16_t position(void);
			void position(uint16_t value);
			std::shared_ptr<Array_SRt60SampleData_t> data(void);
			void data(std::shared_ptr<Array_SRt60SampleData_t> value);
#ifdef MAKEDLL
		public: // This is for internal use
			SRt60Sample_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _SRT60_SAMPLE_T_H
