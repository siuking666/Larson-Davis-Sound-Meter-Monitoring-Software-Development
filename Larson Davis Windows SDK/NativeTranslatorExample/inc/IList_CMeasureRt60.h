/**************************************************************************//**
 * @file IList_CMeasureRt60.h
 * @brief Native Wrapper for Managed type IList<LarsonDavis::SDK::LDCommonStd::Legacy::MeasureRt60^>.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ILIST_CMEASURE_RT60_H
#define _ILIST_CMEASURE_RT60_H
#include <CMeasureRt60.h>
#include <ERt60RecType.h>
#include <ERt60Method.h>
#include <ERt60QualityIndicator.h>
#include <ERt60SamplePeriod.h>
#include <ERt60DataPoint.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI CMeasureRt60;
		struct LDAPI SRt60ByTime_t;
		class LDAPI Array_SRt60TimeSample_t;
		class LDAPI Array_SRt60DataLimits_t;
		struct LDAPI SRt60CalcLines_t;
		struct LDAPI SRt60Record_t;

		class LDAPI IList_CMeasureRt60
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			IList_CMeasureRt60(const IList_CMeasureRt60& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~IList_CMeasureRt60(void);
			virtual int32_t IndexOf(std::shared_ptr<CMeasureRt60> item);
			virtual void Insert(int32_t index, std::shared_ptr<CMeasureRt60> item);
			virtual void RemoveAt(int32_t index);
			virtual std::shared_ptr<CMeasureRt60> Item(int32_t index);
			virtual void Item(int32_t index, std::shared_ptr<CMeasureRt60> value);
			virtual int32_t Count(void);
#ifdef MAKEDLL
		public: // This is for internal use
			IList_CMeasureRt60(){};
			IList_CMeasureRt60(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _ILIST_CMEASURE_RT60_H
