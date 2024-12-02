/**************************************************************************//**
 * @file IReactiveObject.h
 * @brief Native Wrapper for Managed type IReactiveObject.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _IREACTIVE_OBJECT_H
#define _IREACTIVE_OBJECT_H
#include <IEnableLogger.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI IEnableLogger;
		class LDAPI CPropertyChangingEventArgs;

		class LDAPI IReactiveObject : public virtual IEnableLogger
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			IReactiveObject(const IReactiveObject& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~IReactiveObject(void);
			virtual void RaisePropertyChanging(std::shared_ptr<CPropertyChangingEventArgs> args);
#ifdef MAKEDLL
		public: // This is for internal use
			IReactiveObject(){};
			IReactiveObject(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _IREACTIVE_OBJECT_H
