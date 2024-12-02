/**************************************************************************//**
 * @file ESpartanFileBlock.h
 * @brief Native Wrapper for Managed type SpartanFileBlock.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ESPARTAN_FILE_BLOCK_H
#define _ESPARTAN_FILE_BLOCK_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class ESpartanFileBlock
		{
			All = 127,
			Overall = 1,
			SessionLog = 2,
			Note = 4,
			TimeHistory = 8,
			SoundRecords = 16,
			MeasHist = 32,
			AgencyApproval = 64,
		};
	}
}
#endif // _ESPARTAN_FILE_BLOCK_H
