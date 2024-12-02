/**************************************************************************//**
 * @file EDetectorId.h
 * @brief Native Wrapper for Managed type DetectorId.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _EDETECTOR_ID_H
#define _EDETECTOR_ID_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class EDetectorId : uint8_t
		{
			Fast = 1u,
			Slow = 2u,
			Impulse = 3u,
		};
	}
}
#endif // _EDETECTOR_ID_H
