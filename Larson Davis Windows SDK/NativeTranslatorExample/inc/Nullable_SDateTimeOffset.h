/**************************************************************************//**
 * @file Nullable_SDateTimeOffset.h
 * @brief Native Wrapper for Managed type Nullable<System::DateTimeOffset>.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _NULLABLE_SDATE_TIME_OFFSET_H
#define _NULLABLE_SDATE_TIME_OFFSET_H
#include <EDateTimeKind.h>
#include <ETypeCode.h>
#include <EDayOfWeek.h>
namespace LarsonDavis
{
	namespace Native
	{
		struct LDAPI SDateTimeOffset;
		struct LDAPI STimeSpan;
		struct LDAPI SDateTime;
		class LDAPI Array_StringWrapper;

		struct LDAPI Nullable_SDateTimeOffset
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			Nullable_SDateTimeOffset(const Nullable_SDateTimeOffset& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~Nullable_SDateTimeOffset(void);
			Nullable_SDateTimeOffset(void);
			std::shared_ptr<SDateTimeOffset> GetValueOrDefault(void);
			std::shared_ptr<SDateTimeOffset> GetValueOrDefault(std::shared_ptr<SDateTimeOffset> defaultValue);
			Nullable_SDateTimeOffset(std::shared_ptr<SDateTimeOffset> value);
			bool HasValue(void);
			std::shared_ptr<SDateTimeOffset> Value(void);
#ifdef MAKEDLL
		public: // This is for internal use
			Nullable_SDateTimeOffset(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _NULLABLE_SDATE_TIME_OFFSET_H
