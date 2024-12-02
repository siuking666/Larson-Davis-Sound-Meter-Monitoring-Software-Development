/**************************************************************************//**
 * @file IRt60DecayMetaBlock.h
 * @brief Native Wrapper for Managed type IRt60DecayMetaBlock.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _IRT60_DECAY_META_BLOCK_H
#define _IRT60_DECAY_META_BLOCK_H
#include <IMetaBlock.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI IMetaBlock;
		class LDAPI List_CRt60DecayInfo;
		class LDAPI CRt60DecayInfo;
		class LDAPI IComparer_CRt60DecayInfo;
		class LDAPI Array_CRt60DecayInfo;

		class LDAPI IRt60DecayMetaBlock : public virtual IMetaBlock
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			IRt60DecayMetaBlock(const IRt60DecayMetaBlock& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~IRt60DecayMetaBlock(void);
			virtual std::shared_ptr<List_CRt60DecayInfo> Decays(void);
			virtual void Decays(std::shared_ptr<List_CRt60DecayInfo> value);
#ifdef MAKEDLL
		public: // This is for internal use
			IRt60DecayMetaBlock(){};
			IRt60DecayMetaBlock(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _IRT60_DECAY_META_BLOCK_H
