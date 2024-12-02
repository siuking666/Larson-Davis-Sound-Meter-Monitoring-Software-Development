/**************************************************************************//**
 * @file EExchangeRateId_t.h
 * @brief Native Wrapper for Managed type ExchangeRateId_t.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _EEXCHANGE_RATE_ID_T_H
#define _EEXCHANGE_RATE_ID_T_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class EExchangeRateId_t
		{
			dose_ex_rate_3dB = 0,
			dose_ex_rate_4dB = 1,
			dose_ex_rate_5dB = 2,
			dose_ex_rate_6dB = 3,
		};
	}
}
#endif // _EEXCHANGE_RATE_ID_T_H
