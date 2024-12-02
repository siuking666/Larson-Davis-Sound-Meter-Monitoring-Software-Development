/**************************************************************************//**
 * @file ETraceLevel.h
 * @brief Native Wrapper for Managed type TraceLevel.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ETRACE_LEVEL_H
#define _ETRACE_LEVEL_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class ETraceLevel
		{
			Off = 0,
			Error = 1,
			Warning = 2,
			Info = 3,
			Verbose = 4,
		};
	}
}
#endif // _ETRACE_LEVEL_H
