/**************************************************************************//**
 * @file IList_SstTHItemInfo_t.h
 * @brief Native Wrapper for Managed type IList<LarsonDavis::SDK::LDCommonStd::Legacy::stTHItemInfo_t>.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ILIST_SST_THITEM_INFO_T_H
#define _ILIST_SST_THITEM_INFO_T_H
#include <SstTHItemInfo_t.h>
#include <ETHOptionId.h>
#include <ETHOptionType.h>
#include <EUnitType.h>
namespace LarsonDavis
{
	namespace Native
	{
		struct LDAPI SstTHItemInfo_t;

		class LDAPI IList_SstTHItemInfo_t
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			IList_SstTHItemInfo_t(const IList_SstTHItemInfo_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~IList_SstTHItemInfo_t(void);
			virtual int32_t IndexOf(std::shared_ptr<SstTHItemInfo_t> item);
			virtual void Insert(int32_t index, std::shared_ptr<SstTHItemInfo_t> item);
			virtual void RemoveAt(int32_t index);
			virtual std::shared_ptr<SstTHItemInfo_t> Item(int32_t index);
			virtual void Item(int32_t index, std::shared_ptr<SstTHItemInfo_t> value);
			virtual int32_t Count(void);
#ifdef MAKEDLL
		public: // This is for internal use
			IList_SstTHItemInfo_t(){};
			IList_SstTHItemInfo_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _ILIST_SST_THITEM_INFO_T_H
