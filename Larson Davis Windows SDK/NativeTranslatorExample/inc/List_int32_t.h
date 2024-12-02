/**************************************************************************//**
 * @file List_int32_t.h
 * @brief Native Wrapper for Managed type List<System::Int32>.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _LIST_INT32_T_H
#define _LIST_INT32_T_H
#include <IList_int32_t.h>
#include <IList.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI IList_int32_t;
		class LDAPI IList;
		class LDAPI IComparer_int32_t;
		class LDAPI Array_int32_t;

		class LDAPI List_int32_t : public virtual IList_int32_t, public virtual IList
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			List_int32_t(const List_int32_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~List_int32_t(void);
			void Add(int32_t item);
			int32_t BinarySearch(int32_t index, int32_t count, int32_t item, std::shared_ptr<IComparer_int32_t> comparer);
			int32_t BinarySearch(int32_t item);
			int32_t BinarySearch(int32_t item, std::shared_ptr<IComparer_int32_t> comparer);
			void Clear(void);
			bool Contains(int32_t item);
			void CopyTo(std::shared_ptr<Array_int32_t> array);
			void CopyTo(int32_t index, std::shared_ptr<Array_int32_t> array, int32_t arrayIndex, int32_t count);
			void CopyTo(std::shared_ptr<Array_int32_t> array, int32_t arrayIndex);
			std::shared_ptr<List_int32_t> GetRange(int32_t index, int32_t count);
			int32_t IndexOf(int32_t item);
			int32_t IndexOf(int32_t item, int32_t index);
			int32_t IndexOf(int32_t item, int32_t index, int32_t count);
			void Insert(int32_t index, int32_t item);
			int32_t LastIndexOf(int32_t item);
			int32_t LastIndexOf(int32_t item, int32_t index);
			int32_t LastIndexOf(int32_t item, int32_t index, int32_t count);
			bool Remove(int32_t item);
			void RemoveAt(int32_t index);
			void RemoveRange(int32_t index, int32_t count);
			void Reverse(void);
			void Reverse(int32_t index, int32_t count);
			void Sort(void);
			void Sort(std::shared_ptr<IComparer_int32_t> comparer);
			void Sort(int32_t index, int32_t count, std::shared_ptr<IComparer_int32_t> comparer);
			std::shared_ptr<Array_int32_t> ToArray(void);
			void TrimExcess(void);
			List_int32_t(void);
			List_int32_t(int32_t capacity);
			int32_t Capacity(void);
			void Capacity(int32_t value);
			int32_t Count(void);
			int32_t Item(int32_t index);
			void Item(int32_t index, int32_t value);
#ifdef MAKEDLL
		public: // This is for internal use
			List_int32_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _LIST_INT32_T_H
