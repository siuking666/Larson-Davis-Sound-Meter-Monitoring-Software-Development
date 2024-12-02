/**************************************************************************//**
 * @file Nullable_double.h
 * @brief Native Wrapper for Managed type Nullable<System::Double>.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _NULLABLE_DOUBLE_H
#define _NULLABLE_DOUBLE_H
namespace LarsonDavis
{
	namespace Native
	{

		struct LDAPI Nullable_double
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			Nullable_double(const Nullable_double& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~Nullable_double(void);
			Nullable_double(void);
			double GetValueOrDefault(void);
			double GetValueOrDefault(double defaultValue);
			Nullable_double(double value);
			bool HasValue(void);
			double Value(void);
#ifdef MAKEDLL
		public: // This is for internal use
			Nullable_double(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _NULLABLE_DOUBLE_H
