/**************************************************************************//**
 * @file SEnvPreampData_t.h
 * @brief Native Wrapper for Managed type EnvPreampData_t.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _SENV_PREAMP_DATA_T_H
#define _SENV_PREAMP_DATA_T_H
#include <ISupportByteArrayConversion.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI ISupportByteArrayConversion;

		struct LDAPI SEnvPreampData_t : public virtual ISupportByteArrayConversion
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			SEnvPreampData_t(const SEnvPreampData_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~SEnvPreampData_t(void);
			SEnvPreampData_t(void);
			float RHMax(void);
			void RHMax(float value);
			float TempMax(void);
			void TempMax(float value);
			float DewMax(void);
			void DewMax(float value);
			float RHMin(void);
			void RHMin(float value);
			float TempMin(void);
			void TempMin(float value);
			float DewMin(void);
			void DewMin(float value);
#ifdef MAKEDLL
		public: // This is for internal use
			SEnvPreampData_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _SENV_PREAMP_DATA_T_H
