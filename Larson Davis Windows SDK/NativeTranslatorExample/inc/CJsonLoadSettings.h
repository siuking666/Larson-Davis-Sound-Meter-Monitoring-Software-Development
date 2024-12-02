/**************************************************************************//**
 * @file CJsonLoadSettings.h
 * @brief Native Wrapper for Managed type JsonLoadSettings.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _CJSON_LOAD_SETTINGS_H
#define _CJSON_LOAD_SETTINGS_H
#include <ECommentHandling.h>
#include <ELineInfoHandling.h>
#include <EDuplicatePropertyNameHandling.h>
namespace LarsonDavis
{
	namespace Native
	{

		class LDAPI CJsonLoadSettings
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			CJsonLoadSettings(const CJsonLoadSettings& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~CJsonLoadSettings(void);
			CJsonLoadSettings(void);
			ECommentHandling CommentHandling(void);
			void CommentHandling(ECommentHandling value);
			ELineInfoHandling LineInfoHandling(void);
			void LineInfoHandling(ELineInfoHandling value);
			EDuplicatePropertyNameHandling DuplicatePropertyNameHandling(void);
			void DuplicatePropertyNameHandling(EDuplicatePropertyNameHandling value);
#ifdef MAKEDLL
		public: // This is for internal use
			CJsonLoadSettings(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _CJSON_LOAD_SETTINGS_H
