/**************************************************************************//**
 * @file EFormatType.h
 * @brief Native Wrapper for Managed type FormatType.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _EFORMAT_TYPE_H
#define _EFORMAT_TYPE_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class EFormatType
		{
			None = 0,
			dB = 1,
			Date = 2,
			Time = 3,
			F00 = 4,
			Percent = 5,
			F000 = 6,
			Permil = 7,
			Fms = 8,
			F0 = 9,
			F1 = 10,
			F2 = 11,
			F3 = 12,
			F4 = 13,
			F5 = 14,
			F6 = 15,
			N7 = 16,
			EXP = 17,
		};
	}
}
#endif // _EFORMAT_TYPE_H
