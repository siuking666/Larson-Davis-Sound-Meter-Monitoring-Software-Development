/**************************************************************************//**
 * @file IList.h
 * @brief Native Wrapper for Managed type IList.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ILIST_H
#define _ILIST_H
namespace LarsonDavis
{
	namespace Native
	{

		class LDAPI IList
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			IList(const IList& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~IList(void);
			virtual void Clear(void);
			virtual void RemoveAt(int32_t index);
			virtual bool IsReadOnly(void);
			virtual bool IsFixedSize(void);
			virtual int32_t Count(void);
#ifdef MAKEDLL
		public: // This is for internal use
			IList(){};
			IList(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _ILIST_H
