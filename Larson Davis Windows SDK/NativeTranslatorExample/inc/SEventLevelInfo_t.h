/**************************************************************************//**
 * @file SEventLevelInfo_t.h
 * @brief Native Wrapper for Managed type EventLevelInfo_t.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _SEVENT_LEVEL_INFO_T_H
#define _SEVENT_LEVEL_INFO_T_H
#include <ISupportByteArrayConversion.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI ISupportByteArrayConversion;

		struct LDAPI SEventLevelInfo_t : public virtual ISupportByteArrayConversion
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			SEventLevelInfo_t(const SEventLevelInfo_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~SEventLevelInfo_t(void);
			SEventLevelInfo_t(void);
			float a_leq(void);
			void a_leq(float value);
			float a_lmax(void);
			void a_lmax(float value);
			float a_lpeak(void);
			void a_lpeak(float value);
			float c_leq(void);
			void c_leq(float value);
			float c_lmax(void);
			void c_lmax(float value);
			float c_lpeak(void);
			void c_lpeak(float value);
			float z_leq(void);
			void z_leq(float value);
			float z_lmax(void);
			void z_lmax(float value);
			float z_lpeak(void);
			void z_lpeak(float value);
#ifdef MAKEDLL
		public: // This is for internal use
			SEventLevelInfo_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _SEVENT_LEVEL_INFO_T_H
