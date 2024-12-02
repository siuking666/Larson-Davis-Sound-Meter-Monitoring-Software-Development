/**************************************************************************//**
 * @file EDosAlarmSrc_t.h
 * @brief Native Wrapper for Managed type DosAlarmSrc_t.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _EDOS_ALARM_SRC_T_H
#define _EDOS_ALARM_SRC_T_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class EDosAlarmSrc_t
		{
			ALARM_SRC_PROJ_DOSE = 0,
			ALARM_SRC_DOSE = 1,
			ALARM_SRC_PROJ_TWA = 2,
			ALARM_SRC_TWA = 3,
			ALARM_SRC_PROJ_LEPD = 4,
			ALARM_SRC_LEPD = 5,
			ALARM_SRC_LAEQ = 6,
			ALARM_SRC_LAVG = 7,
			ALARM_SRC_LCPEAK = 8,
			ALARM_SRC_LZPEAK = 9,
		};
	}
}
#endif // _EDOS_ALARM_SRC_T_H
