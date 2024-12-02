/**************************************************************************//**
 * @file SDoseCriteria_t.h
 * @brief Native Wrapper for Managed type DoseCriteria_t.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _SDOSE_CRITERIA_T_H
#define _SDOSE_CRITERIA_T_H
namespace LarsonDavis
{
	namespace Native
	{

		struct LDAPI SDoseCriteria_t
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			SDoseCriteria_t(const SDoseCriteria_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~SDoseCriteria_t(void);
			SDoseCriteria_t(void);
			StringWrapper doseName(void);
			void doseName(StringWrapper value);
			bool threshEnable(void);
			void threshEnable(bool value);
			uint8_t exchRate(void);
			void exchRate(uint8_t value);
			float threshold(void);
			void threshold(float value);
			float critLevel(void);
			void critLevel(float value);
			float critDuration(void);
			void critDuration(float value);
#ifdef MAKEDLL
		public: // This is for internal use
			SDoseCriteria_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _SDOSE_CRITERIA_T_H
