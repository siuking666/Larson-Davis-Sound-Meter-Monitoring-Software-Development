/**************************************************************************//**
 * @file CTimeHistoryRecord.h
 * @brief Native Wrapper for Managed type TimeHistoryRecord.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _CTIME_HISTORY_RECORD_H
#define _CTIME_HISTORY_RECORD_H
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI Array_float;
		class LDAPI Array_float_2;

		class LDAPI CTimeHistoryRecord
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			CTimeHistoryRecord(const CTimeHistoryRecord& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~CTimeHistoryRecord(void);
			float GetValue(int32_t nDx);
			void AllocArrays(int32_t numFloats, int32_t numFullOctave, int32_t numThirdOctave);
			CTimeHistoryRecord(void);
			uint32_t Action(void);
			void Action(uint32_t value);
			uint32_t Flag(void);
			void Flag(uint32_t value);
			int32_t RecordNum(void);
			void RecordNum(int32_t value);
			int64_t TimeStamp(void);
			void TimeStamp(int64_t value);
			std::shared_ptr<Array_float> THFloatVals(void);
			void THFloatVals(std::shared_ptr<Array_float> value);
			std::shared_ptr<Array_float_2> THFullOctaveOba(void);
			void THFullOctaveOba(std::shared_ptr<Array_float_2> value);
			std::shared_ptr<Array_float_2> THThirdOctaveOba(void);
			void THThirdOctaveOba(std::shared_ptr<Array_float_2> value);
			float Duration(void);
			void Duration(float value);
#ifdef MAKEDLL
		public: // This is for internal use
			CTimeHistoryRecord(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _CTIME_HISTORY_RECORD_H
