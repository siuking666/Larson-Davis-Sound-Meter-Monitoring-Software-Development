/**************************************************************************//**
 * @file CEventArgs.h
 * @brief Native Wrapper for Managed type EventArgs.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _CEVENT_ARGS_H
#define _CEVENT_ARGS_H
namespace LarsonDavis
{
	namespace Native
	{

		class LDAPI CEventArgs
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			CEventArgs(const CEventArgs& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~CEventArgs(void);
			CEventArgs(void);
			static std::shared_ptr<CEventArgs> Empty(void);
#ifdef MAKEDLL
		public: // This is for internal use
			CEventArgs(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _CEVENT_ARGS_H
