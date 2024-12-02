/**************************************************************************//**
 * @file ICleanup.h
 * @brief Native Wrapper for Managed type ICleanup.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ICLEANUP_H
#define _ICLEANUP_H
namespace LarsonDavis
{
	namespace Native
	{

		class LDAPI ICleanup
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			ICleanup(const ICleanup& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~ICleanup(void);
			virtual void Cleanup(void);
#ifdef MAKEDLL
		public: // This is for internal use
			ICleanup(){};
			ICleanup(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _ICLEANUP_H
