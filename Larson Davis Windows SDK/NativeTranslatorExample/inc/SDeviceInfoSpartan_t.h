/**************************************************************************//**
 * @file SDeviceInfoSpartan_t.h
 * @brief Native Wrapper for Managed type DeviceInfoSpartan_t.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _SDEVICE_INFO_SPARTAN_T_H
#define _SDEVICE_INFO_SPARTAN_T_H
#include <ISupportByteArrayConversion.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI ISupportByteArrayConversion;
		struct LDAPI SString16_t;
		struct LDAPI SString32_t;

		struct LDAPI SDeviceInfoSpartan_t : public virtual ISupportByteArrayConversion
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			SDeviceInfoSpartan_t(const SDeviceInfoSpartan_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~SDeviceInfoSpartan_t(void);
			SDeviceInfoSpartan_t(void);
			std::shared_ptr<SString16_t> SerialNumber(void);
			void SerialNumber(std::shared_ptr<SString16_t> value);
			std::shared_ptr<SString32_t> Model(void);
			void Model(std::shared_ptr<SString32_t> value);
			std::shared_ptr<SString16_t> HWVersion(void);
			void HWVersion(std::shared_ptr<SString16_t> value);
			std::shared_ptr<SString16_t> FWVersion(void);
			void FWVersion(std::shared_ptr<SString16_t> value);
			float Sensitivity(void);
			void Sensitivity(float value);
			std::shared_ptr<SString32_t> Manufacturer(void);
			void Manufacturer(std::shared_ptr<SString32_t> value);
			uint32_t FWDate(void);
			void FWDate(uint32_t value);
			const int32_t Options_Length = 8;
			uint32_t Options(int32_t index);
			void Options(int32_t index, uint32_t value);
			uint32_t SequenceId(void);
			void SequenceId(uint32_t value);
#ifdef MAKEDLL
		public: // This is for internal use
			SDeviceInfoSpartan_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _SDEVICE_INFO_SPARTAN_T_H
