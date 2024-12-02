/**************************************************************************//**
 * @file EStringEscapeHandling.h
 * @brief Native Wrapper for Managed type StringEscapeHandling.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ESTRING_ESCAPE_HANDLING_H
#define _ESTRING_ESCAPE_HANDLING_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class EStringEscapeHandling
		{
			Default = 0,
			EscapeNonAscii = 1,
			EscapeHtml = 2,
		};
	}
}
#endif // _ESTRING_ESCAPE_HANDLING_H
