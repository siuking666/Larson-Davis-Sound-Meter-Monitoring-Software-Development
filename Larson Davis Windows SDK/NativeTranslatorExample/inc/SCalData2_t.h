/**************************************************************************//**
 * @file SCalData2_t.h
 * @brief Native Wrapper for Managed type CalData2_t.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _SCAL_DATA2_T_H
#define _SCAL_DATA2_T_H
#include <ISupportByteArrayConversion.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI ISupportByteArrayConversion;
		struct LDAPI SDateTime;
		class LDAPI Array_float;

		struct LDAPI SCalData2_t : public virtual ISupportByteArrayConversion
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			SCalData2_t(const SCalData2_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~SCalData2_t(void);
			SCalData2_t(void);
			float GetCalScale(void);
			std::shared_ptr<SDateTime> GetCalDate(void);
			StringWrapper GetCalDateStr(StringWrapper prefFormat = L"yyyy-MM-dd HH:mm:ss", bool includeUtcOffset = true);
			int32_t preampType(void);
			void preampType(int32_t value);
			uint32_t calibrationDate(void);
			void calibrationDate(uint32_t value);
			float calibrationScale(void);
			void calibrationScale(float value);
			int32_t bins(void);
			void bins(int32_t value);
			std::shared_ptr<Array_float> spectralData(void);
			void spectralData(std::shared_ptr<Array_float> value);
#ifdef MAKEDLL
		public: // This is for internal use
			SCalData2_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _SCAL_DATA2_T_H
