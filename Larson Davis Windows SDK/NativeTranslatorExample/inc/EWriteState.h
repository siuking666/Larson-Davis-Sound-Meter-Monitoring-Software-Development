/**************************************************************************//**
 * @file EWriteState.h
 * @brief Native Wrapper for Managed type WriteState.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _EWRITE_STATE_H
#define _EWRITE_STATE_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class EWriteState
		{
			Error = 0,
			Closed = 1,
			Object = 2,
			Array = 3,
			Constructor = 4,
			Property = 5,
			Start = 6,
		};
	}
}
#endif // _EWRITE_STATE_H
