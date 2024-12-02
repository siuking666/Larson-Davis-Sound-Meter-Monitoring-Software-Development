/**************************************************************************//**
 * @file EFftFrequencySpan.h
 * @brief Native Wrapper for Managed type FftFrequencySpan.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _EFFT_FREQUENCY_SPAN_H
#define _EFFT_FREQUENCY_SPAN_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class EFftFrequencySpan
		{
			FS20000Hz = 0,
			FS10000Hz = 1,
			FS5000Hz = 2,
			FS2000Hz = 3,
			FS1000Hz = 4,
			FS500Hz = 5,
			FS200Hz = 6,
			FS100Hz = 7,
		};
	}
}
#endif // _EFFT_FREQUENCY_SPAN_H
