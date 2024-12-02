/**************************************************************************//**
 * @file CSerializationCallback.h
 * @brief Native Wrapper for Managed type SerializationCallback.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _CSERIALIZATION_CALLBACK_H
#define _CSERIALIZATION_CALLBACK_H
namespace LarsonDavis
{
	namespace Native
	{

		class LDAPI CSerializationCallback
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			CSerializationCallback(const CSerializationCallback& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~CSerializationCallback(void);
#ifdef MAKEDLL
		public: // This is for internal use
			CSerializationCallback(){};
			CSerializationCallback(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _CSERIALIZATION_CALLBACK_H
