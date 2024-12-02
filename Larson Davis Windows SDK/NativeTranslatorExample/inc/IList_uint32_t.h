/**************************************************************************//**
 * @file IList_uint32_t.h
 * @brief Native Wrapper for Managed type IList<System::UInt32>.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ILIST_UINT32_T_H
#define _ILIST_UINT32_T_H
namespace LarsonDavis
{
	namespace Native
	{

		class LDAPI IList_uint32_t
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			IList_uint32_t(const IList_uint32_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~IList_uint32_t(void);
			virtual int32_t IndexOf(uint32_t item);
			virtual void Insert(int32_t index, uint32_t item);
			virtual void RemoveAt(int32_t index);
			virtual uint32_t Item(int32_t index);
			virtual void Item(int32_t index, uint32_t value);
			virtual int32_t Count(void);
#ifdef MAKEDLL
		public: // This is for internal use
			IList_uint32_t(){};
			IList_uint32_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _ILIST_UINT32_T_H
