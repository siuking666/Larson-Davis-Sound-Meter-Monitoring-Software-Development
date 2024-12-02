/**************************************************************************//**
 * @file CSessionLog.h
 * @brief Native Wrapper for Managed type SessionLog.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _CSESSION_LOG_H
#define _CSESSION_LOG_H
#include <EActionCause.h>
#include <EAudioFormat.h>
namespace LarsonDavis
{
	namespace Native
	{
		struct LDAPI SSessionLog_t;
		class LDAPI ISlmRecord;
		class LDAPI CRunRecord;
		class LDAPI IList_CRunRecord;
		class LDAPI IList_CSoundRecord;
		class LDAPI CSoundRecord;
		class LDAPI Array_uint8_t;

		class LDAPI CSessionLog
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			CSessionLog(const CSessionLog& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~CSessionLog(void);
			void AddRunRecord(std::shared_ptr<SSessionLog_t> session);
			static bool IsMilliSecondAccuracyAvailable(std::shared_ptr<ISlmRecord> rec);
			static StringWrapper GetLogAction(EActionCause type);
			static StringWrapper GetLogCause(std::shared_ptr<ISlmRecord> rec, std::shared_ptr<CRunRecord> runRec);
			static StringWrapper GetCauseCount(std::shared_ptr<ISlmRecord> rec, std::shared_ptr<CRunRecord> runRec);
			CSessionLog(void);
			bool DoAudio(void);
			void DoAudio(bool value);
			int32_t VoiceDataIndex(void);
			void VoiceDataIndex(int32_t value);
			int32_t AudioDataIndex(void);
			void AudioDataIndex(int32_t value);
			std::shared_ptr<IList_CRunRecord> RunRecords(void);
			void RunRecords(std::shared_ptr<IList_CRunRecord> value);
			std::shared_ptr<IList_CSoundRecord> AudioData(void);
			void AudioData(std::shared_ptr<IList_CSoundRecord> value);
			std::shared_ptr<IList_CSoundRecord> VoiceData(void);
			void VoiceData(std::shared_ptr<IList_CSoundRecord> value);
#ifdef MAKEDLL
		public: // This is for internal use
			CSessionLog(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _CSESSION_LOG_H
