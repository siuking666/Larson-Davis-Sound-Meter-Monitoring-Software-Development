/**************************************************************************//**
 * @file IList_CChartInfo.h
 * @brief Native Wrapper for Managed type IList<LarsonDavis::SDK::LDCommonStd::MetaData::ChartInfo^>.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ILIST_CCHART_INFO_H
#define _ILIST_CCHART_INFO_H
#include <CChartInfo.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI CChartInfo;

		class LDAPI IList_CChartInfo
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			IList_CChartInfo(const IList_CChartInfo& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~IList_CChartInfo(void);
			virtual int32_t IndexOf(std::shared_ptr<CChartInfo> item);
			virtual void Insert(int32_t index, std::shared_ptr<CChartInfo> item);
			virtual void RemoveAt(int32_t index);
			virtual std::shared_ptr<CChartInfo> Item(int32_t index);
			virtual void Item(int32_t index, std::shared_ptr<CChartInfo> value);
			virtual int32_t Count(void);
#ifdef MAKEDLL
		public: // This is for internal use
			IList_CChartInfo(){};
			IList_CChartInfo(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _ILIST_CCHART_INFO_H
