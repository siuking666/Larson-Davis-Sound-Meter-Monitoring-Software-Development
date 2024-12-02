/**************************************************************************//**
 * @file IComparer_int32_t.h
 * @brief Native Wrapper for Managed type IComparer<System::Int32>.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ICOMPARER_INT32_T_H
#define _ICOMPARER_INT32_T_H
namespace LarsonDavis
{
	namespace Native
	{

		class LDAPI IComparer_int32_t
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			IComparer_int32_t(const IComparer_int32_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~IComparer_int32_t(void);
			virtual int32_t Compare(int32_t x, int32_t y);
#ifdef MAKEDLL
		public: // This is for internal use
			IComparer_int32_t(){};
			IComparer_int32_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _ICOMPARER_INT32_T_H
