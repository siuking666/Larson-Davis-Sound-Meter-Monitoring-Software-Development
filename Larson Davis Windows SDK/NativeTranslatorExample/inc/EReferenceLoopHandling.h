/**************************************************************************//**
 * @file EReferenceLoopHandling.h
 * @brief Native Wrapper for Managed type ReferenceLoopHandling.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _EREFERENCE_LOOP_HANDLING_H
#define _EREFERENCE_LOOP_HANDLING_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class EReferenceLoopHandling
		{
			Error = 0,
			Ignore = 1,
			Serialize = 2,
		};
	}
}
#endif // _EREFERENCE_LOOP_HANDLING_H
