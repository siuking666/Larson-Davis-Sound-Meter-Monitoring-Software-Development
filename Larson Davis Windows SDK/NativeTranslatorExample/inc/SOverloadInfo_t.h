/**************************************************************************//**
 * @file SOverloadInfo_t.h
 * @brief Native Wrapper for Managed type OverloadInfo_t.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _SOVERLOAD_INFO_T_H
#define _SOVERLOAD_INFO_T_H
#include <ISupportByteArrayConversion.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI ISupportByteArrayConversion;

		struct LDAPI SOverloadInfo_t : public virtual ISupportByteArrayConversion
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			SOverloadInfo_t(const SOverloadInfo_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~SOverloadInfo_t(void);
			SOverloadInfo_t(void);
			int32_t count(void);
			void count(int32_t value);
			float duration(void);
			void duration(float value);
#ifdef MAKEDLL
		public: // This is for internal use
			SOverloadInfo_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _SOVERLOAD_INFO_T_H
