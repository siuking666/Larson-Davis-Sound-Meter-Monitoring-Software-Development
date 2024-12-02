/**************************************************************************//**
 * @file CSerializationErrorCallback.h
 * @brief Native Wrapper for Managed type SerializationErrorCallback.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _CSERIALIZATION_ERROR_CALLBACK_H
#define _CSERIALIZATION_ERROR_CALLBACK_H
namespace LarsonDavis
{
	namespace Native
	{

		class LDAPI CSerializationErrorCallback
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			CSerializationErrorCallback(const CSerializationErrorCallback& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~CSerializationErrorCallback(void);
#ifdef MAKEDLL
		public: // This is for internal use
			CSerializationErrorCallback(){};
			CSerializationErrorCallback(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _CSERIALIZATION_ERROR_CALLBACK_H
