/**************************************************************************//**
 * @file EPeakWeightId.h
 * @brief Native Wrapper for Managed type PeakWeightId.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _EPEAK_WEIGHT_ID_H
#define _EPEAK_WEIGHT_ID_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class EPeakWeightId : uint8_t
		{
			A = 4u,
			C = 2u,
			Z = 5u,
		};
	}
}
#endif // _EPEAK_WEIGHT_ID_H
