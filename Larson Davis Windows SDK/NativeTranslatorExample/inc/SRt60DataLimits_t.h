/**************************************************************************//**
 * @file SRt60DataLimits_t.h
 * @brief Native Wrapper for Managed type Rt60DataLimits_t.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _SRT60_DATA_LIMITS_T_H
#define _SRT60_DATA_LIMITS_T_H
#include <ISupportByteArrayConversion.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI ISupportByteArrayConversion;

		struct LDAPI SRt60DataLimits_t : public virtual ISupportByteArrayConversion
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			SRt60DataLimits_t(const SRt60DataLimits_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~SRt60DataLimits_t(void);
			SRt60DataLimits_t(void);
			int32_t startPoint(void);
			void startPoint(int32_t value);
			int32_t twentydBPoint(void);
			void twentydBPoint(int32_t value);
			int32_t thirtydBPoint(void);
			void thirtydBPoint(int32_t value);
			int32_t stopPoint(void);
			void stopPoint(int32_t value);
#ifdef MAKEDLL
		public: // This is for internal use
			SRt60DataLimits_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _SRT60_DATA_LIMITS_T_H
