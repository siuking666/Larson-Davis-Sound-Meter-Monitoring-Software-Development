/**************************************************************************//**
 * @file CLDRecordBase.h
 * @brief Native Wrapper for Managed type LDRecordBase.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _CLDRECORD_BASE_H
#define _CLDRECORD_BASE_H
#include <CReactiveObservableBase.h>
#include <ILDRecord.h>
#include <EParseError.h>
#include <EMeterType.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI CReactiveObservableBase;
		class LDAPI ILDRecord;
		class LDAPI CCalibration;
		class LDAPI Array_float;
		struct LDAPI SPTBInfo_t;

		class LDAPI CLDRecordBase : public CReactiveObservableBase, public virtual ILDRecord
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			CLDRecordBase(const CLDRecordBase& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~CLDRecordBase(void);
			int64_t GetTimeHistoryTimestamp(int32_t entryNum);
			StringWrapper GetMetricType(void);
			float GetMetricValue(void);
			StringWrapper GetDesiredMetricSetting(void);
			StringWrapper GetFullModelString(void);
			void SetPreampName(void);
			StringWrapper GetMicrophoneInfo(void);
			std::shared_ptr<CCalibration> GetPreCalData(bool skipSessionLog = false);
			StringWrapper DataFileName(void);
			void DataFileName(StringWrapper value);
			StringWrapper Model(void);
			void Model(StringWrapper value);
			StringWrapper SerialNumber(void);
			void SerialNumber(StringWrapper value);
			StringWrapper FwVersion(void);
			void FwVersion(StringWrapper value);
			StringWrapper HwVersion(void);
			void HwVersion(StringWrapper value);
			StringWrapper User(void);
			void User(StringWrapper value);
			StringWrapper Location(void);
			void Location(StringWrapper value);
			StringWrapper JobDescription(void);
			void JobDescription(StringWrapper value);
			StringWrapper Note(void);
			void Note(StringWrapper value);
			StringWrapper FilePath(void);
			void FilePath(StringWrapper value);
			int64_t FileSize(void);
			void FileSize(int64_t value);
			StringWrapper Metric1Type(void);
			void Metric1Type(StringWrapper value);
			float Metric1Level(void);
			void Metric1Level(float value);
			uint32_t StartTimeSeconds(void);
			void StartTimeSeconds(uint32_t value);
			uint32_t RunTimeSeconds(void);
			void RunTimeSeconds(uint32_t value);
			int32_t NumEvents(void);
			void NumEvents(int32_t value);
			int32_t NumOverloads(void);
			void NumOverloads(int32_t value);
			int32_t UserRow(void);
			void UserRow(int32_t value);
			int32_t LocationRow(void);
			void LocationRow(int32_t value);
			int32_t JobDescriptionRow(void);
			void JobDescriptionRow(int32_t value);
			int32_t NoteRow(void);
			void NoteRow(int32_t value);
			bool ParseErrorOccurred(void);
			EParseError ParseErrors(void);
			void ParseErrors(EParseError value);
			int64_t LastModifiedTime(void);
			void LastModifiedTime(int64_t value);
			std::shared_ptr<Array_float> NFUnderRangeLimitsRms(void);
			void NFUnderRangeLimitsRms(std::shared_ptr<Array_float> value);
			std::shared_ptr<Array_float> NFUnderRangeLimitsPeak(void);
			void NFUnderRangeLimitsPeak(std::shared_ptr<Array_float> value);
			std::shared_ptr<Array_float> NFUnderNoiseFloor(void);
			void NFUnderNoiseFloor(std::shared_ptr<Array_float> value);
			std::shared_ptr<Array_float> UnderRangeLimitsOctave(void);
			void UnderRangeLimitsOctave(std::shared_ptr<Array_float> value);
			std::shared_ptr<Array_float> UnderRangeLimitsThirdOctave(void);
			void UnderRangeLimitsThirdOctave(std::shared_ptr<Array_float> value);
			std::shared_ptr<Array_float> NoiseFloorOctave(void);
			void NoiseFloorOctave(std::shared_ptr<Array_float> value);
			std::shared_ptr<Array_float> NoiseFloorThirdOctave(void);
			void NoiseFloorThirdOctave(std::shared_ptr<Array_float> value);
			float NFOverload(void);
			void NFOverload(float value);
			bool TmsEnabled(void);
			EMeterType MeterType(void);
			void MeterType(EMeterType value);
			uint32_t PurOptions(void);
			void PurOptions(uint32_t value);
			std::shared_ptr<SPTBInfo_t> PTBInfo(void);
			void PTBInfo(std::shared_ptr<SPTBInfo_t> value);
			StringWrapper PreampName(void);
			void PreampName(StringWrapper value);
			uint32_t SequenceId(void);
			void SequenceId(uint32_t value);
			StringWrapper UniqueFileId(void);
			void UniqueFileId(StringWrapper value);
#ifdef MAKEDLL
		public: // This is for internal use
			CLDRecordBase(){};
			CLDRecordBase(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _CLDRECORD_BASE_H
