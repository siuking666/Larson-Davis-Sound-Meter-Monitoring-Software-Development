/**************************************************************************//**
 * @file EPartitionType.h
 * @brief Native Wrapper for Managed type PartitionType.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _EPARTITION_TYPE_H
#define _EPARTITION_TYPE_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class EPartitionType
		{
			Airborne = 0,
			Facade = 1,
			Impact = 2,
		};
	}
}
#endif // _EPARTITION_TYPE_H
