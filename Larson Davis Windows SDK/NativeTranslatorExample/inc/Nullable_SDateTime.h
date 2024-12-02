/**************************************************************************//**
 * @file Nullable_SDateTime.h
 * @brief Native Wrapper for Managed type Nullable<System::DateTime>.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _NULLABLE_SDATE_TIME_H
#define _NULLABLE_SDATE_TIME_H
#include <EDateTimeKind.h>
#include <ETypeCode.h>
#include <EDayOfWeek.h>
namespace LarsonDavis
{
	namespace Native
	{
		struct LDAPI SDateTime;
		struct LDAPI STimeSpan;
		class LDAPI Array_StringWrapper;

		struct LDAPI Nullable_SDateTime
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			Nullable_SDateTime(const Nullable_SDateTime& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~Nullable_SDateTime(void);
			Nullable_SDateTime(void);
			std::shared_ptr<SDateTime> GetValueOrDefault(void);
			std::shared_ptr<SDateTime> GetValueOrDefault(std::shared_ptr<SDateTime> defaultValue);
			Nullable_SDateTime(std::shared_ptr<SDateTime> value);
			bool HasValue(void);
			std::shared_ptr<SDateTime> Value(void);
#ifdef MAKEDLL
		public: // This is for internal use
			Nullable_SDateTime(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _NULLABLE_SDATE_TIME_H
