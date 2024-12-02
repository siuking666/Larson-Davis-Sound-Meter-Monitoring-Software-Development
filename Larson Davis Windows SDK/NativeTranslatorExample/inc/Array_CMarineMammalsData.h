/**************************************************************************//**
 * @file Array_CMarineMammalsData.h
 * @brief Native Wrapper for Managed type cli::array<LarsonDavis::SDK::LDCommonStd::Utilities::MarineMammalsData^, 1>.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ARRAY_CMARINE_MAMMALS_DATA_H
#define _ARRAY_CMARINE_MAMMALS_DATA_H
#include <CArray.h>
#include <IList_CMarineMammalsData.h>
#include <CMarineMammalsData.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI CArray;
		class LDAPI IList_CMarineMammalsData;
		class LDAPI CMarineMammalsData;

		class LDAPI Array_CMarineMammalsData : public CArray, public virtual IList_CMarineMammalsData
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			Array_CMarineMammalsData(const Array_CMarineMammalsData& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~Array_CMarineMammalsData(void);
			void Set(int32_t arg0, std::shared_ptr<CMarineMammalsData> arg1);
			std::shared_ptr<CMarineMammalsData> Get(int32_t arg0);
			Array_CMarineMammalsData(int32_t arg0);
#ifdef MAKEDLL
		public: // This is for internal use
			Array_CMarineMammalsData(){};
			Array_CMarineMammalsData(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _ARRAY_CMARINE_MAMMALS_DATA_H
