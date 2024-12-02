/**************************************************************************//**
 * @file EFftLines.h
 * @brief Native Wrapper for Managed type FftLines.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _EFFT_LINES_H
#define _EFFT_LINES_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class EFftLines
		{
			L6400 = 0,
			L3200 = 1,
			L1600 = 2,
			L800 = 3,
			L400 = 4,
		};
	}
}
#endif // _EFFT_LINES_H
