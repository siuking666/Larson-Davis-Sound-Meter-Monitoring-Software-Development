/**************************************************************************//**
 * @file Array_CRt60DecayInfo.h
 * @brief Native Wrapper for Managed type cli::array<LarsonDavis::SDK::LDCommonStd::MetaData::Rt60DecayInfo^, 1>.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ARRAY_CRT60_DECAY_INFO_H
#define _ARRAY_CRT60_DECAY_INFO_H
#include <CArray.h>
#include <IList_CRt60DecayInfo.h>
#include <CRt60DecayInfo.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI CArray;
		class LDAPI IList_CRt60DecayInfo;
		class LDAPI CRt60DecayInfo;

		class LDAPI Array_CRt60DecayInfo : public CArray, public virtual IList_CRt60DecayInfo
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			Array_CRt60DecayInfo(const Array_CRt60DecayInfo& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~Array_CRt60DecayInfo(void);
			void Set(int32_t arg0, std::shared_ptr<CRt60DecayInfo> arg1);
			std::shared_ptr<CRt60DecayInfo> Get(int32_t arg0);
			Array_CRt60DecayInfo(int32_t arg0);
#ifdef MAKEDLL
		public: // This is for internal use
			Array_CRt60DecayInfo(){};
			Array_CRt60DecayInfo(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _ARRAY_CRT60_DECAY_INFO_H
