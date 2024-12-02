/**************************************************************************//**
 * @file IList_CMeasureFft.h
 * @brief Native Wrapper for Managed type IList<LarsonDavis::SDK::LDCommonStd::Legacy::MeasureFft^>.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ILIST_CMEASURE_FFT_H
#define _ILIST_CMEASURE_FFT_H
#include <CMeasureFft.h>
#include <EFftLevel.h>
#include <EVsqConvert.h>
#include <EFftFrequencySpan.h>
#include <EFftLines.h>
#include <EFftWindow.h>
#include <EFftRunMode.h>
#include <EWeightingNdx.h>
#include <EFftTonalityStandard.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI CMeasureFft;
		struct LDAPI SFftRecord_t;
		struct LDAPI SFftInfo_t;
		struct LDAPI SFftLevels_t;
		struct LDAPI SFftTriggerInfo_t;
		class LDAPI IList_CToneInfo;
		class LDAPI CToneInfo;

		class LDAPI IList_CMeasureFft
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			IList_CMeasureFft(const IList_CMeasureFft& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~IList_CMeasureFft(void);
			virtual int32_t IndexOf(std::shared_ptr<CMeasureFft> item);
			virtual void Insert(int32_t index, std::shared_ptr<CMeasureFft> item);
			virtual void RemoveAt(int32_t index);
			virtual std::shared_ptr<CMeasureFft> Item(int32_t index);
			virtual void Item(int32_t index, std::shared_ptr<CMeasureFft> value);
			virtual int32_t Count(void);
#ifdef MAKEDLL
		public: // This is for internal use
			IList_CMeasureFft(){};
			IList_CMeasureFft(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _ILIST_CMEASURE_FFT_H
