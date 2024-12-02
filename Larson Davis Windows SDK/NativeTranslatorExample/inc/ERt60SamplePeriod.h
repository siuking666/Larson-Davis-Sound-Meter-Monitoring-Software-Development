/**************************************************************************//**
 * @file ERt60SamplePeriod.h
 * @brief Native Wrapper for Managed type Rt60SamplePeriod.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ERT60_SAMPLE_PERIOD_H
#define _ERT60_SAMPLE_PERIOD_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class ERt60SamplePeriod
		{
			P2500us = 0,
			P5ms = 1,
			P10ms = 2,
			P20ms = 3,
		};
	}
}
#endif // _ERT60_SAMPLE_PERIOD_H
