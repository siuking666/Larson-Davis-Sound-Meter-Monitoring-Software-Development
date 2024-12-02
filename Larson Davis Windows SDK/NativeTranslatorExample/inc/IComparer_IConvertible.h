/**************************************************************************//**
 * @file IComparer_IConvertible.h
 * @brief Native Wrapper for Managed type IComparer<System::IConvertible^>.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ICOMPARER_ICONVERTIBLE_H
#define _ICOMPARER_ICONVERTIBLE_H
#include <IConvertible.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI IConvertible;

		class LDAPI IComparer_IConvertible
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			IComparer_IConvertible(const IComparer_IConvertible& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~IComparer_IConvertible(void);
			virtual int32_t Compare(std::shared_ptr<IConvertible> x, std::shared_ptr<IConvertible> y);
#ifdef MAKEDLL
		public: // This is for internal use
			IComparer_IConvertible(){};
			IComparer_IConvertible(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _ICOMPARER_ICONVERTIBLE_H
