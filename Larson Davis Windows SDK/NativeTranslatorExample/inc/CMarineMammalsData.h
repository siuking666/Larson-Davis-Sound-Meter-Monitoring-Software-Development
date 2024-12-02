/**************************************************************************//**
 * @file CMarineMammalsData.h
 * @brief Native Wrapper for Managed type MarineMammalsData.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _CMARINE_MAMMALS_DATA_H
#define _CMARINE_MAMMALS_DATA_H
namespace LarsonDavis
{
	namespace Native
	{

		class LDAPI CMarineMammalsData
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			CMarineMammalsData(const CMarineMammalsData& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~CMarineMammalsData(void);
			CMarineMammalsData(double rms, double sel, double peak, double p90, double startTime, int32_t audioRecNum);
			double Rms(void);
			void Rms(double value);
			double Sel(void);
			void Sel(double value);
			double Peak(void);
			void Peak(double value);
			double P90(void);
			void P90(double value);
			double StartTime(void);
			void StartTime(double value);
			int32_t AudioRecordNum(void);
			void AudioRecordNum(int32_t value);
#ifdef MAKEDLL
		public: // This is for internal use
			CMarineMammalsData(){};
			CMarineMammalsData(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _CMARINE_MAMMALS_DATA_H
