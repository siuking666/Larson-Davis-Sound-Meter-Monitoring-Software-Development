/**************************************************************************//**
 * @file CPartition.h
 * @brief Native Wrapper for Managed type Partition.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _CPARTITION_H
#define _CPARTITION_H
#include <EPartitionType.h>
#include <ERt60RecType.h>
#include <ERt60Method.h>
#include <ERt60QualityIndicator.h>
#include <ERt60SamplePeriod.h>
#include <ERt60DataPoint.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI CRoomRx;
		class LDAPI CMeasureRt60;
		struct LDAPI SRt60ByTime_t;
		class LDAPI Array_SRt60TimeSample_t;
		class LDAPI Array_SRt60DataLimits_t;
		struct LDAPI SRt60CalcLines_t;
		struct LDAPI SRt60Record_t;
		class LDAPI CMeasureRta;
		struct LDAPI SRtaRecord_t;
		struct LDAPI SRaHeader_t;
		class LDAPI Array_float;
		class LDAPI Array_CMeasureRt60;
		class LDAPI CRoomTx;

		class LDAPI CPartition
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			CPartition(const CPartition& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~CPartition(void);
			CPartition(void);
			StringWrapper Name(void);
			void Name(StringWrapper value);
			int32_t Id(void);
			void Id(int32_t value);
			EPartitionType Type(void);
			void Type(EPartitionType value);
			std::shared_ptr<CRoomRx> Rx(void);
			void Rx(std::shared_ptr<CRoomRx> value);
			std::shared_ptr<CRoomTx> Tx(void);
			void Tx(std::shared_ptr<CRoomTx> value);
#ifdef MAKEDLL
		public: // This is for internal use
			CPartition(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _CPARTITION_H
