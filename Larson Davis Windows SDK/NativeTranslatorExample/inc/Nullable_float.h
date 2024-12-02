/**************************************************************************//**
 * @file Nullable_float.h
 * @brief Native Wrapper for Managed type Nullable<System::Single>.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _NULLABLE_FLOAT_H
#define _NULLABLE_FLOAT_H
namespace LarsonDavis
{
	namespace Native
	{

		struct LDAPI Nullable_float
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			Nullable_float(const Nullable_float& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~Nullable_float(void);
			Nullable_float(void);
			float GetValueOrDefault(void);
			float GetValueOrDefault(float defaultValue);
			Nullable_float(float value);
			bool HasValue(void);
			float Value(void);
#ifdef MAKEDLL
		public: // This is for internal use
			Nullable_float(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _NULLABLE_FLOAT_H
