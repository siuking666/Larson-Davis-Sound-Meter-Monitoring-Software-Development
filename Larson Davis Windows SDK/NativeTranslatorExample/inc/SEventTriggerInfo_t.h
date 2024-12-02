/**************************************************************************//**
 * @file SEventTriggerInfo_t.h
 * @brief Native Wrapper for Managed type EventTriggerInfo_t.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _SEVENT_TRIGGER_INFO_T_H
#define _SEVENT_TRIGGER_INFO_T_H
#include <ISupportByteArrayConversion.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI ISupportByteArrayConversion;

		struct LDAPI SEventTriggerInfo_t : public virtual ISupportByteArrayConversion
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			SEventTriggerInfo_t(const SEventTriggerInfo_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~SEventTriggerInfo_t(void);
			SEventTriggerInfo_t(void);
			int32_t source_id(void);
			void source_id(int32_t value);
			float level(void);
			void level(float value);
#ifdef MAKEDLL
		public: // This is for internal use
			SEventTriggerInfo_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _SEVENT_TRIGGER_INFO_T_H
