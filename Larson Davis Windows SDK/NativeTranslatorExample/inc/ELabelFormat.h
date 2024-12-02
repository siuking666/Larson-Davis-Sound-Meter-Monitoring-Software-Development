/**************************************************************************//**
 * @file ELabelFormat.h
 * @brief Native Wrapper for Managed type LabelFormat.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ELABEL_FORMAT_H
#define _ELABEL_FORMAT_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class ELabelFormat
		{
			NoHz = 0,
			WithHz = 1,
			Abreviated = 2,
			CPM = 3,
		};
	}
}
#endif // _ELABEL_FORMAT_H
