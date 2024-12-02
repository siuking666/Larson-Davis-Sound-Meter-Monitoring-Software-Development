/**************************************************************************//**
 * @file ETimeHistoryPeriod.h
 * @brief Native Wrapper for Managed type TimeHistoryPeriod.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ETIME_HISTORY_PERIOD_H
#define _ETIME_HISTORY_PERIOD_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class ETimeHistoryPeriod
		{
			P20ms = 0,
			P50ms = 1,
			P100ms = 2,
			P200ms = 3,
			P500ms = 4,
			P1s = 5,
			P2s = 6,
			P5s = 7,
			P10s = 8,
			P15s = 9,
			P20s = 10,
			P30s = 11,
			P1m = 12,
			P2m = 13,
			P5m = 14,
			P10m = 15,
			P15m = 16,
			P20m = 17,
			P30m = 18,
			P1h = 19,
			P24h = 20,
			P2500us = 21,
			P5ms = 22,
			P10ms = 23,
		};
	}
}
#endif // _ETIME_HISTORY_PERIOD_H
