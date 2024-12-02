/**************************************************************************//**
 * @file CToneInfo.h
 * @brief Native Wrapper for Managed type ToneInfo.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _CTONE_INFO_H
#define _CTONE_INFO_H
#include <EFftWindow.h>
#include <EWeightingNdx.h>
namespace LarsonDavis
{
	namespace Native
	{

		class LDAPI CToneInfo
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			CToneInfo(const CToneInfo& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~CToneInfo(void);
			void SetQualityIndicators(EFftWindow window, EWeightingNdx weight, float duration);
			float GetRegressionLineLevel(int32_t index, float slope, float intercept);
			float GetCriticalBandLevel(float toneLevel);
			CToneInfo(void);
			int32_t ToneNum(void);
			void ToneNum(int32_t value);
			float ToneFreq(void);
			void ToneFreq(float value);
			float ToneLevel(void);
			void ToneLevel(float value);
			float MaskingNoise(void);
			void MaskingNoise(float value);
			float CriticalBw(void);
			void CriticalBw(float value);
			float Audibility(void);
			void Audibility(float value);
			float Adjustment(void);
			void Adjustment(float value);
			float Bw3dB(void);
			void Bw3dB(float value);
			float BwEff(void);
			void BwEff(float value);
			bool Is3dBBwOk(void);
			void Is3dBBwOk(bool value);
			bool IsEffBwOk(void);
			void IsEffBwOk(bool value);
			bool IsRegLineValid(void);
			void IsRegLineValid(bool value);
			float RegLineStart(void);
			void RegLineStart(float value);
			float RegLineEnd(void);
			void RegLineEnd(float value);
			float Slope(void);
			void Slope(float value);
			float Intercept(void);
			void Intercept(float value);
			int32_t ToneIndex(void);
			void ToneIndex(int32_t value);
			float CritBandStart(void);
			void CritBandStart(float value);
			float CritBandEnd(void);
			void CritBandEnd(float value);
			bool GoodToneBw(void);
			void GoodToneBw(bool value);
			bool GoodBEffBw(void);
			void GoodBEffBw(bool value);
			bool GoodRegLine(void);
			void GoodRegLine(bool value);
			bool GoodTime(void);
			void GoodTime(bool value);
			bool GoodWindow(void);
			void GoodWindow(bool value);
			bool GoodWeight(void);
			void GoodWeight(bool value);
			bool AllGood(void);
			void AllGood(bool value);
			bool IsOverall(void);
			void IsOverall(bool value);
			float Uncertainty(void);
			void Uncertainty(float value);
			uint32_t Consolidated(void);
			void Consolidated(uint32_t value);
			float LevelCB(void);
			void LevelCB(float value);
#ifdef MAKEDLL
		public: // This is for internal use
			CToneInfo(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _CTONE_INFO_H
