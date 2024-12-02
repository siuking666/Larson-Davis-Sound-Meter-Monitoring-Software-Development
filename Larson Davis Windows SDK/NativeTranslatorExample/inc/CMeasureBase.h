/**************************************************************************//**
 * @file CMeasureBase.h
 * @brief Native Wrapper for Managed type MeasureBase.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _CMEASURE_BASE_H
#define _CMEASURE_BASE_H
#include <EMeasureType.h>
#include <EMeasureSubType.h>
namespace LarsonDavis
{
	namespace Native
	{

		class LDAPI CMeasureBase
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			CMeasureBase(const CMeasureBase& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~CMeasureBase(void);
			StringWrapper GetBandwidthAsString(void);
			CMeasureBase(void);
			int32_t Schema(void);
			void Schema(int32_t value);
			int32_t SubSchema(void);
			void SubSchema(int32_t value);
			StringWrapper Name(void);
			void Name(StringWrapper value);
			int32_t Id(void);
			void Id(int32_t value);
			EMeasureType Type(void);
			void Type(EMeasureType value);
			EMeasureSubType SubType(void);
			void SubType(EMeasureSubType value);
			uint32_t TotalCount(void);
			void TotalCount(uint32_t value);
			uint32_t AverageCount(void);
			void AverageCount(uint32_t value);
			uint32_t Positions(void);
			void Positions(uint32_t value);
			int32_t Bandwidth(void);
			void Bandwidth(int32_t value);
			bool IncludeInAvg(void);
			void IncludeInAvg(bool value);
#ifdef MAKEDLL
		public: // This is for internal use
			CMeasureBase(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _CMEASURE_BASE_H
