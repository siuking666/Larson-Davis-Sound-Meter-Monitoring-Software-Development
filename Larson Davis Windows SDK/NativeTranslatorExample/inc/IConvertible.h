/**************************************************************************//**
 * @file IConvertible.h
 * @brief Native Wrapper for Managed type IConvertible.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ICONVERTIBLE_H
#define _ICONVERTIBLE_H
#include <ETypeCode.h>
namespace LarsonDavis
{
	namespace Native
	{

		class LDAPI IConvertible
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			IConvertible(const IConvertible& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~IConvertible(void);
			virtual ETypeCode GetTypeCode(void);
#ifdef MAKEDLL
		public: // This is for internal use
			IConvertible(){};
			IConvertible(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _ICONVERTIBLE_H
