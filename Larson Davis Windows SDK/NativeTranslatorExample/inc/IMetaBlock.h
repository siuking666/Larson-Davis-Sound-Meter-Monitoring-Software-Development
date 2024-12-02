/**************************************************************************//**
 * @file IMetaBlock.h
 * @brief Native Wrapper for Managed type IMetaBlock.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _IMETA_BLOCK_H
#define _IMETA_BLOCK_H
#include <EBlockTag.h>
namespace LarsonDavis
{
	namespace Native
	{

		class LDAPI IMetaBlock
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			IMetaBlock(const IMetaBlock& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~IMetaBlock(void);
			virtual EBlockTag BlockTag(void);
			virtual void BlockTag(EBlockTag value);
#ifdef MAKEDLL
		public: // This is for internal use
			IMetaBlock(){};
			IMetaBlock(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _IMETA_BLOCK_H
