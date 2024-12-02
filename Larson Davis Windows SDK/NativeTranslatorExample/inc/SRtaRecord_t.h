/**************************************************************************//**
 * @file SRtaRecord_t.h
 * @brief Native Wrapper for Managed type RtaRecord_t.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _SRTA_RECORD_T_H
#define _SRTA_RECORD_T_H
#include <ISupportByteArrayConversion.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI ISupportByteArrayConversion;
		struct LDAPI SRaHeader_t;
		class LDAPI Array_float;

		struct LDAPI SRtaRecord_t : public virtual ISupportByteArrayConversion
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			SRtaRecord_t(const SRtaRecord_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~SRtaRecord_t(void);
			SRtaRecord_t(void);
			std::shared_ptr<SRaHeader_t> stHdr(void);
			void stHdr(std::shared_ptr<SRaHeader_t> value);
			std::shared_ptr<Array_float> fullOctave(void);
			void fullOctave(std::shared_ptr<Array_float> value);
			std::shared_ptr<Array_float> thirdOctave(void);
			void thirdOctave(std::shared_ptr<Array_float> value);
#ifdef MAKEDLL
		public: // This is for internal use
			SRtaRecord_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _SRTA_RECORD_T_H
