/**************************************************************************//**
 * @file CJsonConverterCollection.h
 * @brief Native Wrapper for Managed type JsonConverterCollection.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _CJSON_CONVERTER_COLLECTION_H
#define _CJSON_CONVERTER_COLLECTION_H
#include <Collection_CJsonConverter.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI Collection_CJsonConverter;

		class LDAPI CJsonConverterCollection : public Collection_CJsonConverter
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			CJsonConverterCollection(const CJsonConverterCollection& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~CJsonConverterCollection(void);
			CJsonConverterCollection(void);
#ifdef MAKEDLL
		public: // This is for internal use
			CJsonConverterCollection(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _CJSON_CONVERTER_COLLECTION_H
