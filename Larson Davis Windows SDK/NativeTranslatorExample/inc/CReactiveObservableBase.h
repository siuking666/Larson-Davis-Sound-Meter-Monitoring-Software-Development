/**************************************************************************//**
 * @file CReactiveObservableBase.h
 * @brief Native Wrapper for Managed type ReactiveObservableBase.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _CREACTIVE_OBSERVABLE_BASE_H
#define _CREACTIVE_OBSERVABLE_BASE_H
#include <CReactiveObject.h>
#include <IActivatableReactiveObject.h>
#include <ICleanup.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI CReactiveObject;
		class LDAPI IActivatableReactiveObject;
		class LDAPI ICleanup;
		class LDAPI CViewModelActivator;
		class LDAPI IObservable_SUnit;

		class LDAPI CReactiveObservableBase : public CReactiveObject, public virtual IActivatableReactiveObject, public virtual ICleanup
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			CReactiveObservableBase(const CReactiveObservableBase& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~CReactiveObservableBase(void);
			void Cleanup(void);
			void Dispose(void);
			std::shared_ptr<CViewModelActivator> Activator(void);
#ifdef MAKEDLL
		public: // This is for internal use
			CReactiveObservableBase(){};
			CReactiveObservableBase(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _CREACTIVE_OBSERVABLE_BASE_H
