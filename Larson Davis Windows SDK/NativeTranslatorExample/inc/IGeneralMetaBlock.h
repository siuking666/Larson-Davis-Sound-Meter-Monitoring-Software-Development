/**************************************************************************//**
 * @file IGeneralMetaBlock.h
 * @brief Native Wrapper for Managed type IGeneralMetaBlock.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _IGENERAL_META_BLOCK_H
#define _IGENERAL_META_BLOCK_H
#include <IMetaBlock.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI IMetaBlock;
		class LDAPI CGeneralInfo;

		class LDAPI IGeneralMetaBlock : public virtual IMetaBlock
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			IGeneralMetaBlock(const IGeneralMetaBlock& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~IGeneralMetaBlock(void);
			virtual std::shared_ptr<CGeneralInfo> GeneralInfo(void);
			virtual void GeneralInfo(std::shared_ptr<CGeneralInfo> value);
#ifdef MAKEDLL
		public: // This is for internal use
			IGeneralMetaBlock(){};
			IGeneralMetaBlock(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _IGENERAL_META_BLOCK_H
