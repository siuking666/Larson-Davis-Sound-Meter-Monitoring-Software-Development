/**************************************************************************//**
 * @file SRt60ByTime_t.h
 * @brief Native Wrapper for Managed type Rt60ByTime_t.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _SRT60_BY_TIME_T_H
#define _SRT60_BY_TIME_T_H
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI Array_SRt60TimeSample_t;
		class LDAPI Array_SRt60DataLimits_t;

		struct LDAPI SRt60ByTime_t
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			SRt60ByTime_t(const SRt60ByTime_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~SRt60ByTime_t(void);
			SRt60ByTime_t(void);
			std::shared_ptr<Array_SRt60TimeSample_t> freq(void);
			void freq(std::shared_ptr<Array_SRt60TimeSample_t> value);
			std::shared_ptr<Array_SRt60DataLimits_t> stLim(void);
			void stLim(std::shared_ptr<Array_SRt60DataLimits_t> value);
#ifdef MAKEDLL
		public: // This is for internal use
			SRt60ByTime_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _SRT60_BY_TIME_T_H
