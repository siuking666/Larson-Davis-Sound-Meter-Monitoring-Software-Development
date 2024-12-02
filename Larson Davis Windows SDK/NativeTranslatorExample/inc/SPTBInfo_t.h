/**************************************************************************//**
 * @file SPTBInfo_t.h
 * @brief Native Wrapper for Managed type PTBInfo_t.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _SPTBINFO_T_H
#define _SPTBINFO_T_H
#include <ISupportByteArrayConversion.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI ISupportByteArrayConversion;

		struct LDAPI SPTBInfo_t : public virtual ISupportByteArrayConversion
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			SPTBInfo_t(const SPTBInfo_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~SPTBInfo_t(void);
			SPTBInfo_t(void);
			uint32_t timestamp(void);
			void timestamp(uint32_t value);
			float certifiedMicSensitivity(void);
			void certifiedMicSensitivity(float value);
			float actualMicSensitivity(void);
			void actualMicSensitivity(float value);
			uint32_t sealState(void);
			void sealState(uint32_t value);
			uint32_t sealStateFlags(void);
			void sealStateFlags(uint32_t value);
#ifdef MAKEDLL
		public: // This is for internal use
			SPTBInfo_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _SPTBINFO_T_H
