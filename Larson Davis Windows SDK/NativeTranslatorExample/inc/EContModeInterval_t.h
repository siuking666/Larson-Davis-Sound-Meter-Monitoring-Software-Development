/**************************************************************************//**
 * @file EContModeInterval_t.h
 * @brief Native Wrapper for Managed type ContModeInterval_t.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ECONT_MODE_INTERVAL_T_H
#define _ECONT_MODE_INTERVAL_T_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class EContModeInterval_t
		{
			H_24 = 0,
			H_12 = 1,
			H_6 = 2,
			H_4 = 3,
			H_2 = 4,
			H_1 = 5,
			M_30 = 6,
			M_15 = 7,
			M_10 = 8,
			M_5 = 9,
			M_2 = 10,
			M_1 = 11,
		};
	}
}
#endif // _ECONT_MODE_INTERVAL_T_H
