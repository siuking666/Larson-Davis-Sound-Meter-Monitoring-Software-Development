/**************************************************************************//**
 * @file SSpectraInfo_t.h
 * @brief Native Wrapper for Managed type SpectraInfo_t.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _SSPECTRA_INFO_T_H
#define _SSPECTRA_INFO_T_H
#include <ISupportByteArrayConversion.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI ISupportByteArrayConversion;
		class LDAPI Array_float;

		struct LDAPI SSpectraInfo_t : public virtual ISupportByteArrayConversion
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			SSpectraInfo_t(const SSpectraInfo_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~SSpectraInfo_t(void);
			SSpectraInfo_t(void);
			int32_t type(void);
			void type(int32_t value);
			int32_t bandWidth(void);
			void bandWidth(int32_t value);
			int32_t range(void);
			void range(int32_t value);
			std::shared_ptr<Array_float> overallSpectra(void);
			void overallSpectra(std::shared_ptr<Array_float> value);
			std::shared_ptr<Array_float> maxSpectra(void);
			void maxSpectra(std::shared_ptr<Array_float> value);
			std::shared_ptr<Array_float> minSpectra(void);
			void minSpectra(std::shared_ptr<Array_float> value);
#ifdef MAKEDLL
		public: // This is for internal use
			SSpectraInfo_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _SSPECTRA_INFO_T_H
