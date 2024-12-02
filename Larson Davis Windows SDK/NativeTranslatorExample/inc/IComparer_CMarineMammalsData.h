/**************************************************************************//**
 * @file IComparer_CMarineMammalsData.h
 * @brief Native Wrapper for Managed type IComparer<LarsonDavis::SDK::LDCommonStd::Utilities::MarineMammalsData^>.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ICOMPARER_CMARINE_MAMMALS_DATA_H
#define _ICOMPARER_CMARINE_MAMMALS_DATA_H
#include <CMarineMammalsData.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI CMarineMammalsData;

		class LDAPI IComparer_CMarineMammalsData
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			IComparer_CMarineMammalsData(const IComparer_CMarineMammalsData& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~IComparer_CMarineMammalsData(void);
			virtual int32_t Compare(std::shared_ptr<CMarineMammalsData> x, std::shared_ptr<CMarineMammalsData> y);
#ifdef MAKEDLL
		public: // This is for internal use
			IComparer_CMarineMammalsData(){};
			IComparer_CMarineMammalsData(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _ICOMPARER_CMARINE_MAMMALS_DATA_H
