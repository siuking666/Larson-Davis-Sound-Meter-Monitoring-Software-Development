/**************************************************************************//**
 * @file CJsonConverter.h
 * @brief Native Wrapper for Managed type JsonConverter.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _CJSON_CONVERTER_H
#define _CJSON_CONVERTER_H
namespace LarsonDavis
{
	namespace Native
	{

		class LDAPI CJsonConverter
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			CJsonConverter(const CJsonConverter& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~CJsonConverter(void);
			bool CanRead(void);
			bool CanWrite(void);
#ifdef MAKEDLL
		public: // This is for internal use
			CJsonConverter(){};
			CJsonConverter(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _CJSON_CONVERTER_H
