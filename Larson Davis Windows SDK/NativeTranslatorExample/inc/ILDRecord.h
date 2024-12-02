/**************************************************************************//**
 * @file ILDRecord.h
 * @brief Native Wrapper for Managed type ILDRecord.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ILDRECORD_H
#define _ILDRECORD_H
#include <EParseError.h>
#include <EMeterType.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI CCalibration;
		class LDAPI Array_float;
		struct LDAPI SPTBInfo_t;

		class LDAPI ILDRecord
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			ILDRecord(const ILDRecord& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~ILDRecord(void);
			virtual int64_t GetTimeHistoryTimestamp(int32_t entryNum);
			virtual StringWrapper GetMetricType(void);
			virtual float GetMetricValue(void);
			virtual StringWrapper GetDesiredMetricSetting(void);
			virtual StringWrapper GetFullModelString(void);
			virtual StringWrapper GetMicrophoneInfo(void);
			virtual void SetPreampName(void);
			virtual std::shared_ptr<CCalibration> GetPreCalData(bool skipSessionLog = false);
			virtual StringWrapper DataFileName(void);
			virtual void DataFileName(StringWrapper value);
			virtual StringWrapper Model(void);
			virtual void Model(StringWrapper value);
			virtual StringWrapper SerialNumber(void);
			virtual void SerialNumber(StringWrapper value);
			virtual StringWrapper FwVersion(void);
			virtual void FwVersion(StringWrapper value);
			virtual StringWrapper HwVersion(void);
			virtual void HwVersion(StringWrapper value);
			virtual StringWrapper User(void);
			virtual void User(StringWrapper value);
			virtual StringWrapper Location(void);
			virtual void Location(StringWrapper value);
			virtual StringWrapper JobDescription(void);
			virtual void JobDescription(StringWrapper value);
			virtual StringWrapper Note(void);
			virtual void Note(StringWrapper value);
			virtual StringWrapper FilePath(void);
			virtual void FilePath(StringWrapper value);
			virtual int64_t FileSize(void);
			virtual StringWrapper Metric1Type(void);
			virtual float Metric1Level(void);
			virtual uint32_t StartTimeSeconds(void);
			virtual uint32_t RunTimeSeconds(void);
			virtual int32_t NumEvents(void);
			virtual int32_t NumOverloads(void);
			virtual int32_t UserRow(void);
			virtual void UserRow(int32_t value);
			virtual int32_t LocationRow(void);
			virtual void LocationRow(int32_t value);
			virtual int32_t JobDescriptionRow(void);
			virtual void JobDescriptionRow(int32_t value);
			virtual int32_t NoteRow(void);
			virtual void NoteRow(int32_t value);
			virtual int64_t LastModifiedTime(void);
			virtual bool ParseErrorOccurred(void);
			virtual EParseError ParseErrors(void);
			virtual void ParseErrors(EParseError value);
			virtual std::shared_ptr<Array_float> NFUnderRangeLimitsRms(void);
			virtual void NFUnderRangeLimitsRms(std::shared_ptr<Array_float> value);
			virtual std::shared_ptr<Array_float> NFUnderRangeLimitsPeak(void);
			virtual void NFUnderRangeLimitsPeak(std::shared_ptr<Array_float> value);
			virtual std::shared_ptr<Array_float> NFUnderNoiseFloor(void);
			virtual void NFUnderNoiseFloor(std::shared_ptr<Array_float> value);
			virtual std::shared_ptr<Array_float> UnderRangeLimitsOctave(void);
			virtual void UnderRangeLimitsOctave(std::shared_ptr<Array_float> value);
			virtual std::shared_ptr<Array_float> UnderRangeLimitsThirdOctave(void);
			virtual void UnderRangeLimitsThirdOctave(std::shared_ptr<Array_float> value);
			virtual std::shared_ptr<Array_float> NoiseFloorOctave(void);
			virtual void NoiseFloorOctave(std::shared_ptr<Array_float> value);
			virtual std::shared_ptr<Array_float> NoiseFloorThirdOctave(void);
			virtual void NoiseFloorThirdOctave(std::shared_ptr<Array_float> value);
			virtual float NFOverload(void);
			virtual void NFOverload(float value);
			virtual bool TmsEnabled(void);
			virtual EMeterType MeterType(void);
			virtual void MeterType(EMeterType value);
			virtual uint32_t PurOptions(void);
			virtual void PurOptions(uint32_t value);
			virtual std::shared_ptr<SPTBInfo_t> PTBInfo(void);
			virtual void PTBInfo(std::shared_ptr<SPTBInfo_t> value);
			virtual StringWrapper PreampName(void);
			virtual void PreampName(StringWrapper value);
			virtual uint32_t SequenceId(void);
			virtual void SequenceId(uint32_t value);
			virtual StringWrapper UniqueFileId(void);
			virtual void UniqueFileId(StringWrapper value);
#ifdef MAKEDLL
		public: // This is for internal use
			ILDRecord(){};
			ILDRecord(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _ILDRECORD_H
