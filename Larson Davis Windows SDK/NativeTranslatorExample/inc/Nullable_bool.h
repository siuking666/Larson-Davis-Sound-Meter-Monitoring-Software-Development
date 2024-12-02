/**************************************************************************//**
 * @file Nullable_bool.h
 * @brief Native Wrapper for Managed type Nullable<System::Boolean>.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _NULLABLE_BOOL_H
#define _NULLABLE_BOOL_H
namespace LarsonDavis
{
	namespace Native
	{

		struct LDAPI Nullable_bool
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			Nullable_bool(const Nullable_bool& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~Nullable_bool(void);
			Nullable_bool(void);
			bool GetValueOrDefault(void);
			bool GetValueOrDefault(bool defaultValue);
			Nullable_bool(bool value);
			bool HasValue(void);
			bool Value(void);
#ifdef MAKEDLL
		public: // This is for internal use
			Nullable_bool(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _NULLABLE_BOOL_H
