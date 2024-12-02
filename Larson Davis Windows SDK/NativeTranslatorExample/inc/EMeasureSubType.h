/**************************************************************************//**
 * @file EMeasureSubType.h
 * @brief Native Wrapper for Managed type MeasureSubType.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _EMEASURE_SUB_TYPE_H
#define _EMEASURE_SUB_TYPE_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class EMeasureSubType
		{
			None = 0,
			Sample = 1,
			Average = 2,
		};
	}
}
#endif // _EMEASURE_SUB_TYPE_H
