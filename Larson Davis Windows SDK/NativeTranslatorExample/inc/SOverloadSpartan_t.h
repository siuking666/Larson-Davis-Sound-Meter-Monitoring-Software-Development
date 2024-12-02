/**************************************************************************//**
 * @file SOverloadSpartan_t.h
 * @brief Native Wrapper for Managed type OverloadSpartan_t.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _SOVERLOAD_SPARTAN_T_H
#define _SOVERLOAD_SPARTAN_T_H
#include <ISupportByteArrayConversion.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI ISupportByteArrayConversion;
		struct LDAPI SOverloadInfo_t;

		struct LDAPI SOverloadSpartan_t : public virtual ISupportByteArrayConversion
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			SOverloadSpartan_t(const SOverloadSpartan_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~SOverloadSpartan_t(void);
			SOverloadSpartan_t(void);
			std::shared_ptr<SOverloadInfo_t> slm(void);
			void slm(std::shared_ptr<SOverloadInfo_t> value);
			std::shared_ptr<SOverloadInfo_t> oba(void);
			void oba(std::shared_ptr<SOverloadInfo_t> value);
#ifdef MAKEDLL
		public: // This is for internal use
			SOverloadSpartan_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _SOVERLOAD_SPARTAN_T_H
