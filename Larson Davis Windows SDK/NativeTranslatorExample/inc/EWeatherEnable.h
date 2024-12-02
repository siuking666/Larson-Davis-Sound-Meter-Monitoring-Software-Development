/**************************************************************************//**
 * @file EWeatherEnable.h
 * @brief Native Wrapper for Managed type WeatherEnable.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _EWEATHER_ENABLE_H
#define _EWEATHER_ENABLE_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class EWeatherEnable
		{
			None = 0,
			WeatherInt = 1,
			Vaisala = 2,
		};
	}
}
#endif // _EWEATHER_ENABLE_H
