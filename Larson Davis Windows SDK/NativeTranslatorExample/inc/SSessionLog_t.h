/**************************************************************************//**
 * @file SSessionLog_t.h
 * @brief Native Wrapper for Managed type SessionLog_t.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _SSESSION_LOG_T_H
#define _SSESSION_LOG_T_H
#include <ISupportByteArrayConversion.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI ISupportByteArrayConversion;
		struct LDAPI SLoggedData_t;

		struct LDAPI SSessionLog_t : public virtual ISupportByteArrayConversion
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			SSessionLog_t(const SSessionLog_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~SSessionLog_t(void);
			SSessionLog_t(void);
			int32_t time(void);
			void time(int32_t value);
			uint16_t flags(void);
			void flags(uint16_t value);
			int16_t count(void);
			void count(int16_t value);
			int32_t recNum(void);
			void recNum(int32_t value);
			std::shared_ptr<SLoggedData_t> data(void);
			void data(std::shared_ptr<SLoggedData_t> value);
#ifdef MAKEDLL
		public: // This is for internal use
			SSessionLog_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _SSESSION_LOG_T_H
