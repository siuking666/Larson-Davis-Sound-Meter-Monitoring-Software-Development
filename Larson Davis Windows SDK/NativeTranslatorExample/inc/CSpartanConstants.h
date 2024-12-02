/**************************************************************************//**
 * @file CSpartanConstants.h
 * @brief Native Wrapper for Managed type SpartanConstants.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _CSPARTAN_CONSTANTS_H
#define _CSPARTAN_CONSTANTS_H
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI Array_ESpartanFileBlock;

		class LDAPI CSpartanConstants
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			CSpartanConstants(const CSpartanConstants& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~CSpartanConstants(void);
			static int32_t NumManifestEntries(void);
			static int32_t MaxStructVersion(void);
			static int32_t MaxDosFilenameLen(void);
			static int32_t NumVirtDos(void);
			static int32_t DoseChannels(void);
			static int32_t NumWeightings(void);
			static int32_t NumDetectors(void);
			static int32_t NumLn(void);
			static float OverallUpdateTime(void);
			static int32_t OverallUpdatesPerSec(void);
			static int32_t NumExcd(void);
			static int32_t NumOba(void);
			static int32_t Num821OctaveBins(void);
			static int32_t Num821ThirdBins(void);
			static int32_t NumObaAllBins(void);
			static int32_t NumOptionsBanks(void);
			static int32_t ProfileGraphPoints(void);
			static int32_t RangeDataSize(void);
			static int32_t SpreadsheetDefaultLastColumn(void);
			static float OshaHcCriterionLevel(void);
			static StringWrapper ManifestString(void);
			static int32_t ManifestVersion(void);
			static int32_t OverallFileVersion(void);
			static int32_t Mx21OverallFileVersion(void);
			static int32_t M730OverallFileVersion(void);
			static int32_t ObaBands(void);
			static int32_t DeviceInfoVersion(void);
			static int32_t DeviceInfoVersion1(void);
			static int32_t SystemSettingsVersion3(void);
			static int32_t SystemSettingsVersion(void);
			static int32_t MeasSettingsVersion2(void);
			static int32_t MeasSettingsVersion(void);
			static int32_t OverallDataVersionV1(void);
			static int32_t OverallDataVersion(void);
			static int32_t ObaDataVersion1(void);
			static int32_t ObaDataVersion(void);
			static int32_t ExcdDataVersion(void);
			static int32_t LnDataVersion(void);
			static int32_t DailyDataVersion(void);
			static int32_t PrePostCalVersion(void);
			static int32_t ProfileDataVersion(void);
			static int32_t RangeDataVersion(void);
			static int32_t DeviceDescVersion(void);
			static int32_t MaxBumpSideSamples(void);
			static int32_t AgencyApprovalParserVersion(void);
			static int32_t SLogVersion(void);
			static int32_t THVersion(void);
			static int32_t Mx21THVersion(void);
			static int32_t NotesVersion(void);
			static int32_t SaxThreshold(void);
			static int32_t BumpCheckRowsToAverage(void);
			static int32_t BumpCheckMinDelta(void);
			static int32_t MeasHistVersionV2(void);
			static int32_t MeasHistAnyDataVersion(void);
			static int32_t MeasHistVersion(void);
			static uint32_t FirstMetricColumnOffset(void);
			static std::shared_ptr<Array_ESpartanFileBlock> M730ManifestSections(void);
			static void M730ManifestSections(std::shared_ptr<Array_ESpartanFileBlock> value);
			static std::shared_ptr<Array_ESpartanFileBlock> Mx21ManifestSections(void);
			static void Mx21ManifestSections(std::shared_ptr<Array_ESpartanFileBlock> value);
			static StringWrapper AllX21SettingsCommand(void);
			static StringWrapper AllSettingsCommand(void);
			static StringWrapper GetNotes(void);
			static StringWrapper AddNote(void);
			static StringWrapper GetMinStatus(void);
			static StringWrapper GetAboutInfo(void);
			static StringWrapper GetLiveData(void);
			static StringWrapper GetFileList(void);
			static StringWrapper GetModeCommand(void);
			static StringWrapper RunCommand(void);
			static StringWrapper StopCommand(void);
			static StringWrapper PauseCommand(void);
			static StringWrapper ManualCalibrate(void);
			static StringWrapper PowerOff(void);
			static StringWrapper LockScreen(void);
			static StringWrapper UnlockScreen(void);
			static StringWrapper RebootMeter(void);
			static StringWrapper ResetUSB(void);
			static StringWrapper ResetMeasCommand(void);
			static StringWrapper StoreCommand(void);
			static StringWrapper FormatRestore(void);
			static StringWrapper MassStorageMode(void);
			static StringWrapper DeleteFile(void);
			static StringWrapper DeleteAllFiles(void);
			static StringWrapper GetTHGraphData(void);
			static StringWrapper GetNumTHRecs(void);
			static StringWrapper EnterDfuCommand(void);
			static StringWrapper CalibrationDelta(void);
			static StringWrapper CalibrationLevel(void);
			static StringWrapper CalibrationHistory(void);
			static StringWrapper GetUnderrangeValues(void);
			static StringWrapper GetNoiseFloorValues(void);
			static StringWrapper GetPeakOverload(void);
			static StringWrapper CalHistoryNumberAndStored(void);
			static StringWrapper NumberStoredCalibrationRecords(void);
			static StringWrapper LastCalHistoryNumber(void);
			static StringWrapper AcceptCalibration(void);
			static StringWrapper AcceptCalibrationWarning(void);
			static StringWrapper GetSensitivity(void);
			static StringWrapper SetEpochTime(void);
			static uint8_t RangeOverloadInfoTag(void);
			static uint8_t RangeBbNoiseFloorInfoTag(void);
			static uint8_t RangeBbUnderrangeInfoTag(void);
			static uint8_t RangeObaUnderrangeInfoTag(void);
			static float NoiseFloorOffset(void);
			static int32_t CustomConfigValue(void);
#ifdef MAKEDLL
		public: // This is for internal use
			CSpartanConstants(){};
			CSpartanConstants(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _CSPARTAN_CONSTANTS_H
