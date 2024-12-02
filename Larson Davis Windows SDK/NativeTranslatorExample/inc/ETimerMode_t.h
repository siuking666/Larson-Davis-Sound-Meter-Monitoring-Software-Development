/**************************************************************************//**
 * @file ETimerMode_t.h
 * @brief Native Wrapper for Managed type TimerMode_t.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ETIMER_MODE_T_H
#define _ETIMER_MODE_T_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class ETimerMode_t
		{
			TIMER_MODE_MANUAL = 0,
			TIMER_MODE_TIMED_STOP = 1,
			TIMER_MODE_DAILY = 2,
			TIMER_MODE_CONT = 3,
		};
	}
}
#endif // _ETIMER_MODE_T_H
