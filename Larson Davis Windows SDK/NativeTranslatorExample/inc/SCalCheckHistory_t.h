/**************************************************************************//**
 * @file SCalCheckHistory_t.h
 * @brief Native Wrapper for Managed type CalCheckHistory_t.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _SCAL_CHECK_HISTORY_T_H
#define _SCAL_CHECK_HISTORY_T_H
#include <ISupportByteArrayConversion.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI ISupportByteArrayConversion;
		class LDAPI Array_SCalData2_t;
		class LDAPI Array_float;

		struct LDAPI SCalCheckHistory_t : public virtual ISupportByteArrayConversion
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			SCalCheckHistory_t(const SCalCheckHistory_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~SCalCheckHistory_t(void);
			SCalCheckHistory_t(void);
			std::shared_ptr<Array_SCalData2_t> data(void);
			void data(std::shared_ptr<Array_SCalData2_t> value);
			std::shared_ptr<Array_float> standardLevel(void);
			void standardLevel(std::shared_ptr<Array_float> value);
#ifdef MAKEDLL
		public: // This is for internal use
			SCalCheckHistory_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _SCAL_CHECK_HISTORY_T_H
