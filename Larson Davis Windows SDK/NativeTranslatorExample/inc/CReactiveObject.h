/**************************************************************************//**
 * @file CReactiveObject.h
 * @brief Native Wrapper for Managed type ReactiveObject.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _CREACTIVE_OBJECT_H
#define _CREACTIVE_OBJECT_H
#include <IReactiveNotifyPropertyChanged_IReactiveObject.h>
#include <IHandleObservableErrors.h>
#include <IReactiveObject.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI IReactiveNotifyPropertyChanged_IReactiveObject;
		class LDAPI IHandleObservableErrors;
		class LDAPI IReactiveObject;
		class LDAPI IObservable_IReactivePropertyChangedEventArgs_IReactiveObject;

		class LDAPI CReactiveObject : public virtual IReactiveNotifyPropertyChanged_IReactiveObject, public virtual IHandleObservableErrors, public virtual IReactiveObject
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			CReactiveObject(const CReactiveObject& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~CReactiveObject(void);
			bool AreChangeNotificationsEnabled(void);
			CReactiveObject(void);
			std::shared_ptr<IObservable_IReactivePropertyChangedEventArgs_IReactiveObject> Changing(void);
			std::shared_ptr<IObservable_IReactivePropertyChangedEventArgs_IReactiveObject> Changed(void);
#ifdef MAKEDLL
		public: // This is for internal use
			CReactiveObject(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _CREACTIVE_OBJECT_H
