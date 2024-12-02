/**************************************************************************//**
 * @file SortedList_int32_t_CEditBandInfo.h
 * @brief Native Wrapper for Managed type SortedList<System::Int32, LarsonDavis::SDK::LDCommonStd::MetaData::EditBandInfo^>.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _SORTED_LIST_INT32_T_CEDIT_BAND_INFO_H
#define _SORTED_LIST_INT32_T_CEDIT_BAND_INFO_H
#include <IDictionary_int32_t_CEditBandInfo.h>
#include <IDictionary.h>
#include <CEditBandInfo.h>
#include <EEditBandAction.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI IDictionary_int32_t_CEditBandInfo;
		class LDAPI IDictionary;
		class LDAPI CEditBandInfo;
		class LDAPI IComparer_int32_t;
		class LDAPI IList_int32_t;
		class LDAPI IList_CEditBandInfo;

		class LDAPI SortedList_int32_t_CEditBandInfo : public virtual IDictionary_int32_t_CEditBandInfo, public virtual IDictionary
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			SortedList_int32_t_CEditBandInfo(const SortedList_int32_t_CEditBandInfo& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~SortedList_int32_t_CEditBandInfo(void);
			void Add(int32_t key, std::shared_ptr<CEditBandInfo> value);
			void Clear(void);
			bool ContainsKey(int32_t key);
			bool ContainsValue(std::shared_ptr<CEditBandInfo> value);
			int32_t IndexOfKey(int32_t key);
			int32_t IndexOfValue(std::shared_ptr<CEditBandInfo> value);
			bool TryGetValue(int32_t key, std::shared_ptr<CEditBandInfo>& value);
			void RemoveAt(int32_t index);
			bool Remove(int32_t key);
			void TrimExcess(void);
			SortedList_int32_t_CEditBandInfo(void);
			SortedList_int32_t_CEditBandInfo(int32_t capacity);
			SortedList_int32_t_CEditBandInfo(std::shared_ptr<IComparer_int32_t> comparer);
			SortedList_int32_t_CEditBandInfo(int32_t capacity, std::shared_ptr<IComparer_int32_t> comparer);
			SortedList_int32_t_CEditBandInfo(std::shared_ptr<IDictionary_int32_t_CEditBandInfo> dictionary);
			SortedList_int32_t_CEditBandInfo(std::shared_ptr<IDictionary_int32_t_CEditBandInfo> dictionary, std::shared_ptr<IComparer_int32_t> comparer);
			int32_t Capacity(void);
			void Capacity(int32_t value);
			std::shared_ptr<IComparer_int32_t> Comparer(void);
			int32_t Count(void);
			std::shared_ptr<IList_int32_t> Keys(void);
			std::shared_ptr<IList_CEditBandInfo> Values(void);
			std::shared_ptr<CEditBandInfo> Item(int32_t key);
			void Item(int32_t key, std::shared_ptr<CEditBandInfo> value);
#ifdef MAKEDLL
		public: // This is for internal use
			SortedList_int32_t_CEditBandInfo(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _SORTED_LIST_INT32_T_CEDIT_BAND_INFO_H
