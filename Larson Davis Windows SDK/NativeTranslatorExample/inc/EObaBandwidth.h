/**************************************************************************//**
 * @file EObaBandwidth.h
 * @brief Native Wrapper for Managed type ObaBandwidth.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _EOBA_BANDWIDTH_H
#define _EOBA_BANDWIDTH_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class EObaBandwidth
		{
			Off = 0,
			FullOctave = 1,
			ThirdOctave = 2,
			Both = 3,
		};
	}
}
#endif // _EOBA_BANDWIDTH_H
