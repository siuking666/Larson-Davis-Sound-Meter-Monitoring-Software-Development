/**************************************************************************//**
 * @file EDecimalFormat.h
 * @brief Native Wrapper for Managed type DecimalFormat.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _EDECIMAL_FORMAT_H
#define _EDECIMAL_FORMAT_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class EDecimalFormat
		{
			Decimal = 0,
			Comma = 1,
		};
	}
}
#endif // _EDECIMAL_FORMAT_H
