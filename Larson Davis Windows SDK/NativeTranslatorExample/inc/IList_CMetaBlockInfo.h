/**************************************************************************//**
 * @file IList_CMetaBlockInfo.h
 * @brief Native Wrapper for Managed type IList<LarsonDavis::SDK::LDCommonStd::MetaData::MetaBlockInfo^>.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ILIST_CMETA_BLOCK_INFO_H
#define _ILIST_CMETA_BLOCK_INFO_H
#include <CMetaBlockInfo.h>
#include <EBlockTag.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI CMetaBlockInfo;

		class LDAPI IList_CMetaBlockInfo
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			IList_CMetaBlockInfo(const IList_CMetaBlockInfo& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~IList_CMetaBlockInfo(void);
			virtual int32_t IndexOf(std::shared_ptr<CMetaBlockInfo> item);
			virtual void Insert(int32_t index, std::shared_ptr<CMetaBlockInfo> item);
			virtual void RemoveAt(int32_t index);
			virtual std::shared_ptr<CMetaBlockInfo> Item(int32_t index);
			virtual void Item(int32_t index, std::shared_ptr<CMetaBlockInfo> value);
			virtual int32_t Count(void);
#ifdef MAKEDLL
		public: // This is for internal use
			IList_CMetaBlockInfo(){};
			IList_CMetaBlockInfo(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _ILIST_CMETA_BLOCK_INFO_H
