/**************************************************************************//**
 * @file IComparer_CRt60DecayInfo.h
 * @brief Native Wrapper for Managed type IComparer<LarsonDavis::SDK::LDCommonStd::MetaData::Rt60DecayInfo^>.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ICOMPARER_CRT60_DECAY_INFO_H
#define _ICOMPARER_CRT60_DECAY_INFO_H
#include <CRt60DecayInfo.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI CRt60DecayInfo;

		class LDAPI IComparer_CRt60DecayInfo
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			IComparer_CRt60DecayInfo(const IComparer_CRt60DecayInfo& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~IComparer_CRt60DecayInfo(void);
			virtual int32_t Compare(std::shared_ptr<CRt60DecayInfo> x, std::shared_ptr<CRt60DecayInfo> y);
#ifdef MAKEDLL
		public: // This is for internal use
			IComparer_CRt60DecayInfo(){};
			IComparer_CRt60DecayInfo(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _ICOMPARER_CRT60_DECAY_INFO_H
