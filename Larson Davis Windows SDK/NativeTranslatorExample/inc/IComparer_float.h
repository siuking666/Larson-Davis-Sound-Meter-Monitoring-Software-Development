/**************************************************************************//**
 * @file IComparer_float.h
 * @brief Native Wrapper for Managed type IComparer<System::Single>.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ICOMPARER_FLOAT_H
#define _ICOMPARER_FLOAT_H
namespace LarsonDavis
{
	namespace Native
	{

		class LDAPI IComparer_float
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			IComparer_float(const IComparer_float& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~IComparer_float(void);
			virtual int32_t Compare(float x, float y);
#ifdef MAKEDLL
		public: // This is for internal use
			IComparer_float(){};
			IComparer_float(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _ICOMPARER_FLOAT_H
