/**************************************************************************//**
 * @file EDetectorSelect_t.h
 * @brief Native Wrapper for Managed type DetectorSelect_t.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _EDETECTOR_SELECT_T_H
#define _EDETECTOR_SELECT_T_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class EDetectorSelect_t
		{
			DETECTOR_IMPL = 0,
			DETECTOR_FAST = 1,
			DETECTOR_SLOW = 2,
			DETECTOR_LINEAR = 3,
		};
	}
}
#endif // _EDETECTOR_SELECT_T_H
