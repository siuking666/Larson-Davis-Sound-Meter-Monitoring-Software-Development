/**************************************************************************//**
 * @file ELineInfoHandling.h
 * @brief Native Wrapper for Managed type LineInfoHandling.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ELINE_INFO_HANDLING_H
#define _ELINE_INFO_HANDLING_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class ELineInfoHandling
		{
			Ignore = 0,
			Load = 1,
		};
	}
}
#endif // _ELINE_INFO_HANDLING_H
