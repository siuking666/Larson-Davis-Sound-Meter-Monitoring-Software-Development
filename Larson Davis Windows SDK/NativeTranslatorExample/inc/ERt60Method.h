/**************************************************************************//**
 * @file ERt60Method.h
 * @brief Native Wrapper for Managed type Rt60Method.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ERT60_METHOD_H
#define _ERT60_METHOD_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class ERt60Method
		{
			Impulse = 0,
			Interrupted = 1,
		};
	}
}
#endif // _ERT60_METHOD_H
