/**************************************************************************//**
 * @file IReferenceResolver.h
 * @brief Native Wrapper for Managed type IReferenceResolver.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _IREFERENCE_RESOLVER_H
#define _IREFERENCE_RESOLVER_H
namespace LarsonDavis
{
	namespace Native
	{

		class LDAPI IReferenceResolver
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			IReferenceResolver(const IReferenceResolver& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~IReferenceResolver(void);
#ifdef MAKEDLL
		public: // This is for internal use
			IReferenceResolver(){};
			IReferenceResolver(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _IREFERENCE_RESOLVER_H
