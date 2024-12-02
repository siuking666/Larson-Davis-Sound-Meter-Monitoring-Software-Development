/**************************************************************************//**
 * @file ERt60RecType.h
 * @brief Native Wrapper for Managed type Rt60RecType.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ERT60_REC_TYPE_H
#define _ERT60_REC_TYPE_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class ERt60RecType
		{
			Freq = 0,
			Leq = 1,
			Lmax = 2,
			Lbk = 3,
			T20 = 4,
			BtT20 = 5,
			BkT20 = 6,
			CoT20 = 7,
			CuT20 = 8,
			SdT20 = 9,
			T30 = 10,
			BtT30 = 11,
			BkT30 = 12,
			CoT30 = 13,
			CuT30 = 14,
			SdT30 = 15,
			Edt = 16,
			Max = 17,
		};
	}
}
#endif // _ERT60_REC_TYPE_H
