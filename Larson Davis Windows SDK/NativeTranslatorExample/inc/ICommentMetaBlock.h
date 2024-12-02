/**************************************************************************//**
 * @file ICommentMetaBlock.h
 * @brief Native Wrapper for Managed type ICommentMetaBlock.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ICOMMENT_META_BLOCK_H
#define _ICOMMENT_META_BLOCK_H
#include <IMetaBlock.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI IMetaBlock;
		class LDAPI List_CMarkerInfo;
		class LDAPI CMarkerInfo;
		class LDAPI IComparer_CMarkerInfo;
		class LDAPI Array_CMarkerInfo;

		class LDAPI ICommentMetaBlock : public virtual IMetaBlock
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			ICommentMetaBlock(const ICommentMetaBlock& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~ICommentMetaBlock(void);
			virtual std::shared_ptr<List_CMarkerInfo> Markers(void);
			virtual void Markers(std::shared_ptr<List_CMarkerInfo> value);
#ifdef MAKEDLL
		public: // This is for internal use
			ICommentMetaBlock(){};
			ICommentMetaBlock(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _ICOMMENT_META_BLOCK_H
