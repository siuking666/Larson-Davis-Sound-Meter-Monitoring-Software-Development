/**************************************************************************//**
 * @file ETHOptionType.h
 * @brief Native Wrapper for Managed type THOptionType.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ETHOPTION_TYPE_H
#define _ETHOPTION_TYPE_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class ETHOptionType
		{
			dB = 1,
			FullOctave = 2,
			ThirdOctave = 3,
			Weather = 4,
			Normal = 5,
			LxT = 6,
		};
	}
}
#endif // _ETHOPTION_TYPE_H
