/**************************************************************************//**
 * @file SCalHistoryTypes_t.h
 * @brief Native Wrapper for Managed type CalHistoryTypes_t.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _SCAL_HISTORY_TYPES_T_H
#define _SCAL_HISTORY_TYPES_T_H
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI Array_SCalData2_t;

		struct LDAPI SCalHistoryTypes_t
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			SCalHistoryTypes_t(const SCalHistoryTypes_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~SCalHistoryTypes_t(void);
			SCalHistoryTypes_t(void);
			std::shared_ptr<Array_SCalData2_t> data(void);
			void data(std::shared_ptr<Array_SCalData2_t> value);
#ifdef MAKEDLL
		public: // This is for internal use
			SCalHistoryTypes_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _SCAL_HISTORY_TYPES_T_H
