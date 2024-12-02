/**************************************************************************//**
 * @file EDoseMode_t.h
 * @brief Native Wrapper for Managed type DoseMode_t.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _EDOSE_MODE_T_H
#define _EDOSE_MODE_T_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class EDoseMode_t
		{
			DOSE_MODE_DOSE = 0,
			DOSE_MODE_ISO = 1,
		};
	}
}
#endif // _EDOSE_MODE_T_H
