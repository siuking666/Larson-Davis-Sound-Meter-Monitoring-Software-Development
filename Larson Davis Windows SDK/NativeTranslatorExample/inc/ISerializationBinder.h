/**************************************************************************//**
 * @file ISerializationBinder.h
 * @brief Native Wrapper for Managed type ISerializationBinder.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ISERIALIZATION_BINDER_H
#define _ISERIALIZATION_BINDER_H
namespace LarsonDavis
{
	namespace Native
	{

		class LDAPI ISerializationBinder
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			ISerializationBinder(const ISerializationBinder& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~ISerializationBinder(void);
#ifdef MAKEDLL
		public: // This is for internal use
			ISerializationBinder(){};
			ISerializationBinder(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _ISERIALIZATION_BINDER_H
