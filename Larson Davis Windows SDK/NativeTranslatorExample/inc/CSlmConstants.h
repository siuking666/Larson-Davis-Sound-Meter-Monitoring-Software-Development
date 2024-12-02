/**************************************************************************//**
 * @file CSlmConstants.h
 * @brief Native Wrapper for Managed type SlmConstants.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _CSLM_CONSTANTS_H
#define _CSLM_CONSTANTS_H
#include <EObaBandwidth.h>
#include <ELabelFormat.h>
#include <ERt60RecType.h>
namespace LarsonDavis
{
	namespace Native
	{
		struct LDAPI SRt60ColInfo_t;
		class LDAPI Array_SGenericLookup_t;
		class LDAPI Array_SGenericLookupFloat_t;
		class LDAPI Array_StringWrapper;
		class LDAPI Array_float;
		class LDAPI Array_SFilterFreqInfo_t;
		class LDAPI Array_SRt60ColInfo_t;
		class LDAPI Array_SRt60ColOrder_t;
		class LDAPI Array_SIsoGrades_t;

		class LDAPI CSlmConstants
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			CSlmConstants(const CSlmConstants& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~CSlmConstants(void);
			static StringWrapper GetObaFrequencyLabel(EObaBandwidth octave, int32_t ndx, ELabelFormat label = ELabelFormat::NoHz, bool localize = true, StringWrapper appendage = L"");
			static float GetObaFrequencyValue(EObaBandwidth octave, int32_t ndx);
			static std::shared_ptr<SRt60ColInfo_t> GetRt60ColumnInfo(ERt60RecType id);
			static int32_t GetGenericIntValue(std::shared_ptr<Array_SGenericLookup_t> stLookup, int32_t id);
			static float GetGenericFloatValue(std::shared_ptr<Array_SGenericLookupFloat_t> stLookup, int32_t id);
			static StringWrapper GetGenericStringValue(std::shared_ptr<Array_SGenericLookup_t> stLookup, int32_t id, bool localize = true);
			static StringWrapper GetGenericStringValue(std::shared_ptr<Array_SGenericLookupFloat_t> stLookup, int32_t id, bool localize = true);
			static int32_t FullOctave(void);
			static int32_t ThirdOctave(void);
			static int32_t DoseChannels(void);
			static int32_t SmsOutCount(void);
			static int32_t Magnitude4(void);
			static int32_t Magnitude5(void);
			static int32_t NumEventCounters(void);
			static int32_t NumCalibrators(void);
			static int32_t NumPreampTypes(void);
			static int32_t NumLns(void);
			static int32_t NumCommunityNoise(void);
			static int32_t NumMarkers(void);
			static int32_t NumUserFields(void);
			static int32_t CalTypes(void);
			static int32_t CalHists(void);
			static int32_t CalDefs(void);
			static int32_t WindDirStatsBins(void);
			static int32_t ProfileSize(void);
			static int32_t MaxStringSize(void);
			static int32_t Sz8(void);
			static int32_t Sz16(void);
			static int32_t Sz32(void);
			static int32_t Sz64(void);
			static int32_t Sz128(void);
			static int32_t Sz256(void);
			static int32_t Sz512(void);
			static int32_t NumStatBins(void);
			static int32_t NumLnStatBins(void);
			static int32_t MaxFileLength(void);
			static int32_t MaxSettingsFileLength(void);
			static int32_t MaxUserFileLength(void);
			static int32_t FileOverallTitleLength(void);
			static int32_t MaxStructVersion(void);
			static int32_t MaxFftLines(void);
			static int32_t MaxDecaysPerPosition(void);
			static int32_t NumRt60TimeSamples(void);
			static float Percent05(void);
			static float Percent10(void);
			static float Percent90(void);
			static float Percent95(void);
			static float Percent100(void);
			static float Permil05(void);
			static float Permil10(void);
			static float Permil05Raw(void);
			static float Permil10Raw(void);
			static float BtLowLimit(void);
			static float T20BkLowLimitdB(void);
			static float T30BkLowLimitdB(void);
			static float CoFairThreshold(void);
			static float CoGoodThreshold(void);
			static int32_t ChunkSize(void);
			static float MaxCalScale(void);
			static float FlashSD2MinVersion(void);
			static std::shared_ptr<Array_StringWrapper> ObaFrequency(void);
			static std::shared_ptr<Array_StringWrapper> ObaFrequencyHz(void);
			static std::shared_ptr<Array_StringWrapper> ObaFrequencyAbreviated(void);
			static std::shared_ptr<Array_StringWrapper> ObaFrequencyCmp(void);
			static std::shared_ptr<Array_StringWrapper> ObaFullOctaveNoHz(void);
			static std::shared_ptr<Array_StringWrapper> ObaThirdOctaveNoHz(void);
			static std::shared_ptr<Array_float> ObaFrequencyValues(void);
			static std::shared_ptr<Array_StringWrapper> Weights(void);
			static std::shared_ptr<Array_StringWrapper> Detectors(void);
			static std::shared_ptr<Array_StringWrapper> DetectorsLong(void);
			static std::shared_ptr<Array_StringWrapper> WindDirs(void);
			static std::shared_ptr<Array_StringWrapper> WindDirUnits(void);
			static std::shared_ptr<Array_StringWrapper> RICorrections(void);
			static std::shared_ptr<Array_SFilterFreqInfo_t> FullOctaveFilters(void);
			static std::shared_ptr<Array_SFilterFreqInfo_t> ThirdOctaveFilters(void);
			static std::shared_ptr<Array_SRt60ColInfo_t> Rt60Columns(void);
			static std::shared_ptr<Array_SRt60ColOrder_t> Rt60SumAll(void);
			static std::shared_ptr<Array_SRt60ColOrder_t> Rt60SumT20(void);
			static std::shared_ptr<Array_SRt60ColOrder_t> Rt60SumT30(void);
			static std::shared_ptr<Array_SIsoGrades_t> IsoGrades(void);
			static std::shared_ptr<Array_SGenericLookup_t> MaxRunTimeLookup(void);
			static std::shared_ptr<Array_SGenericLookupFloat_t> Rt60PeriodLookup(void);
			static std::shared_ptr<Array_SGenericLookupFloat_t> FftWindowLookup(void);
			static std::shared_ptr<Array_SGenericLookupFloat_t> FftToneSeekDeltaLookup(void);
			static std::shared_ptr<Array_SGenericLookupFloat_t> FftRegressionRangeLookup(void);
			static std::shared_ptr<Array_SGenericLookup_t> FftFreqSpanLookup(void);
			static std::shared_ptr<Array_SGenericLookup_t> FftLinesLookup(void);
			static std::shared_ptr<Array_SGenericLookup_t> FftRunModeLookup(void);
			static std::shared_ptr<Array_SGenericLookup_t> FftIntegrationMethodLookup(void);
			static std::shared_ptr<Array_SGenericLookup_t> MinFftCountLookup(void);
			static std::shared_ptr<Array_SGenericLookup_t> FftTonalityLookup(void);
			static std::shared_ptr<Array_SGenericLookup_t> SourceFrequency(void);
			static int32_t MaxUserFileNameLength_(void);
#ifdef MAKEDLL
		public: // This is for internal use
			CSlmConstants(){};
			CSlmConstants(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _CSLM_CONSTANTS_H
