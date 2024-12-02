/**************************************************************************//**
 * @file Array_SstTHOptionInfo_t.h
 * @brief Native Wrapper for Managed type cli::array<LarsonDavis::SDK::LDCommonStd::Legacy::stTHOptionInfo_t, 1>.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ARRAY_SST_THOPTION_INFO_T_H
#define _ARRAY_SST_THOPTION_INFO_T_H
#include <CArray.h>
#include <IList_SstTHOptionInfo_t.h>
#include <SstTHOptionInfo_t.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI CArray;
		class LDAPI IList_SstTHOptionInfo_t;
		struct LDAPI SstTHOptionInfo_t;

		class LDAPI Array_SstTHOptionInfo_t : public CArray, public virtual IList_SstTHOptionInfo_t
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			Array_SstTHOptionInfo_t(const Array_SstTHOptionInfo_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~Array_SstTHOptionInfo_t(void);
			std::shared_ptr<SstTHOptionInfo_t> Get(int32_t arg0);
			void Set(int32_t arg0, std::shared_ptr<SstTHOptionInfo_t> arg1);
			Array_SstTHOptionInfo_t(int32_t arg0);
#ifdef MAKEDLL
		public: // This is for internal use
			Array_SstTHOptionInfo_t(){};
			Array_SstTHOptionInfo_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _ARRAY_SST_THOPTION_INFO_T_H
