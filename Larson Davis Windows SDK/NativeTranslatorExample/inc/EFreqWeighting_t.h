/**************************************************************************//**
 * @file EFreqWeighting_t.h
 * @brief Native Wrapper for Managed type FreqWeighting_t.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _EFREQ_WEIGHTING_T_H
#define _EFREQ_WEIGHTING_T_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class EFreqWeighting_t
		{
			FREQWT_A = 0,
			FREQWT_C = 1,
			FREQWT_Z = 2,
		};
	}
}
#endif // _EFREQ_WEIGHTING_T_H
