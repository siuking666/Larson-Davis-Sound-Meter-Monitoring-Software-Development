/**************************************************************************//**
 * @file SCalData_t.h
 * @brief Native Wrapper for Managed type CalData_t.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _SCAL_DATA_T_H
#define _SCAL_DATA_T_H
#include <ISupportByteArrayConversion.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI ISupportByteArrayConversion;
		class LDAPI Array_uint32_t;
		class LDAPI Array_float;

		struct LDAPI SCalData_t : public virtual ISupportByteArrayConversion
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			SCalData_t(const SCalData_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~SCalData_t(void);
			SCalData_t(void);
			std::shared_ptr<Array_uint32_t> calibrationDate(void);
			void calibrationDate(std::shared_ptr<Array_uint32_t> value);
			std::shared_ptr<Array_float> calibrationScale(void);
			void calibrationScale(std::shared_ptr<Array_float> value);
#ifdef MAKEDLL
		public: // This is for internal use
			SCalData_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _SCAL_DATA_T_H
