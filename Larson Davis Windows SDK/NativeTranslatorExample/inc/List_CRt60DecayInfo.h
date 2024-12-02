/**************************************************************************//**
 * @file List_CRt60DecayInfo.h
 * @brief Native Wrapper for Managed type List<LarsonDavis::SDK::LDCommonStd::MetaData::Rt60DecayInfo^>.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _LIST_CRT60_DECAY_INFO_H
#define _LIST_CRT60_DECAY_INFO_H
#include <IList_CRt60DecayInfo.h>
#include <IList.h>
#include <CRt60DecayInfo.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI IList_CRt60DecayInfo;
		class LDAPI IList;
		class LDAPI CRt60DecayInfo;
		class LDAPI IComparer_CRt60DecayInfo;
		class LDAPI Array_CRt60DecayInfo;

		class LDAPI List_CRt60DecayInfo : public virtual IList_CRt60DecayInfo, public virtual IList
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			List_CRt60DecayInfo(const List_CRt60DecayInfo& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~List_CRt60DecayInfo(void);
			void Add(std::shared_ptr<CRt60DecayInfo> item);
			int32_t BinarySearch(int32_t index, int32_t count, std::shared_ptr<CRt60DecayInfo> item, std::shared_ptr<IComparer_CRt60DecayInfo> comparer);
			int32_t BinarySearch(std::shared_ptr<CRt60DecayInfo> item);
			int32_t BinarySearch(std::shared_ptr<CRt60DecayInfo> item, std::shared_ptr<IComparer_CRt60DecayInfo> comparer);
			void Clear(void);
			bool Contains(std::shared_ptr<CRt60DecayInfo> item);
			void CopyTo(std::shared_ptr<Array_CRt60DecayInfo> array);
			void CopyTo(int32_t index, std::shared_ptr<Array_CRt60DecayInfo> array, int32_t arrayIndex, int32_t count);
			void CopyTo(std::shared_ptr<Array_CRt60DecayInfo> array, int32_t arrayIndex);
			std::shared_ptr<List_CRt60DecayInfo> GetRange(int32_t index, int32_t count);
			int32_t IndexOf(std::shared_ptr<CRt60DecayInfo> item);
			int32_t IndexOf(std::shared_ptr<CRt60DecayInfo> item, int32_t index);
			int32_t IndexOf(std::shared_ptr<CRt60DecayInfo> item, int32_t index, int32_t count);
			void Insert(int32_t index, std::shared_ptr<CRt60DecayInfo> item);
			int32_t LastIndexOf(std::shared_ptr<CRt60DecayInfo> item);
			int32_t LastIndexOf(std::shared_ptr<CRt60DecayInfo> item, int32_t index);
			int32_t LastIndexOf(std::shared_ptr<CRt60DecayInfo> item, int32_t index, int32_t count);
			bool Remove(std::shared_ptr<CRt60DecayInfo> item);
			void RemoveAt(int32_t index);
			void RemoveRange(int32_t index, int32_t count);
			void Reverse(void);
			void Reverse(int32_t index, int32_t count);
			void Sort(void);
			void Sort(std::shared_ptr<IComparer_CRt60DecayInfo> comparer);
			void Sort(int32_t index, int32_t count, std::shared_ptr<IComparer_CRt60DecayInfo> comparer);
			std::shared_ptr<Array_CRt60DecayInfo> ToArray(void);
			void TrimExcess(void);
			List_CRt60DecayInfo(void);
			List_CRt60DecayInfo(int32_t capacity);
			int32_t Capacity(void);
			void Capacity(int32_t value);
			int32_t Count(void);
			std::shared_ptr<CRt60DecayInfo> Item(int32_t index);
			void Item(int32_t index, std::shared_ptr<CRt60DecayInfo> value);
#ifdef MAKEDLL
		public: // This is for internal use
			List_CRt60DecayInfo(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _LIST_CRT60_DECAY_INFO_H
