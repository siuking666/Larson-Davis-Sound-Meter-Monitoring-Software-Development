/**************************************************************************//**
 * @file SRt60ColOrder_t.h
 * @brief Native Wrapper for Managed type Rt60ColOrder_t.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _SRT60_COL_ORDER_T_H
#define _SRT60_COL_ORDER_T_H
#include <ISupportByteArrayConversion.h>
#include <ERt60RecType.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI ISupportByteArrayConversion;

		struct LDAPI SRt60ColOrder_t : public virtual ISupportByteArrayConversion
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			SRt60ColOrder_t(const SRt60ColOrder_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~SRt60ColOrder_t(void);
			SRt60ColOrder_t(void);
			ERt60RecType id(void);
			void id(ERt60RecType value);
			uint32_t headerAlign(void);
			void headerAlign(uint32_t value);
			uint32_t dataAlign(void);
			void dataAlign(uint32_t value);
#ifdef MAKEDLL
		public: // This is for internal use
			SRt60ColOrder_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _SRT60_COL_ORDER_T_H
