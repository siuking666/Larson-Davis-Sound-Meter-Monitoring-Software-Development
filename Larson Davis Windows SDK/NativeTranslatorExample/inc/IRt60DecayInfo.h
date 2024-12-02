/**************************************************************************//**
 * @file IRt60DecayInfo.h
 * @brief Native Wrapper for Managed type IRt60DecayInfo.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _IRT60_DECAY_INFO_H
#define _IRT60_DECAY_INFO_H
namespace LarsonDavis
{
	namespace Native
	{

		class LDAPI IRt60DecayInfo
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			IRt60DecayInfo(const IRt60DecayInfo& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~IRt60DecayInfo(void);
			virtual int32_t WhichDecay(void);
			virtual void WhichDecay(int32_t value);
			virtual bool Excluded(void);
			virtual void Excluded(bool value);
#ifdef MAKEDLL
		public: // This is for internal use
			IRt60DecayInfo(){};
			IRt60DecayInfo(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _IRT60_DECAY_INFO_H
