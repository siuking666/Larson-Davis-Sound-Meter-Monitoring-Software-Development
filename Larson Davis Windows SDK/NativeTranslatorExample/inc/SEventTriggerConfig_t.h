/**************************************************************************//**
 * @file SEventTriggerConfig_t.h
 * @brief Native Wrapper for Managed type EventTriggerConfig_t.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _SEVENT_TRIGGER_CONFIG_T_H
#define _SEVENT_TRIGGER_CONFIG_T_H
#include <ISupportByteArrayConversion.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI ISupportByteArrayConversion;

		struct LDAPI SEventTriggerConfig_t : public virtual ISupportByteArrayConversion
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			SEventTriggerConfig_t(const SEventTriggerConfig_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~SEventTriggerConfig_t(void);
			SEventTriggerConfig_t(void);
			uint32_t tag(void);
			void tag(uint32_t value);
			bool enabled(void);
			void enabled(bool value);
			float triggerLevel(void);
			void triggerLevel(float value);
#ifdef MAKEDLL
		public: // This is for internal use
			SEventTriggerConfig_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _SEVENT_TRIGGER_CONFIG_T_H
