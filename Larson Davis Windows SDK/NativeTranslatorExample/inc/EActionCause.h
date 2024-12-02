/**************************************************************************//**
 * @file EActionCause.h
 * @brief Native Wrapper for Managed type ActionCause.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _EACTION_CAUSE_H
#define _EACTION_CAUSE_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class EActionCause : uint16_t
		{
			ActionStop = 1u,
			ActionRun = 2u,
			ActionPause = 4u,
			ActionResume = 8u,
			ActionVoice = 16u,
			ActionAudio = 32u,
			ActionCal = 64u,
			ActionReset = 128u,
			ActionGpsSync = 129u,
			ActionBackErase = 130u,
			ActionMarker = 131u,
			ActionCalChange = 132u,
			ActionPreampOff = 133u,
			ActionPreampOn = 134u,
			ActionFileAvg = 135u,
			ActionWatchdog = 136u,
			ActionUsbFault = 137u,
			ActionPanic = 138u,
			ActionChargeFault = 139u,
			ActionNtpSync = 140u,
			ActionTimeChange = 141u,
			ActionBufferOverflow = 142u,
			ActionRunMask = 227u,
			ActionRunRaL1 = 6u,
			ActionRunRaL2 = 10u,
			ActionRunRaB2 = 14u,
			ActionRunRaT2 = 18u,
			ActionRunRaTh = 22u,
			ActionMask = 255u,
			CauseKey = 256u,
			CauseIO = 512u,
			CauseTimer = 1024u,
			CauseSchedule = 1280u,
			CauseTrigger = 1536u,
			CausePower = 2048u,
			CauseMemory = 4096u,
			CausePreampConnect = 8192u,
			CausePreampDisconnect = 16384u,
			CauseStable = 32768u,
			Cause831IntEt = 33024u,
			CauseAnalogModem = 33280u,
			CauseCounterWrap = 33536u,
			CauseInternalFault = 33792u,
			CauseMeterUpdate = 34048u,
			CauseChargeTempFault = 34304u,
			CauseChargeVoltageFault = 34560u,
			CauseBatteryTypeFault = 34816u,
			CauseChargeCurrentFault = 35072u,
			CauseMemoryDisconnect = 35328u,
			CauseMask = 65280u,
			CauseSREvent = 256u,
			CauseSRMeasurement = 512u,
			CauseSRTimeHistory = 1024u,
			CauseMarker1 = 256u,
			CauseMarker2 = 512u,
			CauseMarker3 = 768u,
			CauseMarker4 = 1024u,
			CauseMarker5 = 1280u,
			CauseMarker6 = 1536u,
			CauseMarker7 = 1792u,
			CauseMarker8 = 2048u,
			CauseMarker9 = 2304u,
			CauseMarker10 = 2560u,
			CauseTimeSyncPositive = 256u,
			CauseTimeSyncNegative = 512u,
		};
	}
}
#endif // _EACTION_CAUSE_H
