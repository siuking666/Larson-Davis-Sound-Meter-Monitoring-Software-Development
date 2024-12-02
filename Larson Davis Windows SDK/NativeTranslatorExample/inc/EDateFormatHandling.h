/**************************************************************************//**
 * @file EDateFormatHandling.h
 * @brief Native Wrapper for Managed type DateFormatHandling.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _EDATE_FORMAT_HANDLING_H
#define _EDATE_FORMAT_HANDLING_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class EDateFormatHandling
		{
			IsoDateFormat = 0,
			MicrosoftDateFormat = 1,
		};
	}
}
#endif // _EDATE_FORMAT_HANDLING_H
