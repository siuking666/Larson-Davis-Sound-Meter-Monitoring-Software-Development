/**************************************************************************//**
 * @file EUnitType.h
 * @brief Native Wrapper for Managed type UnitType.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _EUNIT_TYPE_H
#define _EUNIT_TYPE_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class EUnitType
		{
			None = 0,
			Wind = 1,
			Temp = 2,
			Humidity = 3,
			Barometer = 4,
			RainAccum = 5,
			RainMaxIntensity = 6,
			RainDuration = 7,
			HailAccum = 8,
			HailMaxIntensity = 9,
			HailDuration = 10,
			Altitude = 11,
			dB = 12,
			Volts = 13,
			Direction = 14,
		};
	}
}
#endif // _EUNIT_TYPE_H
