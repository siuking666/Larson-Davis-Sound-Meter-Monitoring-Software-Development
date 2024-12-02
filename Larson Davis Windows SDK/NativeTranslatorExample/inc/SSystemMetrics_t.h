/**************************************************************************//**
 * @file SSystemMetrics_t.h
 * @brief Native Wrapper for Managed type SystemMetrics_t.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _SSYSTEM_METRICS_T_H
#define _SSYSTEM_METRICS_T_H
#include <ISupportByteArrayConversion.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI ISupportByteArrayConversion;
		struct LDAPI SMetrics_t;

		struct LDAPI SSystemMetrics_t : public virtual ISupportByteArrayConversion
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			SSystemMetrics_t(const SSystemMetrics_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~SSystemMetrics_t(void);
			SSystemMetrics_t(void);
			std::shared_ptr<SMetrics_t> InternalTemp(void);
			void InternalTemp(std::shared_ptr<SMetrics_t> value);
			std::shared_ptr<SMetrics_t> ExternalVolts(void);
			void ExternalVolts(std::shared_ptr<SMetrics_t> value);
#ifdef MAKEDLL
		public: // This is for internal use
			SSystemMetrics_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _SSYSTEM_METRICS_T_H
