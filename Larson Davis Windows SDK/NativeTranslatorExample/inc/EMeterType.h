/**************************************************************************//**
 * @file EMeterType.h
 * @brief Native Wrapper for Managed type MeterType.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _EMETER_TYPE_H
#define _EMETER_TYPE_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class EMeterType
		{
			DirectIo = -1,
			Unknown = 0,
			LxT = 1,
			LxTse = 2,
			M831 = 3,
			HVM100 = 4,
			HVM200 = 5,
			M831C = 6,
			M730 = 7,
			M730IS = 8,
			MWD730 = 9,
			M821 = 10,
			M721 = 11,
			M821SE = 12,
			M721SE = 13,
		};
	}
}
#endif // _EMETER_TYPE_H
