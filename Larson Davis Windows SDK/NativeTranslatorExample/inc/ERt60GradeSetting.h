/**************************************************************************//**
 * @file ERt60GradeSetting.h
 * @brief Native Wrapper for Managed type Rt60GradeSetting.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ERT60_GRADE_SETTING_H
#define _ERT60_GRADE_SETTING_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class ERt60GradeSetting
		{
			Ok = 0,
			NotApplicable = 1,
			Conflict = 2,
		};
	}
}
#endif // _ERT60_GRADE_SETTING_H
