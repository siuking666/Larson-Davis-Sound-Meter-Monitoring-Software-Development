/**************************************************************************//**
 * @file SEnvPreampInfo_t.h
 * @brief Native Wrapper for Managed type EnvPreampInfo_t.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _SENV_PREAMP_INFO_T_H
#define _SENV_PREAMP_INFO_T_H
#include <ISupportByteArrayConversion.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI ISupportByteArrayConversion;

		struct LDAPI SEnvPreampInfo_t : public virtual ISupportByteArrayConversion
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			SEnvPreampInfo_t(const SEnvPreampInfo_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~SEnvPreampInfo_t(void);
			SEnvPreampInfo_t(void);
			float RH(void);
			void RH(float value);
			float Temp(void);
			void Temp(float value);
			float Dew(void);
			void Dew(float value);
			uint32_t modelnum(void);
			void modelnum(uint32_t value);
			uint32_t serialnum(void);
			void serialnum(uint32_t value);
			uint32_t flags(void);
			void flags(uint32_t value);
#ifdef MAKEDLL
		public: // This is for internal use
			SEnvPreampInfo_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _SENV_PREAMP_INFO_T_H
