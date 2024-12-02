/**************************************************************************//**
 * @file SRt60Record_t.h
 * @brief Native Wrapper for Managed type Rt60Record_t.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _SRT60_RECORD_T_H
#define _SRT60_RECORD_T_H
#include <ISupportByteArrayConversion.h>
#include <EMeasureSubType.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI ISupportByteArrayConversion;
		struct LDAPI SRt60Average_t;
		struct LDAPI SRt60SampleLimits_t;

		struct LDAPI SRt60Record_t : public virtual ISupportByteArrayConversion
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			SRt60Record_t(const SRt60Record_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~SRt60Record_t(void);
			SRt60Record_t(void);
			EMeasureSubType recType(void);
			void recType(EMeasureSubType value);
			std::shared_ptr<SRt60Average_t> stAvg(void);
			void stAvg(std::shared_ptr<SRt60Average_t> value);
			std::shared_ptr<SRt60SampleLimits_t> stSpl(void);
			void stSpl(std::shared_ptr<SRt60SampleLimits_t> value);
#ifdef MAKEDLL
		public: // This is for internal use
			SRt60Record_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _SRT60_RECORD_T_H
