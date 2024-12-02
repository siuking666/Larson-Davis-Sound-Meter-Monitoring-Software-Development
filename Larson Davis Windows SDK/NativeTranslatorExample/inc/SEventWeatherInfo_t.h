/**************************************************************************//**
 * @file SEventWeatherInfo_t.h
 * @brief Native Wrapper for Managed type EventWeatherInfo_t.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _SEVENT_WEATHER_INFO_T_H
#define _SEVENT_WEATHER_INFO_T_H
#include <ISupportByteArrayConversion.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI ISupportByteArrayConversion;

		struct LDAPI SEventWeatherInfo_t : public virtual ISupportByteArrayConversion
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			SEventWeatherInfo_t(const SEventWeatherInfo_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~SEventWeatherInfo_t(void);
			SEventWeatherInfo_t(void);
			float lmax_wind_speed(void);
			void lmax_wind_speed(float value);
			float lmax_wind_dir(void);
			void lmax_wind_dir(float value);
			float max_wind_speed(void);
			void max_wind_speed(float value);
			float max_wind_dir(void);
			void max_wind_dir(float value);
#ifdef MAKEDLL
		public: // This is for internal use
			SEventWeatherInfo_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _SEVENT_WEATHER_INFO_T_H
