/**************************************************************************//**
 * @file List_IConvertible.h
 * @brief Native Wrapper for Managed type List<System::IConvertible^>.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _LIST_ICONVERTIBLE_H
#define _LIST_ICONVERTIBLE_H
#include <IList_IConvertible.h>
#include <IList.h>
#include <IConvertible.h>
#include <ETypeCode.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI IList_IConvertible;
		class LDAPI IList;
		class LDAPI IConvertible;
		class LDAPI IComparer_IConvertible;
		class LDAPI Array_IConvertible;

		class LDAPI List_IConvertible : public virtual IList_IConvertible, public virtual IList
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			List_IConvertible(const List_IConvertible& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~List_IConvertible(void);
			void Add(std::shared_ptr<IConvertible> item);
			int32_t BinarySearch(int32_t index, int32_t count, std::shared_ptr<IConvertible> item, std::shared_ptr<IComparer_IConvertible> comparer);
			int32_t BinarySearch(std::shared_ptr<IConvertible> item);
			int32_t BinarySearch(std::shared_ptr<IConvertible> item, std::shared_ptr<IComparer_IConvertible> comparer);
			void Clear(void);
			bool Contains(std::shared_ptr<IConvertible> item);
			void CopyTo(std::shared_ptr<Array_IConvertible> array);
			void CopyTo(int32_t index, std::shared_ptr<Array_IConvertible> array, int32_t arrayIndex, int32_t count);
			void CopyTo(std::shared_ptr<Array_IConvertible> array, int32_t arrayIndex);
			std::shared_ptr<List_IConvertible> GetRange(int32_t index, int32_t count);
			int32_t IndexOf(std::shared_ptr<IConvertible> item);
			int32_t IndexOf(std::shared_ptr<IConvertible> item, int32_t index);
			int32_t IndexOf(std::shared_ptr<IConvertible> item, int32_t index, int32_t count);
			void Insert(int32_t index, std::shared_ptr<IConvertible> item);
			int32_t LastIndexOf(std::shared_ptr<IConvertible> item);
			int32_t LastIndexOf(std::shared_ptr<IConvertible> item, int32_t index);
			int32_t LastIndexOf(std::shared_ptr<IConvertible> item, int32_t index, int32_t count);
			bool Remove(std::shared_ptr<IConvertible> item);
			void RemoveAt(int32_t index);
			void RemoveRange(int32_t index, int32_t count);
			void Reverse(void);
			void Reverse(int32_t index, int32_t count);
			void Sort(void);
			void Sort(std::shared_ptr<IComparer_IConvertible> comparer);
			void Sort(int32_t index, int32_t count, std::shared_ptr<IComparer_IConvertible> comparer);
			std::shared_ptr<Array_IConvertible> ToArray(void);
			void TrimExcess(void);
			List_IConvertible(void);
			List_IConvertible(int32_t capacity);
			int32_t Capacity(void);
			void Capacity(int32_t value);
			int32_t Count(void);
			std::shared_ptr<IConvertible> Item(int32_t index);
			void Item(int32_t index, std::shared_ptr<IConvertible> value);
#ifdef MAKEDLL
		public: // This is for internal use
			List_IConvertible(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _LIST_ICONVERTIBLE_H
