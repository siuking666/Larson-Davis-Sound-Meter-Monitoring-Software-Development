/**************************************************************************//**
 * @file IList_int64_t.h
 * @brief Native Wrapper for Managed type IList<System::Int64>.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ILIST_INT64_T_H
#define _ILIST_INT64_T_H
namespace LarsonDavis
{
	namespace Native
	{

		class LDAPI IList_int64_t
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			IList_int64_t(const IList_int64_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~IList_int64_t(void);
			virtual int32_t IndexOf(int64_t item);
			virtual void Insert(int32_t index, int64_t item);
			virtual void RemoveAt(int32_t index);
			virtual int64_t Item(int32_t index);
			virtual void Item(int32_t index, int64_t value);
			virtual int32_t Count(void);
#ifdef MAKEDLL
		public: // This is for internal use
			IList_int64_t(){};
			IList_int64_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _ILIST_INT64_T_H
