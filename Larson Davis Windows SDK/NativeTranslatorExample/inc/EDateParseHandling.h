/**************************************************************************//**
 * @file EDateParseHandling.h
 * @brief Native Wrapper for Managed type DateParseHandling.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _EDATE_PARSE_HANDLING_H
#define _EDATE_PARSE_HANDLING_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class EDateParseHandling
		{
			None = 0,
			DateTime = 1,
			DateTimeOffset = 2,
		};
	}
}
#endif // _EDATE_PARSE_HANDLING_H
