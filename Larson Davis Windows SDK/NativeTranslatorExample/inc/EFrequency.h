/**************************************************************************//**
 * @file EFrequency.h
 * @brief Native Wrapper for Managed type Frequency.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _EFREQUENCY_H
#define _EFREQUENCY_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class EFrequency
		{
			Freq_Z = 0,
			Freq_Mid = 1,
			Freq_6_3 = 2,
			FreqOffset = 2,
			Freq_8 = 3,
			Freq_10 = 4,
			Freq_12_5 = 5,
			Freq_16 = 6,
			Freq_20 = 7,
			Freq_25 = 8,
			Freq_31_5 = 9,
			Freq_40 = 10,
			Freq_50 = 11,
			Freq_63 = 12,
			Freq_80 = 13,
			Freq_100 = 14,
			Freq_125 = 15,
			Freq_160 = 16,
			Freq_200 = 17,
			Freq_250 = 18,
			Freq_315 = 19,
			Freq_400 = 20,
			Freq_500 = 21,
			Freq_630 = 22,
			Freq_800 = 23,
			Freq_1000 = 24,
			Freq_1250 = 25,
			Freq_1600 = 26,
			Freq_2000 = 27,
			Freq_2500 = 28,
			Freq_3150 = 29,
			Freq_4000 = 30,
			Freq_5000 = 31,
			Freq_6300 = 32,
			Freq_8000 = 33,
			Freq_10000 = 34,
			Freq_12500 = 35,
			Freq_16000 = 36,
			Freq_20000 = 37,
			Freq_Invalid = 38,
			Max = 38,
		};
	}
}
#endif // _EFREQUENCY_H
