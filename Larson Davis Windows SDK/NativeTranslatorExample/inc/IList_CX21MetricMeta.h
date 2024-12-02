/**************************************************************************//**
 * @file IList_CX21MetricMeta.h
 * @brief Native Wrapper for Managed type IList<LarsonDavis::SDK::LDCommonStd::Core::X21MetricMeta^>.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ILIST_CX21_METRIC_META_H
#define _ILIST_CX21_METRIC_META_H
#include <CX21MetricMeta.h>
#include <EMetricId.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI CX21MetricMeta;

		class LDAPI IList_CX21MetricMeta
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			IList_CX21MetricMeta(const IList_CX21MetricMeta& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~IList_CX21MetricMeta(void);
			virtual int32_t IndexOf(std::shared_ptr<CX21MetricMeta> item);
			virtual void Insert(int32_t index, std::shared_ptr<CX21MetricMeta> item);
			virtual void RemoveAt(int32_t index);
			virtual std::shared_ptr<CX21MetricMeta> Item(int32_t index);
			virtual void Item(int32_t index, std::shared_ptr<CX21MetricMeta> value);
			virtual int32_t Count(void);
#ifdef MAKEDLL
		public: // This is for internal use
			IList_CX21MetricMeta(){};
			IList_CX21MetricMeta(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _ILIST_CX21_METRIC_META_H
