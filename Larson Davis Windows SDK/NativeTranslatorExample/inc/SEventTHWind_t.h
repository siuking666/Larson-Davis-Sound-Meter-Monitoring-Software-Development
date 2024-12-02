/**************************************************************************//**
 * @file SEventTHWind_t.h
 * @brief Native Wrapper for Managed type EventTHWind_t.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _SEVENT_THWIND_T_H
#define _SEVENT_THWIND_T_H
#include <ISupportByteArrayConversion.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI ISupportByteArrayConversion;

		struct LDAPI SEventTHWind_t : public virtual ISupportByteArrayConversion
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			SEventTHWind_t(const SEventTHWind_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~SEventTHWind_t(void);
			SEventTHWind_t(void);
			float max_speed(void);
			void max_speed(float value);
			float direction(void);
			void direction(float value);
#ifdef MAKEDLL
		public: // This is for internal use
			SEventTHWind_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _SEVENT_THWIND_T_H
