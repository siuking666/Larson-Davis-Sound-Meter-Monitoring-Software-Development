/**************************************************************************//**
 * @file IObserver_SUnit.h
 * @brief Native Wrapper for Managed type IObserver<System::Reactive::Unit>.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _IOBSERVER_SUNIT_H
#define _IOBSERVER_SUNIT_H
#include <SUnit.h>
namespace LarsonDavis
{
	namespace Native
	{
		struct LDAPI SUnit;

		class LDAPI IObserver_SUnit
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			IObserver_SUnit(const IObserver_SUnit& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~IObserver_SUnit(void);
			virtual void OnNext(std::shared_ptr<SUnit> value);
			virtual void OnCompleted(void);
#ifdef MAKEDLL
		public: // This is for internal use
			IObserver_SUnit(){};
			IObserver_SUnit(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _IOBSERVER_SUNIT_H
