/**************************************************************************//**
 * @file IHandleObservableErrors.h
 * @brief Native Wrapper for Managed type IHandleObservableErrors.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _IHANDLE_OBSERVABLE_ERRORS_H
#define _IHANDLE_OBSERVABLE_ERRORS_H
namespace LarsonDavis
{
	namespace Native
	{

		class LDAPI IHandleObservableErrors
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			IHandleObservableErrors(const IHandleObservableErrors& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~IHandleObservableErrors(void);
#ifdef MAKEDLL
		public: // This is for internal use
			IHandleObservableErrors(){};
			IHandleObservableErrors(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _IHANDLE_OBSERVABLE_ERRORS_H
