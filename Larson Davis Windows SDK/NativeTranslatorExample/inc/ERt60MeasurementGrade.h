/**************************************************************************//**
 * @file ERt60MeasurementGrade.h
 * @brief Native Wrapper for Managed type Rt60MeasurementGrade.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ERT60_MEASUREMENT_GRADE_H
#define _ERT60_MEASUREMENT_GRADE_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class ERt60MeasurementGrade
		{
			Precision12x3 = 0,
			Precision36x1 = 1,
			Engineering6x2 = 2,
			Engineering12x1 = 3,
			Survey = 4,
			Unqualified = 5,
			InvalBand = 6,
			InvalFreq = 7,
			Unqualified3rdOctave12x1 = 8,
			Unqualified3rdOctave6x2 = 9,
			InvalFreq3rdOctave12x1 = 10,
			InvalFreq3rdOctave6x2 = 11,
			Max = 12,
		};
	}
}
#endif // _ERT60_MEASUREMENT_GRADE_H
