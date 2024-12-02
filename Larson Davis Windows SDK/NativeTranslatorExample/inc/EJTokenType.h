/**************************************************************************//**
 * @file EJTokenType.h
 * @brief Native Wrapper for Managed type JTokenType.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _EJTOKEN_TYPE_H
#define _EJTOKEN_TYPE_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class EJTokenType
		{
			None = 0,
			Object = 1,
			Array = 2,
			Constructor = 3,
			Property = 4,
			Comment = 5,
			Integer = 6,
			Float = 7,
			String = 8,
			Boolean = 9,
			Null = 10,
			Undefined = 11,
			Date = 12,
			Raw = 13,
			Bytes = 14,
			Guid = 15,
			Uri = 16,
			TimeSpan = 17,
		};
	}
}
#endif // _EJTOKEN_TYPE_H
