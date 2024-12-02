/**************************************************************************//**
 * @file CSoundRecord.h
 * @brief Native Wrapper for Managed type SoundRecord.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _CSOUND_RECORD_H
#define _CSOUND_RECORD_H
#include <EAudioFormat.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI Array_uint8_t;

		class LDAPI CSoundRecord
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			CSoundRecord(const CSoundRecord& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~CSoundRecord(void);
			CSoundRecord(void);
			int32_t NumSamples(void);
			void NumSamples(int32_t value);
			int32_t Type(void);
			void Type(int32_t value);
			int32_t SampleRate(void);
			void SampleRate(int32_t value);
			int32_t NumBitsPerSample(void);
			void NumBitsPerSample(int32_t value);
			int32_t Channels(void);
			void Channels(int32_t value);
			int32_t DataSize(void);
			void DataSize(int32_t value);
			int32_t Id(void);
			void Id(int32_t value);
			EAudioFormat Format(void);
			void Format(EAudioFormat value);
			std::shared_ptr<Array_uint8_t> Data(void);
			int64_t DataOffset(void);
			void DataOffset(int64_t value);
			int32_t PreRecord(void);
			void PreRecord(int32_t value);
			float Gain(void);
			void Gain(float value);
#ifdef MAKEDLL
		public: // This is for internal use
			CSoundRecord(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _CSOUND_RECORD_H
