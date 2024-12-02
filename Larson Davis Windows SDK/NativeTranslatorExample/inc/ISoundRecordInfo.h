/**************************************************************************//**
 * @file ISoundRecordInfo.h
 * @brief Native Wrapper for Managed type ISoundRecordInfo.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ISOUND_RECORD_INFO_H
#define _ISOUND_RECORD_INFO_H
#include <IMetaBlockInfo.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI IMetaBlockInfo;

		class LDAPI ISoundRecordInfo : public virtual IMetaBlockInfo
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			ISoundRecordInfo(const ISoundRecordInfo& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~ISoundRecordInfo(void);
#ifdef MAKEDLL
		public: // This is for internal use
			ISoundRecordInfo(){};
			ISoundRecordInfo(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _ISOUND_RECORD_INFO_H
