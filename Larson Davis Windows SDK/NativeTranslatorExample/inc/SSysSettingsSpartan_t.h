/**************************************************************************//**
 * @file SSysSettingsSpartan_t.h
 * @brief Native Wrapper for Managed type SysSettingsSpartan_t.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _SSYS_SETTINGS_SPARTAN_T_H
#define _SSYS_SETTINGS_SPARTAN_T_H
#include <ISupportByteArrayConversion.h>
#include <EDateFormatSpartan_t.h>
#include <ELanguage.h>
#include <EDecimalFormat.h>
#include <EDosAutoOff_t.h>
#include <EPropOnOff_t.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI ISupportByteArrayConversion;
		struct LDAPI SString16_t;
		struct LDAPI SString32_t;
		struct LDAPI SString256_t;

		struct LDAPI SSysSettingsSpartan_t : public virtual ISupportByteArrayConversion
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			SSysSettingsSpartan_t(const SSysSettingsSpartan_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~SSysSettingsSpartan_t(void);
			SSysSettingsSpartan_t(void);
			std::shared_ptr<SString16_t> UserDefinedName(void);
			void UserDefinedName(std::shared_ptr<SString16_t> value);
			EDateFormatSpartan_t DateFormat(void);
			void DateFormat(EDateFormatSpartan_t value);
			float NoiseLevel(void);
			void NoiseLevel(float value);
			float dBReference(void);
			void dBReference(float value);
			ELanguage Language(void);
			void Language(ELanguage value);
			EDecimalFormat DecimalChar(void);
			void DecimalChar(EDecimalFormat value);
			EDosAutoOff_t AutoOffTime(void);
			void AutoOffTime(EDosAutoOff_t value);
			std::shared_ptr<SString16_t> BLEAuthKey(void);
			void BLEAuthKey(std::shared_ptr<SString16_t> value);
			float CalLevel(void);
			void CalLevel(float value);
			std::shared_ptr<SString32_t> AdminPass(void);
			void AdminPass(std::shared_ptr<SString32_t> value);
			int32_t AdminFlags(void);
			void AdminFlags(int32_t value);
			EPropOnOff_t AutoStoreEnable(void);
			void AutoStoreEnable(EPropOnOff_t value);
			EPropOnOff_t ModemEnable(void);
			void ModemEnable(EPropOnOff_t value);
			int32_t ModemPeriod(void);
			void ModemPeriod(int32_t value);
			std::shared_ptr<SString256_t> ModemHost(void);
			void ModemHost(std::shared_ptr<SString256_t> value);
			int32_t ModemPort(void);
			void ModemPort(int32_t value);
			std::shared_ptr<SString256_t> ModemAPN(void);
			void ModemAPN(std::shared_ptr<SString256_t> value);
			int32_t Backlight(void);
			void Backlight(int32_t value);
			int32_t CorrSelect(void);
			void CorrSelect(int32_t value);
			int32_t MicSelect(void);
			void MicSelect(int32_t value);
			std::shared_ptr<SString16_t> PreampSerial(void);
			void PreampSerial(std::shared_ptr<SString16_t> value);
			std::shared_ptr<SString16_t> MicSerial(void);
			void MicSerial(std::shared_ptr<SString16_t> value);
			std::shared_ptr<SString16_t> MicModel(void);
			void MicModel(std::shared_ptr<SString16_t> value);
			float MicSensitivity(void);
			void MicSensitivity(float value);
#ifdef MAKEDLL
		public: // This is for internal use
			SSysSettingsSpartan_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _SSYS_SETTINGS_SPARTAN_T_H
