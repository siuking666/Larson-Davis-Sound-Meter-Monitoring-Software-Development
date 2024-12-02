/**************************************************************************//**
 * @file List_CMarineMammalsData.h
 * @brief Native Wrapper for Managed type List<LarsonDavis::SDK::LDCommonStd::Utilities::MarineMammalsData^>.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _LIST_CMARINE_MAMMALS_DATA_H
#define _LIST_CMARINE_MAMMALS_DATA_H
#include <IList_CMarineMammalsData.h>
#include <IList.h>
#include <CMarineMammalsData.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI IList_CMarineMammalsData;
		class LDAPI IList;
		class LDAPI CMarineMammalsData;
		class LDAPI IComparer_CMarineMammalsData;
		class LDAPI Array_CMarineMammalsData;

		class LDAPI List_CMarineMammalsData : public virtual IList_CMarineMammalsData, public virtual IList
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			List_CMarineMammalsData(const List_CMarineMammalsData& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~List_CMarineMammalsData(void);
			void Add(std::shared_ptr<CMarineMammalsData> item);
			int32_t BinarySearch(int32_t index, int32_t count, std::shared_ptr<CMarineMammalsData> item, std::shared_ptr<IComparer_CMarineMammalsData> comparer);
			int32_t BinarySearch(std::shared_ptr<CMarineMammalsData> item);
			int32_t BinarySearch(std::shared_ptr<CMarineMammalsData> item, std::shared_ptr<IComparer_CMarineMammalsData> comparer);
			void Clear(void);
			bool Contains(std::shared_ptr<CMarineMammalsData> item);
			void CopyTo(std::shared_ptr<Array_CMarineMammalsData> array);
			void CopyTo(int32_t index, std::shared_ptr<Array_CMarineMammalsData> array, int32_t arrayIndex, int32_t count);
			void CopyTo(std::shared_ptr<Array_CMarineMammalsData> array, int32_t arrayIndex);
			std::shared_ptr<List_CMarineMammalsData> GetRange(int32_t index, int32_t count);
			int32_t IndexOf(std::shared_ptr<CMarineMammalsData> item);
			int32_t IndexOf(std::shared_ptr<CMarineMammalsData> item, int32_t index);
			int32_t IndexOf(std::shared_ptr<CMarineMammalsData> item, int32_t index, int32_t count);
			void Insert(int32_t index, std::shared_ptr<CMarineMammalsData> item);
			int32_t LastIndexOf(std::shared_ptr<CMarineMammalsData> item);
			int32_t LastIndexOf(std::shared_ptr<CMarineMammalsData> item, int32_t index);
			int32_t LastIndexOf(std::shared_ptr<CMarineMammalsData> item, int32_t index, int32_t count);
			bool Remove(std::shared_ptr<CMarineMammalsData> item);
			void RemoveAt(int32_t index);
			void RemoveRange(int32_t index, int32_t count);
			void Reverse(void);
			void Reverse(int32_t index, int32_t count);
			void Sort(void);
			void Sort(std::shared_ptr<IComparer_CMarineMammalsData> comparer);
			void Sort(int32_t index, int32_t count, std::shared_ptr<IComparer_CMarineMammalsData> comparer);
			std::shared_ptr<Array_CMarineMammalsData> ToArray(void);
			void TrimExcess(void);
			List_CMarineMammalsData(void);
			List_CMarineMammalsData(int32_t capacity);
			int32_t Capacity(void);
			void Capacity(int32_t value);
			int32_t Count(void);
			std::shared_ptr<CMarineMammalsData> Item(int32_t index);
			void Item(int32_t index, std::shared_ptr<CMarineMammalsData> value);
#ifdef MAKEDLL
		public: // This is for internal use
			List_CMarineMammalsData(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _LIST_CMARINE_MAMMALS_DATA_H
