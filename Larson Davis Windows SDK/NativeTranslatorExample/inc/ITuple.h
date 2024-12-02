/**************************************************************************//**
 * @file ITuple.h
 * @brief Native Wrapper for Managed type ITuple.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ITUPLE_H
#define _ITUPLE_H
namespace LarsonDavis
{
	namespace Native
	{

		class LDAPI ITuple
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			ITuple(const ITuple& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~ITuple(void);
			virtual int32_t Length(void);
#ifdef MAKEDLL
		public: // This is for internal use
			ITuple(){};
			ITuple(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _ITUPLE_H
