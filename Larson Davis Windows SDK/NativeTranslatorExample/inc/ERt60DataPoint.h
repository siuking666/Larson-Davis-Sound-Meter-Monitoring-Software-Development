/**************************************************************************//**
 * @file ERt60DataPoint.h
 * @brief Native Wrapper for Managed type Rt60DataPoint.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ERT60_DATA_POINT_H
#define _ERT60_DATA_POINT_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class ERt60DataPoint
		{
			Start = 0,
			P20dB = 1,
			P30dB = 2,
			Stop = 3,
		};
	}
}
#endif // _ERT60_DATA_POINT_H
