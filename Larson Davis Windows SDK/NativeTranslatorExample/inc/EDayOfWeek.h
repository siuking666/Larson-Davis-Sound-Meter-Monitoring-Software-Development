/**************************************************************************//**
 * @file EDayOfWeek.h
 * @brief Native Wrapper for Managed type DayOfWeek.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _EDAY_OF_WEEK_H
#define _EDAY_OF_WEEK_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class EDayOfWeek
		{
			Sunday = 0,
			Monday = 1,
			Tuesday = 2,
			Wednesday = 3,
			Thursday = 4,
			Friday = 5,
			Saturday = 6,
		};
	}
}
#endif // _EDAY_OF_WEEK_H
