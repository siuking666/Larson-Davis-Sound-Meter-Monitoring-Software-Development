/**************************************************************************//**
 * @file EFftLevel.h
 * @brief Native Wrapper for Managed type FftLevel.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _EFFT_LEVEL_H
#define _EFFT_LEVEL_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class EFftLevel
		{
			Avg = 0,
			Max = 1,
		};
	}
}
#endif // _EFFT_LEVEL_H
