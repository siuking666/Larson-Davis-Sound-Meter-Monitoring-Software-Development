/**************************************************************************//**
 * @file CManifestMetaBlock.h
 * @brief Native Wrapper for Managed type ManifestMetaBlock.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _CMANIFEST_META_BLOCK_H
#define _CMANIFEST_META_BLOCK_H
#include <IManifestMetaBlock.h>
#include <EBlockTag.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI IManifestMetaBlock;
		class LDAPI IList_CMetaBlockInfo;
		class LDAPI CMetaBlockInfo;

		class LDAPI CManifestMetaBlock : public virtual IManifestMetaBlock
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			CManifestMetaBlock(const CManifestMetaBlock& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~CManifestMetaBlock(void);
			CManifestMetaBlock(void);
			EBlockTag BlockTag(void);
			void BlockTag(EBlockTag value);
			int64_t EndOfMeterDataPos(void);
			void EndOfMeterDataPos(int64_t value);
			int64_t NextMetaBlockPos(void);
			void NextMetaBlockPos(int64_t value);
			StringWrapper Version(void);
			void Version(StringWrapper value);
			std::shared_ptr<IList_CMetaBlockInfo> BlockList(void);
			void BlockList(std::shared_ptr<IList_CMetaBlockInfo> value);
			StringWrapper AppVersion(void);
#ifdef MAKEDLL
		public: // This is for internal use
			CManifestMetaBlock(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _CMANIFEST_META_BLOCK_H
