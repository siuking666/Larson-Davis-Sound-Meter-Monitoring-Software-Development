/**************************************************************************//**
 * @file EBlockTag.h
 * @brief Native Wrapper for Managed type BlockTag.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _EBLOCK_TAG_H
#define _EBLOCK_TAG_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class EBlockTag
		{
			System = 0,
			Prefer = 1,
			Settings = 2,
			Cal = 3,
			Overall = 4,
			Current = 5,
			Dose = 6,
			LnTable = 7,
			Session = 8,
			Voice = 9,
			VoiceComp = 10,
			Audio = 11,
			AudioComp = 12,
			Excd = 13,
			ExcdTH = 14,
			TimeHist = 15,
			Interval = 16,
			ExcdRecord = 17,
			OverallOverload = 18,
			OverallProfile = 19,
			DailyNoise = 20,
			GPS = 21,
			SpectralLn = 22,
			NoiseFloors = 23,
			Weather = 24,
			MHSimple = 25,
			CalHist = 26,
			CalCheck = 27,
			InternalOnly = 28,
			EnvPreampInfo = 29,
			EnvPreampData = 30,
			RaL1 = 31,
			RaL2 = 32,
			RaB2 = 33,
			RaT2 = 34,
			RaRT60Record = 35,
			RaAbtsLevel = 36,
			FftOverallSpectraData = 37,
			FftMHData = 38,
			SystemMetrics = 39,
			EventTriggers = 40,
			PTBInfo = 41,
			FftOverallTriggerData = 42,
			LastMeterBlockTag = 42,
			MaxTags = 42,
			MeterBlockTagCount = 43,
			SoftwareBlockStart = 10000,
			GeneralInfo = 10042,
			EditBands = 10043,
			ChartInfo = 10044,
			SoundRecords = 10045,
			Comments = 10046,
			Rt60Decay = 10047,
			Manifest = 10048,
			MetaBlockTagCount = 6,
			Count = 49,
		};
	}
}
#endif // _EBLOCK_TAG_H
