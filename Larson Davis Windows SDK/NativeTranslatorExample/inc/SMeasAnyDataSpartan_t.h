/**************************************************************************//**
 * @file SMeasAnyDataSpartan_t.h
 * @brief Native Wrapper for Managed type MeasAnyDataSpartan_t.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _SMEAS_ANY_DATA_SPARTAN_T_H
#define _SMEAS_ANY_DATA_SPARTAN_T_H
#include <ISupportByteArrayConversion.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI ISupportByteArrayConversion;
		struct LDAPI SOverloadSpartan_t;
		class LDAPI Array_float;
		class LDAPI Array_SDetectorTs2_t;

		struct LDAPI SMeasAnyDataSpartan_t : public virtual ISupportByteArrayConversion
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			SMeasAnyDataSpartan_t(const SMeasAnyDataSpartan_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~SMeasAnyDataSpartan_t(void);
			SMeasAnyDataSpartan_t(void);
			uint32_t flags(void);
			void flags(uint32_t value);
			float runtime(void);
			void runtime(float value);
			float pausetime(void);
			void pausetime(float value);
			uint32_t starttime(void);
			void starttime(uint32_t value);
			uint32_t endtime(void);
			void endtime(uint32_t value);
			uint32_t count(void);
			void count(uint32_t value);
			std::shared_ptr<SOverloadSpartan_t> overloads(void);
			void overloads(std::shared_ptr<SOverloadSpartan_t> value);
			std::shared_ptr<Array_float> profile(void);
			void profile(std::shared_ptr<Array_float> value);
			uint32_t time_hist_record(void);
			void time_hist_record(uint32_t value);
			uint32_t sound_record(void);
			void sound_record(uint32_t value);
			std::shared_ptr<Array_SDetectorTs2_t> allData(void);
			void allData(std::shared_ptr<Array_SDetectorTs2_t> value);
#ifdef MAKEDLL
		public: // This is for internal use
			SMeasAnyDataSpartan_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _SMEAS_ANY_DATA_SPARTAN_T_H
