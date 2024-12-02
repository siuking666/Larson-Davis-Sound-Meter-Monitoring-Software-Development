/**************************************************************************//**
 * @file IList_IConvertible.h
 * @brief Native Wrapper for Managed type IList<System::IConvertible^>.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ILIST_ICONVERTIBLE_H
#define _ILIST_ICONVERTIBLE_H
#include <IConvertible.h>
#include <ETypeCode.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI IConvertible;

		class LDAPI IList_IConvertible
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			IList_IConvertible(const IList_IConvertible& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~IList_IConvertible(void);
			virtual int32_t IndexOf(std::shared_ptr<IConvertible> item);
			virtual void Insert(int32_t index, std::shared_ptr<IConvertible> item);
			virtual void RemoveAt(int32_t index);
			virtual std::shared_ptr<IConvertible> Item(int32_t index);
			virtual void Item(int32_t index, std::shared_ptr<IConvertible> value);
			virtual int32_t Count(void);
#ifdef MAKEDLL
		public: // This is for internal use
			IList_IConvertible(){};
			IList_IConvertible(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _ILIST_ICONVERTIBLE_H
