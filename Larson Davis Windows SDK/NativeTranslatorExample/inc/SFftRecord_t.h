/**************************************************************************//**
 * @file SFftRecord_t.h
 * @brief Native Wrapper for Managed type FftRecord_t.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _SFFT_RECORD_T_H
#define _SFFT_RECORD_T_H
#include <ISupportByteArrayConversion.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI ISupportByteArrayConversion;
		struct LDAPI SFftInfo_t;
		struct LDAPI SFftLevels_t;
		struct LDAPI SFftTriggerInfo_t;

		struct LDAPI SFftRecord_t : public virtual ISupportByteArrayConversion
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			SFftRecord_t(const SFftRecord_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~SFftRecord_t(void);
			SFftRecord_t(void);
			std::shared_ptr<SFftInfo_t> stInfo(void);
			void stInfo(std::shared_ptr<SFftInfo_t> value);
			std::shared_ptr<SFftLevels_t> stLevels(void);
			void stLevels(std::shared_ptr<SFftLevels_t> value);
			std::shared_ptr<SFftTriggerInfo_t> triggerInfo(void);
			void triggerInfo(std::shared_ptr<SFftTriggerInfo_t> value);
#ifdef MAKEDLL
		public: // This is for internal use
			SFftRecord_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _SFFT_RECORD_T_H
