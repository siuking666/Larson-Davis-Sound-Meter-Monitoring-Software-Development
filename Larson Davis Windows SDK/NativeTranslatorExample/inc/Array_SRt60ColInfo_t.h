/**************************************************************************//**
 * @file Array_SRt60ColInfo_t.h
 * @brief Native Wrapper for Managed type cli::array<LarsonDavis::SDK::LDCommonStd::Legacy::Rt60ColInfo_t, 1>.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ARRAY_SRT60_COL_INFO_T_H
#define _ARRAY_SRT60_COL_INFO_T_H
#include <CArray.h>
#include <IList_SRt60ColInfo_t.h>
#include <SRt60ColInfo_t.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI CArray;
		class LDAPI IList_SRt60ColInfo_t;
		struct LDAPI SRt60ColInfo_t;

		class LDAPI Array_SRt60ColInfo_t : public CArray, public virtual IList_SRt60ColInfo_t
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			Array_SRt60ColInfo_t(const Array_SRt60ColInfo_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~Array_SRt60ColInfo_t(void);
			std::shared_ptr<SRt60ColInfo_t> Get(int32_t arg0);
			void Set(int32_t arg0, std::shared_ptr<SRt60ColInfo_t> arg1);
			Array_SRt60ColInfo_t(int32_t arg0);
#ifdef MAKEDLL
		public: // This is for internal use
			Array_SRt60ColInfo_t(){};
			Array_SRt60ColInfo_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _ARRAY_SRT60_COL_INFO_T_H
