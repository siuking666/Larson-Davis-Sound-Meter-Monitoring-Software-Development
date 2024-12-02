/**************************************************************************//**
 * @file EMergeArrayHandling.h
 * @brief Native Wrapper for Managed type MergeArrayHandling.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _EMERGE_ARRAY_HANDLING_H
#define _EMERGE_ARRAY_HANDLING_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class EMergeArrayHandling
		{
			Concat = 0,
			Union = 1,
			Replace = 2,
			Merge = 3,
		};
	}
}
#endif // _EMERGE_ARRAY_HANDLING_H
