/**************************************************************************//**
 * @file SDailyNoise_t.h
 * @brief Native Wrapper for Managed type DailyNoise_t.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _SDAILY_NOISE_T_H
#define _SDAILY_NOISE_T_H
#include <ISupportByteArrayConversion.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI ISupportByteArrayConversion;

		struct LDAPI SDailyNoise_t : public virtual ISupportByteArrayConversion
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			SDailyNoise_t(const SDailyNoise_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~SDailyNoise_t(void);
			SDailyNoise_t(void);
			const int32_t HNL_Length = 24;
			float HNL(int32_t index);
			void HNL(int32_t index, float value);
			float Time(void);
			void Time(float value);
			const int32_t TimeHr_Length = 24;
			float TimeHr(int32_t index);
			void TimeHr(int32_t index, float value);
			float Lden_Day(void);
			void Lden_Day(float value);
			float T_Lden_Day(void);
			void T_Lden_Day(float value);
			float Lden_Eve(void);
			void Lden_Eve(float value);
			float T_Lden_Eve(void);
			void T_Lden_Eve(float value);
			float Lden_Night(void);
			void Lden_Night(float value);
			float T_Lden_Night(void);
			void T_Lden_Night(float value);
			float Ldn_Day(void);
			void Ldn_Day(float value);
			float T_Ldn_Day(void);
			void T_Ldn_Day(float value);
			float Ldn_Night(void);
			void Ldn_Night(float value);
			float T_Ldn_Night(void);
			void T_Ldn_Night(float value);
#ifdef MAKEDLL
		public: // This is for internal use
			SDailyNoise_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _SDAILY_NOISE_T_H
