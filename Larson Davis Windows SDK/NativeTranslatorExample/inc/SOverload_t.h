/**************************************************************************//**
 * @file SOverload_t.h
 * @brief Native Wrapper for Managed type Overload_t.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _SOVERLOAD_T_H
#define _SOVERLOAD_T_H
#include <ISupportByteArrayConversion.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI ISupportByteArrayConversion;

		struct LDAPI SOverload_t : public virtual ISupportByteArrayConversion
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			SOverload_t(const SOverload_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~SOverload_t(void);
			SOverload_t(void);
			int32_t count(void);
			void count(int32_t value);
			float duration(void);
			void duration(float value);
			int32_t OBAcount(void);
			void OBAcount(int32_t value);
			float OBAduration(void);
			void OBAduration(float value);
#ifdef MAKEDLL
		public: // This is for internal use
			SOverload_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _SOVERLOAD_T_H
