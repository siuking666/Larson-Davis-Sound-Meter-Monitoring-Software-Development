/**************************************************************************//**
 * @file Array_SDetector_t.h
 * @brief Native Wrapper for Managed type cli::array<LarsonDavis::SDK::LDCommonStd::Legacy::Detector_t, 1>.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ARRAY_SDETECTOR_T_H
#define _ARRAY_SDETECTOR_T_H
#include <CArray.h>
#include <IList_SDetector_t.h>
#include <SDetector_t.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI CArray;
		class LDAPI IList_SDetector_t;
		struct LDAPI SDetector_t;

		class LDAPI Array_SDetector_t : public CArray, public virtual IList_SDetector_t
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			Array_SDetector_t(const Array_SDetector_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~Array_SDetector_t(void);
			std::shared_ptr<SDetector_t> Get(int32_t arg0);
			void Set(int32_t arg0, std::shared_ptr<SDetector_t> arg1);
			Array_SDetector_t(int32_t arg0);
#ifdef MAKEDLL
		public: // This is for internal use
			Array_SDetector_t(){};
			Array_SDetector_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _ARRAY_SDETECTOR_T_H
