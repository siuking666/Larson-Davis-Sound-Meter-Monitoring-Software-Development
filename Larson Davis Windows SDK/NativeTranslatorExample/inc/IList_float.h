/**************************************************************************//**
 * @file IList_float.h
 * @brief Native Wrapper for Managed type IList<System::Single>.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ILIST_FLOAT_H
#define _ILIST_FLOAT_H
namespace LarsonDavis
{
	namespace Native
	{

		class LDAPI IList_float
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			IList_float(const IList_float& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~IList_float(void);
			virtual int32_t IndexOf(float item);
			virtual void Insert(int32_t index, float item);
			virtual void RemoveAt(int32_t index);
			virtual float Item(int32_t index);
			virtual void Item(int32_t index, float value);
			virtual int32_t Count(void);
#ifdef MAKEDLL
		public: // This is for internal use
			IList_float(){};
			IList_float(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _ILIST_FLOAT_H
