/**************************************************************************//**
 * @file SstTHItemInfo_t.h
 * @brief Native Wrapper for Managed type stTHItemInfo_t.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _SST_THITEM_INFO_T_H
#define _SST_THITEM_INFO_T_H
#include <ETHOptionId.h>
#include <ETHOptionType.h>
#include <EUnitType.h>
namespace LarsonDavis
{
	namespace Native
	{

		struct LDAPI SstTHItemInfo_t
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			SstTHItemInfo_t(const SstTHItemInfo_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~SstTHItemInfo_t(void);
			SstTHItemInfo_t(void);
			int32_t ndx(void);
			void ndx(int32_t value);
			ETHOptionId id(void);
			void id(ETHOptionId value);
			ETHOptionType type(void);
			void type(ETHOptionType value);
			EUnitType unitType(void);
			void unitType(EUnitType value);
			StringWrapper label(void);
			void label(StringWrapper value);
			int32_t order(void);
			void order(int32_t value);
#ifdef MAKEDLL
		public: // This is for internal use
			SstTHItemInfo_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _SST_THITEM_INFO_T_H
