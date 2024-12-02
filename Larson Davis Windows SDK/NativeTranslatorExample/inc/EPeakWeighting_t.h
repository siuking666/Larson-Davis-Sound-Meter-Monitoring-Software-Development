/**************************************************************************//**
 * @file EPeakWeighting_t.h
 * @brief Native Wrapper for Managed type PeakWeighting_t.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _EPEAK_WEIGHTING_T_H
#define _EPEAK_WEIGHTING_T_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class EPeakWeighting_t
		{
			PEAKWT_A = 0,
			PEAKWT_C = 1,
			PEAKWT_Z = 2,
		};
	}
}
#endif // _EPEAK_WEIGHTING_T_H
