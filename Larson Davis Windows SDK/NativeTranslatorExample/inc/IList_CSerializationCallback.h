/**************************************************************************//**
 * @file IList_CSerializationCallback.h
 * @brief Native Wrapper for Managed type IList<Newtonsoft::Json::Serialization::SerializationCallback^>.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ILIST_CSERIALIZATION_CALLBACK_H
#define _ILIST_CSERIALIZATION_CALLBACK_H
#include <CSerializationCallback.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI CSerializationCallback;

		class LDAPI IList_CSerializationCallback
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			IList_CSerializationCallback(const IList_CSerializationCallback& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~IList_CSerializationCallback(void);
			virtual int32_t IndexOf(std::shared_ptr<CSerializationCallback> item);
			virtual void Insert(int32_t index, std::shared_ptr<CSerializationCallback> item);
			virtual void RemoveAt(int32_t index);
			virtual std::shared_ptr<CSerializationCallback> Item(int32_t index);
			virtual void Item(int32_t index, std::shared_ptr<CSerializationCallback> value);
			virtual int32_t Count(void);
#ifdef MAKEDLL
		public: // This is for internal use
			IList_CSerializationCallback(){};
			IList_CSerializationCallback(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _ILIST_CSERIALIZATION_CALLBACK_H
