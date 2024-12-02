/**************************************************************************//**
 * @file IActivatableReactiveObject.h
 * @brief Native Wrapper for Managed type IActivatableReactiveObject.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _IACTIVATABLE_REACTIVE_OBJECT_H
#define _IACTIVATABLE_REACTIVE_OBJECT_H
#include <IActivatableViewModel.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI IActivatableViewModel;

		class LDAPI IActivatableReactiveObject : public virtual IActivatableViewModel
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			IActivatableReactiveObject(const IActivatableReactiveObject& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~IActivatableReactiveObject(void);
#ifdef MAKEDLL
		public: // This is for internal use
			IActivatableReactiveObject(){};
			IActivatableReactiveObject(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _IACTIVATABLE_REACTIVE_OBJECT_H
