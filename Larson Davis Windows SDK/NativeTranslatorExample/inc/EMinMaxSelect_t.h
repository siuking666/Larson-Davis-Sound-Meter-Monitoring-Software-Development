/**************************************************************************//**
 * @file EMinMaxSelect_t.h
 * @brief Native Wrapper for Managed type MinMaxSelect_t.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _EMIN_MAX_SELECT_T_H
#define _EMIN_MAX_SELECT_T_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class EMinMaxSelect_t
		{
			MIN_MAX_OFF = 0,
			MIN_ONLY = 1,
			MAX_ONLY = 2,
			MIN_AND_MAX = 3,
		};
	}
}
#endif // _EMIN_MAX_SELECT_T_H
