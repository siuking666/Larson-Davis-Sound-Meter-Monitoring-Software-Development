/**************************************************************************//**
 * @file CEventTimeHistoryManager.h
 * @brief Native Wrapper for Managed type EventTimeHistoryManager.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _CEVENT_TIME_HISTORY_MANAGER_H
#define _CEVENT_TIME_HISTORY_MANAGER_H
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI Array_SEventTHRecord_t;
		struct LDAPI SEventTHRecord_t;

		class LDAPI CEventTimeHistoryManager
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			CEventTimeHistoryManager(const CEventTimeHistoryManager& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~CEventTimeHistoryManager(void);
			void SetNumVals(int32_t samples, int32_t obaSize);
			CEventTimeHistoryManager(void);
			int32_t NumSamples(void);
			void NumSamples(int32_t value);
			int32_t ObaSize(void);
			void ObaSize(int32_t value);
			int32_t EventTHRecordVersion(void);
			void EventTHRecordVersion(int32_t value);
			std::shared_ptr<Array_SEventTHRecord_t> ETHRecs(void);
			void ETHRecs(std::shared_ptr<Array_SEventTHRecord_t> value);
#ifdef MAKEDLL
		public: // This is for internal use
			CEventTimeHistoryManager(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _CEVENT_TIME_HISTORY_MANAGER_H
