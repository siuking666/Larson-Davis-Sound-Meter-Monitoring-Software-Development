/**************************************************************************//**
 * @file ESpartanFileBlockVersion.h
 * @brief Native Wrapper for Managed type SpartanFileBlockVersion.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ESPARTAN_FILE_BLOCK_VERSION_H
#define _ESPARTAN_FILE_BLOCK_VERSION_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class ESpartanFileBlockVersion
		{
			Unknown = 0,
			TimeHist1 = 1,
			TimeHist2 = 2,
			TimeHist3 = 3,
			TimeHist4 = 4,
			TimeHist5 = 5,
			MeasHist1 = 1,
			MeasHist2 = 2,
			MeasHist3 = 3,
			Overall1 = 1,
			Overall2 = 2,
			Overall3 = 3,
			Overall4 = 4,
			Overall5 = 5,
			Overall6 = 6,
			Overall7 = 7,
			Overall8 = 8,
			Overall9 = 9,
			Overall10 = 10,
			SessLog1 = 1,
			SRec1 = 1,
			Note1 = 1,
			AgencyApproval1 = 1,
		};
	}
}
#endif // _ESPARTAN_FILE_BLOCK_VERSION_H
