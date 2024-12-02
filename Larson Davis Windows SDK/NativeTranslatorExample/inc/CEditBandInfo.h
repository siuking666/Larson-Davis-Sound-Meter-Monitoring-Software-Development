/**************************************************************************//**
 * @file CEditBandInfo.h
 * @brief Native Wrapper for Managed type EditBandInfo.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _CEDIT_BAND_INFO_H
#define _CEDIT_BAND_INFO_H
#include <IEditBandInfo.h>
#include <EEditBandAction.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI IEditBandInfo;

		class LDAPI CEditBandInfo : public virtual IEditBandInfo
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			CEditBandInfo(const CEditBandInfo& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~CEditBandInfo(void);
			CEditBandInfo(void);
			CEditBandInfo(int32_t id, EEditBandAction action, int32_t begin, int64_t beginTime, int32_t end, int64_t endTime, float offset);
			int32_t Id(void);
			void Id(int32_t value);
			EEditBandAction Action(void);
			void Action(EEditBandAction value);
			EEditBandAction PrevAction(void);
			void PrevAction(EEditBandAction value);
			int32_t Begin(void);
			void Begin(int32_t value);
			int64_t BeginTime(void);
			void BeginTime(int64_t value);
			int32_t End(void);
			void End(int32_t value);
			int64_t EndTime(void);
			void EndTime(int64_t value);
			int32_t PrevBegin(void);
			void PrevBegin(int32_t value);
			int64_t PrevBeginTime(void);
			void PrevBeginTime(int64_t value);
			int32_t PrevEnd(void);
			void PrevEnd(int32_t value);
			int64_t PrevEndTime(void);
			void PrevEndTime(int64_t value);
			float Offset(void);
			void Offset(float value);
			float PrevOffset(void);
			void PrevOffset(float value);
			bool LastBand(void);
			void LastBand(bool value);
#ifdef MAKEDLL
		public: // This is for internal use
			CEditBandInfo(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _CEDIT_BAND_INFO_H
