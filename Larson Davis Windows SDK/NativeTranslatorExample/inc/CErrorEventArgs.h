/**************************************************************************//**
 * @file CErrorEventArgs.h
 * @brief Native Wrapper for Managed type ErrorEventArgs.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _CERROR_EVENT_ARGS_H
#define _CERROR_EVENT_ARGS_H
#include <CEventArgs.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI CEventArgs;
		class LDAPI CErrorContext;

		class LDAPI CErrorEventArgs : public CEventArgs
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			CErrorEventArgs(const CErrorEventArgs& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~CErrorEventArgs(void);
			std::shared_ptr<CErrorContext> ErrorContext(void);
#ifdef MAKEDLL
		public: // This is for internal use
			CErrorEventArgs(){};
			CErrorEventArgs(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _CERROR_EVENT_ARGS_H
