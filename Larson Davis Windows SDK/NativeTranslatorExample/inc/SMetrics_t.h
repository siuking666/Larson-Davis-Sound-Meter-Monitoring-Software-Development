/**************************************************************************//**
 * @file SMetrics_t.h
 * @brief Native Wrapper for Managed type Metrics_t.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _SMETRICS_T_H
#define _SMETRICS_T_H
#include <ISupportByteArrayConversion.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI ISupportByteArrayConversion;

		struct LDAPI SMetrics_t : public virtual ISupportByteArrayConversion
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			SMetrics_t(const SMetrics_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~SMetrics_t(void);
			SMetrics_t(void);
			float get_min(void);
			void get_min(float value);
			float get_max(void);
			void get_max(float value);
			float current(void);
			void current(float value);
			float sum(void);
			void sum(float value);
			int32_t count(void);
			void count(int32_t value);
#ifdef MAKEDLL
		public: // This is for internal use
			SMetrics_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _SMETRICS_T_H
