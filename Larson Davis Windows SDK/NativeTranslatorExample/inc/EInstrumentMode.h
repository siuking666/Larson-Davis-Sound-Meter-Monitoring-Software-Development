/**************************************************************************//**
 * @file EInstrumentMode.h
 * @brief Native Wrapper for Managed type InstrumentMode.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _EINSTRUMENT_MODE_H
#define _EINSTRUMENT_MODE_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class EInstrumentMode
		{
			Slm = 0,
			RT60 = 1,
			Fft = 2,
			AudCal = 3,
			Hvm = 100,
			Dosi = 200,
			Unknown = 10000,
		};
	}
}
#endif // _EINSTRUMENT_MODE_H
