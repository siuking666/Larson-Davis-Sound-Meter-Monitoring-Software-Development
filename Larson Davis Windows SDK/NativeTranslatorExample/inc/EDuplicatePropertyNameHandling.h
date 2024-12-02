/**************************************************************************//**
 * @file EDuplicatePropertyNameHandling.h
 * @brief Native Wrapper for Managed type DuplicatePropertyNameHandling.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _EDUPLICATE_PROPERTY_NAME_HANDLING_H
#define _EDUPLICATE_PROPERTY_NAME_HANDLING_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class EDuplicatePropertyNameHandling
		{
			Replace = 0,
			Ignore = 1,
			Error = 2,
		};
	}
}
#endif // _EDUPLICATE_PROPERTY_NAME_HANDLING_H
