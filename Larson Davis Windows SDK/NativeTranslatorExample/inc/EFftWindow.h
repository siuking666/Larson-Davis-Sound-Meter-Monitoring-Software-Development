/**************************************************************************//**
 * @file EFftWindow.h
 * @brief Native Wrapper for Managed type FftWindow.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _EFFT_WINDOW_H
#define _EFFT_WINDOW_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class EFftWindow
		{
			Hanning = 0,
			FlatTop = 1,
			Rectangle = 2,
		};
	}
}
#endif // _EFFT_WINDOW_H
