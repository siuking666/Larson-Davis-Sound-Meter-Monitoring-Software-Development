/**************************************************************************//**
 * @file SFftLevels_t.h
 * @brief Native Wrapper for Managed type FftLevels_t.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _SFFT_LEVELS_T_H
#define _SFFT_LEVELS_T_H
#include <ISupportByteArrayConversion.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI ISupportByteArrayConversion;
		class LDAPI Array_float;

		struct LDAPI SFftLevels_t : public virtual ISupportByteArrayConversion
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			SFftLevels_t(const SFftLevels_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~SFftLevels_t(void);
			SFftLevels_t(void);
			std::shared_ptr<Array_float> levelAvg(void);
			void levelAvg(std::shared_ptr<Array_float> value);
			std::shared_ptr<Array_float> levelMax(void);
			void levelMax(std::shared_ptr<Array_float> value);
#ifdef MAKEDLL
		public: // This is for internal use
			SFftLevels_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _SFFT_LEVELS_T_H
