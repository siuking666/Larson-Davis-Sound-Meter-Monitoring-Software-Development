/**************************************************************************//**
 * @file IList_CIntervalInfo.h
 * @brief Native Wrapper for Managed type IList<LarsonDavis::SDK::LDCommonStd::Legacy::IntervalInfo^>.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ILIST_CINTERVAL_INFO_H
#define _ILIST_CINTERVAL_INFO_H
#include <CIntervalInfo.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI CIntervalInfo;
		class LDAPI Array_int32_t;
		class LDAPI Array_float;
		class LDAPI Array_float_2;
		struct LDAPI SSpectraInfo_t;
		class LDAPI CMeasureRta;
		struct LDAPI SRtaRecord_t;
		struct LDAPI SRaHeader_t;
		struct LDAPI Sdegmin;
		struct LDAPI SWeatherData_t;
		struct LDAPI SOverload_t;
		class LDAPI Array_SEventCounts_t;
		struct LDAPI SEnvPreampData_t;

		class LDAPI IList_CIntervalInfo
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			IList_CIntervalInfo(const IList_CIntervalInfo& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~IList_CIntervalInfo(void);
			virtual int32_t IndexOf(std::shared_ptr<CIntervalInfo> item);
			virtual void Insert(int32_t index, std::shared_ptr<CIntervalInfo> item);
			virtual void RemoveAt(int32_t index);
			virtual std::shared_ptr<CIntervalInfo> Item(int32_t index);
			virtual void Item(int32_t index, std::shared_ptr<CIntervalInfo> value);
			virtual int32_t Count(void);
#ifdef MAKEDLL
		public: // This is for internal use
			IList_CIntervalInfo(){};
			IList_CIntervalInfo(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _ILIST_CINTERVAL_INFO_H
