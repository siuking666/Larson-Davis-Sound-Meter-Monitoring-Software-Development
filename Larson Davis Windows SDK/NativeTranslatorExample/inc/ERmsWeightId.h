/**************************************************************************//**
 * @file ERmsWeightId.h
 * @brief Native Wrapper for Managed type RmsWeightId.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ERMS_WEIGHT_ID_H
#define _ERMS_WEIGHT_ID_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class ERmsWeightId : uint8_t
		{
			A = 1u,
			C = 2u,
			Z = 3u,
		};
	}
}
#endif // _ERMS_WEIGHT_ID_H
