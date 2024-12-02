/**************************************************************************//**
 * @file IMetaBlockInfo.h
 * @brief Native Wrapper for Managed type IMetaBlockInfo.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _IMETA_BLOCK_INFO_H
#define _IMETA_BLOCK_INFO_H
#include <IMetaBlock.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI IMetaBlock;

		class LDAPI IMetaBlockInfo : public virtual IMetaBlock
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			IMetaBlockInfo(const IMetaBlockInfo& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~IMetaBlockInfo(void);
			virtual int64_t Offset(void);
			virtual void Offset(int64_t value);
			virtual int64_t Length(void);
			virtual void Length(int64_t value);
			virtual StringWrapper ExtraInfo(void);
			virtual void ExtraInfo(StringWrapper value);
#ifdef MAKEDLL
		public: // This is for internal use
			IMetaBlockInfo(){};
			IMetaBlockInfo(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _IMETA_BLOCK_INFO_H
