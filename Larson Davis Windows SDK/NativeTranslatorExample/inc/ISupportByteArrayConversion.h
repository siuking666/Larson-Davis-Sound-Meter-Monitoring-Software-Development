/**************************************************************************//**
 * @file ISupportByteArrayConversion.h
 * @brief Native Wrapper for Managed type ISupportByteArrayConversion.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ISUPPORT_BYTE_ARRAY_CONVERSION_H
#define _ISUPPORT_BYTE_ARRAY_CONVERSION_H
namespace LarsonDavis
{
	namespace Native
	{

		class LDAPI ISupportByteArrayConversion
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			ISupportByteArrayConversion(const ISupportByteArrayConversion& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~ISupportByteArrayConversion(void);
#ifdef MAKEDLL
		public: // This is for internal use
			ISupportByteArrayConversion(){};
			ISupportByteArrayConversion(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _ISUPPORT_BYTE_ARRAY_CONVERSION_H
