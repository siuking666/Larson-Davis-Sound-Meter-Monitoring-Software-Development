/**************************************************************************//**
 * @file ISoundRecordMetaBlock.h
 * @brief Native Wrapper for Managed type ISoundRecordMetaBlock.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ISOUND_RECORD_META_BLOCK_H
#define _ISOUND_RECORD_META_BLOCK_H
#include <IMetaBlock.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI IMetaBlock;
		class LDAPI IList_CSoundRecordInfo;
		class LDAPI CSoundRecordInfo;

		class LDAPI ISoundRecordMetaBlock : public virtual IMetaBlock
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			ISoundRecordMetaBlock(const ISoundRecordMetaBlock& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~ISoundRecordMetaBlock(void);
			virtual std::shared_ptr<IList_CSoundRecordInfo> SoundRecords(void);
			virtual void SoundRecords(std::shared_ptr<IList_CSoundRecordInfo> value);
#ifdef MAKEDLL
		public: // This is for internal use
			ISoundRecordMetaBlock(){};
			ISoundRecordMetaBlock(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _ISOUND_RECORD_META_BLOCK_H
