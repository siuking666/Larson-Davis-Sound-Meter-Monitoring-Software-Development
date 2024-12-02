/**************************************************************************//**
 * @file SstTHOptionInfo_t.h
 * @brief Native Wrapper for Managed type stTHOptionInfo_t.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _SST_THOPTION_INFO_T_H
#define _SST_THOPTION_INFO_T_H
#include <ETHOptionId.h>
#include <ETHOptionFlag.h>
#include <ETHOptionType.h>
#include <EUnitType.h>
namespace LarsonDavis
{
	namespace Native
	{

		struct LDAPI SstTHOptionInfo_t
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			SstTHOptionInfo_t(const SstTHOptionInfo_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~SstTHOptionInfo_t(void);
			SstTHOptionInfo_t(void);
			ETHOptionId id(void);
			void id(ETHOptionId value);
			ETHOptionFlag flag(void);
			void flag(ETHOptionFlag value);
			uint32_t option(void);
			void option(uint32_t value);
			ETHOptionType type(void);
			void type(ETHOptionType value);
			EUnitType unitType(void);
			void unitType(EUnitType value);
			StringWrapper label(void);
			void label(StringWrapper value);
			int32_t length(void);
			void length(int32_t value);
			int32_t order(void);
			void order(int32_t value);
#ifdef MAKEDLL
		public: // This is for internal use
			SstTHOptionInfo_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _SST_THOPTION_INFO_T_H
