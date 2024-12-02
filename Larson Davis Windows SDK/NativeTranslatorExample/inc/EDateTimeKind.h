/**************************************************************************//**
 * @file EDateTimeKind.h
 * @brief Native Wrapper for Managed type DateTimeKind.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _EDATE_TIME_KIND_H
#define _EDATE_TIME_KIND_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class EDateTimeKind
		{
			Unspecified = 0,
			Utc = 1,
			Local = 2,
		};
	}
}
#endif // _EDATE_TIME_KIND_H
