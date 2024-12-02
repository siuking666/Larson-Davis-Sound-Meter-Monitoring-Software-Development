/**************************************************************************//**
 * @file CJsonSelectSettings.h
 * @brief Native Wrapper for Managed type JsonSelectSettings.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _CJSON_SELECT_SETTINGS_H
#define _CJSON_SELECT_SETTINGS_H
namespace LarsonDavis
{
	namespace Native
	{
		struct LDAPI Nullable_STimeSpan;
		struct LDAPI STimeSpan;

		class LDAPI CJsonSelectSettings
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			CJsonSelectSettings(const CJsonSelectSettings& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~CJsonSelectSettings(void);
			CJsonSelectSettings(void);
			std::shared_ptr<Nullable_STimeSpan> RegexMatchTimeout(void);
			void RegexMatchTimeout(std::shared_ptr<Nullable_STimeSpan> value);
			bool ErrorWhenNoMatch(void);
			void ErrorWhenNoMatch(bool value);
#ifdef MAKEDLL
		public: // This is for internal use
			CJsonSelectSettings(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _CJSON_SELECT_SETTINGS_H
