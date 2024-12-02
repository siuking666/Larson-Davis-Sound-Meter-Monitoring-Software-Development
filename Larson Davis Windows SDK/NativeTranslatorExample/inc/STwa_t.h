/**************************************************************************//**
 * @file STwa_t.h
 * @brief Native Wrapper for Managed type Twa_t.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _STWA_T_H
#define _STWA_T_H
#include <ISupportByteArrayConversion.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI ISupportByteArrayConversion;

		struct LDAPI STwa_t : public virtual ISupportByteArrayConversion
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			STwa_t(const STwa_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~STwa_t(void);
			STwa_t(void);
			float level(void);
			void level(float value);
			float time(void);
			void time(float value);
			int32_t count(void);
			void count(int32_t value);
			uint64_t dosefract(void);
			void dosefract(uint64_t value);
			uint64_t dose(void);
			void dose(uint64_t value);
#ifdef MAKEDLL
		public: // This is for internal use
			STwa_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _STWA_T_H
