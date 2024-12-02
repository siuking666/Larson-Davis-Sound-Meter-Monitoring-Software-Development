/**************************************************************************//**
 * @file SUserPreferences_t.h
 * @brief Native Wrapper for Managed type UserPreferences_t.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _SUSER_PREFERENCES_T_H
#define _SUSER_PREFERENCES_T_H
#include <ISupportByteArrayConversion.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI ISupportByteArrayConversion;
		struct LDAPI Sset_Enum;
		struct LDAPI Sset_UnsignedInt;
		struct LDAPI Sset_Int;
		struct LDAPI Sset_FloatArray11;
		struct LDAPI Sset_FloatArray13;
		struct LDAPI Sset_String;
		struct LDAPI Sset_Float;
		class LDAPI Array_Sset_Enum;
		class LDAPI Array_Sset_String;

		struct LDAPI SUserPreferences_t : public virtual ISupportByteArrayConversion
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			SUserPreferences_t(const SUserPreferences_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~SUserPreferences_t(void);
			SUserPreferences_t(void);
			std::shared_ptr<Sset_Enum> LockCal(void);
			void LockCal(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_Enum> LockTask(void);
			void LockTask(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_Enum> LockMode(void);
			void LockMode(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_UnsignedInt> LockCombination(void);
			void LockCombination(std::shared_ptr<Sset_UnsignedInt> value);
			std::shared_ptr<Sset_Enum> DateFormat(void);
			void DateFormat(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_Enum> AutoSyncDateTime(void);
			void AutoSyncDateTime(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_Enum> DecimalFormat(void);
			void DecimalFormat(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_Enum> AutoStoreMode(void);
			void AutoStoreMode(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_Enum> ResetPrompt(void);
			void ResetPrompt(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_Enum> Language(void);
			void Language(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_Enum> PowerAutoSleep(void);
			void PowerAutoSleep(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_Enum> PowerAutoOff(void);
			void PowerAutoOff(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_Enum> BackLight(void);
			void BackLight(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_Enum> BackLightTimer(void);
			void BackLightTimer(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_Enum> BatteryType(void);
			void BatteryType(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_Enum> Outputs(void);
			void Outputs(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_Int> DisplayContrast(void);
			void DisplayContrast(std::shared_ptr<Sset_Int> value);
			std::shared_ptr<Sset_Enum> VoiceCompression(void);
			void VoiceCompression(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_Enum> OverwriteOldestFiles(void);
			void OverwriteOldestFiles(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_Enum> TaktMetricEnable(void);
			void TaktMetricEnable(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_Enum> CompressDataFiles(void);
			void CompressDataFiles(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_Enum> USBStorage(void);
			void USBStorage(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_FloatArray11> FullOctaveReferenceSpectra1(void);
			void FullOctaveReferenceSpectra1(std::shared_ptr<Sset_FloatArray11> value);
			std::shared_ptr<Sset_FloatArray11> FullOctaveReferenceSpectra2(void);
			void FullOctaveReferenceSpectra2(std::shared_ptr<Sset_FloatArray11> value);
			std::shared_ptr<Sset_FloatArray11> FullOctaveReferenceSpectra3(void);
			void FullOctaveReferenceSpectra3(std::shared_ptr<Sset_FloatArray11> value);
			std::shared_ptr<Sset_FloatArray11> FullOctaveReferenceSpectra4(void);
			void FullOctaveReferenceSpectra4(std::shared_ptr<Sset_FloatArray11> value);
			std::shared_ptr<Sset_FloatArray13> ThirdOctaveReferenceSpectra1(void);
			void ThirdOctaveReferenceSpectra1(std::shared_ptr<Sset_FloatArray13> value);
			std::shared_ptr<Sset_FloatArray13> ThirdOctaveReferenceSpectra2(void);
			void ThirdOctaveReferenceSpectra2(std::shared_ptr<Sset_FloatArray13> value);
			std::shared_ptr<Sset_FloatArray13> ThirdOctaveReferenceSpectra3(void);
			void ThirdOctaveReferenceSpectra3(std::shared_ptr<Sset_FloatArray13> value);
			std::shared_ptr<Sset_FloatArray13> ThirdOctaveReferenceSpectra4(void);
			void ThirdOctaveReferenceSpectra4(std::shared_ptr<Sset_FloatArray13> value);
			std::shared_ptr<Sset_Int> StartupTab(void);
			void StartupTab(std::shared_ptr<Sset_Int> value);
			std::shared_ptr<Sset_UnsignedInt> DisplayOptions1(void);
			void DisplayOptions1(std::shared_ptr<Sset_UnsignedInt> value);
			std::shared_ptr<Sset_UnsignedInt> DisplayOptions2(void);
			void DisplayOptions2(std::shared_ptr<Sset_UnsignedInt> value);
			std::shared_ptr<Sset_UnsignedInt> DisplayOptions3(void);
			void DisplayOptions3(std::shared_ptr<Sset_UnsignedInt> value);
			std::shared_ptr<Sset_UnsignedInt> DisplayOptions4(void);
			void DisplayOptions4(std::shared_ptr<Sset_UnsignedInt> value);
			std::shared_ptr<Sset_UnsignedInt> DisplayOptions5(void);
			void DisplayOptions5(std::shared_ptr<Sset_UnsignedInt> value);
			std::shared_ptr<Sset_UnsignedInt> DisplayOptions6(void);
			void DisplayOptions6(std::shared_ptr<Sset_UnsignedInt> value);
			std::shared_ptr<Sset_UnsignedInt> DisplayOptions7(void);
			void DisplayOptions7(std::shared_ptr<Sset_UnsignedInt> value);
			std::shared_ptr<Sset_UnsignedInt> DisplayOptions8(void);
			void DisplayOptions8(std::shared_ptr<Sset_UnsignedInt> value);
			std::shared_ptr<Sset_Int> GraphBottom(void);
			void GraphBottom(std::shared_ptr<Sset_Int> value);
			std::shared_ptr<Sset_Int> GraphHeight(void);
			void GraphHeight(std::shared_ptr<Sset_Int> value);
			std::shared_ptr<Sset_Int> OBAGraphBottom(void);
			void OBAGraphBottom(std::shared_ptr<Sset_Int> value);
			std::shared_ptr<Sset_Int> OBAGraphHeight(void);
			void OBAGraphHeight(std::shared_ptr<Sset_Int> value);
			std::shared_ptr<Sset_Int> AnyLevelItem1(void);
			void AnyLevelItem1(std::shared_ptr<Sset_Int> value);
			std::shared_ptr<Sset_Int> AnyLevelItem2(void);
			void AnyLevelItem2(std::shared_ptr<Sset_Int> value);
			std::shared_ptr<Sset_String> ModemPhoneNumber(void);
			void ModemPhoneNumber(std::shared_ptr<Sset_String> value);
			std::shared_ptr<Sset_String> ModemPassword(void);
			void ModemPassword(std::shared_ptr<Sset_String> value);
			std::shared_ptr<Sset_Int> ModemMonitorNumber(void);
			void ModemMonitorNumber(std::shared_ptr<Sset_Int> value);
			std::shared_ptr<Sset_String> ModemInitializationString(void);
			void ModemInitializationString(std::shared_ptr<Sset_String> value);
			std::shared_ptr<Sset_Enum> ModemOnOff(void);
			void ModemOnOff(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_Int> ModemDialOutSetting(void);
			void ModemDialOutSetting(std::shared_ptr<Sset_Int> value);
			std::shared_ptr<Sset_Enum> WirelessModemOnOff(void);
			void WirelessModemOnOff(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_String> EdgeApn(void);
			void EdgeApn(std::shared_ptr<Sset_String> value);
			std::shared_ptr<Sset_String> EdgeApnUsername(void);
			void EdgeApnUsername(std::shared_ptr<Sset_String> value);
			std::shared_ptr<Sset_String> EdgeApnPassword(void);
			void EdgeApnPassword(std::shared_ptr<Sset_String> value);
			std::shared_ptr<Sset_String> EdgePassword(void);
			void EdgePassword(std::shared_ptr<Sset_String> value);
			std::shared_ptr<Sset_Int> EdgeMonitorNumber(void);
			void EdgeMonitorNumber(std::shared_ptr<Sset_Int> value);
			std::shared_ptr<Sset_Enum> UnitsSystem(void);
			void UnitsSystem(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_Enum> GPSMode(void);
			void GPSMode(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_Enum> RICorrection(void);
			void RICorrection(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_Enum> USBPORTOnOff(void);
			void USBPORTOnOff(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_Int> TimezoneCorrectionHours(void);
			void TimezoneCorrectionHours(std::shared_ptr<Sset_Int> value);
			std::shared_ptr<Sset_Int> TimezoneCorrectionMinutes(void);
			void TimezoneCorrectionMinutes(std::shared_ptr<Sset_Int> value);
			std::shared_ptr<Sset_Int> LogicIn(void);
			void LogicIn(std::shared_ptr<Sset_Int> value);
			std::shared_ptr<Sset_Int> LogicOut(void);
			void LogicOut(std::shared_ptr<Sset_Int> value);
			std::shared_ptr<Sset_String> FullOctaveReferenceSpectra1Name(void);
			void FullOctaveReferenceSpectra1Name(std::shared_ptr<Sset_String> value);
			std::shared_ptr<Sset_String> FullOctaveReferenceSpectra2Name(void);
			void FullOctaveReferenceSpectra2Name(std::shared_ptr<Sset_String> value);
			std::shared_ptr<Sset_String> FullOctaveReferenceSpectra3Name(void);
			void FullOctaveReferenceSpectra3Name(std::shared_ptr<Sset_String> value);
			std::shared_ptr<Sset_String> FullOctaveReferenceSpectra4Name(void);
			void FullOctaveReferenceSpectra4Name(std::shared_ptr<Sset_String> value);
			std::shared_ptr<Sset_String> ThirdOctaveReferenceSpectra1Name(void);
			void ThirdOctaveReferenceSpectra1Name(std::shared_ptr<Sset_String> value);
			std::shared_ptr<Sset_String> ThirdOctaveReferenceSpectra2Name(void);
			void ThirdOctaveReferenceSpectra2Name(std::shared_ptr<Sset_String> value);
			std::shared_ptr<Sset_String> ThirdOctaveReferenceSpectra3Name(void);
			void ThirdOctaveReferenceSpectra3Name(std::shared_ptr<Sset_String> value);
			std::shared_ptr<Sset_String> ThirdOctaveReferenceSpectra4Name(void);
			void ThirdOctaveReferenceSpectra4Name(std::shared_ptr<Sset_String> value);
			std::shared_ptr<Sset_Enum> RS232OnOff(void);
			void RS232OnOff(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_Int> BaudRateSetting(void);
			void BaudRateSetting(std::shared_ptr<Sset_Int> value);
			std::shared_ptr<Sset_Int> FlowControl(void);
			void FlowControl(std::shared_ptr<Sset_Int> value);
			std::shared_ptr<Sset_Float> ExtShutoffVolts(void);
			void ExtShutoffVolts(std::shared_ptr<Sset_Float> value);
			std::shared_ptr<Sset_Int> AnyLevelItem3(void);
			void AnyLevelItem3(std::shared_ptr<Sset_Int> value);
			std::shared_ptr<Sset_Int> AnyLevelItem4(void);
			void AnyLevelItem4(std::shared_ptr<Sset_Int> value);
			std::shared_ptr<Array_Sset_Enum> SMSOutType(void);
			void SMSOutType(std::shared_ptr<Array_Sset_Enum> value);
			std::shared_ptr<Array_Sset_String> SMSOutNumber(void);
			void SMSOutNumber(std::shared_ptr<Array_Sset_String> value);
			std::shared_ptr<Sset_UnsignedInt> OptionsMask(void);
			void OptionsMask(std::shared_ptr<Sset_UnsignedInt> value);
			std::shared_ptr<Sset_Enum> BluetoothOnOff(void);
			void BluetoothOnOff(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_Enum> FFT_CursorType(void);
			void FFT_CursorType(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_Int> FFT_NumHarmonics(void);
			void FFT_NumHarmonics(std::shared_ptr<Sset_Int> value);
			std::shared_ptr<Sset_Int> FFT_GraphBottom(void);
			void FFT_GraphBottom(std::shared_ptr<Sset_Int> value);
			std::shared_ptr<Sset_Int> FFT_GraphHeight(void);
			void FFT_GraphHeight(std::shared_ptr<Sset_Int> value);
			std::shared_ptr<Sset_Enum> IntEtWatchdog(void);
			void IntEtWatchdog(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_Enum> PRM2103Heater(void);
			void PRM2103Heater(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_String> NetworkPassword(void);
			void NetworkPassword(std::shared_ptr<Sset_String> value);
			std::shared_ptr<Sset_UnsignedInt> DisplayBrightness(void);
			void DisplayBrightness(std::shared_ptr<Sset_UnsignedInt> value);
			std::shared_ptr<Sset_Enum> BatteryChargeOnOff(void);
			void BatteryChargeOnOff(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_String> TimeZone(void);
			void TimeZone(std::shared_ptr<Sset_String> value);
			std::shared_ptr<Sset_Enum> DisplayColorScheme(void);
			void DisplayColorScheme(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Array_Sset_String> NtpServers(void);
			void NtpServers(std::shared_ptr<Array_Sset_String> value);
			std::shared_ptr<Sset_Enum> SftpServiceType(void);
			void SftpServiceType(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_String> SftpHost(void);
			void SftpHost(std::shared_ptr<Sset_String> value);
			std::shared_ptr<Sset_String> SftpPath(void);
			void SftpPath(std::shared_ptr<Sset_String> value);
			std::shared_ptr<Sset_String> SftpUserName(void);
			void SftpUserName(std::shared_ptr<Sset_String> value);
			std::shared_ptr<Sset_String> SftpPwdEncrypted(void);
			void SftpPwdEncrypted(std::shared_ptr<Sset_String> value);
			std::shared_ptr<Sset_Enum> SftpPushControl(void);
			void SftpPushControl(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_Enum> SftpMoveCopy(void);
			void SftpMoveCopy(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_Enum> SftpEmailControl(void);
			void SftpEmailControl(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_UnsignedInt> EmailAlertControl(void);
			void EmailAlertControl(std::shared_ptr<Sset_UnsignedInt> value);
			std::shared_ptr<Sset_Enum> FftHorizontalUnits(void);
			void FftHorizontalUnits(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_Enum> FftYAxisScale(void);
			void FftYAxisScale(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_Enum> Rv50LowPowerEnable(void);
			void Rv50LowPowerEnable(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_UnsignedInt> Rv50EnaTime(void);
			void Rv50EnaTime(std::shared_ptr<Sset_UnsignedInt> value);
			std::shared_ptr<Sset_UnsignedInt> Rv50EnaDuration(void);
			void Rv50EnaDuration(std::shared_ptr<Sset_UnsignedInt> value);
			std::shared_ptr<Sset_UnsignedInt> Rv50EnaAlertTimeout(void);
			void Rv50EnaAlertTimeout(std::shared_ptr<Sset_UnsignedInt> value);
			std::shared_ptr<Sset_UnsignedInt> SchedulingEnable(void);
			void SchedulingEnable(std::shared_ptr<Sset_UnsignedInt> value);
			std::shared_ptr<Sset_Enum> FftUserXducerUnits(void);
			void FftUserXducerUnits(std::shared_ptr<Sset_Enum> value);
#ifdef MAKEDLL
		public: // This is for internal use
			SUserPreferences_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _SUSER_PREFERENCES_T_H
