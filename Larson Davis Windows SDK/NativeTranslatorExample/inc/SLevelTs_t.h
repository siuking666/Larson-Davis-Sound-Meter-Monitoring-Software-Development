/**************************************************************************//**
 * @file SLevelTs_t.h
 * @brief Native Wrapper for Managed type LevelTs_t.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _SLEVEL_TS_T_H
#define _SLEVEL_TS_T_H
#include <ISupportByteArrayConversion.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI ISupportByteArrayConversion;

		struct LDAPI SLevelTs_t : public virtual ISupportByteArrayConversion
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			SLevelTs_t(const SLevelTs_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~SLevelTs_t(void);
			SLevelTs_t(void);
			float level(void);
			void level(float value);
			float dose(void);
			void dose(float value);
			float get_max(void);
			void get_max(float value);
			float get_min(void);
			void get_min(float value);
			uint32_t tmax(void);
			void tmax(uint32_t value);
			uint32_t tmin(void);
			void tmin(uint32_t value);
#ifdef MAKEDLL
		public: // This is for internal use
			SLevelTs_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _SLEVEL_TS_T_H
