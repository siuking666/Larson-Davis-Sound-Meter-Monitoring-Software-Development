/**************************************************************************//**
 * @file CPropertyChangingEventArgs.h
 * @brief Native Wrapper for Managed type PropertyChangingEventArgs.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _CPROPERTY_CHANGING_EVENT_ARGS_H
#define _CPROPERTY_CHANGING_EVENT_ARGS_H
#include <CEventArgs.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI CEventArgs;

		class LDAPI CPropertyChangingEventArgs : public CEventArgs
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			CPropertyChangingEventArgs(const CPropertyChangingEventArgs& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~CPropertyChangingEventArgs(void);
			CPropertyChangingEventArgs(StringWrapper propertyName);
			StringWrapper PropertyName(void);
#ifdef MAKEDLL
		public: // This is for internal use
			CPropertyChangingEventArgs(){};
			CPropertyChangingEventArgs(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _CPROPERTY_CHANGING_EVENT_ARGS_H
