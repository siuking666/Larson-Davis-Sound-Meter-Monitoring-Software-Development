/**************************************************************************//**
 * @file ETHOptionId.h
 * @brief Native Wrapper for Managed type THOptionId.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ETHOPTION_ID_H
#define _ETHOPTION_ID_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class ETHOptionId
		{
			Leq = 0,
			Lmax = 1,
			Lpeak = 2,
			Lpk = 2,
			Lmin = 3,
			SPL = 4,
			CMinusA = 5,
			LeqA = 6,
			PeakA = 7,
			LApk = 7,
			SlowLmaxA = 8,
			FastLmaxA = 9,
			ImpLmaxA = 10,
			SlowLminA = 11,
			FastLminA = 12,
			ImpLminA = 13,
			ASlowSPL = 14,
			AFastSPL = 15,
			AImplSPL = 16,
			LeqC = 17,
			PeakC = 18,
			LCpk = 18,
			SlowLmaxC = 19,
			FastLmaxC = 20,
			ImpLmaxC = 21,
			SlowLminC = 22,
			FastLminC = 23,
			ImpLminC = 24,
			CSlowSPL = 25,
			CFastSPL = 26,
			CImplSPL = 27,
			LeqZ = 28,
			PeakZ = 29,
			LZpk = 29,
			SlowLmaxZ = 30,
			FastLmaxZ = 31,
			ImpLmaxZ = 32,
			SlowLminZ = 33,
			FastLminZ = 34,
			ImpLminZ = 35,
			ZSlowSPL = 36,
			ZFastSPL = 37,
			ZImplSPL = 38,
			Ltm5 = 39,
			LTWA1 = 40,
			LTWA2 = 41,
			OBALeq11 = 42,
			OBAMax11 = 43,
			OBAMin11 = 44,
			OBALeq13 = 45,
			OBAMax13 = 46,
			OBAMin13 = 47,
			OBASPL11 = 48,
			OBASPL13 = 49,
			AvgWindSpeed = 50,
			GustDir = 51,
			GustSpeed = 52,
			ADC1Avg = 53,
			ADC1Max = 54,
			ADC1Min = 55,
			ADC2Avg = 56,
			ADC2Max = 57,
			ADC2Min = 58,
			PreampHumidity = 59,
			PreampTemperature = 60,
			ExtPower = 61,
			Battery = 62,
			IntTemp = 63,
			ADC3Avg = 64,
			ADC3Max = 65,
			ADC3Min = 66,
			AvgWindDir = 67,
			RainMaxIntensity = 68,
			HailMaxIntensity = 69,
			Dur_Frac = 70,
			Wslowspl = 71,
			Wfastspl = 72,
			Wimplspl = 73,
			Wimplminusleq = 74,
			Ln1 = 75,
			Ln2 = 76,
			Ln3 = 77,
			Ln4 = 78,
			Ln5 = 79,
			Ln6 = 80,
			RunningLeq = 81,
			RainAccumulation = 82,
			RainDuration = 83,
			HailAccumulation = 84,
			HailDuration = 85,
		};
	}
}
#endif // _ETHOPTION_ID_H
