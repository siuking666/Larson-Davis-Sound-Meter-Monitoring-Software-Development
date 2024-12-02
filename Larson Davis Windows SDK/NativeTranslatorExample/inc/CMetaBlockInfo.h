/**************************************************************************//**
 * @file CMetaBlockInfo.h
 * @brief Native Wrapper for Managed type MetaBlockInfo.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _CMETA_BLOCK_INFO_H
#define _CMETA_BLOCK_INFO_H
#include <IMetaBlockInfo.h>
#include <EBlockTag.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI IMetaBlockInfo;

		class LDAPI CMetaBlockInfo : public virtual IMetaBlockInfo
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			CMetaBlockInfo(const CMetaBlockInfo& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~CMetaBlockInfo(void);
			CMetaBlockInfo(void);
			CMetaBlockInfo(EBlockTag tag);
			EBlockTag BlockTag(void);
			void BlockTag(EBlockTag value);
			int64_t Offset(void);
			void Offset(int64_t value);
			int64_t Length(void);
			void Length(int64_t value);
			StringWrapper ExtraInfo(void);
			void ExtraInfo(StringWrapper value);
#ifdef MAKEDLL
		public: // This is for internal use
			CMetaBlockInfo(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _CMETA_BLOCK_INFO_H
