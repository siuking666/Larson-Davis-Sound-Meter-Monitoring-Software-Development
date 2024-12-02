/**************************************************************************//**
 * @file SFftTriggerInfo_t.h
 * @brief Native Wrapper for Managed type FftTriggerInfo_t.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _SFFT_TRIGGER_INFO_T_H
#define _SFFT_TRIGGER_INFO_T_H
#include <ISupportByteArrayConversion.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI ISupportByteArrayConversion;

		struct LDAPI SFftTriggerInfo_t : public virtual ISupportByteArrayConversion
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			SFftTriggerInfo_t(const SFftTriggerInfo_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~SFftTriggerInfo_t(void);
			SFftTriggerInfo_t(void);
			int32_t triggerSource(void);
			void triggerSource(int32_t value);
			float triggerLevel(void);
			void triggerLevel(float value);
#ifdef MAKEDLL
		public: // This is for internal use
			SFftTriggerInfo_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _SFFT_TRIGGER_INFO_T_H
