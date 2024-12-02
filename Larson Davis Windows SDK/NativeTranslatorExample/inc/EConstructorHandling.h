/**************************************************************************//**
 * @file EConstructorHandling.h
 * @brief Native Wrapper for Managed type ConstructorHandling.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ECONSTRUCTOR_HANDLING_H
#define _ECONSTRUCTOR_HANDLING_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class EConstructorHandling
		{
			Default = 0,
			AllowNonPublicDefaultConstructor = 1,
		};
	}
}
#endif // _ECONSTRUCTOR_HANDLING_H
