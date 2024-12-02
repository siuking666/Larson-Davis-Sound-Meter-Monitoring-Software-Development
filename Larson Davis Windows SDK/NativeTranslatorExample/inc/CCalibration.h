/**************************************************************************//**
 * @file CCalibration.h
 * @brief Native Wrapper for Managed type Calibration.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _CCALIBRATION_H
#define _CCALIBRATION_H
#include <ECalibrationType.h>
#include <EPreampType.h>
namespace LarsonDavis
{
	namespace Native
	{
		struct LDAPI SDateTime;
		struct LDAPI SCalData2_t;
		class LDAPI Array_float;

		class LDAPI CCalibration
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			CCalibration(const CCalibration& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~CCalibration(void);
			std::shared_ptr<SDateTime> GetCalDateTime(void);
			StringWrapper GetCalDateTimeString(void);
			StringWrapper GetCalDateTimeString(StringWrapper dateFormat);
			float GetCalOffset(void);
			CCalibration(void);
			CCalibration(ECalibrationType calType, StringWrapper name, StringWrapper model, StringWrapper serial, std::shared_ptr<SCalData2_t> calData, float level, bool sessionLog = false);
			ECalibrationType CalibrationType(void);
			void CalibrationType(ECalibrationType value);
			EPreampType PreampType(void);
			void PreampType(EPreampType value);
			StringWrapper PreampName(void);
			void PreampName(StringWrapper value);
			StringWrapper MeterModel(void);
			void MeterModel(StringWrapper value);
			StringWrapper SerialNumber(void);
			void SerialNumber(StringWrapper value);
			uint32_t CalibrationDate(void);
			void CalibrationDate(uint32_t value);
			float CalibrationScale(void);
			void CalibrationScale(float value);
			float CalibrationLevel(void);
			void CalibrationLevel(float value);
			float CalibrationOffset(void);
			void CalibrationOffset(float value);
			float Deviation(void);
			void Deviation(float value);
			int32_t Bins(void);
			void Bins(int32_t value);
			std::shared_ptr<Array_float> SpectralData(void);
			void SpectralData(std::shared_ptr<Array_float> value);
			bool SpectralDataAvailable(void);
			bool SessionLog(void);
			void SessionLog(bool value);
			StringWrapper CalibrationDateStr(void);
			StringWrapper CalibrationDateShortStr(void);
			StringWrapper CalibrationScaleStr(void);
			StringWrapper CalibrationLevelStr(void);
			StringWrapper CalibrationOffsetStr(void);
			StringWrapper DeviationStr(void);
			StringWrapper ModelSerialKey(void);
			void ModelSerialKey(StringWrapper value);
#ifdef MAKEDLL
		public: // This is for internal use
			CCalibration(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _CCALIBRATION_H
