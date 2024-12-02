/**************************************************************************//**
 * @file EDetectorNdx.h
 * @brief Native Wrapper for Managed type DetectorNdx.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _EDETECTOR_NDX_H
#define _EDETECTOR_NDX_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class EDetectorNdx : uint8_t
		{
			Impulse = 0u,
			Fast = 1u,
			Slow = 2u,
		};
	}
}
#endif // _EDETECTOR_NDX_H
