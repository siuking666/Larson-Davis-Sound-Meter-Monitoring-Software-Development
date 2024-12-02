/**************************************************************************//**
 * @file CMeasureRta.h
 * @brief Native Wrapper for Managed type MeasureRta.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _CMEASURE_RTA_H
#define _CMEASURE_RTA_H
#include <CMeasureBase.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI CMeasureBase;
		struct LDAPI SRtaRecord_t;
		struct LDAPI SRaHeader_t;
		class LDAPI Array_float;

		class LDAPI CMeasureRta : public CMeasureBase
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			CMeasureRta(const CMeasureRta& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~CMeasureRta(void);
			CMeasureRta(void);
			std::shared_ptr<SRtaRecord_t> RtaHeader(void);
			void RtaHeader(std::shared_ptr<SRtaRecord_t> value);
			uint32_t Flags(void);
			void Flags(uint32_t value);
#ifdef MAKEDLL
		public: // This is for internal use
			CMeasureRta(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _CMEASURE_RTA_H
