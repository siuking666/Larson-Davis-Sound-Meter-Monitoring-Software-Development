/**************************************************************************//**
 * @file SDetectorTs_t.h
 * @brief Native Wrapper for Managed type DetectorTs_t.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _SDETECTOR_TS_T_H
#define _SDETECTOR_TS_T_H
#include <ISupportByteArrayConversion.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI ISupportByteArrayConversion;
		struct LDAPI SLevelTs_t;

		struct LDAPI SDetectorTs_t : public virtual ISupportByteArrayConversion
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			SDetectorTs_t(const SDetectorTs_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~SDetectorTs_t(void);
			SDetectorTs_t(void);
			std::shared_ptr<SLevelTs_t> peak(void);
			void peak(std::shared_ptr<SLevelTs_t> value);
			std::shared_ptr<SLevelTs_t> impulse(void);
			void impulse(std::shared_ptr<SLevelTs_t> value);
			std::shared_ptr<SLevelTs_t> fast(void);
			void fast(std::shared_ptr<SLevelTs_t> value);
			std::shared_ptr<SLevelTs_t> slow(void);
			void slow(std::shared_ptr<SLevelTs_t> value);
			std::shared_ptr<SLevelTs_t> linear(void);
			void linear(std::shared_ptr<SLevelTs_t> value);
#ifdef MAKEDLL
		public: // This is for internal use
			SDetectorTs_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _SDETECTOR_TS_T_H
