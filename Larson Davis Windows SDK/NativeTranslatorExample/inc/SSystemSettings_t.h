/**************************************************************************//**
 * @file SSystemSettings_t.h
 * @brief Native Wrapper for Managed type SystemSettings_t.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _SSYSTEM_SETTINGS_T_H
#define _SSYSTEM_SETTINGS_T_H
#include <ISupportByteArrayConversion.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI ISupportByteArrayConversion;
		struct LDAPI SFirwareVersion_t;
		struct LDAPI Sset_UnsignedInt;
		class LDAPI Array_Sset_Float;
		class LDAPI Array_Sset_String;
		struct LDAPI Sset_Enum;
		struct LDAPI Sset_Int;
		struct LDAPI Sset_Float;
		struct LDAPI Sset_IPAddr;
		struct LDAPI Sset_String;
		struct LDAPI Sset_ByteString;

		struct LDAPI SSystemSettings_t : public virtual ISupportByteArrayConversion
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			SSystemSettings_t(const SSystemSettings_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~SSystemSettings_t(void);
			SSystemSettings_t(void);
			std::shared_ptr<SFirwareVersion_t> version(void);
			void version(std::shared_ptr<SFirwareVersion_t> value);
			std::shared_ptr<Sset_UnsignedInt> DateTime(void);
			void DateTime(std::shared_ptr<Sset_UnsignedInt> value);
			std::shared_ptr<Array_Sset_Float> CalibratorLevel(void);
			void CalibratorLevel(std::shared_ptr<Array_Sset_Float> value);
			std::shared_ptr<Array_Sset_Float> CalibratorFrequency(void);
			void CalibratorFrequency(std::shared_ptr<Array_Sset_Float> value);
			std::shared_ptr<Array_Sset_String> CalibratorInfo(void);
			void CalibratorInfo(std::shared_ptr<Array_Sset_String> value);
			std::shared_ptr<Sset_Enum> CertRemind(void);
			void CertRemind(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_Enum> CertInterval(void);
			void CertInterval(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Array_Sset_String> UserString(void);
			void UserString(std::shared_ptr<Array_Sset_String> value);
			std::shared_ptr<Sset_Int> ActiveCalibratorIndex(void);
			void ActiveCalibratorIndex(std::shared_ptr<Sset_Int> value);
			std::shared_ptr<Array_Sset_Float> MicrophoneSensitivity(void);
			void MicrophoneSensitivity(std::shared_ptr<Array_Sset_Float> value);
			std::shared_ptr<Array_Sset_Float> MicrophoneNoiseFloor(void);
			void MicrophoneNoiseFloor(std::shared_ptr<Array_Sset_Float> value);
			std::shared_ptr<Array_Sset_String> MicrophoneInfo(void);
			void MicrophoneInfo(std::shared_ptr<Array_Sset_String> value);
			std::shared_ptr<Sset_Float> StdEALevel(void);
			void StdEALevel(std::shared_ptr<Sset_Float> value);
			std::shared_ptr<Sset_Enum> StaticIPEnable(void);
			void StaticIPEnable(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_IPAddr> StaticIP(void);
			void StaticIP(std::shared_ptr<Sset_IPAddr> value);
			std::shared_ptr<Sset_IPAddr> SubnetMask(void);
			void SubnetMask(std::shared_ptr<Sset_IPAddr> value);
			std::shared_ptr<Sset_IPAddr> GatewayIP(void);
			void GatewayIP(std::shared_ptr<Sset_IPAddr> value);
			std::shared_ptr<Sset_IPAddr> NameServerIP(void);
			void NameServerIP(std::shared_ptr<Sset_IPAddr> value);
			std::shared_ptr<Sset_String> SmtpEndpoint(void);
			void SmtpEndpoint(std::shared_ptr<Sset_String> value);
			std::shared_ptr<Sset_String> SmtpUsername(void);
			void SmtpUsername(std::shared_ptr<Sset_String> value);
			std::shared_ptr<Sset_UnsignedInt> SmtpOptions(void);
			void SmtpOptions(std::shared_ptr<Sset_UnsignedInt> value);
			std::shared_ptr<Sset_Enum> SecurityEnable(void);
			void SecurityEnable(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_UnsignedInt> SecurityTimeout(void);
			void SecurityTimeout(std::shared_ptr<Sset_UnsignedInt> value);
			std::shared_ptr<Sset_Enum> XducerEnable(void);
			void XducerEnable(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_Enum> XducerUnits(void);
			void XducerUnits(std::shared_ptr<Sset_Enum> value);
			std::shared_ptr<Sset_ByteString> XducerUnitsCustom(void);
			void XducerUnitsCustom(std::shared_ptr<Sset_ByteString> value);
			std::shared_ptr<Sset_Float> XducerSensitivity(void);
			void XducerSensitivity(std::shared_ptr<Sset_Float> value);
			float VoltageCalibration(void);
			void VoltageCalibration(float value);
			float RangeCalibration(void);
			void RangeCalibration(float value);
			float ObaLowRangeCalibration(void);
			void ObaLowRangeCalibration(float value);
			float GainCalibration(void);
			void GainCalibration(float value);
#ifdef MAKEDLL
		public: // This is for internal use
			SSystemSettings_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _SSYSTEM_SETTINGS_T_H
