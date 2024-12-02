/**************************************************************************//**
 * @file IEnableLogger.h
 * @brief Native Wrapper for Managed type IEnableLogger.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _IENABLE_LOGGER_H
#define _IENABLE_LOGGER_H
namespace LarsonDavis
{
	namespace Native
	{

		class LDAPI IEnableLogger
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			IEnableLogger(const IEnableLogger& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~IEnableLogger(void);
#ifdef MAKEDLL
		public: // This is for internal use
			IEnableLogger(){};
			IEnableLogger(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _IENABLE_LOGGER_H
