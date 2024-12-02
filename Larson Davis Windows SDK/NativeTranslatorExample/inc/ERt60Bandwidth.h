/**************************************************************************//**
 * @file ERt60Bandwidth.h
 * @brief Native Wrapper for Managed type Rt60Bandwidth.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ERT60_BANDWIDTH_H
#define _ERT60_BANDWIDTH_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class ERt60Bandwidth
		{
			Off = 0,
			FullOctave = 1,
			ThirdOctave = 2,
			Both = 3,
		};
	}
}
#endif // _ERT60_BANDWIDTH_H
