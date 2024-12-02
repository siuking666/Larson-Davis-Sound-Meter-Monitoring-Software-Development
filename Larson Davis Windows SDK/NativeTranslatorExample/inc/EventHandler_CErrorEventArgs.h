/**************************************************************************//**
 * @file EventHandler_CErrorEventArgs.h
 * @brief Native Wrapper for Managed type EventHandler<Newtonsoft::Json::Serialization::ErrorEventArgs^>.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _EVENT_HANDLER_CERROR_EVENT_ARGS_H
#define _EVENT_HANDLER_CERROR_EVENT_ARGS_H
#include <CErrorEventArgs.h>
namespace LarsonDavis
{
	namespace Native
	{

		class LDAPI EventHandler_CErrorEventArgs
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			EventHandler_CErrorEventArgs(const EventHandler_CErrorEventArgs& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~EventHandler_CErrorEventArgs(void);
#ifdef MAKEDLL
		public: // This is for internal use
			EventHandler_CErrorEventArgs(){};
			EventHandler_CErrorEventArgs(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _EVENT_HANDLER_CERROR_EVENT_ARGS_H
