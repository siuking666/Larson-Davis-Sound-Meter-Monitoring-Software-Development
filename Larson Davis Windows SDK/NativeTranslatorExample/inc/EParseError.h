/**************************************************************************//**
 * @file EParseError.h
 * @brief Native Wrapper for Managed type ParseError.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _EPARSE_ERROR_H
#define _EPARSE_ERROR_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class EParseError : uint32_t
		{
			None = 0u,
			DeviceInfo = 1u,
			SystemSettings = 2u,
			MeasSettings = 4u,
			Overall = 8u,
			OBA = 16u,
			Excd = 32u,
			Ln = 64u,
			Daily = 128u,
			ProfileData = 256u,
			PreCal = 512u,
			PostCal = 1024u,
			RangeData = 2048u,
			DeviceDesc = 4096u,
			AgencyApproval = 8192u,
			Note = 16384u,
			MeasAnyData = 32768u,
			TimeHistory = 65536u,
			SessionLog = 131072u,
			SoundRec = 262144u,
		};
	}
}
#endif // _EPARSE_ERROR_H
