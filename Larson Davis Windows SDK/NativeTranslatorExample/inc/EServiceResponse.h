/**************************************************************************//**
 * @file EServiceResponse.h
 * @brief Native Wrapper for Managed type ServiceResponse.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ESERVICE_RESPONSE_H
#define _ESERVICE_RESPONSE_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class EServiceResponse
		{
			Undefined = -1,
			Success = 0,
			SuccessWithTruncation = 1,
			SuccessWithParseError = 2,
			MultiRecord = 3,
			StatusUpdateFail = 4,
			ConnectionFail = 5,
			BadFileName = 6,
			BadFileFormat = 7,
			FileOpenFail = 8,
			CommunicationError = 9,
			ConfigUpdateFail = 10,
			UploadFirmwareFileFail = 11,
			UpgradeFirmwareFail = 12,
			UpgradeSBCDaemonFail = 13,
			DeleteFirmwareFileFail = 14,
			RebootSlmFail = 15,
			DownloadFail = 16,
			TranslationFail = 17,
			TranslationParseFail = 18,
			TranslationCriticalFail = 19,
			TranslationSuspicious = 20,
			DeleteDownloadFileFailed = 21,
			CommandFailed = 22,
			OutOfMemoryError = 23,
			ObsoleteFirmware = 24,
			SuccessNoFilesToDownload = 25,
		};
	}
}
#endif // _ESERVICE_RESPONSE_H
