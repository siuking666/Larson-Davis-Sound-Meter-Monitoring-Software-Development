/**************************************************************************//**
 * @file IList_SIsoGrades_t.h
 * @brief Native Wrapper for Managed type IList<LarsonDavis::SDK::LDCommonStd::Legacy::IsoGrades_t>.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ILIST_SISO_GRADES_T_H
#define _ILIST_SISO_GRADES_T_H
#include <SIsoGrades_t.h>
#include <ERt60MeasurementGrade.h>
#include <EFrequency.h>
namespace LarsonDavis
{
	namespace Native
	{
		struct LDAPI SIsoGrades_t;

		class LDAPI IList_SIsoGrades_t
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			IList_SIsoGrades_t(const IList_SIsoGrades_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~IList_SIsoGrades_t(void);
			virtual int32_t IndexOf(std::shared_ptr<SIsoGrades_t> item);
			virtual void Insert(int32_t index, std::shared_ptr<SIsoGrades_t> item);
			virtual void RemoveAt(int32_t index);
			virtual std::shared_ptr<SIsoGrades_t> Item(int32_t index);
			virtual void Item(int32_t index, std::shared_ptr<SIsoGrades_t> value);
			virtual int32_t Count(void);
#ifdef MAKEDLL
		public: // This is for internal use
			IList_SIsoGrades_t(){};
			IList_SIsoGrades_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _ILIST_SISO_GRADES_T_H
