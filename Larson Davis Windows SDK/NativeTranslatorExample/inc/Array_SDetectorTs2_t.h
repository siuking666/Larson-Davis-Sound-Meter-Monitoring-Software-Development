/**************************************************************************//**
 * @file Array_SDetectorTs2_t.h
 * @brief Native Wrapper for Managed type cli::array<LarsonDavis::SDK::LDCommonStd::Core::DetectorTs2_t, 1>.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ARRAY_SDETECTOR_TS2_T_H
#define _ARRAY_SDETECTOR_TS2_T_H
#include <CArray.h>
#include <IList_SDetectorTs2_t.h>
#include <SDetectorTs2_t.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI CArray;
		class LDAPI IList_SDetectorTs2_t;
		struct LDAPI SDetectorTs2_t;

		class LDAPI Array_SDetectorTs2_t : public CArray, public virtual IList_SDetectorTs2_t
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			Array_SDetectorTs2_t(const Array_SDetectorTs2_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~Array_SDetectorTs2_t(void);
			std::shared_ptr<SDetectorTs2_t> Get(int32_t arg0);
			void Set(int32_t arg0, std::shared_ptr<SDetectorTs2_t> arg1);
			Array_SDetectorTs2_t(int32_t arg0);
#ifdef MAKEDLL
		public: // This is for internal use
			Array_SDetectorTs2_t(){};
			Array_SDetectorTs2_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _ARRAY_SDETECTOR_TS2_T_H
