/**************************************************************************//**
 * @file IObservable_SUnit.h
 * @brief Native Wrapper for Managed type IObservable<System::Reactive::Unit>.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _IOBSERVABLE_SUNIT_H
#define _IOBSERVABLE_SUNIT_H
#include <SUnit.h>
namespace LarsonDavis
{
	namespace Native
	{

		class LDAPI IObservable_SUnit
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			IObservable_SUnit(const IObservable_SUnit& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~IObservable_SUnit(void);
#ifdef MAKEDLL
		public: // This is for internal use
			IObservable_SUnit(){};
			IObservable_SUnit(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _IOBSERVABLE_SUNIT_H
