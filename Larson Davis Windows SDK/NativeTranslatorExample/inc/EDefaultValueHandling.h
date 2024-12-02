/**************************************************************************//**
 * @file EDefaultValueHandling.h
 * @brief Native Wrapper for Managed type DefaultValueHandling.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _EDEFAULT_VALUE_HANDLING_H
#define _EDEFAULT_VALUE_HANDLING_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class EDefaultValueHandling
		{
			Include = 0,
			Ignore = 1,
			Populate = 2,
			IgnoreAndPopulate = 3,
		};
	}
}
#endif // _EDEFAULT_VALUE_HANDLING_H
