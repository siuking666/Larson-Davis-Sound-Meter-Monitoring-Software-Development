/**************************************************************************//**
 * @file IList_CMarineMammalsData.h
 * @brief Native Wrapper for Managed type IList<LarsonDavis::SDK::LDCommonStd::Utilities::MarineMammalsData^>.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ILIST_CMARINE_MAMMALS_DATA_H
#define _ILIST_CMARINE_MAMMALS_DATA_H
#include <CMarineMammalsData.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI CMarineMammalsData;

		class LDAPI IList_CMarineMammalsData
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			IList_CMarineMammalsData(const IList_CMarineMammalsData& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~IList_CMarineMammalsData(void);
			virtual int32_t IndexOf(std::shared_ptr<CMarineMammalsData> item);
			virtual void Insert(int32_t index, std::shared_ptr<CMarineMammalsData> item);
			virtual void RemoveAt(int32_t index);
			virtual std::shared_ptr<CMarineMammalsData> Item(int32_t index);
			virtual void Item(int32_t index, std::shared_ptr<CMarineMammalsData> value);
			virtual int32_t Count(void);
#ifdef MAKEDLL
		public: // This is for internal use
			IList_CMarineMammalsData(){};
			IList_CMarineMammalsData(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _ILIST_CMARINE_MAMMALS_DATA_H
