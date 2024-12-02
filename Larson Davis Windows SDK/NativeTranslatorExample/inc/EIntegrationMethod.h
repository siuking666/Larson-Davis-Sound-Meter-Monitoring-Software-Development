/**************************************************************************//**
 * @file EIntegrationMethod.h
 * @brief Native Wrapper for Managed type IntegrationMethod.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _EINTEGRATION_METHOD_H
#define _EINTEGRATION_METHOD_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class EIntegrationMethod
		{
			Linear = 0,
			Exponential = 1,
		};
	}
}
#endif // _EINTEGRATION_METHOD_H
