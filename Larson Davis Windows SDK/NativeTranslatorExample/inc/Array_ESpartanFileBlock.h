/**************************************************************************//**
 * @file Array_ESpartanFileBlock.h
 * @brief Native Wrapper for Managed type cli::array<LarsonDavis::SDK::LDCommonStd::Core::SpartanFileBlock, 1>.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ARRAY_ESPARTAN_FILE_BLOCK_H
#define _ARRAY_ESPARTAN_FILE_BLOCK_H
#include <CArray.h>
#include <IList_ESpartanFileBlock.h>
#include <ESpartanFileBlock.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI CArray;
		class LDAPI IList_ESpartanFileBlock;

		class LDAPI Array_ESpartanFileBlock : public CArray, public virtual IList_ESpartanFileBlock
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			Array_ESpartanFileBlock(const Array_ESpartanFileBlock& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~Array_ESpartanFileBlock(void);
			ESpartanFileBlock Get(int32_t arg0);
			void Set(int32_t arg0, ESpartanFileBlock arg1);
			Array_ESpartanFileBlock(int32_t arg0);
#ifdef MAKEDLL
		public: // This is for internal use
			Array_ESpartanFileBlock(){};
			Array_ESpartanFileBlock(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _ARRAY_ESPARTAN_FILE_BLOCK_H
