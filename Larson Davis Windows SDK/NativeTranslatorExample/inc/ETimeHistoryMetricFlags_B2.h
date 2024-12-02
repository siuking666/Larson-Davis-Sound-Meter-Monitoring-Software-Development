/**************************************************************************//**
 * @file ETimeHistoryMetricFlags_B2.h
 * @brief Native Wrapper for Managed type TimeHistoryMetricFlags_B2.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ETIME_HISTORY_METRIC_FLAGS_B2_H
#define _ETIME_HISTORY_METRIC_FLAGS_B2_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class ETimeHistoryMetricFlags_B2 : uint32_t
		{
			None = 0u,
			LZSmin = 1u,
			LZSmax = 2u,
			LZFmin = 4u,
			LZFmax = 8u,
			LZImin = 16u,
			LZImax = 32u,
			ExternalVolts = 64u,
			MeasurementMetrics = 127u,
			SupportedFields = 127u,
		};
	}
}
#endif // _ETIME_HISTORY_METRIC_FLAGS_B2_H
