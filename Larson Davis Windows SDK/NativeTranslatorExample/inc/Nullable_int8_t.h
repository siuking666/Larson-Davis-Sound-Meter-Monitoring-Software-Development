/**************************************************************************//**
 * @file Nullable_int8_t.h
 * @brief Native Wrapper for Managed type Nullable<System::SByte>.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _NULLABLE_INT8_T_H
#define _NULLABLE_INT8_T_H
namespace LarsonDavis
{
	namespace Native
	{

		struct LDAPI Nullable_int8_t
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			Nullable_int8_t(const Nullable_int8_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~Nullable_int8_t(void);
			Nullable_int8_t(void);
			int8_t GetValueOrDefault(void);
			int8_t GetValueOrDefault(int8_t defaultValue);
			Nullable_int8_t(int8_t value);
			bool HasValue(void);
			int8_t Value(void);
#ifdef MAKEDLL
		public: // This is for internal use
			Nullable_int8_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _NULLABLE_INT8_T_H
