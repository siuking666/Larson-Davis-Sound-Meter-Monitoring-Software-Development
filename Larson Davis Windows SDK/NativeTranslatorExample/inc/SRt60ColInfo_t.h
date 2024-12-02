/**************************************************************************//**
 * @file SRt60ColInfo_t.h
 * @brief Native Wrapper for Managed type Rt60ColInfo_t.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _SRT60_COL_INFO_T_H
#define _SRT60_COL_INFO_T_H
#include <ERt60RecType.h>
#include <EFormatType.h>
namespace LarsonDavis
{
	namespace Native
	{

		struct LDAPI SRt60ColInfo_t
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			SRt60ColInfo_t(const SRt60ColInfo_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~SRt60ColInfo_t(void);
			SRt60ColInfo_t(void);
			ERt60RecType id(void);
			void id(ERt60RecType value);
			StringWrapper str(void);
			void str(StringWrapper value);
			StringWrapper units(void);
			void units(StringWrapper value);
			EFormatType fmtId(void);
			void fmtId(EFormatType value);
#ifdef MAKEDLL
		public: // This is for internal use
			SRt60ColInfo_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _SRT60_COL_INFO_T_H
