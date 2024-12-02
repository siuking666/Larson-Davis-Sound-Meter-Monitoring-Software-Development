/**************************************************************************//**
 * @file EMeasureType.h
 * @brief Native Wrapper for Managed type MeasureType.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _EMEASURE_TYPE_H
#define _EMEASURE_TYPE_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class EMeasureType
		{
			None = 0,
			L1 = 1,
			L2 = 2,
			B2 = 3,
			T2 = 4,
			Fft = 5,
		};
	}
}
#endif // _EMEASURE_TYPE_H
