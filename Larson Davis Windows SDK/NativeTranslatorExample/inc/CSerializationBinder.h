/**************************************************************************//**
 * @file CSerializationBinder.h
 * @brief Native Wrapper for Managed type SerializationBinder.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _CSERIALIZATION_BINDER_H
#define _CSERIALIZATION_BINDER_H
namespace LarsonDavis
{
	namespace Native
	{

		class LDAPI CSerializationBinder
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			CSerializationBinder(const CSerializationBinder& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~CSerializationBinder(void);
#ifdef MAKEDLL
		public: // This is for internal use
			CSerializationBinder(){};
			CSerializationBinder(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _CSERIALIZATION_BINDER_H
