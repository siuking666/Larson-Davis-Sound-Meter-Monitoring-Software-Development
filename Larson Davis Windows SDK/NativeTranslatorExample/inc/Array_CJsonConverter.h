/**************************************************************************//**
 * @file Array_CJsonConverter.h
 * @brief Native Wrapper for Managed type cli::array<Newtonsoft::Json::JsonConverter^, 1>.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ARRAY_CJSON_CONVERTER_H
#define _ARRAY_CJSON_CONVERTER_H
#include <CArray.h>
#include <IList_CJsonConverter.h>
#include <CJsonConverter.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI CArray;
		class LDAPI IList_CJsonConverter;
		class LDAPI CJsonConverter;

		class LDAPI Array_CJsonConverter : public CArray, public virtual IList_CJsonConverter
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			Array_CJsonConverter(const Array_CJsonConverter& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~Array_CJsonConverter(void);
			void Set(int32_t arg0, std::shared_ptr<CJsonConverter> arg1);
			std::shared_ptr<CJsonConverter> Get(int32_t arg0);
			Array_CJsonConverter(int32_t arg0);
#ifdef MAKEDLL
		public: // This is for internal use
			Array_CJsonConverter(){};
			Array_CJsonConverter(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _ARRAY_CJSON_CONVERTER_H
