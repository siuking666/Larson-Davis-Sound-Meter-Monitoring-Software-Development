/**************************************************************************//**
 * @file EUnitConversion.h
 * @brief Native Wrapper for Managed type UnitConversion.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _EUNIT_CONVERSION_H
#define _EUNIT_CONVERSION_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class EUnitConversion
		{
			SI = 0,
			English = 1,
		};
	}
}
#endif // _EUNIT_CONVERSION_H
