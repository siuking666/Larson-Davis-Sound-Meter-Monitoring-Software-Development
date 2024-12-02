/**************************************************************************//**
 * @file IActivatableViewModel.h
 * @brief Native Wrapper for Managed type IActivatableViewModel.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _IACTIVATABLE_VIEW_MODEL_H
#define _IACTIVATABLE_VIEW_MODEL_H
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI CViewModelActivator;
		class LDAPI IObservable_SUnit;

		class LDAPI IActivatableViewModel
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			IActivatableViewModel(const IActivatableViewModel& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~IActivatableViewModel(void);
			virtual std::shared_ptr<CViewModelActivator> Activator(void);
#ifdef MAKEDLL
		public: // This is for internal use
			IActivatableViewModel(){};
			IActivatableViewModel(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _IACTIVATABLE_VIEW_MODEL_H
