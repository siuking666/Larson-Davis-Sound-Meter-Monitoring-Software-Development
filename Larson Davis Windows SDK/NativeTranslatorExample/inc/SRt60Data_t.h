/**************************************************************************//**
 * @file SRt60Data_t.h
 * @brief Native Wrapper for Managed type Rt60Data_t.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _SRT60_DATA_T_H
#define _SRT60_DATA_T_H
namespace LarsonDavis
{
	namespace Native
	{

		struct LDAPI SRt60Data_t
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			SRt60Data_t(const SRt60Data_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~SRt60Data_t(void);
			SRt60Data_t(void);
			float slopeT20(void);
			void slopeT20(float value);
			float interceptT20(void);
			void interceptT20(float value);
			float decayTimeT20(void);
			void decayTimeT20(float value);
			float slopeT30(void);
			void slopeT30(float value);
			float interceptT30(void);
			void interceptT30(float value);
			float decayTimeT30(void);
			void decayTimeT30(float value);
			float slopeEdt(void);
			void slopeEdt(float value);
			float interceptEdt(void);
			void interceptEdt(float value);
			float decayTimeEdt(void);
			void decayTimeEdt(float value);
#ifdef MAKEDLL
		public: // This is for internal use
			SRt60Data_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _SRT60_DATA_T_H
