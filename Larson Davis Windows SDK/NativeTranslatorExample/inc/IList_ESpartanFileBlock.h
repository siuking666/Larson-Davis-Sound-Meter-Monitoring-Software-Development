/**************************************************************************//**
 * @file IList_ESpartanFileBlock.h
 * @brief Native Wrapper for Managed type IList<LarsonDavis::SDK::LDCommonStd::Core::SpartanFileBlock>.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ILIST_ESPARTAN_FILE_BLOCK_H
#define _ILIST_ESPARTAN_FILE_BLOCK_H
#include <ESpartanFileBlock.h>
namespace LarsonDavis
{
	namespace Native
	{

		class LDAPI IList_ESpartanFileBlock
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			IList_ESpartanFileBlock(const IList_ESpartanFileBlock& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~IList_ESpartanFileBlock(void);
			virtual int32_t IndexOf(ESpartanFileBlock item);
			virtual void Insert(int32_t index, ESpartanFileBlock item);
			virtual void RemoveAt(int32_t index);
			virtual ESpartanFileBlock Item(int32_t index);
			virtual void Item(int32_t index, ESpartanFileBlock value);
			virtual int32_t Count(void);
#ifdef MAKEDLL
		public: // This is for internal use
			IList_ESpartanFileBlock(){};
			IList_ESpartanFileBlock(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _ILIST_ESPARTAN_FILE_BLOCK_H
