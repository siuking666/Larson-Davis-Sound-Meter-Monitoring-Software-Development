/**************************************************************************//**
 * @file IList_Sset_Float.h
 * @brief Native Wrapper for Managed type IList<LarsonDavis::SDK::LDCommonStd::Legacy::set_Float>.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ILIST_SSET_FLOAT_H
#define _ILIST_SSET_FLOAT_H
#include <Sset_Float.h>
namespace LarsonDavis
{
	namespace Native
	{
		struct LDAPI Sset_Float;

		class LDAPI IList_Sset_Float
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			IList_Sset_Float(const IList_Sset_Float& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~IList_Sset_Float(void);
			virtual int32_t IndexOf(std::shared_ptr<Sset_Float> item);
			virtual void Insert(int32_t index, std::shared_ptr<Sset_Float> item);
			virtual void RemoveAt(int32_t index);
			virtual std::shared_ptr<Sset_Float> Item(int32_t index);
			virtual void Item(int32_t index, std::shared_ptr<Sset_Float> value);
			virtual int32_t Count(void);
#ifdef MAKEDLL
		public: // This is for internal use
			IList_Sset_Float(){};
			IList_Sset_Float(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _ILIST_SSET_FLOAT_H
