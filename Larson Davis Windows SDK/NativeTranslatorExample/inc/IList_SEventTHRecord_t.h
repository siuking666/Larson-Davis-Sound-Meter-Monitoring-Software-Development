/**************************************************************************//**
 * @file IList_SEventTHRecord_t.h
 * @brief Native Wrapper for Managed type IList<LarsonDavis::SDK::LDCommonStd::Legacy::EventTHRecord_t>.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ILIST_SEVENT_THRECORD_T_H
#define _ILIST_SEVENT_THRECORD_T_H
#include <SEventTHRecord_t.h>
namespace LarsonDavis
{
	namespace Native
	{
		struct LDAPI SEventTHRecord_t;
		class LDAPI Array_float;
		struct LDAPI SEventTHWind_t;

		class LDAPI IList_SEventTHRecord_t
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			IList_SEventTHRecord_t(const IList_SEventTHRecord_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~IList_SEventTHRecord_t(void);
			virtual int32_t IndexOf(std::shared_ptr<SEventTHRecord_t> item);
			virtual void Insert(int32_t index, std::shared_ptr<SEventTHRecord_t> item);
			virtual void RemoveAt(int32_t index);
			virtual std::shared_ptr<SEventTHRecord_t> Item(int32_t index);
			virtual void Item(int32_t index, std::shared_ptr<SEventTHRecord_t> value);
			virtual int32_t Count(void);
#ifdef MAKEDLL
		public: // This is for internal use
			IList_SEventTHRecord_t(){};
			IList_SEventTHRecord_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _ILIST_SEVENT_THRECORD_T_H
