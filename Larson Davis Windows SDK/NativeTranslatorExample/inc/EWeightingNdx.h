/**************************************************************************//**
 * @file EWeightingNdx.h
 * @brief Native Wrapper for Managed type WeightingNdx.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _EWEIGHTING_NDX_H
#define _EWEIGHTING_NDX_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class EWeightingNdx : uint8_t
		{
			A = 0u,
			C = 1u,
			Z = 2u,
		};
	}
}
#endif // _EWEIGHTING_NDX_H
