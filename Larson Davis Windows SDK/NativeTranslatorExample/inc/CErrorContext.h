/**************************************************************************//**
 * @file CErrorContext.h
 * @brief Native Wrapper for Managed type ErrorContext.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _CERROR_CONTEXT_H
#define _CERROR_CONTEXT_H
namespace LarsonDavis
{
	namespace Native
	{

		class LDAPI CErrorContext
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			CErrorContext(const CErrorContext& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~CErrorContext(void);
			StringWrapper Path(void);
			bool Handled(void);
			void Handled(bool value);
#ifdef MAKEDLL
		public: // This is for internal use
			CErrorContext(){};
			CErrorContext(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _CERROR_CONTEXT_H
