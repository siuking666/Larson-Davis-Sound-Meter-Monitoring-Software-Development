/**************************************************************************//**
 * @file EFloatFormatHandling.h
 * @brief Native Wrapper for Managed type FloatFormatHandling.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _EFLOAT_FORMAT_HANDLING_H
#define _EFLOAT_FORMAT_HANDLING_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class EFloatFormatHandling
		{
			String = 0,
			Symbol = 1,
			DefaultValue = 2,
		};
	}
}
#endif // _EFLOAT_FORMAT_HANDLING_H
