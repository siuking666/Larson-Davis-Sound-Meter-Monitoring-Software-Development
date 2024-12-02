/**************************************************************************//**
 * @file IList_CToneInfo.h
 * @brief Native Wrapper for Managed type IList<LarsonDavis::SDK::LDCommonStd::Legacy::ToneInfo^>.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ILIST_CTONE_INFO_H
#define _ILIST_CTONE_INFO_H
#include <CToneInfo.h>
#include <EFftWindow.h>
#include <EWeightingNdx.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI CToneInfo;

		class LDAPI IList_CToneInfo
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			IList_CToneInfo(const IList_CToneInfo& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~IList_CToneInfo(void);
			virtual int32_t IndexOf(std::shared_ptr<CToneInfo> item);
			virtual void Insert(int32_t index, std::shared_ptr<CToneInfo> item);
			virtual void RemoveAt(int32_t index);
			virtual std::shared_ptr<CToneInfo> Item(int32_t index);
			virtual void Item(int32_t index, std::shared_ptr<CToneInfo> value);
			virtual int32_t Count(void);
#ifdef MAKEDLL
		public: // This is for internal use
			IList_CToneInfo(){};
			IList_CToneInfo(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _ILIST_CTONE_INFO_H
