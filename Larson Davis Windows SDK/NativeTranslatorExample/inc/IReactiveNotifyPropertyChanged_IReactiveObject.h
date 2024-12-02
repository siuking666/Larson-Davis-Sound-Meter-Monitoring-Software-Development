/**************************************************************************//**
 * @file IReactiveNotifyPropertyChanged_IReactiveObject.h
 * @brief Native Wrapper for Managed type IReactiveNotifyPropertyChanged<ReactiveUI::IReactiveObject^>.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _IREACTIVE_NOTIFY_PROPERTY_CHANGED_IREACTIVE_OBJECT_H
#define _IREACTIVE_NOTIFY_PROPERTY_CHANGED_IREACTIVE_OBJECT_H
#include <IReactiveObject.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI IObservable_IReactivePropertyChangedEventArgs_IReactiveObject;

		class LDAPI IReactiveNotifyPropertyChanged_IReactiveObject
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			IReactiveNotifyPropertyChanged_IReactiveObject(const IReactiveNotifyPropertyChanged_IReactiveObject& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~IReactiveNotifyPropertyChanged_IReactiveObject(void);
			virtual std::shared_ptr<IObservable_IReactivePropertyChangedEventArgs_IReactiveObject> Changing(void);
			virtual std::shared_ptr<IObservable_IReactivePropertyChangedEventArgs_IReactiveObject> Changed(void);
#ifdef MAKEDLL
		public: // This is for internal use
			IReactiveNotifyPropertyChanged_IReactiveObject(){};
			IReactiveNotifyPropertyChanged_IReactiveObject(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _IREACTIVE_NOTIFY_PROPERTY_CHANGED_IREACTIVE_OBJECT_H
