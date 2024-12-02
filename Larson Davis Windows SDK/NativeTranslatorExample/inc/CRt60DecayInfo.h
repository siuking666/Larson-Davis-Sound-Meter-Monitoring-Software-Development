/**************************************************************************//**
 * @file CRt60DecayInfo.h
 * @brief Native Wrapper for Managed type Rt60DecayInfo.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _CRT60_DECAY_INFO_H
#define _CRT60_DECAY_INFO_H
#include <IRt60DecayInfo.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI IRt60DecayInfo;

		class LDAPI CRt60DecayInfo : public virtual IRt60DecayInfo
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			CRt60DecayInfo(const CRt60DecayInfo& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~CRt60DecayInfo(void);
			CRt60DecayInfo(void);
			CRt60DecayInfo(int32_t whichDecay, bool excluded);
			int32_t WhichDecay(void);
			void WhichDecay(int32_t value);
			bool Excluded(void);
			void Excluded(bool value);
#ifdef MAKEDLL
		public: // This is for internal use
			CRt60DecayInfo(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _CRT60_DECAY_INFO_H
