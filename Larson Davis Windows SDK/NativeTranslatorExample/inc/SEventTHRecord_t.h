/**************************************************************************//**
 * @file SEventTHRecord_t.h
 * @brief Native Wrapper for Managed type EventTHRecord_t.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _SEVENT_THRECORD_T_H
#define _SEVENT_THRECORD_T_H
#include <ISupportByteArrayConversion.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI ISupportByteArrayConversion;
		class LDAPI Array_float;
		struct LDAPI SEventTHWind_t;

		struct LDAPI SEventTHRecord_t : public virtual ISupportByteArrayConversion
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			SEventTHRecord_t(const SEventTHRecord_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~SEventTHRecord_t(void);
			SEventTHRecord_t(void);
			float level(void);
			void level(float value);
			std::shared_ptr<Array_float> oba(void);
			void oba(std::shared_ptr<Array_float> value);
			std::shared_ptr<SEventTHWind_t> wind(void);
			void wind(std::shared_ptr<SEventTHWind_t> value);
#ifdef MAKEDLL
		public: // This is for internal use
			SEventTHRecord_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _SEVENT_THRECORD_T_H
