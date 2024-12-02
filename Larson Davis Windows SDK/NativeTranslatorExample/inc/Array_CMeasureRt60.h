/**************************************************************************//**
 * @file Array_CMeasureRt60.h
 * @brief Native Wrapper for Managed type cli::array<LarsonDavis::SDK::LDCommonStd::Legacy::MeasureRt60^, 1>.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ARRAY_CMEASURE_RT60_H
#define _ARRAY_CMEASURE_RT60_H
#include <CArray.h>
#include <IList_CMeasureRt60.h>
#include <CMeasureRt60.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI CArray;
		class LDAPI IList_CMeasureRt60;
		class LDAPI CMeasureRt60;

		class LDAPI Array_CMeasureRt60 : public CArray, public virtual IList_CMeasureRt60
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			Array_CMeasureRt60(const Array_CMeasureRt60& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~Array_CMeasureRt60(void);
			void Set(int32_t arg0, std::shared_ptr<CMeasureRt60> arg1);
			std::shared_ptr<CMeasureRt60> Get(int32_t arg0);
			Array_CMeasureRt60(int32_t arg0);
#ifdef MAKEDLL
		public: // This is for internal use
			Array_CMeasureRt60(){};
			Array_CMeasureRt60(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _ARRAY_CMEASURE_RT60_H
