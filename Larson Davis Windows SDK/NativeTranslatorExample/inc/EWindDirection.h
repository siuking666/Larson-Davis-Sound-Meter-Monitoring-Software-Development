/**************************************************************************//**
 * @file EWindDirection.h
 * @brief Native Wrapper for Managed type WindDirection.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _EWIND_DIRECTION_H
#define _EWIND_DIRECTION_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class EWindDirection
		{
			Compass = 0,
			Degrees = 1,
			Percent = 2,
			Volts = 3,
		};
	}
}
#endif // _EWIND_DIRECTION_H
