/**************************************************************************//**
 * @file CMeasureFft.h
 * @brief Native Wrapper for Managed type MeasureFft.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _CMEASURE_FFT_H
#define _CMEASURE_FFT_H
#include <CMeasureBase.h>
#include <EFftLevel.h>
#include <EVsqConvert.h>
#include <EFftFrequencySpan.h>
#include <EFftLines.h>
#include <EFftWindow.h>
#include <EFftRunMode.h>
#include <EWeightingNdx.h>
#include <EFftTonalityStandard.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI CMeasureBase;
		struct LDAPI SFftRecord_t;
		struct LDAPI SFftInfo_t;
		struct LDAPI SFftLevels_t;
		struct LDAPI SFftTriggerInfo_t;
		class LDAPI IList_CToneInfo;
		class LDAPI CToneInfo;

		class LDAPI CMeasureFft : public CMeasureBase
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			CMeasureFft(const CMeasureFft& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~CMeasureFft(void);
			void InitLevelArrays(void);
			void InitLevelArrays(uint32_t siz);
			float GetData(EFftLevel levelId, int32_t ndx, EVsqConvert convert);
			StringWrapper GetDataAsString(EFftLevel levelId, int32_t ndx, EVsqConvert convert);
			float GetLeq(EVsqConvert convert);
			float GetLpeak(EVsqConvert convert);
			int32_t GetFrequencySpan(void);
			int32_t GetFrequencySpan(EFftFrequencySpan band);
			int32_t GetNumLines(void);
			int32_t GetNumLines(EFftLines lines);
			float GetResolution(void);
			StringWrapper GetWindowAsString(void);
			StringWrapper GetWindowAsString(EFftWindow window);
			StringWrapper GetRunModeAsString(EFftRunMode mode);
			StringWrapper GetIntegrationMethodAsString(int32_t integrationMethod);
			CMeasureFft(void);
			std::shared_ptr<SFftRecord_t> Fft(void);
			void Fft(std::shared_ptr<SFftRecord_t> value);
			std::shared_ptr<SFftTriggerInfo_t> TriggerInfo(void);
			void TriggerInfo(std::shared_ptr<SFftTriggerInfo_t> value);
			std::shared_ptr<IList_CToneInfo> ToneInfo(void);
			void ToneInfo(std::shared_ptr<IList_CToneInfo> value);
			uint32_t Flags(void);
			void Flags(uint32_t value);
			uint32_t StartTimeSeconds(void);
			void StartTimeSeconds(uint32_t value);
			uint32_t StartTimeMicro(void);
			void StartTimeMicro(uint32_t value);
			float Duration(void);
			void Duration(float value);
			int32_t FftCount(void);
			void FftCount(int32_t value);
			int32_t OverloadCount(void);
			void OverloadCount(int32_t value);
			float OverloadDuration(void);
			void OverloadDuration(float value);
			float Leq(void);
			void Leq(float value);
			float Lpeak(void);
			void Lpeak(float value);
			uint32_t ArraySize(void);
			void ArraySize(uint32_t value);
			EFftFrequencySpan FrequencySpan(void);
			void FrequencySpan(EFftFrequencySpan value);
			EFftLines NumLines(void);
			void NumLines(EFftLines value);
			EFftWindow Window(void);
			void Window(EFftWindow value);
			EFftTonalityStandard TonalityStandard(void);
			void TonalityStandard(EFftTonalityStandard value);
			float ToneSeekDelta(void);
			void ToneSeekDelta(float value);
			float RegressionRange(void);
			void RegressionRange(float value);
			bool TonalityIsSet(void);
			void TonalityIsSet(bool value);
#ifdef MAKEDLL
		public: // This is for internal use
			CMeasureFft(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _CMEASURE_FFT_H
