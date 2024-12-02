/**************************************************************************//**
 * @file IChartInfo.h
 * @brief Native Wrapper for Managed type IChartInfo.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ICHART_INFO_H
#define _ICHART_INFO_H
namespace LarsonDavis
{
	namespace Native
	{

		class LDAPI IChartInfo
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			IChartInfo(const IChartInfo& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~IChartInfo(void);
#ifdef MAKEDLL
		public: // This is for internal use
			IChartInfo(){};
			IChartInfo(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _ICHART_INFO_H
