/**************************************************************************//**
 * @file SFftInfo_t.h
 * @brief Native Wrapper for Managed type FftInfo_t.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _SFFT_INFO_T_H
#define _SFFT_INFO_T_H
#include <ISupportByteArrayConversion.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI ISupportByteArrayConversion;

		struct LDAPI SFftInfo_t : public virtual ISupportByteArrayConversion
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			SFftInfo_t(const SFftInfo_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~SFftInfo_t(void);
			SFftInfo_t(void);
			uint32_t flag(void);
			void flag(uint32_t value);
			uint32_t startSec(void);
			void startSec(uint32_t value);
			uint32_t startMicroSec(void);
			void startMicroSec(uint32_t value);
			float duration(void);
			void duration(float value);
			int32_t count(void);
			void count(int32_t value);
			int32_t overloadCount(void);
			void overloadCount(int32_t value);
			float overloadDuration(void);
			void overloadDuration(float value);
			float leq(void);
			void leq(float value);
			float lpeak(void);
			void lpeak(float value);
			uint32_t arrSize(void);
			void arrSize(uint32_t value);
#ifdef MAKEDLL
		public: // This is for internal use
			SFftInfo_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _SFFT_INFO_T_H
