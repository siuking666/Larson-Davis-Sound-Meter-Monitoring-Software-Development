/**************************************************************************//**
 * @file SManifestBlockSpartan_t.h
 * @brief Native Wrapper for Managed type ManifestBlockSpartan_t.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _SMANIFEST_BLOCK_SPARTAN_T_H
#define _SMANIFEST_BLOCK_SPARTAN_T_H
#include <ISupportByteArrayConversion.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI ISupportByteArrayConversion;
		struct LDAPI SFileInfoHeaderSpartan_t;
		struct LDAPI SBlockHeaderSpartan_t;
		struct LDAPI SManifestEntrySpartan_t;
		struct LDAPI SBlockFooterSpartan_t;

		struct LDAPI SManifestBlockSpartan_t : public virtual ISupportByteArrayConversion
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			SManifestBlockSpartan_t(const SManifestBlockSpartan_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~SManifestBlockSpartan_t(void);
			SManifestBlockSpartan_t(void);
			std::shared_ptr<SFileInfoHeaderSpartan_t> manifestHeader(void);
			void manifestHeader(std::shared_ptr<SFileInfoHeaderSpartan_t> value);
			std::shared_ptr<SBlockHeaderSpartan_t> blockHeader(void);
			void blockHeader(std::shared_ptr<SBlockHeaderSpartan_t> value);
			std::shared_ptr<SManifestEntrySpartan_t> overallManifestEntry(void);
			void overallManifestEntry(std::shared_ptr<SManifestEntrySpartan_t> value);
			std::shared_ptr<SManifestEntrySpartan_t> sessionLogManifestEntry(void);
			void sessionLogManifestEntry(std::shared_ptr<SManifestEntrySpartan_t> value);
			std::shared_ptr<SManifestEntrySpartan_t> notesManifestEntry(void);
			void notesManifestEntry(std::shared_ptr<SManifestEntrySpartan_t> value);
			std::shared_ptr<SManifestEntrySpartan_t> timeHistManifestEntry(void);
			void timeHistManifestEntry(std::shared_ptr<SManifestEntrySpartan_t> value);
			std::shared_ptr<SManifestEntrySpartan_t> soundRecordsManifestEntry(void);
			void soundRecordsManifestEntry(std::shared_ptr<SManifestEntrySpartan_t> value);
			std::shared_ptr<SManifestEntrySpartan_t> measHistManifestEntry(void);
			void measHistManifestEntry(std::shared_ptr<SManifestEntrySpartan_t> value);
			std::shared_ptr<SBlockFooterSpartan_t> blockFooter(void);
			void blockFooter(std::shared_ptr<SBlockFooterSpartan_t> value);
#ifdef MAKEDLL
		public: // This is for internal use
			SManifestBlockSpartan_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _SMANIFEST_BLOCK_SPARTAN_T_H
