/**************************************************************************//**
 * @file IList_CRt60DecayInfo.h
 * @brief Native Wrapper for Managed type IList<LarsonDavis::SDK::LDCommonStd::MetaData::Rt60DecayInfo^>.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ILIST_CRT60_DECAY_INFO_H
#define _ILIST_CRT60_DECAY_INFO_H
#include <CRt60DecayInfo.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI CRt60DecayInfo;

		class LDAPI IList_CRt60DecayInfo
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			IList_CRt60DecayInfo(const IList_CRt60DecayInfo& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~IList_CRt60DecayInfo(void);
			virtual int32_t IndexOf(std::shared_ptr<CRt60DecayInfo> item);
			virtual void Insert(int32_t index, std::shared_ptr<CRt60DecayInfo> item);
			virtual void RemoveAt(int32_t index);
			virtual std::shared_ptr<CRt60DecayInfo> Item(int32_t index);
			virtual void Item(int32_t index, std::shared_ptr<CRt60DecayInfo> value);
			virtual int32_t Count(void);
#ifdef MAKEDLL
		public: // This is for internal use
			IList_CRt60DecayInfo(){};
			IList_CRt60DecayInfo(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _ILIST_CRT60_DECAY_INFO_H
