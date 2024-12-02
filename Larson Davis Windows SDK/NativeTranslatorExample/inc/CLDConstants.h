/**************************************************************************//**
 * @file CLDConstants.h
 * @brief Native Wrapper for Managed type LDConstants.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _CLDCONSTANTS_H
#define _CLDCONSTANTS_H
#include <EDateTimeKind.h>
#include <ETypeCode.h>
#include <EDayOfWeek.h>
namespace LarsonDavis
{
	namespace Native
	{
		struct LDAPI SDateTime;
		struct LDAPI STimeSpan;
		class LDAPI Array_StringWrapper;

		class LDAPI CLDConstants
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			CLDConstants(const CLDConstants& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~CLDConstants(void);
			static StringWrapper DefaultTimeFormat(void);
			static StringWrapper DefaultDateFormat(void);
			static StringWrapper DefaultDateTimeFormat(void);
			static StringWrapper DefaultStatusDateTimeFormat(void);
			static float InvalidVal(void);
			static int32_t HoursPerDay(void);
			static int32_t SecondsPerMinute(void);
			static int32_t SecondsPerHour(void);
			static int32_t SecondsPerDay(void);
			static uint32_t MilliPerSecond(void);
			static uint32_t SubSecondThFactor(void);
			static uint32_t MicroPerMilli(void);
			static uint32_t MicroPerSecond(void);
			static std::shared_ptr<SDateTime> Epoch(void);
			static int32_t MaxExcelRows(void);
			static float MaxdB(void);
			static StringWrapper NewMeterString(void);
			static int32_t BrowserButtonsHeight(void);
			static StringWrapper ModelName831C(void);
			static StringWrapper ModelName831(void);
			static StringWrapper ModelNameLxT(void);
			static StringWrapper ModelNameLxTse(void);
			static StringWrapper ModelNameHVM200(void);
			static StringWrapper ModelNameHVM100(void);
			static StringWrapper ModelName730(void);
			static StringWrapper ModelName730IS(void);
			static StringWrapper ModelNameWD730(void);
			static StringWrapper ModelName821(void);
			static StringWrapper ModelName721(void);
			static StringWrapper ModelName821se(void);
			static StringWrapper ModelName721se(void);
			static StringWrapper MetersHeader(void);
			static StringWrapper ProjectsHeader(void);
			static uint16_t DefaultSecurePort(void);
			static uint16_t DefaultNonSecurePort(void);
			static uint16_t DefaultLocalhostBasePort(void);
			static int32_t MaxSettingsNameLenOnMeterWithoutExtension(void);
			static StringWrapper IPv4Localhost(void);
			static StringWrapper LocalhostName(void);
			static double FishSELThreshold(void);
			static double MaxValidWindSpeed(void);
			static int32_t MarineMammalsEventTriggerLevel(void);
			static int32_t MarineMammalsPrePeakTime(void);
			static int32_t MarineMammalsPostPeakTime(void);
			static int32_t SpreadsheetDefaultLastColumn(void);
			static StringWrapper X21_MARKER_CHAR(void);
			static int32_t NumWeights(void);
			static int32_t FullOctaveBins(void);
			static int32_t ThirdOctaveBins(void);
			static float ValidPTBSeal(void);
			static uint32_t SealStateMask(void);
			static uint16_t DefaultSecurePort_(void);
			static uint16_t DefaultNonSecurePort_(void);
			static uint16_t DefaultLocalhostBasePort_(void);
#ifdef MAKEDLL
		public: // This is for internal use
			CLDConstants(){};
			CLDConstants(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _CLDCONSTANTS_H
