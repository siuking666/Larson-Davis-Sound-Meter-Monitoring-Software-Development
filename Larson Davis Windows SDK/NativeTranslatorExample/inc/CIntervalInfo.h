/**************************************************************************//**
 * @file CIntervalInfo.h
 * @brief Native Wrapper for Managed type IntervalInfo.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _CINTERVAL_INFO_H
#define _CINTERVAL_INFO_H
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI Array_int32_t;
		class LDAPI Array_float;
		class LDAPI Array_float_2;
		struct LDAPI SSpectraInfo_t;
		class LDAPI CMeasureRta;
		struct LDAPI SRtaRecord_t;
		struct LDAPI SRaHeader_t;
		struct LDAPI Sdegmin;
		struct LDAPI SWeatherData_t;
		struct LDAPI SOverload_t;
		class LDAPI Array_SEventCounts_t;
		struct LDAPI SEnvPreampData_t;

		class LDAPI CIntervalInfo
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			CIntervalInfo(const CIntervalInfo& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~CIntervalInfo(void);
			CIntervalInfo(void);
			int64_t StartTime(void);
			void StartTime(int64_t value);
			int64_t EndTime(void);
			void EndTime(int64_t value);
			int64_t PeakMaxTime(void);
			void PeakMaxTime(int64_t value);
			int64_t MaxTime(void);
			void MaxTime(int64_t value);
			int64_t MinTime(void);
			void MinTime(int64_t value);
			std::shared_ptr<Array_int32_t> LnTable(void);
			void LnTable(std::shared_ptr<Array_int32_t> value);
			int32_t NumOba(void);
			void NumOba(int32_t value);
			uint32_t SRNumber(void);
			void SRNumber(uint32_t value);
			float RunTime(void);
			void RunTime(float value);
			float Leq(void);
			void Leq(float value);
			float LCeq(void);
			void LCeq(float value);
			float LAeq(void);
			void LAeq(float value);
			float SEL(void);
			void SEL(float value);
			float Max(void);
			void Max(float value);
			float Peak(void);
			void Peak(float value);
			float Min(void);
			void Min(float value);
			float SEA(void);
			void SEA(float value);
			float LTm5(void);
			void LTm5(float value);
			float PauseTime(void);
			void PauseTime(float value);
			float LwIeq(void);
			void LwIeq(float value);
			float Lweq(void);
			void Lweq(float value);
			std::shared_ptr<Array_float> LnValues(void);
			void LnValues(std::shared_ptr<Array_float> value);
			std::shared_ptr<Array_float> LnPercents(void);
			void LnPercents(std::shared_ptr<Array_float> value);
			std::shared_ptr<Array_float> TWA(void);
			void TWA(std::shared_ptr<Array_float> value);
			std::shared_ptr<Array_float> CurrentProfile(void);
			void CurrentProfile(std::shared_ptr<Array_float> value);
			std::shared_ptr<Array_float_2> SpectralLn(void);
			void SpectralLn(std::shared_ptr<Array_float_2> value);
			float Altitude(void);
			void Altitude(float value);
			std::shared_ptr<SSpectraInfo_t> FullOctaveSpectra(void);
			void FullOctaveSpectra(std::shared_ptr<SSpectraInfo_t> value);
			std::shared_ptr<SSpectraInfo_t> ThirdOctaveSpectra(void);
			void ThirdOctaveSpectra(std::shared_ptr<SSpectraInfo_t> value);
			uint32_t Flags(void);
			void Flags(uint32_t value);
			std::shared_ptr<CMeasureRta> Rta(void);
			void Rta(std::shared_ptr<CMeasureRta> value);
			std::shared_ptr<Sdegmin> Latitude(void);
			void Latitude(std::shared_ptr<Sdegmin> value);
			std::shared_ptr<Sdegmin> Longitude(void);
			void Longitude(std::shared_ptr<Sdegmin> value);
			uint16_t GpsFlags(void);
			void GpsFlags(uint16_t value);
			std::shared_ptr<SWeatherData_t> Weather(void);
			void Weather(std::shared_ptr<SWeatherData_t> value);
			std::shared_ptr<SOverload_t> CurrentOverloads(void);
			void CurrentOverloads(std::shared_ptr<SOverload_t> value);
			std::shared_ptr<Array_SEventCounts_t> ExceedCnts(void);
			void ExceedCnts(std::shared_ptr<Array_SEventCounts_t> value);
			std::shared_ptr<SEnvPreampData_t> P426A12Data(void);
			void P426A12Data(std::shared_ptr<SEnvPreampData_t> value);
#ifdef MAKEDLL
		public: // This is for internal use
			CIntervalInfo(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _CINTERVAL_INFO_H
