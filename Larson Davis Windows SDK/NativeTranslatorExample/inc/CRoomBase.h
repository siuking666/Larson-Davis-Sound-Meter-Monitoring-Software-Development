/**************************************************************************//**
 * @file CRoomBase.h
 * @brief Native Wrapper for Managed type RoomBase.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _CROOM_BASE_H
#define _CROOM_BASE_H
#include <ERoomType.h>
namespace LarsonDavis
{
	namespace Native
	{

		class LDAPI CRoomBase
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			CRoomBase(const CRoomBase& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~CRoomBase(void);
			CRoomBase(void);
			int32_t Schema(void);
			void Schema(int32_t value);
			int32_t SubSchema(void);
			void SubSchema(int32_t value);
			int32_t Id(void);
			void Id(int32_t value);
			ERoomType Type(void);
			void Type(ERoomType value);
			StringWrapper Name(void);
			void Name(StringWrapper value);
#ifdef MAKEDLL
		public: // This is for internal use
			CRoomBase(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _CROOM_BASE_H
