/**************************************************************************//**
 * @file SRT60_QI_t.h
 * @brief Native Wrapper for Managed type RT60_QI_t.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _SRT60_QI_T_H
#define _SRT60_QI_T_H
namespace LarsonDavis
{
	namespace Native
	{

		struct LDAPI SRT60_QI_t
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			SRT60_QI_t(const SRT60_QI_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~SRT60_QI_t(void);
			SRT60_QI_t(void);
			float Cu(void);
			void Cu(float value);
			float NL_T20(void);
			void NL_T20(float value);
			float NL_T30(void);
			void NL_T30(float value);
			float SD_T20(void);
			void SD_T20(float value);
			float SD_T30(void);
			void SD_T30(float value);
#ifdef MAKEDLL
		public: // This is for internal use
			SRT60_QI_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _SRT60_QI_T_H
