/**************************************************************************//**
 * @file SUnit.h
 * @brief Native Wrapper for Managed type Unit.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _SUNIT_H
#define _SUNIT_H
namespace LarsonDavis
{
	namespace Native
	{

		struct LDAPI SUnit
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			SUnit(const SUnit& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~SUnit(void);
			SUnit(void);
			static std::shared_ptr<SUnit> Default(void);
#ifdef MAKEDLL
		public: // This is for internal use
			SUnit(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _SUNIT_H
