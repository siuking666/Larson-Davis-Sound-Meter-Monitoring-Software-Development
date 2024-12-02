/**************************************************************************//**
 * @file CArray.h
 * @brief Native Wrapper for Managed type Array.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _CARRAY_H
#define _CARRAY_H
#include <IList.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI IList;
		class LDAPI IComparer;

		class LDAPI CArray : public virtual IList
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			CArray(const CArray& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~CArray(void);
			static void Copy(std::shared_ptr<CArray> sourceArray, std::shared_ptr<CArray> destinationArray, int32_t length);
			static void Copy(std::shared_ptr<CArray> sourceArray, int32_t sourceIndex, std::shared_ptr<CArray> destinationArray, int32_t destinationIndex, int32_t length);
			static void ConstrainedCopy(std::shared_ptr<CArray> sourceArray, int32_t sourceIndex, std::shared_ptr<CArray> destinationArray, int32_t destinationIndex, int32_t length);
			static void Copy(std::shared_ptr<CArray> sourceArray, std::shared_ptr<CArray> destinationArray, int64_t length);
			static void Copy(std::shared_ptr<CArray> sourceArray, int64_t sourceIndex, std::shared_ptr<CArray> destinationArray, int64_t destinationIndex, int64_t length);
			int64_t GetLongLength(int32_t dimension);
			void CopyTo(std::shared_ptr<CArray> array, int32_t index);
			void CopyTo(std::shared_ptr<CArray> array, int64_t index);
			static void Reverse(std::shared_ptr<CArray> array);
			static void Sort(std::shared_ptr<CArray> array);
			static void Sort(std::shared_ptr<CArray> keys, std::shared_ptr<CArray> items);
			static void Sort(std::shared_ptr<CArray> array, int32_t index, int32_t length);
			static void Sort(std::shared_ptr<CArray> keys, std::shared_ptr<CArray> items, int32_t index, int32_t length);
			static void Sort(std::shared_ptr<CArray> array, std::shared_ptr<IComparer> comparer);
			static void Sort(std::shared_ptr<CArray> keys, std::shared_ptr<CArray> items, std::shared_ptr<IComparer> comparer);
			static void Sort(std::shared_ptr<CArray> array, int32_t index, int32_t length, std::shared_ptr<IComparer> comparer);
			void Initialize(void);
			static void Clear(std::shared_ptr<CArray> array, int32_t index, int32_t length);
			int32_t GetLength(int32_t dimension);
			int32_t GetUpperBound(int32_t dimension);
			int32_t GetLowerBound(int32_t dimension);
			static void Reverse(std::shared_ptr<CArray> array, int32_t index, int32_t length);
			static void Sort(std::shared_ptr<CArray> keys, std::shared_ptr<CArray> items, int32_t index, int32_t length, std::shared_ptr<IComparer> comparer);
			int32_t Length(void);
			int64_t LongLength(void);
			int32_t Rank(void);
			bool IsReadOnly(void);
			bool IsFixedSize(void);
			bool IsSynchronized(void);
#ifdef MAKEDLL
		public: // This is for internal use
			CArray(){};
			CArray(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _CARRAY_H
