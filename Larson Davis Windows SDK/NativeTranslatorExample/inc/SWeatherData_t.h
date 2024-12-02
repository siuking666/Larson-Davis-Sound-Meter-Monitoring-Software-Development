/**************************************************************************//**
 * @file SWeatherData_t.h
 * @brief Native Wrapper for Managed type WeatherData_t.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _SWEATHER_DATA_T_H
#define _SWEATHER_DATA_T_H
#include <ISupportByteArrayConversion.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI ISupportByteArrayConversion;
		class LDAPI Array_uint32_t;

		struct LDAPI SWeatherData_t : public virtual ISupportByteArrayConversion
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			SWeatherData_t(const SWeatherData_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~SWeatherData_t(void);
			SWeatherData_t(void);
			float WindSpeedAvg(void);
			void WindSpeedAvg(float value);
			float WindSpeedMax(void);
			void WindSpeedMax(float value);
			float WindSpeedMin(void);
			void WindSpeedMin(float value);
			std::shared_ptr<Array_uint32_t> WindDirStats(void);
			void WindDirStats(std::shared_ptr<Array_uint32_t> value);
			float WindDirMax(void);
			void WindDirMax(float value);
			float ADC1Avg(void);
			void ADC1Avg(float value);
			float ADC1Max(void);
			void ADC1Max(float value);
			float ADC1Min(void);
			void ADC1Min(float value);
			float ADC2Avg(void);
			void ADC2Avg(float value);
			float ADC2Max(void);
			void ADC2Max(float value);
			float ADC2Min(void);
			void ADC2Min(float value);
			float ADC3Avg(void);
			void ADC3Avg(float value);
			float ADC3Max(void);
			void ADC3Max(float value);
			float ADC3Min(void);
			void ADC3Min(float value);
			float RainTotal(void);
			void RainTotal(float value);
			float RainMaxRate(void);
			void RainMaxRate(float value);
			float RainDuration(void);
			void RainDuration(float value);
			float HailTotal(void);
			void HailTotal(float value);
			float HailMaxRate(void);
			void HailMaxRate(float value);
			float HailDuration(void);
			void HailDuration(float value);
#ifdef MAKEDLL
		public: // This is for internal use
			SWeatherData_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _SWEATHER_DATA_T_H
