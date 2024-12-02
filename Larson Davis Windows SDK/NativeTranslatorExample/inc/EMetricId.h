/**************************************************************************//**
 * @file EMetricId.h
 * @brief Native Wrapper for Managed type MetricId.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _EMETRIC_ID_H
#define _EMETRIC_ID_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class EMetricId
		{
			LAeq = 0,
			LCeq = 1,
			LASmax = 2,
			LAFmax = 3,
			LCpeak = 4,
			LCpk = 4,
			LZpeak = 5,
			LZpk = 5,
			TWA3 = 6,
			TWA5 = 7,
			IntTemp = 8,
			GaugeTemp = 9,
			BattVolt = 10,
			BattPercent = 11,
			AvgCurrent = 12,
			EstTime = 13,
			Tms = 14,
			FullOba = 15,
			ThirdOba = 16,
			FullObaMin = 17,
			FullObaMax = 18,
			ThirdObaMin = 19,
			ThirdObaMax = 20,
			LASmin = 21,
			LAFmin = 22,
			LAImin = 23,
			LAImax = 24,
			LApeak = 25,
			LApk = 25,
			LCSmin = 26,
			LCSmax = 27,
			LCFmin = 28,
			LCFmax = 29,
			LCImin = 30,
			LCImax = 31,
			LZeq = 32,
			LZSmin = 33,
			LZSmax = 34,
			LZFmin = 35,
			LZFmax = 36,
			LZImin = 37,
			LZImax = 38,
			ExtVolts = 39,
			PwrSource = 40,
			Bump = 41,
			Motion = 42,
			Overload = 43,
			Invalid = 44,
		};
	}
}
#endif // _EMETRIC_ID_H
