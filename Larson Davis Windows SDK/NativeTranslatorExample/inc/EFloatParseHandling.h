/**************************************************************************//**
 * @file EFloatParseHandling.h
 * @brief Native Wrapper for Managed type FloatParseHandling.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _EFLOAT_PARSE_HANDLING_H
#define _EFLOAT_PARSE_HANDLING_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class EFloatParseHandling
		{
			Double = 0,
			Decimal = 1,
		};
	}
}
#endif // _EFLOAT_PARSE_HANDLING_H
