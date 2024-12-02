/**************************************************************************//**
 * @file EMissingMemberHandling.h
 * @brief Native Wrapper for Managed type MissingMemberHandling.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _EMISSING_MEMBER_HANDLING_H
#define _EMISSING_MEMBER_HANDLING_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class EMissingMemberHandling
		{
			Ignore = 0,
			Error = 1,
		};
	}
}
#endif // _EMISSING_MEMBER_HANDLING_H
