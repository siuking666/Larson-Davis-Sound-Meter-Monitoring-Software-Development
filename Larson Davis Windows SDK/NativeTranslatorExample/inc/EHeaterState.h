/**************************************************************************//**
 * @file EHeaterState.h
 * @brief Native Wrapper for Managed type HeaterState.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _EHEATER_STATE_H
#define _EHEATER_STATE_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class EHeaterState
		{
			Off = 0,
			Enabled = 1,
			Timed = 2,
		};
	}
}
#endif // _EHEATER_STATE_H
