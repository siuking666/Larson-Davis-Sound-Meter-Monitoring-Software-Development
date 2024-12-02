/**************************************************************************//**
 * @file ITypedList.h
 * @brief Native Wrapper for Managed type ITypedList.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ITYPED_LIST_H
#define _ITYPED_LIST_H
namespace LarsonDavis
{
	namespace Native
	{

		class LDAPI ITypedList
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			ITypedList(const ITypedList& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~ITypedList(void);
#ifdef MAKEDLL
		public: // This is for internal use
			ITypedList(){};
			ITypedList(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _ITYPED_LIST_H
