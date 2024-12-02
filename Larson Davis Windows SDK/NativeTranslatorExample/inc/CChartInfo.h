/**************************************************************************//**
 * @file CChartInfo.h
 * @brief Native Wrapper for Managed type ChartInfo.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _CCHART_INFO_H
#define _CCHART_INFO_H
#include <IChartInfo.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI IChartInfo;

		class LDAPI CChartInfo : public virtual IChartInfo
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			CChartInfo(const CChartInfo& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~CChartInfo(void);
#ifdef MAKEDLL
		public: // This is for internal use
			CChartInfo(){};
			CChartInfo(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _CCHART_INFO_H
