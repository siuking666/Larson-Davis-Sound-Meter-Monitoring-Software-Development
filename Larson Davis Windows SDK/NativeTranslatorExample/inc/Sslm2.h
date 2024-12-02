/**************************************************************************//**
 * @file Sslm2.h
 * @brief Native Wrapper for Managed type slm2.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _SSLM2_H
#define _SSLM2_H
#include <ISupportByteArrayConversion.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI ISupportByteArrayConversion;
		struct LDAPI SDetectorTs_t;
		class LDAPI Array_SDetector_t;

		struct LDAPI Sslm2 : public virtual ISupportByteArrayConversion
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			Sslm2(const Sslm2& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~Sslm2(void);
			Sslm2(void);
			uint32_t flags(void);
			void flags(uint32_t value);
			float runtime(void);
			void runtime(float value);
			float pausetime(void);
			void pausetime(float value);
			uint32_t count(void);
			void count(uint32_t value);
			uint32_t starttime(void);
			void starttime(uint32_t value);
			uint32_t endtime(void);
			void endtime(uint32_t value);
			std::shared_ptr<SDetectorTs_t> a(void);
			void a(std::shared_ptr<SDetectorTs_t> value);
			std::shared_ptr<SDetectorTs_t> c(void);
			void c(std::shared_ptr<SDetectorTs_t> value);
			std::shared_ptr<SDetectorTs_t> z(void);
			void z(std::shared_ptr<SDetectorTs_t> value);
			std::shared_ptr<Array_SDetector_t> octave(void);
			void octave(std::shared_ptr<Array_SDetector_t> value);
			std::shared_ptr<Array_SDetector_t> third(void);
			void third(std::shared_ptr<Array_SDetector_t> value);
#ifdef MAKEDLL
		public: // This is for internal use
			Sslm2(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _SSLM2_H
