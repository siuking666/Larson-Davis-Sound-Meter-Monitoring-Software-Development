/**************************************************************************//**
 * @file EDosAutoOff_t.h
 * @brief Native Wrapper for Managed type DosAutoOff_t.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _EDOS_AUTO_OFF_T_H
#define _EDOS_AUTO_OFF_T_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class EDosAutoOff_t
		{
			AUTO_OFF_NEVER = 0,
			AUTO_OFF_5MIN = 1,
			AUTO_OFF_10MIN = 2,
			AUTO_OFF_30MIN = 3,
			AUTO_OFF_60MIN = 4,
		};
	}
}
#endif // _EDOS_AUTO_OFF_T_H
