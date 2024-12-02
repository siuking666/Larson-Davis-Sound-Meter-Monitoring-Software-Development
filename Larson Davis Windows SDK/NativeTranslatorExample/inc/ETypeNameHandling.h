/**************************************************************************//**
 * @file ETypeNameHandling.h
 * @brief Native Wrapper for Managed type TypeNameHandling.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ETYPE_NAME_HANDLING_H
#define _ETYPE_NAME_HANDLING_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class ETypeNameHandling
		{
			None = 0,
			Objects = 1,
			Arrays = 2,
			All = 3,
			Auto = 4,
		};
	}
}
#endif // _ETYPE_NAME_HANDLING_H
