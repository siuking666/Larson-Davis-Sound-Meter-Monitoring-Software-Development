/**************************************************************************//**
 * @file EFftRegressionRange.h
 * @brief Native Wrapper for Managed type FftRegressionRange.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _EFFT_REGRESSION_RANGE_H
#define _EFFT_REGRESSION_RANGE_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class EFftRegressionRange
		{
			R50 = 0,
			R75 = 1,
			R100 = 2,
			R150 = 3,
			R200 = 4,
		};
	}
}
#endif // _EFFT_REGRESSION_RANGE_H
