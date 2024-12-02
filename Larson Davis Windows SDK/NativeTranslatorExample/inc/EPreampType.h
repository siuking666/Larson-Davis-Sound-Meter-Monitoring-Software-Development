/**************************************************************************//**
 * @file EPreampType.h
 * @brief Native Wrapper for Managed type PreampType.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _EPREAMP_TYPE_H
#define _EPREAMP_TYPE_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class EPreampType
		{
			Direct = 0,
			Prm831 = 1,
			Icp = 2,
			Unknown = 3,
			Prm2102 = 4,
			Prm2100 = 5,
			PrmLxT1 = 6,
			PrmLxT1L = 7,
			PrmLxT2 = 8,
			PrmLxT2L = 9,
			PrmLxT2B = 10,
			Prm2103 = 11,
			PrmLxT2C = 12,
			Prm821 = 13,
			Prm721 = 14,
			LxT1 = 1,
			LxT1L = 2,
			LxT2 = 3,
			LxT2L = 4,
			LxT2Bx = 5,
			Prm831x = 6,
			Unknownx = 7,
		};
	}
}
#endif // _EPREAMP_TYPE_H
