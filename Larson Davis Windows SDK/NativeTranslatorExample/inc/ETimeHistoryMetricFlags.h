/**************************************************************************//**
 * @file ETimeHistoryMetricFlags.h
 * @brief Native Wrapper for Managed type TimeHistoryMetricFlags.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ETIME_HISTORY_METRIC_FLAGS_H
#define _ETIME_HISTORY_METRIC_FLAGS_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class ETimeHistoryMetricFlags : uint32_t
		{
			None = 0u,
			LAeq = 1u,
			Cpk = 16u,
			LCeq = 2u,
			LAs = 4u,
			LAf = 8u,
			Zpk = 32u,
			Twa3 = 64u,
			Twa5 = 128u,
			InternalTemperature = 256u,
			GaugeTemperature = 512u,
			BatteryVoltage = 1024u,
			BatteryPercent = 2048u,
			AverageCurrent = 4096u,
			EstimatedTime = 8192u,
			Oba11 = 16384u,
			Oba13 = 32768u,
			ObaOctaveMin = 65536u,
			ObaOctaveMax = 131072u,
			ObaThirdMin = 262144u,
			ObaThirdMax = 524288u,
			LASmin = 1048576u,
			LAFmin = 2097152u,
			LAImin = 4194304u,
			LAImax = 8388608u,
			LApk = 16777216u,
			LCSmin = 33554432u,
			LCSmax = 67108864u,
			LCFmin = 134217728u,
			LCFmax = 268435456u,
			LCImin = 536870912u,
			LCImax = 1073741824u,
			LZeq = 2147483648u,
			MeasurementMetrics = 4294902015u,
			SystemMetrics = 7936u,
			SupportedFields = 4294958847u,
			UnitTestMetrics = 4294139903u,
		};
	}
}
#endif // _ETIME_HISTORY_METRIC_FLAGS_H
