/**************************************************************************//**
 * @file ENullValueHandling.h
 * @brief Native Wrapper for Managed type NullValueHandling.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ENULL_VALUE_HANDLING_H
#define _ENULL_VALUE_HANDLING_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class ENullValueHandling
		{
			Include = 0,
			Ignore = 1,
		};
	}
}
#endif // _ENULL_VALUE_HANDLING_H
