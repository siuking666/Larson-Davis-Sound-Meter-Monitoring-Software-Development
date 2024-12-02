/**************************************************************************//**
 * @file ERt60NoiseType.h
 * @brief Native Wrapper for Managed type Rt60NoiseType.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ERT60_NOISE_TYPE_H
#define _ERT60_NOISE_TYPE_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class ERt60NoiseType
		{
			Off = 0,
			White = 1,
			Pink = 2,
		};
	}
}
#endif // _ERT60_NOISE_TYPE_H
