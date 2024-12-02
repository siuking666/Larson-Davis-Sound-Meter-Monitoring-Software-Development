/**************************************************************************//**
 * @file EEditBandAction.h
 * @brief Native Wrapper for Managed type EditBandAction.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _EEDIT_BAND_ACTION_H
#define _EEDIT_BAND_ACTION_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class EEditBandAction
		{
			Offset = 0,
			Exclude = 1,
			Remove = 2,
		};
	}
}
#endif // _EEDIT_BAND_ACTION_H
