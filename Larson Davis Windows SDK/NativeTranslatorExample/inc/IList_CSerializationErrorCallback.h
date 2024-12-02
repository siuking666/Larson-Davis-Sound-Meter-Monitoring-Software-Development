/**************************************************************************//**
 * @file IList_CSerializationErrorCallback.h
 * @brief Native Wrapper for Managed type IList<Newtonsoft::Json::Serialization::SerializationErrorCallback^>.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ILIST_CSERIALIZATION_ERROR_CALLBACK_H
#define _ILIST_CSERIALIZATION_ERROR_CALLBACK_H
#include <CSerializationErrorCallback.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI CSerializationErrorCallback;

		class LDAPI IList_CSerializationErrorCallback
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			IList_CSerializationErrorCallback(const IList_CSerializationErrorCallback& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~IList_CSerializationErrorCallback(void);
			virtual int32_t IndexOf(std::shared_ptr<CSerializationErrorCallback> item);
			virtual void Insert(int32_t index, std::shared_ptr<CSerializationErrorCallback> item);
			virtual void RemoveAt(int32_t index);
			virtual std::shared_ptr<CSerializationErrorCallback> Item(int32_t index);
			virtual void Item(int32_t index, std::shared_ptr<CSerializationErrorCallback> value);
			virtual int32_t Count(void);
#ifdef MAKEDLL
		public: // This is for internal use
			IList_CSerializationErrorCallback(){};
			IList_CSerializationErrorCallback(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _ILIST_CSERIALIZATION_ERROR_CALLBACK_H
