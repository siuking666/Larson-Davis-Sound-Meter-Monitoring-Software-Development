/**************************************************************************//**
 * @file SLoggedData_t.h
 * @brief Native Wrapper for Managed type LoggedData_t.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _SLOGGED_DATA_T_H
#define _SLOGGED_DATA_T_H
#include <ISupportByteArrayConversion.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI ISupportByteArrayConversion;

		struct LDAPI SLoggedData_t : public virtual ISupportByteArrayConversion
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			SLoggedData_t(const SLoggedData_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~SLoggedData_t(void);
			SLoggedData_t(void);
			float cal_level(void);
			void cal_level(float value);
#ifdef MAKEDLL
		public: // This is for internal use
			SLoggedData_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _SLOGGED_DATA_T_H
