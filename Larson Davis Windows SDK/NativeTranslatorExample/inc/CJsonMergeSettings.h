/**************************************************************************//**
 * @file CJsonMergeSettings.h
 * @brief Native Wrapper for Managed type JsonMergeSettings.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _CJSON_MERGE_SETTINGS_H
#define _CJSON_MERGE_SETTINGS_H
#include <EMergeArrayHandling.h>
#include <EMergeNullValueHandling.h>
#include <EStringComparison.h>
namespace LarsonDavis
{
	namespace Native
	{

		class LDAPI CJsonMergeSettings
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			CJsonMergeSettings(const CJsonMergeSettings& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~CJsonMergeSettings(void);
			CJsonMergeSettings(void);
			EMergeArrayHandling MergeArrayHandling(void);
			void MergeArrayHandling(EMergeArrayHandling value);
			EMergeNullValueHandling MergeNullValueHandling(void);
			void MergeNullValueHandling(EMergeNullValueHandling value);
			EStringComparison PropertyNameComparison(void);
			void PropertyNameComparison(EStringComparison value);
#ifdef MAKEDLL
		public: // This is for internal use
			CJsonMergeSettings(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _CJSON_MERGE_SETTINGS_H
