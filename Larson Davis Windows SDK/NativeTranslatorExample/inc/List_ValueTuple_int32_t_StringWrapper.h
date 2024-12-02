/**************************************************************************//**
 * @file List_ValueTuple_int32_t_StringWrapper.h
 * @brief Native Wrapper for Managed type List<System::ValueTuple<System::Int32, System::String^>>.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _LIST_VALUE_TUPLE_INT32_T_STRING_WRAPPER_H
#define _LIST_VALUE_TUPLE_INT32_T_STRING_WRAPPER_H
#include <IList_ValueTuple_int32_t_StringWrapper.h>
#include <IList.h>
#include <ValueTuple_int32_t_StringWrapper.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI IList_ValueTuple_int32_t_StringWrapper;
		class LDAPI IList;
		struct LDAPI ValueTuple_int32_t_StringWrapper;
		class LDAPI IComparer_ValueTuple_int32_t_StringWrapper;
		class LDAPI Array_ValueTuple_int32_t_StringWrapper;

		class LDAPI List_ValueTuple_int32_t_StringWrapper : public virtual IList_ValueTuple_int32_t_StringWrapper, public virtual IList
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			List_ValueTuple_int32_t_StringWrapper(const List_ValueTuple_int32_t_StringWrapper& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~List_ValueTuple_int32_t_StringWrapper(void);
			void Add(std::shared_ptr<ValueTuple_int32_t_StringWrapper> item);
			int32_t BinarySearch(int32_t index, int32_t count, std::shared_ptr<ValueTuple_int32_t_StringWrapper> item, std::shared_ptr<IComparer_ValueTuple_int32_t_StringWrapper> comparer);
			int32_t BinarySearch(std::shared_ptr<ValueTuple_int32_t_StringWrapper> item);
			int32_t BinarySearch(std::shared_ptr<ValueTuple_int32_t_StringWrapper> item, std::shared_ptr<IComparer_ValueTuple_int32_t_StringWrapper> comparer);
			void Clear(void);
			bool Contains(std::shared_ptr<ValueTuple_int32_t_StringWrapper> item);
			void CopyTo(std::shared_ptr<Array_ValueTuple_int32_t_StringWrapper> array);
			void CopyTo(int32_t index, std::shared_ptr<Array_ValueTuple_int32_t_StringWrapper> array, int32_t arrayIndex, int32_t count);
			void CopyTo(std::shared_ptr<Array_ValueTuple_int32_t_StringWrapper> array, int32_t arrayIndex);
			std::shared_ptr<List_ValueTuple_int32_t_StringWrapper> GetRange(int32_t index, int32_t count);
			int32_t IndexOf(std::shared_ptr<ValueTuple_int32_t_StringWrapper> item);
			int32_t IndexOf(std::shared_ptr<ValueTuple_int32_t_StringWrapper> item, int32_t index);
			int32_t IndexOf(std::shared_ptr<ValueTuple_int32_t_StringWrapper> item, int32_t index, int32_t count);
			void Insert(int32_t index, std::shared_ptr<ValueTuple_int32_t_StringWrapper> item);
			int32_t LastIndexOf(std::shared_ptr<ValueTuple_int32_t_StringWrapper> item);
			int32_t LastIndexOf(std::shared_ptr<ValueTuple_int32_t_StringWrapper> item, int32_t index);
			int32_t LastIndexOf(std::shared_ptr<ValueTuple_int32_t_StringWrapper> item, int32_t index, int32_t count);
			bool Remove(std::shared_ptr<ValueTuple_int32_t_StringWrapper> item);
			void RemoveAt(int32_t index);
			void RemoveRange(int32_t index, int32_t count);
			void Reverse(void);
			void Reverse(int32_t index, int32_t count);
			void Sort(void);
			void Sort(std::shared_ptr<IComparer_ValueTuple_int32_t_StringWrapper> comparer);
			void Sort(int32_t index, int32_t count, std::shared_ptr<IComparer_ValueTuple_int32_t_StringWrapper> comparer);
			std::shared_ptr<Array_ValueTuple_int32_t_StringWrapper> ToArray(void);
			void TrimExcess(void);
			List_ValueTuple_int32_t_StringWrapper(void);
			List_ValueTuple_int32_t_StringWrapper(int32_t capacity);
			int32_t Capacity(void);
			void Capacity(int32_t value);
			int32_t Count(void);
			std::shared_ptr<ValueTuple_int32_t_StringWrapper> Item(int32_t index);
			void Item(int32_t index, std::shared_ptr<ValueTuple_int32_t_StringWrapper> value);
#ifdef MAKEDLL
		public: // This is for internal use
			List_ValueTuple_int32_t_StringWrapper(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _LIST_VALUE_TUPLE_INT32_T_STRING_WRAPPER_H
