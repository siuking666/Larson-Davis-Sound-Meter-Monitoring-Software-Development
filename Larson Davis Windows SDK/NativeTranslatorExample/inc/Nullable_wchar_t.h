/**************************************************************************//**
 * @file Nullable_wchar_t.h
 * @brief Native Wrapper for Managed type Nullable<System::Char>.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _NULLABLE_WCHAR_T_H
#define _NULLABLE_WCHAR_T_H
namespace LarsonDavis
{
	namespace Native
	{

		struct LDAPI Nullable_wchar_t
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			Nullable_wchar_t(const Nullable_wchar_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~Nullable_wchar_t(void);
			Nullable_wchar_t(void);
			wchar_t GetValueOrDefault(void);
			wchar_t GetValueOrDefault(wchar_t defaultValue);
			Nullable_wchar_t(wchar_t value);
			bool HasValue(void);
			wchar_t Value(void);
#ifdef MAKEDLL
		public: // This is for internal use
			Nullable_wchar_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _NULLABLE_WCHAR_T_H
