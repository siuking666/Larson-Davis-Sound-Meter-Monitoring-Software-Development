/**************************************************************************//**
 * @file SIsoGrades_t.h
 * @brief Native Wrapper for Managed type IsoGrades_t.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _SISO_GRADES_T_H
#define _SISO_GRADES_T_H
#include <ERt60MeasurementGrade.h>
#include <EFrequency.h>
namespace LarsonDavis
{
	namespace Native
	{

		struct LDAPI SIsoGrades_t
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			SIsoGrades_t(const SIsoGrades_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~SIsoGrades_t(void);
			SIsoGrades_t(void);
			ERt60MeasurementGrade id(void);
			void id(ERt60MeasurementGrade value);
			StringWrapper str(void);
			void str(StringWrapper value);
			int32_t srcMicPos(void);
			void srcMicPos(int32_t value);
			int32_t srcPos(void);
			void srcPos(int32_t value);
			int32_t micPos(void);
			void micPos(int32_t value);
			int32_t decays(void);
			void decays(int32_t value);
			EFrequency loOctave(void);
			void loOctave(EFrequency value);
			EFrequency hiOctave(void);
			void hiOctave(EFrequency value);
			EFrequency loThird(void);
			void loThird(EFrequency value);
			EFrequency hiThird(void);
			void hiThird(EFrequency value);
#ifdef MAKEDLL
		public: // This is for internal use
			SIsoGrades_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _SISO_GRADES_T_H
