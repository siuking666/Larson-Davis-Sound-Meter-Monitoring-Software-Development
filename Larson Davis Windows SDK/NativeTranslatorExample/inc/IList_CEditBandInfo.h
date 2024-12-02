/**************************************************************************//**
 * @file IList_CEditBandInfo.h
 * @brief Native Wrapper for Managed type IList<LarsonDavis::SDK::LDCommonStd::MetaData::EditBandInfo^>.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ILIST_CEDIT_BAND_INFO_H
#define _ILIST_CEDIT_BAND_INFO_H
#include <CEditBandInfo.h>
#include <EEditBandAction.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI CEditBandInfo;

		class LDAPI IList_CEditBandInfo
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			IList_CEditBandInfo(const IList_CEditBandInfo& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~IList_CEditBandInfo(void);
			virtual int32_t IndexOf(std::shared_ptr<CEditBandInfo> item);
			virtual void Insert(int32_t index, std::shared_ptr<CEditBandInfo> item);
			virtual void RemoveAt(int32_t index);
			virtual std::shared_ptr<CEditBandInfo> Item(int32_t index);
			virtual void Item(int32_t index, std::shared_ptr<CEditBandInfo> value);
			virtual int32_t Count(void);
#ifdef MAKEDLL
		public: // This is for internal use
			IList_CEditBandInfo(){};
			IList_CEditBandInfo(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _ILIST_CEDIT_BAND_INFO_H
