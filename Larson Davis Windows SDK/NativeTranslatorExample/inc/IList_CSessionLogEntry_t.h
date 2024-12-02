/**************************************************************************//**
 * @file IList_CSessionLogEntry_t.h
 * @brief Native Wrapper for Managed type IList<LarsonDavis::SDK::LDCommonStd::Core::SessionLogEntry_t^>.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ILIST_CSESSION_LOG_ENTRY_T_H
#define _ILIST_CSESSION_LOG_ENTRY_T_H
#include <CSessionLogEntry_t.h>
#include <ESpartanSLogType.h>
#include <ESpartanSLogCause.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI CSessionLogEntry_t;
		class LDAPI Array_uint8_t;

		class LDAPI IList_CSessionLogEntry_t
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			IList_CSessionLogEntry_t(const IList_CSessionLogEntry_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~IList_CSessionLogEntry_t(void);
			virtual int32_t IndexOf(std::shared_ptr<CSessionLogEntry_t> item);
			virtual void Insert(int32_t index, std::shared_ptr<CSessionLogEntry_t> item);
			virtual void RemoveAt(int32_t index);
			virtual std::shared_ptr<CSessionLogEntry_t> Item(int32_t index);
			virtual void Item(int32_t index, std::shared_ptr<CSessionLogEntry_t> value);
			virtual int32_t Count(void);
#ifdef MAKEDLL
		public: // This is for internal use
			IList_CSessionLogEntry_t(){};
			IList_CSessionLogEntry_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _ILIST_CSESSION_LOG_ENTRY_T_H
