/**************************************************************************//**
 * @file SDataLimitsEDT_t.h
 * @brief Native Wrapper for Managed type DataLimitsEDT_t.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _SDATA_LIMITS_EDT_T_H
#define _SDATA_LIMITS_EDT_T_H
namespace LarsonDavis
{
	namespace Native
	{

		struct LDAPI SDataLimitsEDT_t
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			SDataLimitsEDT_t(const SDataLimitsEDT_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~SDataLimitsEDT_t(void);
			SDataLimitsEDT_t(void);
			int32_t peak_point(void);
			void peak_point(int32_t value);
			int32_t ten_db_point(void);
			void ten_db_point(int32_t value);
#ifdef MAKEDLL
		public: // This is for internal use
			SDataLimitsEDT_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _SDATA_LIMITS_EDT_T_H
