/**************************************************************************//**
 * @file EFftTonalityStandard.h
 * @brief Native Wrapper for Managed type FftTonalityStandard.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _EFFT_TONALITY_STANDARD_H
#define _EFFT_TONALITY_STANDARD_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class EFftTonalityStandard
		{
			None = 0,
			Tone1996_2 = 1,
			Tone20065 = 2,
		};
	}
}
#endif // _EFFT_TONALITY_STANDARD_H
