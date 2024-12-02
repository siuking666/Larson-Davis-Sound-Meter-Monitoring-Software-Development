/**************************************************************************//**
 * @file IEditBandInfo.h
 * @brief Native Wrapper for Managed type IEditBandInfo.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _IEDIT_BAND_INFO_H
#define _IEDIT_BAND_INFO_H
#include <EEditBandAction.h>
namespace LarsonDavis
{
	namespace Native
	{

		class LDAPI IEditBandInfo
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			IEditBandInfo(const IEditBandInfo& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~IEditBandInfo(void);
			virtual int32_t Id(void);
			virtual void Id(int32_t value);
			virtual EEditBandAction Action(void);
			virtual void Action(EEditBandAction value);
			virtual int32_t Begin(void);
			virtual void Begin(int32_t value);
			virtual int32_t End(void);
			virtual void End(int32_t value);
			virtual float Offset(void);
			virtual void Offset(float value);
#ifdef MAKEDLL
		public: // This is for internal use
			IEditBandInfo(){};
			IEditBandInfo(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _IEDIT_BAND_INFO_H
