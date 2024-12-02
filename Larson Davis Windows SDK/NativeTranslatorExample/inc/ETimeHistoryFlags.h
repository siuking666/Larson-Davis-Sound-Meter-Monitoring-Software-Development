/**************************************************************************//**
 * @file ETimeHistoryFlags.h
 * @brief Native Wrapper for Managed type TimeHistoryFlags.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ETIME_HISTORY_FLAGS_H
#define _ETIME_HISTORY_FLAGS_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class ETimeHistoryFlags : uint32_t
		{
			NONE = 0u,
			OVERLOAD = 1u,
			MOTION = 2u,
			BUMP = 4u,
			PAUSED = 8u,
			START = 16u,
			STOP = 32u,
			SREC = 64u,
			A1_ACT_TRIG = 128u,
			A1_LIM_TRIG = 256u,
			A2_ACT_TRIG = 512u,
			A2_LIM_TRIG = 1024u,
			SAMPLES_ERR = 2048u,
			PARTIAL = 4096u,
			USB_POWERED = 8192u,
			QI_POWERED = 16384u,
			EXT_V_POWERED = 32768u,
			DATA_INVALID = 65536u,
			FUTURE_17 = 131072u,
			FUTURE_18 = 262144u,
			FUTURE_19 = 524288u,
			FUTURE_20 = 1048576u,
			FUTURE_21 = 2097152u,
			FUTURE_22 = 4194304u,
			FUTURE_23 = 8388608u,
			FUTURE_24 = 16777216u,
			FUTURE_25 = 33554432u,
			FUTURE_26 = 67108864u,
			FUTURE_27 = 134217728u,
			FUTURE_28 = 268435456u,
			FUTURE_29 = 536870912u,
			FUTURE_30 = 1073741824u,
			PRE_RUN = 2147483648u,
		};
	}
}
#endif // _ETIME_HISTORY_FLAGS_H
