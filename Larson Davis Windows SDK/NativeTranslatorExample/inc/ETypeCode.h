/**************************************************************************//**
 * @file ETypeCode.h
 * @brief Native Wrapper for Managed type TypeCode.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ETYPE_CODE_H
#define _ETYPE_CODE_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class ETypeCode
		{
			Empty = 0,
			Object = 1,
			DBNull = 2,
			Boolean = 3,
			Char = 4,
			SByte = 5,
			Byte = 6,
			Int16 = 7,
			UInt16 = 8,
			Int32 = 9,
			UInt32 = 10,
			Int64 = 11,
			UInt64 = 12,
			Single = 13,
			Double = 14,
			Decimal = 15,
			DateTime = 16,
			String = 18,
		};
	}
}
#endif // _ETYPE_CODE_H
