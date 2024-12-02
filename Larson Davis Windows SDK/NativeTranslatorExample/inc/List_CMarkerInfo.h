/**************************************************************************//**
 * @file List_CMarkerInfo.h
 * @brief Native Wrapper for Managed type List<LarsonDavis::SDK::LDCommonStd::MetaData::MarkerInfo^>.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _LIST_CMARKER_INFO_H
#define _LIST_CMARKER_INFO_H
#include <IList_CMarkerInfo.h>
#include <IList.h>
#include <CMarkerInfo.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI IList_CMarkerInfo;
		class LDAPI IList;
		class LDAPI CMarkerInfo;
		class LDAPI IComparer_CMarkerInfo;
		class LDAPI Array_CMarkerInfo;

		class LDAPI List_CMarkerInfo : public virtual IList_CMarkerInfo, public virtual IList
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			List_CMarkerInfo(const List_CMarkerInfo& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~List_CMarkerInfo(void);
			void Add(std::shared_ptr<CMarkerInfo> item);
			int32_t BinarySearch(int32_t index, int32_t count, std::shared_ptr<CMarkerInfo> item, std::shared_ptr<IComparer_CMarkerInfo> comparer);
			int32_t BinarySearch(std::shared_ptr<CMarkerInfo> item);
			int32_t BinarySearch(std::shared_ptr<CMarkerInfo> item, std::shared_ptr<IComparer_CMarkerInfo> comparer);
			void Clear(void);
			bool Contains(std::shared_ptr<CMarkerInfo> item);
			void CopyTo(std::shared_ptr<Array_CMarkerInfo> array);
			void CopyTo(int32_t index, std::shared_ptr<Array_CMarkerInfo> array, int32_t arrayIndex, int32_t count);
			void CopyTo(std::shared_ptr<Array_CMarkerInfo> array, int32_t arrayIndex);
			std::shared_ptr<List_CMarkerInfo> GetRange(int32_t index, int32_t count);
			int32_t IndexOf(std::shared_ptr<CMarkerInfo> item);
			int32_t IndexOf(std::shared_ptr<CMarkerInfo> item, int32_t index);
			int32_t IndexOf(std::shared_ptr<CMarkerInfo> item, int32_t index, int32_t count);
			void Insert(int32_t index, std::shared_ptr<CMarkerInfo> item);
			int32_t LastIndexOf(std::shared_ptr<CMarkerInfo> item);
			int32_t LastIndexOf(std::shared_ptr<CMarkerInfo> item, int32_t index);
			int32_t LastIndexOf(std::shared_ptr<CMarkerInfo> item, int32_t index, int32_t count);
			bool Remove(std::shared_ptr<CMarkerInfo> item);
			void RemoveAt(int32_t index);
			void RemoveRange(int32_t index, int32_t count);
			void Reverse(void);
			void Reverse(int32_t index, int32_t count);
			void Sort(void);
			void Sort(std::shared_ptr<IComparer_CMarkerInfo> comparer);
			void Sort(int32_t index, int32_t count, std::shared_ptr<IComparer_CMarkerInfo> comparer);
			std::shared_ptr<Array_CMarkerInfo> ToArray(void);
			void TrimExcess(void);
			List_CMarkerInfo(void);
			List_CMarkerInfo(int32_t capacity);
			int32_t Capacity(void);
			void Capacity(int32_t value);
			int32_t Count(void);
			std::shared_ptr<CMarkerInfo> Item(int32_t index);
			void Item(int32_t index, std::shared_ptr<CMarkerInfo> value);
#ifdef MAKEDLL
		public: // This is for internal use
			List_CMarkerInfo(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _LIST_CMARKER_INFO_H
