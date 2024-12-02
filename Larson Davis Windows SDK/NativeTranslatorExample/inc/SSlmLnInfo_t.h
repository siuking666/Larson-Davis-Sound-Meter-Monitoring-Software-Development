/**************************************************************************//**
 * @file SSlmLnInfo_t.h
 * @brief Native Wrapper for Managed type SlmLnInfo_t.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _SSLM_LN_INFO_T_H
#define _SSLM_LN_INFO_T_H
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI Array_int32_t;

		struct LDAPI SSlmLnInfo_t
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			SSlmLnInfo_t(const SSlmLnInfo_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~SSlmLnInfo_t(void);
			SSlmLnInfo_t(void);
			std::shared_ptr<Array_int32_t> lnTable(void);
			void lnTable(std::shared_ptr<Array_int32_t> value);
			int32_t baseDB(void);
			void baseDB(int32_t value);
			int32_t status(void);
			void status(int32_t value);
			int32_t samples(void);
			void samples(int32_t value);
#ifdef MAKEDLL
		public: // This is for internal use
			SSlmLnInfo_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _SSLM_LN_INFO_T_H
