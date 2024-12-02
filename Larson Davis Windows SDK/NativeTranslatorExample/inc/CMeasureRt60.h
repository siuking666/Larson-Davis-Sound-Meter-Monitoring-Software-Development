/**************************************************************************//**
 * @file CMeasureRt60.h
 * @brief Native Wrapper for Managed type MeasureRt60.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _CMEASURE_RT60_H
#define _CMEASURE_RT60_H
#include <CMeasureBase.h>
#include <ERt60RecType.h>
#include <ERt60Method.h>
#include <ERt60QualityIndicator.h>
#include <ERt60SamplePeriod.h>
#include <ERt60DataPoint.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI CMeasureBase;
		struct LDAPI SRt60ByTime_t;
		class LDAPI Array_SRt60TimeSample_t;
		class LDAPI Array_SRt60DataLimits_t;
		struct LDAPI SRt60CalcLines_t;
		struct LDAPI SRt60Record_t;

		class LDAPI CMeasureRt60 : public CMeasureBase
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			CMeasureRt60(const CMeasureRt60& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~CMeasureRt60(void);
			void SetMaxBins(void);
			float GetData(ERt60RecType id, int32_t bin, ERt60Method method);
			StringWrapper GetDataAsString(ERt60RecType id, int32_t bin, ERt60Method method);
			void SetQualityIndicators(ERt60Method method);
			ERt60QualityIndicator GetQualityIndicator(ERt60RecType id, int32_t bin, ERt60Method method);
			int32_t GetDecaysPerPosition(int32_t ndx);
			int32_t UpdateDecaysPerPosition(int32_t ndx, uint8_t mod);
			float GetSamplePeriod(ERt60SamplePeriod period);
			StringWrapper GetSamplePeriodString(ERt60SamplePeriod period, bool addUnits = true);
			float GetSampleTime(ERt60SamplePeriod period, int32_t ndx);
			float GetSampleData(int32_t ndx, int32_t bin);
			int32_t GetDataPoint(ERt60DataPoint id, int32_t bin);
			void InitByTimeAverage(void);
			CMeasureRt60(void);
			std::shared_ptr<SRt60ByTime_t> Rt60ByTime(void);
			void Rt60ByTime(std::shared_ptr<SRt60ByTime_t> value);
			std::shared_ptr<SRt60CalcLines_t> Rt60CalcLines(void);
			void Rt60CalcLines(std::shared_ptr<SRt60CalcLines_t> value);
			uint16_t Position(void);
			void Position(uint16_t value);
			int32_t SampleCount(void);
			void SampleCount(int32_t value);
			int32_t MaxBins(void);
			bool QualityIndicatorsSet(void);
			void QualityIndicatorsSet(bool value);
			bool ByTimeAverageInitialized(void);
			void ByTimeAverageInitialized(bool value);
			std::shared_ptr<SRt60Record_t> Rt60(void);
			void Rt60(std::shared_ptr<SRt60Record_t> value);
#ifdef MAKEDLL
		public: // This is for internal use
			CMeasureRt60(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _CMEASURE_RT60_H
