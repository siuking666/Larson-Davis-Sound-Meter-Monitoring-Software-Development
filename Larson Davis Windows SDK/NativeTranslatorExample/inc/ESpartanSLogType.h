/**************************************************************************//**
 * @file ESpartanSLogType.h
 * @brief Native Wrapper for Managed type SpartanSLogType.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ESPARTAN_SLOG_TYPE_H
#define _ESPARTAN_SLOG_TYPE_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class ESpartanSLogType : uint16_t
		{
			Run = 0u,
			Stop = 1u,
			Pause = 2u,
			Resume = 3u,
			SoundRec = 4u,
			VoiceNote = 5u,
			Disconnect = 6u,
			Connect = 7u,
		};
	}
}
#endif // _ESPARTAN_SLOG_TYPE_H
