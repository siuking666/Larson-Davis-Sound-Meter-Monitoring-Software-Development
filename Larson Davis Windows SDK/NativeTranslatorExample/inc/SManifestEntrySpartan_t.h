/**************************************************************************//**
 * @file SManifestEntrySpartan_t.h
 * @brief Native Wrapper for Managed type ManifestEntrySpartan_t.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _SMANIFEST_ENTRY_SPARTAN_T_H
#define _SMANIFEST_ENTRY_SPARTAN_T_H
#include <ISupportByteArrayConversion.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI ISupportByteArrayConversion;

		struct LDAPI SManifestEntrySpartan_t : public virtual ISupportByteArrayConversion
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			SManifestEntrySpartan_t(const SManifestEntrySpartan_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~SManifestEntrySpartan_t(void);
			SManifestEntrySpartan_t(void);
			int32_t tag(void);
			void tag(int32_t value);
			int32_t startOffset(void);
			void startOffset(int32_t value);
			int32_t length(void);
			void length(int32_t value);
			int32_t number(void);
			void number(int32_t value);
#ifdef MAKEDLL
		public: // This is for internal use
			SManifestEntrySpartan_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _SMANIFEST_ENTRY_SPARTAN_T_H
