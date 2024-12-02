/**************************************************************************//**
 * @file CSlmLegacy.h
 * @brief Native Wrapper for Managed type SlmLegacy.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _CSLM_LEGACY_H
#define _CSLM_LEGACY_H
#include <EMeterType.h>
#include <EPreampType.h>
namespace LarsonDavis
{
	namespace Native
	{

		class LDAPI CSlmLegacy
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			CSlmLegacy(const CSlmLegacy& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~CSlmLegacy(void);
			static bool IsValid(float val);
			static StringWrapper MakeLWeightDetectorString(int32_t wgt, int32_t det, StringWrapper metric);
			static StringWrapper MakeLWeightDetectorHTML(int32_t wgt, int32_t det, StringWrapper metric);
			static StringWrapper MakeLWeightDetectorString(int32_t wgt, int32_t det, StringWrapper metric, StringWrapper format);
			static StringWrapper GetPreampName(EMeterType meter, EPreampType preamp, bool restricted = false);
			static int32_t GetAudioSampleRate(int32_t samplingRate);
#ifdef MAKEDLL
		public: // This is for internal use
			CSlmLegacy(){};
			CSlmLegacy(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _CSLM_LEGACY_H
