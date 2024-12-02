/**************************************************************************//**
 * @file List_float.h
 * @brief Native Wrapper for Managed type List<System::Single>.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _LIST_FLOAT_H
#define _LIST_FLOAT_H
#include <IList_float.h>
#include <IList.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI IList_float;
		class LDAPI IList;
		class LDAPI IComparer_float;
		class LDAPI Array_float;

		class LDAPI List_float : public virtual IList_float, public virtual IList
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			List_float(const List_float& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~List_float(void);
			void Add(float item);
			int32_t BinarySearch(int32_t index, int32_t count, float item, std::shared_ptr<IComparer_float> comparer);
			int32_t BinarySearch(float item);
			int32_t BinarySearch(float item, std::shared_ptr<IComparer_float> comparer);
			void Clear(void);
			bool Contains(float item);
			void CopyTo(std::shared_ptr<Array_float> array);
			void CopyTo(int32_t index, std::shared_ptr<Array_float> array, int32_t arrayIndex, int32_t count);
			void CopyTo(std::shared_ptr<Array_float> array, int32_t arrayIndex);
			std::shared_ptr<List_float> GetRange(int32_t index, int32_t count);
			int32_t IndexOf(float item);
			int32_t IndexOf(float item, int32_t index);
			int32_t IndexOf(float item, int32_t index, int32_t count);
			void Insert(int32_t index, float item);
			int32_t LastIndexOf(float item);
			int32_t LastIndexOf(float item, int32_t index);
			int32_t LastIndexOf(float item, int32_t index, int32_t count);
			bool Remove(float item);
			void RemoveAt(int32_t index);
			void RemoveRange(int32_t index, int32_t count);
			void Reverse(void);
			void Reverse(int32_t index, int32_t count);
			void Sort(void);
			void Sort(std::shared_ptr<IComparer_float> comparer);
			void Sort(int32_t index, int32_t count, std::shared_ptr<IComparer_float> comparer);
			std::shared_ptr<Array_float> ToArray(void);
			void TrimExcess(void);
			List_float(void);
			List_float(int32_t capacity);
			int32_t Capacity(void);
			void Capacity(int32_t value);
			int32_t Count(void);
			float Item(int32_t index);
			void Item(int32_t index, float value);
#ifdef MAKEDLL
		public: // This is for internal use
			List_float(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _LIST_FLOAT_H
