/**************************************************************************//**
 * @file EObjectCreationHandling.h
 * @brief Native Wrapper for Managed type ObjectCreationHandling.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _EOBJECT_CREATION_HANDLING_H
#define _EOBJECT_CREATION_HANDLING_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class EObjectCreationHandling
		{
			Auto = 0,
			Reuse = 1,
			Replace = 2,
		};
	}
}
#endif // _EOBJECT_CREATION_HANDLING_H
