/**************************************************************************//**
 * @file CTimeHistoryManager.h
 * @brief Native Wrapper for Managed type TimeHistoryManager.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _CTIME_HISTORY_MANAGER_H
#define _CTIME_HISTORY_MANAGER_H
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI IList_SstTHItemInfo_t;
		class LDAPI IList_CTimeHistoryRecord;
		class LDAPI CTimeHistoryRecord;
		class LDAPI Array_float;
		class LDAPI Array_float_2;

		class LDAPI CTimeHistoryManager
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			CTimeHistoryManager(const CTimeHistoryManager& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~CTimeHistoryManager(void);
			void SetNumVals(void);
			int32_t GetTmsIndex(std::shared_ptr<IList_SstTHItemInfo_t> thItems);
			CTimeHistoryManager(void);
			int32_t NumTHRecords(void);
			void NumTHRecords(int32_t value);
			uint32_t THFlags1(void);
			void THFlags1(uint32_t value);
			uint32_t THFlags2(void);
			void THFlags2(uint32_t value);
			uint32_t THFlags3(void);
			void THFlags3(uint32_t value);
			int32_t RecLen(void);
			void RecLen(int32_t value);
			int32_t THStructVer(void);
			void THStructVer(int32_t value);
			int64_t THDataOffset(void);
			void THDataOffset(int64_t value);
			int32_t NumFloatVals(void);
			void NumFloatVals(int32_t value);
			int32_t NumOba11Vals(void);
			void NumOba11Vals(int32_t value);
			int32_t NumOba13Vals(void);
			void NumOba13Vals(int32_t value);
			int32_t MiscStartIndex(void);
			void MiscStartIndex(int32_t value);
			bool DurFracEnable(void);
			void DurFracEnable(bool value);
			int32_t DurFracIndex(void);
			void DurFracIndex(int32_t value);
			int32_t NumTimeHistoryItems(void);
			std::shared_ptr<IList_CTimeHistoryRecord> THRecs(void);
			void THRecs(std::shared_ptr<IList_CTimeHistoryRecord> value);
#ifdef MAKEDLL
		public: // This is for internal use
			CTimeHistoryManager(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _CTIME_HISTORY_MANAGER_H
