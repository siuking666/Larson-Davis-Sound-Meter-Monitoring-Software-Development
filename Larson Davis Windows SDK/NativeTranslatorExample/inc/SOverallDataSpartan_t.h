/**************************************************************************//**
 * @file SOverallDataSpartan_t.h
 * @brief Native Wrapper for Managed type OverallDataSpartan_t.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _SOVERALL_DATA_SPARTAN_T_H
#define _SOVERALL_DATA_SPARTAN_T_H
#include <ISupportByteArrayConversion.h>
#include <EPreampType.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI ISupportByteArrayConversion;
		class LDAPI Array_SDetectorTs_t;
		class LDAPI Array_STwa_t;

		struct LDAPI SOverallDataSpartan_t : public virtual ISupportByteArrayConversion
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			SOverallDataSpartan_t(const SOverallDataSpartan_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~SOverallDataSpartan_t(void);
			SOverallDataSpartan_t(void);
			std::shared_ptr<Array_SDetectorTs_t> detectors(void);
			void detectors(std::shared_ptr<Array_SDetectorTs_t> value);
			std::shared_ptr<Array_STwa_t> twa(void);
			void twa(std::shared_ptr<Array_STwa_t> value);
			uint32_t overallFlags(void);
			void overallFlags(uint32_t value);
			uint32_t startTime(void);
			void startTime(uint32_t value);
			uint32_t stopTime(void);
			void stopTime(uint32_t value);
			uint32_t overallCount(void);
			void overallCount(uint32_t value);
			uint32_t pauseCount(void);
			void pauseCount(uint32_t value);
			uint32_t overallMotionCount(void);
			void overallMotionCount(uint32_t value);
			uint32_t overallBumpCount(void);
			void overallBumpCount(uint32_t value);
			uint32_t overloadCount(void);
			void overloadCount(uint32_t value);
			uint32_t overloadDuration(void);
			void overloadDuration(uint32_t value);
			uint32_t startBattRunTimeEst(void);
			void startBattRunTimeEst(uint32_t value);
			uint32_t stopBattRunTimeEst(void);
			void stopBattRunTimeEst(uint32_t value);
			uint32_t numThEntries(void);
			void numThEntries(uint32_t value);
			uint32_t numMeasHistEntries(void);
			void numMeasHistEntries(uint32_t value);
			EPreampType preampType(void);
			void preampType(EPreampType value);
#ifdef MAKEDLL
		public: // This is for internal use
			SOverallDataSpartan_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _SOVERALL_DATA_SPARTAN_T_H
