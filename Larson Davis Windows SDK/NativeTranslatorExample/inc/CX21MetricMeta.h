/**************************************************************************//**
 * @file CX21MetricMeta.h
 * @brief Native Wrapper for Managed type X21MetricMeta.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _CX21_METRIC_META_H
#define _CX21_METRIC_META_H
#include <EMetricId.h>
namespace LarsonDavis
{
	namespace Native
	{

		class LDAPI CX21MetricMeta
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			CX21MetricMeta(const CX21MetricMeta& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~CX21MetricMeta(void);
			uint32_t Length(void);
			uint32_t Column(void);
			void Column(uint32_t value);
			StringWrapper Header(void);
			bool IsMetric(void);
			EMetricId Id(void);
			bool IsLinear(void);
			StringWrapper Units(void);
			uint32_t ColumnCount(void);
			void ColumnCount(uint32_t value);
			int32_t MetricListIndex(void);
			void MetricListIndex(int32_t value);
			bool Adjustable(void);
			void Adjustable(bool value);
#ifdef MAKEDLL
		public: // This is for internal use
			CX21MetricMeta(){};
			CX21MetricMeta(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _CX21_METRIC_META_H
