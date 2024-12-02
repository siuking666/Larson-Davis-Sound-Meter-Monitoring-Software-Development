/**************************************************************************//**
 * @file IEqualityComparer.h
 * @brief Native Wrapper for Managed type IEqualityComparer.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _IEQUALITY_COMPARER_H
#define _IEQUALITY_COMPARER_H
namespace LarsonDavis
{
	namespace Native
	{

		class LDAPI IEqualityComparer
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			IEqualityComparer(const IEqualityComparer& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~IEqualityComparer(void);
#ifdef MAKEDLL
		public: // This is for internal use
			IEqualityComparer(){};
			IEqualityComparer(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _IEQUALITY_COMPARER_H
