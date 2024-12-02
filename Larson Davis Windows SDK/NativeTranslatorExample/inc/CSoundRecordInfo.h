/**************************************************************************//**
 * @file CSoundRecordInfo.h
 * @brief Native Wrapper for Managed type SoundRecordInfo.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _CSOUND_RECORD_INFO_H
#define _CSOUND_RECORD_INFO_H
#include <CMetaBlockInfo.h>
#include <ISoundRecordInfo.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI CMetaBlockInfo;
		class LDAPI ISoundRecordInfo;

		class LDAPI CSoundRecordInfo : public CMetaBlockInfo, public virtual ISoundRecordInfo
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			CSoundRecordInfo(const CSoundRecordInfo& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~CSoundRecordInfo(void);
			CSoundRecordInfo(void);
#ifdef MAKEDLL
		public: // This is for internal use
			CSoundRecordInfo(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _CSOUND_RECORD_INFO_H
