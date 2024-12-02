/**************************************************************************//**
 * @file CSoundRecordMetaBlock.h
 * @brief Native Wrapper for Managed type SoundRecordMetaBlock.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _CSOUND_RECORD_META_BLOCK_H
#define _CSOUND_RECORD_META_BLOCK_H
#include <ISoundRecordMetaBlock.h>
#include <EBlockTag.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI ISoundRecordMetaBlock;
		class LDAPI IList_CSoundRecordInfo;
		class LDAPI CSoundRecordInfo;

		class LDAPI CSoundRecordMetaBlock : public virtual ISoundRecordMetaBlock
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			CSoundRecordMetaBlock(const CSoundRecordMetaBlock& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~CSoundRecordMetaBlock(void);
			CSoundRecordMetaBlock(void);
			EBlockTag BlockTag(void);
			void BlockTag(EBlockTag value);
			std::shared_ptr<IList_CSoundRecordInfo> SoundRecords(void);
			void SoundRecords(std::shared_ptr<IList_CSoundRecordInfo> value);
#ifdef MAKEDLL
		public: // This is for internal use
			CSoundRecordMetaBlock(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _CSOUND_RECORD_META_BLOCK_H
