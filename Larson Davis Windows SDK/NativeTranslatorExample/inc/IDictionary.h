/**************************************************************************//**
 * @file IDictionary.h
 * @brief Native Wrapper for Managed type IDictionary.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _IDICTIONARY_H
#define _IDICTIONARY_H
namespace LarsonDavis
{
	namespace Native
	{

		class LDAPI IDictionary
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			IDictionary(const IDictionary& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~IDictionary(void);
			virtual void Clear(void);
			virtual bool IsReadOnly(void);
			virtual bool IsFixedSize(void);
#ifdef MAKEDLL
		public: // This is for internal use
			IDictionary(){};
			IDictionary(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _IDICTIONARY_H
