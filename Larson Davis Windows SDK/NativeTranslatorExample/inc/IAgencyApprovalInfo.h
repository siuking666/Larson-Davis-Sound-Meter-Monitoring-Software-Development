/**************************************************************************//**
 * @file IAgencyApprovalInfo.h
 * @brief Native Wrapper for Managed type IAgencyApprovalInfo.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _IAGENCY_APPROVAL_INFO_H
#define _IAGENCY_APPROVAL_INFO_H
namespace LarsonDavis
{
	namespace Native
	{

		class LDAPI IAgencyApprovalInfo
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			IAgencyApprovalInfo(const IAgencyApprovalInfo& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~IAgencyApprovalInfo(void);
			virtual bool HasAgencyApprovalOption(void);
			virtual StringWrapper SealValidString(void);
			virtual bool IsFirmwareApproved(void);
			virtual StringWrapper AgencyAcronym(void);
			virtual uint32_t Timestamp(void);
			virtual uint32_t CalDateTime(void);
			virtual float CertifiedMicSensitivity(void);
			virtual float ActualMicSensitivity(void);
			virtual uint32_t SealState(void);
			virtual uint32_t SealStateFlags(void);
			virtual StringWrapper PreampName(void);
			virtual StringWrapper AgencyFirmwareVersion(void);
			virtual StringWrapper HardwareVersion(void);
			virtual StringWrapper FullModelString(void);
			virtual StringWrapper MicrophoneInfo(void);
			virtual bool InvalidMerged(void);
			virtual bool InvalidCalibration(void);
			virtual bool InvalidSensitivity(void);
			virtual bool InvalidOption(void);
			virtual bool InvalidFirmware(void);
			virtual bool InvalidHardware(void);
			virtual bool InvalidMic(void);
			virtual bool InvalidMicCorrection(void);
			virtual bool InvalidMode(void);
			virtual bool InvalidNF30(void);
			virtual bool InvalidPreamp(void);
			virtual bool InvalidParseError(void);
#ifdef MAKEDLL
		public: // This is for internal use
			IAgencyApprovalInfo(){};
			IAgencyApprovalInfo(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _IAGENCY_APPROVAL_INFO_H
