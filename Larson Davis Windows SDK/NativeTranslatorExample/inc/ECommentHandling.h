/**************************************************************************//**
 * @file ECommentHandling.h
 * @brief Native Wrapper for Managed type CommentHandling.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ECOMMENT_HANDLING_H
#define _ECOMMENT_HANDLING_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class ECommentHandling
		{
			Ignore = 0,
			Load = 1,
		};
	}
}
#endif // _ECOMMENT_HANDLING_H
