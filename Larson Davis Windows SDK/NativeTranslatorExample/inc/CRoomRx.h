/**************************************************************************//**
 * @file CRoomRx.h
 * @brief Native Wrapper for Managed type RoomRx.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _CROOM_RX_H
#define _CROOM_RX_H
#include <CRoomBase.h>
#include <ERt60RecType.h>
#include <ERt60Method.h>
#include <ERt60QualityIndicator.h>
#include <ERt60SamplePeriod.h>
#include <ERt60DataPoint.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI CRoomBase;
		class LDAPI CMeasureRt60;
		struct LDAPI SRt60ByTime_t;
		class LDAPI Array_SRt60TimeSample_t;
		class LDAPI Array_SRt60DataLimits_t;
		struct LDAPI SRt60CalcLines_t;
		struct LDAPI SRt60Record_t;
		class LDAPI CMeasureRta;
		struct LDAPI SRtaRecord_t;
		struct LDAPI SRaHeader_t;
		class LDAPI Array_float;
		class LDAPI Array_CMeasureRt60;

		class LDAPI CRoomRx : public CRoomBase
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			CRoomRx(const CRoomRx& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~CRoomRx(void);
			CRoomRx(void);
			std::shared_ptr<CMeasureRt60> T2(void);
			void T2(std::shared_ptr<CMeasureRt60> value);
			std::shared_ptr<CMeasureRta> B2(void);
			void B2(std::shared_ptr<CMeasureRta> value);
			std::shared_ptr<CMeasureRta> L2(void);
			void L2(std::shared_ptr<CMeasureRta> value);
			std::shared_ptr<Array_CMeasureRt60> Positions(void);
			void Positions(std::shared_ptr<Array_CMeasureRt60> value);
#ifdef MAKEDLL
		public: // This is for internal use
			CRoomRx(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _CROOM_RX_H
