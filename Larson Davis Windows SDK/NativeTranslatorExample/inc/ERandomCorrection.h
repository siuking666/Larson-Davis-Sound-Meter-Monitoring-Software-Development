/**************************************************************************//**
 * @file ERandomCorrection.h
 * @brief Native Wrapper for Managed type RandomCorrection.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ERANDOM_CORRECTION_H
#define _ERANDOM_CORRECTION_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class ERandomCorrection
		{
			Off = 0,
			RI2FF = 1,
			FF2RI = 2,
			FF2RI_2106_8 = 3,
			FF2FF_2106_8 = 4,
			FF290_2106_8 = 5,
			FF2RI_2116 = 6,
			FF2FF_2116 = 7,
			FF290_2116 = 8,
			P12RI = 9,
			Count = 10,
		};
	}
}
#endif // _ERANDOM_CORRECTION_H
