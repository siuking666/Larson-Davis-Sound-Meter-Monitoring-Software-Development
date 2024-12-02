/**************************************************************************//**
 * @file ELanguage.h
 * @brief Native Wrapper for Managed type Language.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ELANGUAGE_H
#define _ELANGUAGE_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class ELanguage
		{
			English = 0,
			French = 1,
			German = 2,
			Italian = 3,
			Portuguese = 4,
			Spanish = 5,
			Swedish = 6,
			Norwegian = 7,
			PortugueseBr = 8,
		};
	}
}
#endif // _ELANGUAGE_H
