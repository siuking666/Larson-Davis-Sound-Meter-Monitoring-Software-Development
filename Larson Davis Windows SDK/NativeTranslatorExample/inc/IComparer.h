/**************************************************************************//**
 * @file IComparer.h
 * @brief Native Wrapper for Managed type IComparer.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ICOMPARER_H
#define _ICOMPARER_H
namespace LarsonDavis
{
	namespace Native
	{

		class LDAPI IComparer
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			IComparer(const IComparer& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~IComparer(void);
#ifdef MAKEDLL
		public: // This is for internal use
			IComparer(){};
			IComparer(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _ICOMPARER_H
