/**************************************************************************//**
 * @file EAudioFormat.h
 * @brief Native Wrapper for Managed type AudioFormat.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _EAUDIO_FORMAT_H
#define _EAUDIO_FORMAT_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class EAudioFormat
		{
			Unknown = 0,
			Raw = 1,
			Wave = 2,
			Ogg = 3,
		};
	}
}
#endif // _EAUDIO_FORMAT_H
