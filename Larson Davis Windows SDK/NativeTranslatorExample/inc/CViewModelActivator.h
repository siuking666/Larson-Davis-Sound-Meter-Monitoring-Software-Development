/**************************************************************************//**
 * @file CViewModelActivator.h
 * @brief Native Wrapper for Managed type ViewModelActivator.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _CVIEW_MODEL_ACTIVATOR_H
#define _CVIEW_MODEL_ACTIVATOR_H
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI IObservable_SUnit;

		class LDAPI CViewModelActivator
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			CViewModelActivator(const CViewModelActivator& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~CViewModelActivator(void);
			void Deactivate(bool ignoreRefCount = false);
			void Dispose(void);
			CViewModelActivator(void);
			std::shared_ptr<IObservable_SUnit> Activated(void);
			std::shared_ptr<IObservable_SUnit> Deactivated(void);
#ifdef MAKEDLL
		public: // This is for internal use
			CViewModelActivator(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _CVIEW_MODEL_ACTIVATOR_H
