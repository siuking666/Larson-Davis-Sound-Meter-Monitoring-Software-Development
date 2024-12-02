/**************************************************************************//**
 * @file EStringComparison.h
 * @brief Native Wrapper for Managed type StringComparison.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ESTRING_COMPARISON_H
#define _ESTRING_COMPARISON_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class EStringComparison
		{
			CurrentCulture = 0,
			CurrentCultureIgnoreCase = 1,
			InvariantCulture = 2,
			InvariantCultureIgnoreCase = 3,
			Ordinal = 4,
			OrdinalIgnoreCase = 5,
		};
	}
}
#endif // _ESTRING_COMPARISON_H
