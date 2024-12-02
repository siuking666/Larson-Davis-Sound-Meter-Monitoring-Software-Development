/**************************************************************************//**
 * @file IComparer_CMarkerInfo.h
 * @brief Native Wrapper for Managed type IComparer<LarsonDavis::SDK::LDCommonStd::MetaData::MarkerInfo^>.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ICOMPARER_CMARKER_INFO_H
#define _ICOMPARER_CMARKER_INFO_H
#include <CMarkerInfo.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI CMarkerInfo;

		class LDAPI IComparer_CMarkerInfo
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			IComparer_CMarkerInfo(const IComparer_CMarkerInfo& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~IComparer_CMarkerInfo(void);
			virtual int32_t Compare(std::shared_ptr<CMarkerInfo> x, std::shared_ptr<CMarkerInfo> y);
#ifdef MAKEDLL
		public: // This is for internal use
			IComparer_CMarkerInfo(){};
			IComparer_CMarkerInfo(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _ICOMPARER_CMARKER_INFO_H
