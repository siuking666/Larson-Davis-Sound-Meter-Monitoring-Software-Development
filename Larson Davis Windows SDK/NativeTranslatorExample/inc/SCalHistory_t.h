/**************************************************************************//**
 * @file SCalHistory_t.h
 * @brief Native Wrapper for Managed type CalHistory_t.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _SCAL_HISTORY_T_H
#define _SCAL_HISTORY_T_H
#include <ISupportByteArrayConversion.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI ISupportByteArrayConversion;
		class LDAPI Array_SCalData_t;

		struct LDAPI SCalHistory_t : public virtual ISupportByteArrayConversion
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			SCalHistory_t(const SCalHistory_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~SCalHistory_t(void);
			SCalHistory_t(void);
			std::shared_ptr<Array_SCalData_t> types(void);
			void types(std::shared_ptr<Array_SCalData_t> value);
#ifdef MAKEDLL
		public: // This is for internal use
			SCalHistory_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _SCAL_HISTORY_T_H
