/**************************************************************************//**
 * @file CSessionLogEntry_t.h
 * @brief Native Wrapper for Managed type SessionLogEntry_t.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _CSESSION_LOG_ENTRY_T_H
#define _CSESSION_LOG_ENTRY_T_H
#include <ESpartanSLogType.h>
#include <ESpartanSLogCause.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI Array_uint8_t;

		class LDAPI CSessionLogEntry_t
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			CSessionLogEntry_t(const CSessionLogEntry_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~CSessionLogEntry_t(void);
			CSessionLogEntry_t(std::shared_ptr<Array_uint8_t> entry);
			uint32_t Timestamp(void);
			void Timestamp(uint32_t value);
			StringWrapper Type(void);
			void Type(StringWrapper value);
			StringWrapper Cause(void);
			void Cause(StringWrapper value);
			int32_t Number(void);
			void Number(int32_t value);
			ESpartanSLogType TypeId(void);
			void TypeId(ESpartanSLogType value);
			ESpartanSLogCause CauseId(void);
			void CauseId(ESpartanSLogCause value);
#ifdef MAKEDLL
		public: // This is for internal use
			CSessionLogEntry_t(){};
			CSessionLogEntry_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _CSESSION_LOG_ENTRY_T_H
