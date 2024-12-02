/**************************************************************************//**
 * @file EJsonToken.h
 * @brief Native Wrapper for Managed type JsonToken.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _EJSON_TOKEN_H
#define _EJSON_TOKEN_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class EJsonToken
		{
			None = 0,
			StartObject = 1,
			StartArray = 2,
			StartConstructor = 3,
			PropertyName = 4,
			Comment = 5,
			Raw = 6,
			Integer = 7,
			Float = 8,
			String = 9,
			Boolean = 10,
			Null = 11,
			Undefined = 12,
			EndObject = 13,
			EndArray = 14,
			EndConstructor = 15,
			Date = 16,
			Bytes = 17,
		};
	}
}
#endif // _EJSON_TOKEN_H
