/**************************************************************************//**
 * @file Array_CMarkerInfo.h
 * @brief Native Wrapper for Managed type cli::array<LarsonDavis::SDK::LDCommonStd::MetaData::MarkerInfo^, 1>.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ARRAY_CMARKER_INFO_H
#define _ARRAY_CMARKER_INFO_H
#include <CArray.h>
#include <IList_CMarkerInfo.h>
#include <CMarkerInfo.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI CArray;
		class LDAPI IList_CMarkerInfo;
		class LDAPI CMarkerInfo;

		class LDAPI Array_CMarkerInfo : public CArray, public virtual IList_CMarkerInfo
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			Array_CMarkerInfo(const Array_CMarkerInfo& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~Array_CMarkerInfo(void);
			void Set(int32_t arg0, std::shared_ptr<CMarkerInfo> arg1);
			std::shared_ptr<CMarkerInfo> Get(int32_t arg0);
			Array_CMarkerInfo(int32_t arg0);
#ifdef MAKEDLL
		public: // This is for internal use
			Array_CMarkerInfo(){};
			Array_CMarkerInfo(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _ARRAY_CMARKER_INFO_H
