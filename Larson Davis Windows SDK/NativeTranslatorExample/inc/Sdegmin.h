/**************************************************************************//**
 * @file Sdegmin.h
 * @brief Native Wrapper for Managed type degmin.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _SDEGMIN_H
#define _SDEGMIN_H
#include <ISupportByteArrayConversion.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI ISupportByteArrayConversion;

		struct LDAPI Sdegmin : public virtual ISupportByteArrayConversion
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			Sdegmin(const Sdegmin& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~Sdegmin(void);
			Sdegmin(void);
			int32_t deg(void);
			void deg(int32_t value);
			float get_min(void);
			void get_min(float value);
#ifdef MAKEDLL
		public: // This is for internal use
			Sdegmin(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _SDEGMIN_H
