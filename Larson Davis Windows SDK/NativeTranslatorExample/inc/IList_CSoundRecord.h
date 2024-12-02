/**************************************************************************//**
 * @file IList_CSoundRecord.h
 * @brief Native Wrapper for Managed type IList<LarsonDavis::SDK::LDCommonStd::Legacy::SoundRecord^>.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ILIST_CSOUND_RECORD_H
#define _ILIST_CSOUND_RECORD_H
#include <CSoundRecord.h>
#include <EAudioFormat.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI CSoundRecord;
		class LDAPI Array_uint8_t;

		class LDAPI IList_CSoundRecord
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			IList_CSoundRecord(const IList_CSoundRecord& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~IList_CSoundRecord(void);
			virtual int32_t IndexOf(std::shared_ptr<CSoundRecord> item);
			virtual void Insert(int32_t index, std::shared_ptr<CSoundRecord> item);
			virtual void RemoveAt(int32_t index);
			virtual std::shared_ptr<CSoundRecord> Item(int32_t index);
			virtual void Item(int32_t index, std::shared_ptr<CSoundRecord> value);
			virtual int32_t Count(void);
#ifdef MAKEDLL
		public: // This is for internal use
			IList_CSoundRecord(){};
			IList_CSoundRecord(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _ILIST_CSOUND_RECORD_H
