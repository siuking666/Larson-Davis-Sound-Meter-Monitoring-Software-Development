/**************************************************************************//**
 * @file CSpartanInterval.h
 * @brief Native Wrapper for Managed type SpartanInterval.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _CSPARTAN_INTERVAL_H
#define _CSPARTAN_INTERVAL_H
namespace LarsonDavis
{
	namespace Native
	{
		struct LDAPI SMeasHistSpartan_t;
		struct LDAPI SBlockHeaderSpartan_t;
		struct LDAPI SMeasAnyDataSpartan_t;
		struct LDAPI SBlockFooterSpartan_t;
		struct LDAPI SLnDataSpartan_t;
		class LDAPI Array_float;
		class LDAPI Array_float_2;
		class LDAPI Array_int64_t_2;
		class LDAPI Array_int64_t;
		struct LDAPI SOverloadSpartan_t;

		class LDAPI CSpartanInterval
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			CSpartanInterval(const CSpartanInterval& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~CSpartanInterval(void);
			CSpartanInterval(void);
			std::shared_ptr<SMeasHistSpartan_t> MeasHist(void);
			void MeasHist(std::shared_ptr<SMeasHistSpartan_t> value);
			uint32_t Flags(void);
			void Flags(uint32_t value);
			int64_t StartTime(void);
			void StartTime(int64_t value);
			float RunTime(void);
			void RunTime(float value);
			float PauseTime(void);
			void PauseTime(float value);
			int64_t EndTime(void);
			void EndTime(int64_t value);
			uint32_t SRNumber(void);
			void SRNumber(uint32_t value);
			std::shared_ptr<Array_float> Lweq(void);
			void Lweq(std::shared_ptr<Array_float> value);
			std::shared_ptr<Array_float> SEL(void);
			void SEL(std::shared_ptr<Array_float> value);
			std::shared_ptr<Array_float_2> Min(void);
			void Min(std::shared_ptr<Array_float_2> value);
			std::shared_ptr<Array_int64_t_2> MinTime(void);
			void MinTime(std::shared_ptr<Array_int64_t_2> value);
			std::shared_ptr<Array_float_2> Max(void);
			void Max(std::shared_ptr<Array_float_2> value);
			std::shared_ptr<Array_int64_t_2> MaxTime(void);
			void MaxTime(std::shared_ptr<Array_int64_t_2> value);
			std::shared_ptr<Array_float_2> Lwteq(void);
			void Lwteq(std::shared_ptr<Array_float_2> value);
			std::shared_ptr<Array_float> Peak(void);
			void Peak(std::shared_ptr<Array_float> value);
			std::shared_ptr<Array_int64_t> PeakTime(void);
			void PeakTime(std::shared_ptr<Array_int64_t> value);
			std::shared_ptr<Array_float> LnValues(void);
			void LnValues(std::shared_ptr<Array_float> value);
			std::shared_ptr<Array_float> TWA(void);
			void TWA(std::shared_ptr<Array_float> value);
			std::shared_ptr<Array_float> CurrentProfile(void);
			void CurrentProfile(std::shared_ptr<Array_float> value);
			int32_t NumOba(void);
			void NumOba(int32_t value);
			bool IsInitialized(void);
			void IsInitialized(bool value);
			std::shared_ptr<SOverloadSpartan_t> Overloads(void);
			void Overloads(std::shared_ptr<SOverloadSpartan_t> value);
#ifdef MAKEDLL
		public: // This is for internal use
			CSpartanInterval(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _CSPARTAN_INTERVAL_H
