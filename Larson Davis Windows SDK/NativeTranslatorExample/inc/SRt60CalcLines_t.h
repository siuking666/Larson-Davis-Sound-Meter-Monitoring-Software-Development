/**************************************************************************//**
 * @file SRt60CalcLines_t.h
 * @brief Native Wrapper for Managed type Rt60CalcLines_t.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _SRT60_CALC_LINES_T_H
#define _SRT60_CALC_LINES_T_H
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI Array_SRt60TimeSample_t;

		struct LDAPI SRt60CalcLines_t
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			SRt60CalcLines_t(const SRt60CalcLines_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~SRt60CalcLines_t(void);
			SRt60CalcLines_t(void);
			std::shared_ptr<Array_SRt60TimeSample_t> schroederByFreq(void);
			void schroederByFreq(std::shared_ptr<Array_SRt60TimeSample_t> value);
			std::shared_ptr<Array_SRt60TimeSample_t> regressionLineByFreq(void);
			void regressionLineByFreq(std::shared_ptr<Array_SRt60TimeSample_t> value);
#ifdef MAKEDLL
		public: // This is for internal use
			SRt60CalcLines_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _SRT60_CALC_LINES_T_H
