/**************************************************************************//**
 * @file SFilterFreqInfo_t.h
 * @brief Native Wrapper for Managed type FilterFreqInfo_t.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _SFILTER_FREQ_INFO_T_H
#define _SFILTER_FREQ_INFO_T_H
#include <EFrequency.h>
namespace LarsonDavis
{
	namespace Native
	{

		struct LDAPI SFilterFreqInfo_t
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			SFilterFreqInfo_t(const SFilterFreqInfo_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~SFilterFreqInfo_t(void);
			SFilterFreqInfo_t(void);
			EFrequency id(void);
			void id(EFrequency value);
			StringWrapper str(void);
			void str(StringWrapper value);
			float filterFreq(void);
			void filterFreq(float value);
			float filterBand(void);
			void filterBand(float value);
#ifdef MAKEDLL
		public: // This is for internal use
			SFilterFreqInfo_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _SFILTER_FREQ_INFO_T_H
