/**************************************************************************//**
 * @file IContractResolver.h
 * @brief Native Wrapper for Managed type IContractResolver.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ICONTRACT_RESOLVER_H
#define _ICONTRACT_RESOLVER_H
namespace LarsonDavis
{
	namespace Native
	{

		class LDAPI IContractResolver
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			IContractResolver(const IContractResolver& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~IContractResolver(void);
#ifdef MAKEDLL
		public: // This is for internal use
			IContractResolver(){};
			IContractResolver(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _ICONTRACT_RESOLVER_H
