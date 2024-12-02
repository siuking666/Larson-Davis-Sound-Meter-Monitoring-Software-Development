/**************************************************************************//**
 * @file IEditBandMetaBlock.h
 * @brief Native Wrapper for Managed type IEditBandMetaBlock.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _IEDIT_BAND_META_BLOCK_H
#define _IEDIT_BAND_META_BLOCK_H
#include <IMetaBlock.h>
#include <EEditBandAction.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI IMetaBlock;
		class LDAPI SortedList_int32_t_CEditBandInfo;
		class LDAPI CEditBandInfo;
		class LDAPI IComparer_int32_t;
		class LDAPI IDictionary_int32_t_CEditBandInfo;
		class LDAPI IList_int32_t;
		class LDAPI IList_CEditBandInfo;

		class LDAPI IEditBandMetaBlock : public virtual IMetaBlock
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			IEditBandMetaBlock(const IEditBandMetaBlock& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~IEditBandMetaBlock(void);
			virtual std::shared_ptr<SortedList_int32_t_CEditBandInfo> EditBands(void);
			virtual void EditBands(std::shared_ptr<SortedList_int32_t_CEditBandInfo> value);
			virtual bool EndAdjusted(void);
			virtual void EndAdjusted(bool value);
#ifdef MAKEDLL
		public: // This is for internal use
			IEditBandMetaBlock(){};
			IEditBandMetaBlock(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _IEDIT_BAND_META_BLOCK_H
