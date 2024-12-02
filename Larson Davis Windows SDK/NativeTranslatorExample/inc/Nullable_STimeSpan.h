/**************************************************************************//**
 * @file Nullable_STimeSpan.h
 * @brief Native Wrapper for Managed type Nullable<System::TimeSpan>.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _NULLABLE_STIME_SPAN_H
#define _NULLABLE_STIME_SPAN_H
namespace LarsonDavis
{
	namespace Native
	{
		struct LDAPI STimeSpan;

		struct LDAPI Nullable_STimeSpan
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			Nullable_STimeSpan(const Nullable_STimeSpan& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~Nullable_STimeSpan(void);
			Nullable_STimeSpan(void);
			std::shared_ptr<STimeSpan> GetValueOrDefault(void);
			std::shared_ptr<STimeSpan> GetValueOrDefault(std::shared_ptr<STimeSpan> defaultValue);
			Nullable_STimeSpan(std::shared_ptr<STimeSpan> value);
			bool HasValue(void);
			std::shared_ptr<STimeSpan> Value(void);
#ifdef MAKEDLL
		public: // This is for internal use
			Nullable_STimeSpan(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _NULLABLE_STIME_SPAN_H
