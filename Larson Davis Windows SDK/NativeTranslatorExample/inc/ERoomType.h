/**************************************************************************//**
 * @file ERoomType.h
 * @brief Native Wrapper for Managed type RoomType.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _EROOM_TYPE_H
#define _EROOM_TYPE_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class ERoomType
		{
			None = 0,
			Tx = 1,
			Rx = 2,
		};
	}
}
#endif // _EROOM_TYPE_H
