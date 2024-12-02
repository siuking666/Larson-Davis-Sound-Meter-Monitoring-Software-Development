/**************************************************************************//**
 * @file EDateTimeStyles.h
 * @brief Native Wrapper for Managed type DateTimeStyles.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _EDATE_TIME_STYLES_H
#define _EDATE_TIME_STYLES_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class EDateTimeStyles
		{
			None = 0,
			AllowLeadingWhite = 1,
			AllowTrailingWhite = 2,
			AllowInnerWhite = 4,
			AllowWhiteSpaces = 7,
			NoCurrentDateDefault = 8,
			AdjustToUniversal = 16,
			AssumeLocal = 32,
			AssumeUniversal = 64,
			RoundtripKind = 128,
		};
	}
}
#endif // _EDATE_TIME_STYLES_H
