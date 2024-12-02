/**************************************************************************//**
 * @file CRoomTx.h
 * @brief Native Wrapper for Managed type RoomTx.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _CROOM_TX_H
#define _CROOM_TX_H
#include <CRoomBase.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI CRoomBase;
		class LDAPI CMeasureRta;
		struct LDAPI SRtaRecord_t;
		struct LDAPI SRaHeader_t;
		class LDAPI Array_float;

		class LDAPI CRoomTx : public CRoomBase
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			CRoomTx(const CRoomTx& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~CRoomTx(void);
			CRoomTx(void);
			std::shared_ptr<CMeasureRta> L1(void);
			void L1(std::shared_ptr<CMeasureRta> value);
#ifdef MAKEDLL
		public: // This is for internal use
			CRoomTx(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _CROOM_TX_H
