/**************************************************************************//**
 * @file Array_IConvertible.h
 * @brief Native Wrapper for Managed type cli::array<System::IConvertible^, 1>.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ARRAY_ICONVERTIBLE_H
#define _ARRAY_ICONVERTIBLE_H
#include <CArray.h>
#include <IList_IConvertible.h>
#include <IConvertible.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI CArray;
		class LDAPI IList_IConvertible;
		class LDAPI IConvertible;

		class LDAPI Array_IConvertible : public CArray, public virtual IList_IConvertible
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			Array_IConvertible(const Array_IConvertible& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~Array_IConvertible(void);
			void Set(int32_t arg0, std::shared_ptr<IConvertible> arg1);
			std::shared_ptr<IConvertible> Get(int32_t arg0);
			Array_IConvertible(int32_t arg0);
#ifdef MAKEDLL
		public: // This is for internal use
			Array_IConvertible(){};
			Array_IConvertible(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _ARRAY_ICONVERTIBLE_H
