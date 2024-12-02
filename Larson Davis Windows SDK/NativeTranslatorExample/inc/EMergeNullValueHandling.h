/**************************************************************************//**
 * @file EMergeNullValueHandling.h
 * @brief Native Wrapper for Managed type MergeNullValueHandling.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _EMERGE_NULL_VALUE_HANDLING_H
#define _EMERGE_NULL_VALUE_HANDLING_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class EMergeNullValueHandling
		{
			Ignore = 0,
			Merge = 1,
		};
	}
}
#endif // _EMERGE_NULL_VALUE_HANDLING_H
