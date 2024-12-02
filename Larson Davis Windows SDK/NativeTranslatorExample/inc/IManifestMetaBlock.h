/**************************************************************************//**
 * @file IManifestMetaBlock.h
 * @brief Native Wrapper for Managed type IManifestMetaBlock.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _IMANIFEST_META_BLOCK_H
#define _IMANIFEST_META_BLOCK_H
#include <IMetaBlock.h>
#include <EBlockTag.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI IMetaBlock;
		class LDAPI IList_CMetaBlockInfo;
		class LDAPI CMetaBlockInfo;

		class LDAPI IManifestMetaBlock : public virtual IMetaBlock
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			IManifestMetaBlock(const IManifestMetaBlock& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~IManifestMetaBlock(void);
			virtual std::shared_ptr<IList_CMetaBlockInfo> BlockList(void);
			virtual void BlockList(std::shared_ptr<IList_CMetaBlockInfo> value);
#ifdef MAKEDLL
		public: // This is for internal use
			IManifestMetaBlock(){};
			IManifestMetaBlock(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _IMANIFEST_META_BLOCK_H
