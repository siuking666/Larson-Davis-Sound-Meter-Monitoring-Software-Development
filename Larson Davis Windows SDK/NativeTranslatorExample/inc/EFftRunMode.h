/**************************************************************************//**
 * @file EFftRunMode.h
 * @brief Native Wrapper for Managed type FftRunMode.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _EFFT_RUN_MODE_H
#define _EFFT_RUN_MODE_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class EFftRunMode
		{
			ManualStop = 0,
			CountStop = 1,
			TimedStop = 2,
			Continuous = 3,
			SingleBlockTimer = 4,
			DailyTimer = 5,
		};
	}
}
#endif // _EFFT_RUN_MODE_H
