/**************************************************************************//**
 * @file SPrePostCalSpartan_v2_t.h
 * @brief Native Wrapper for Managed type PrePostCalSpartan_v2_t.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _SPRE_POST_CAL_SPARTAN_V2_T_H
#define _SPRE_POST_CAL_SPARTAN_V2_T_H
#include <ISupportByteArrayConversion.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI ISupportByteArrayConversion;

		struct LDAPI SPrePostCalSpartan_v2_t : public virtual ISupportByteArrayConversion
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			SPrePostCalSpartan_v2_t(const SPrePostCalSpartan_v2_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~SPrePostCalSpartan_v2_t(void);
			SPrePostCalSpartan_v2_t(void);
			uint32_t date(void);
			void date(uint32_t value);
			float sensitivity(void);
			void sensitivity(float value);
			float meas_level(void);
			void meas_level(float value);
			float cal_level(void);
			void cal_level(float value);
			float deviation(void);
			void deviation(float value);
#ifdef MAKEDLL
		public: // This is for internal use
			SPrePostCalSpartan_v2_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _SPRE_POST_CAL_SPARTAN_V2_T_H
