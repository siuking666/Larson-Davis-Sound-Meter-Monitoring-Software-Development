/**************************************************************************//**
 * @file CMarineMammalsSummaryData.h
 * @brief Native Wrapper for Managed type MarineMammalsSummaryData.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _CMARINE_MAMMALS_SUMMARY_DATA_H
#define _CMARINE_MAMMALS_SUMMARY_DATA_H
namespace LarsonDavis
{
	namespace Native
	{

		class LDAPI CMarineMammalsSummaryData
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			CMarineMammalsSummaryData(const CMarineMammalsSummaryData& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~CMarineMammalsSummaryData(void);
			CMarineMammalsSummaryData(void);
			double RmsMax(void);
			void RmsMax(double value);
			double RmsMean(void);
			void RmsMean(double value);
			double RmsMed(void);
			void RmsMed(double value);
			double SelMax(void);
			void SelMax(double value);
			double SelMean(void);
			void SelMean(double value);
			double SelMed(void);
			void SelMed(double value);
			double PeakMax(void);
			void PeakMax(double value);
			double PeakMean(void);
			void PeakMean(double value);
			double PeakMed(void);
			void PeakMed(double value);
			double P90Max(void);
			void P90Max(double value);
			double P90Mean(void);
			void P90Mean(double value);
			double P90Med(void);
			void P90Med(double value);
			double MammalsCumSEL(void);
			void MammalsCumSEL(double value);
			double FishCumSEL(void);
			void FishCumSEL(double value);
			double MammalSelSummation(void);
			void MammalSelSummation(double value);
			double FishSelSummation(void);
			void FishSelSummation(double value);
			int32_t Count(void);
			void Count(int32_t value);
			int32_t MarineColumn(void);
			void MarineColumn(int32_t value);
			int32_t SummaryWorksheetRow(void);
			void SummaryWorksheetRow(int32_t value);
			int32_t EventTriggerLevel(void);
			void EventTriggerLevel(int32_t value);
			int32_t PrePeakTime(void);
			void PrePeakTime(int32_t value);
			int32_t PostPeakTime(void);
			void PostPeakTime(int32_t value);
#ifdef MAKEDLL
		public: // This is for internal use
			CMarineMammalsSummaryData(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _CMARINE_MAMMALS_SUMMARY_DATA_H
