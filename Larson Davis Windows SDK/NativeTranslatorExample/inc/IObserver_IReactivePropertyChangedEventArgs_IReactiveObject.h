/**************************************************************************//**
 * @file IObserver_IReactivePropertyChangedEventArgs_IReactiveObject.h
 * @brief Native Wrapper for Managed type IObserver<ReactiveUI::IReactivePropertyChangedEventArgs<ReactiveUI::IReactiveObject^>^>.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _IOBSERVER_IREACTIVE_PROPERTY_CHANGED_EVENT_ARGS_IREACTIVE_OBJECT_H
#define _IOBSERVER_IREACTIVE_PROPERTY_CHANGED_EVENT_ARGS_IREACTIVE_OBJECT_H
#include <IReactivePropertyChangedEventArgs_IReactiveObject.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI IReactivePropertyChangedEventArgs_IReactiveObject;

		class LDAPI IObserver_IReactivePropertyChangedEventArgs_IReactiveObject
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			IObserver_IReactivePropertyChangedEventArgs_IReactiveObject(const IObserver_IReactivePropertyChangedEventArgs_IReactiveObject& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~IObserver_IReactivePropertyChangedEventArgs_IReactiveObject(void);
			virtual void OnNext(std::shared_ptr<IReactivePropertyChangedEventArgs_IReactiveObject> value);
			virtual void OnCompleted(void);
#ifdef MAKEDLL
		public: // This is for internal use
			IObserver_IReactivePropertyChangedEventArgs_IReactiveObject(){};
			IObserver_IReactivePropertyChangedEventArgs_IReactiveObject(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _IOBSERVER_IREACTIVE_PROPERTY_CHANGED_EVENT_ARGS_IREACTIVE_OBJECT_H
