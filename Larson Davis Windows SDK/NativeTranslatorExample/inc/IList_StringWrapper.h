/**************************************************************************//**
 * @file IList_StringWrapper.h
 * @brief Native Wrapper for Managed type IList<System::String^>.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ILIST_STRING_WRAPPER_H
#define _ILIST_STRING_WRAPPER_H
namespace LarsonDavis
{
	namespace Native
	{

		class LDAPI IList_StringWrapper
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			IList_StringWrapper(const IList_StringWrapper& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~IList_StringWrapper(void);
			virtual int32_t IndexOf(StringWrapper item);
			virtual void Insert(int32_t index, StringWrapper item);
			virtual void RemoveAt(int32_t index);
			virtual StringWrapper Item(int32_t index);
			virtual void Item(int32_t index, StringWrapper value);
			virtual int32_t Count(void);
#ifdef MAKEDLL
		public: // This is for internal use
			IList_StringWrapper(){};
			IList_StringWrapper(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _ILIST_STRING_WRAPPER_H
