/**************************************************************************//**
 * @file ETimeSpanStyles.h
 * @brief Native Wrapper for Managed type TimeSpanStyles.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ETIME_SPAN_STYLES_H
#define _ETIME_SPAN_STYLES_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class ETimeSpanStyles
		{
			None = 0,
			AssumeNegative = 1,
		};
	}
}
#endif // _ETIME_SPAN_STYLES_H
