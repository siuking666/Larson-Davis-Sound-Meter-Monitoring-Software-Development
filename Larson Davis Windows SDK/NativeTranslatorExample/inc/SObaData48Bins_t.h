/**************************************************************************//**
 * @file SObaData48Bins_t.h
 * @brief Native Wrapper for Managed type ObaData48Bins_t.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _SOBA_DATA48_BINS_T_H
#define _SOBA_DATA48_BINS_T_H
#include <ISupportByteArrayConversion.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI ISupportByteArrayConversion;
		class LDAPI Array_SDetectorTs_t;

		struct LDAPI SObaData48Bins_t : public virtual ISupportByteArrayConversion
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			SObaData48Bins_t(const SObaData48Bins_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~SObaData48Bins_t(void);
			SObaData48Bins_t(void);
			std::shared_ptr<Array_SDetectorTs_t> oba(void);
			void oba(std::shared_ptr<Array_SDetectorTs_t> value);
#ifdef MAKEDLL
		public: // This is for internal use
			SObaData48Bins_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _SOBA_DATA48_BINS_T_H
