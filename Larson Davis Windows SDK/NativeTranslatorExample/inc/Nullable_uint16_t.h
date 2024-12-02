/**************************************************************************//**
 * @file Nullable_uint16_t.h
 * @brief Native Wrapper for Managed type Nullable<System::UInt16>.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _NULLABLE_UINT16_T_H
#define _NULLABLE_UINT16_T_H
namespace LarsonDavis
{
	namespace Native
	{

		struct LDAPI Nullable_uint16_t
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			Nullable_uint16_t(const Nullable_uint16_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~Nullable_uint16_t(void);
			Nullable_uint16_t(void);
			uint16_t GetValueOrDefault(void);
			uint16_t GetValueOrDefault(uint16_t defaultValue);
			Nullable_uint16_t(uint16_t value);
			bool HasValue(void);
			uint16_t Value(void);
#ifdef MAKEDLL
		public: // This is for internal use
			Nullable_uint16_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _NULLABLE_UINT16_T_H
