/**************************************************************************//**
 * @file CSpartanSoundRecord.h
 * @brief Native Wrapper for Managed type SpartanSoundRecord.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _CSPARTAN_SOUND_RECORD_H
#define _CSPARTAN_SOUND_RECORD_H
namespace LarsonDavis
{
	namespace Native
	{

		class LDAPI CSpartanSoundRecord
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			CSpartanSoundRecord(const CSpartanSoundRecord& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~CSpartanSoundRecord(void);
#ifdef MAKEDLL
		public: // This is for internal use
			CSpartanSoundRecord(){};
			CSpartanSoundRecord(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _CSPARTAN_SOUND_RECORD_H
