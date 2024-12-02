/**************************************************************************//**
 * @file IReactivePropertyChangedEventArgs_IReactiveObject.h
 * @brief Native Wrapper for Managed type IReactivePropertyChangedEventArgs<ReactiveUI::IReactiveObject^>.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _IREACTIVE_PROPERTY_CHANGED_EVENT_ARGS_IREACTIVE_OBJECT_H
#define _IREACTIVE_PROPERTY_CHANGED_EVENT_ARGS_IREACTIVE_OBJECT_H
#include <IReactiveObject.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI IReactiveObject;
		class LDAPI CPropertyChangingEventArgs;

		class LDAPI IReactivePropertyChangedEventArgs_IReactiveObject
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			IReactivePropertyChangedEventArgs_IReactiveObject(const IReactivePropertyChangedEventArgs_IReactiveObject& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~IReactivePropertyChangedEventArgs_IReactiveObject(void);
			virtual StringWrapper PropertyName(void);
			virtual std::shared_ptr<IReactiveObject> Sender(void);
#ifdef MAKEDLL
		public: // This is for internal use
			IReactivePropertyChangedEventArgs_IReactiveObject(){};
			IReactivePropertyChangedEventArgs_IReactiveObject(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _IREACTIVE_PROPERTY_CHANGED_EVENT_ARGS_IREACTIVE_OBJECT_H
