/**************************************************************************//**
 * @file ESpartanSLogCause.h
 * @brief Native Wrapper for Managed type SpartanSLogCause.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ESPARTAN_SLOG_CAUSE_H
#define _ESPARTAN_SLOG_CAUSE_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class ESpartanSLogCause : uint16_t
		{
			Remote = 0u,
			Local = 1u,
			Timer = 2u,
			Power = 3u,
			Memory = 4u,
			Event = 5u,
		};
	}
}
#endif // _ESPARTAN_SLOG_CAUSE_H
