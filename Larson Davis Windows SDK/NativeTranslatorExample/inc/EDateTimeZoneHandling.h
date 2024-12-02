/**************************************************************************//**
 * @file EDateTimeZoneHandling.h
 * @brief Native Wrapper for Managed type DateTimeZoneHandling.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _EDATE_TIME_ZONE_HANDLING_H
#define _EDATE_TIME_ZONE_HANDLING_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class EDateTimeZoneHandling
		{
			Local = 0,
			Utc = 1,
			Unspecified = 2,
			RoundtripKind = 3,
		};
	}
}
#endif // _EDATE_TIME_ZONE_HANDLING_H
