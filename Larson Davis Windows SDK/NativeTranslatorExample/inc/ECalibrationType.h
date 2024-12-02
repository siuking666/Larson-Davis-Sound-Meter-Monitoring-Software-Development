/**************************************************************************//**
 * @file ECalibrationType.h
 * @brief Native Wrapper for Managed type CalibrationType.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ECALIBRATION_TYPE_H
#define _ECALIBRATION_TYPE_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class ECalibrationType
		{
			Unknown = 0,
			Normal = 1,
			CalCheck = 2,
		};
	}
}
#endif // _ECALIBRATION_TYPE_H
