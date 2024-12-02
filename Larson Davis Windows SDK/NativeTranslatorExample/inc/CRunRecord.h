/**************************************************************************//**
 * @file CRunRecord.h
 * @brief Native Wrapper for Managed type RunRecord.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _CRUN_RECORD_H
#define _CRUN_RECORD_H
#include <EActionCause.h>
namespace LarsonDavis
{
	namespace Native
	{
		struct LDAPI SSessionLog_t;

		class LDAPI CRunRecord
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			CRunRecord(const CRunRecord& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~CRunRecord(void);
			CRunRecord(void);
			CRunRecord(std::shared_ptr<SSessionLog_t> session, EActionCause type, EActionCause cause, int32_t typeCnt);
			int32_t Schema(void);
			void Schema(int32_t value);
			int64_t RecordDate(void);
			void RecordDate(int64_t value);
			EActionCause Type(void);
			void Type(EActionCause value);
			EActionCause Cause(void);
			void Cause(EActionCause value);
			int32_t VoiceDataIndex(void);
			void VoiceDataIndex(int32_t value);
			int32_t AudioDataIndex(void);
			void AudioDataIndex(int32_t value);
			int32_t THRecord(void);
			void THRecord(int32_t value);
			int32_t Count(void);
			void Count(int32_t value);
			float Data(void);
			void Data(float value);
#ifdef MAKEDLL
		public: // This is for internal use
			CRunRecord(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _CRUN_RECORD_H
