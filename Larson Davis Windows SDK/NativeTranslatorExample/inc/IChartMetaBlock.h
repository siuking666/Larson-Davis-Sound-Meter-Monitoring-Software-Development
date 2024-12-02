/**************************************************************************//**
 * @file IChartMetaBlock.h
 * @brief Native Wrapper for Managed type IChartMetaBlock.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ICHART_META_BLOCK_H
#define _ICHART_META_BLOCK_H
#include <IMetaBlock.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI IMetaBlock;
		class LDAPI IList_CChartInfo;
		class LDAPI CChartInfo;

		class LDAPI IChartMetaBlock : public virtual IMetaBlock
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			IChartMetaBlock(const IChartMetaBlock& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~IChartMetaBlock(void);
			virtual std::shared_ptr<IList_CChartInfo> Charts(void);
			virtual void Charts(std::shared_ptr<IList_CChartInfo> value);
#ifdef MAKEDLL
		public: // This is for internal use
			IChartMetaBlock(){};
			IChartMetaBlock(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _ICHART_META_BLOCK_H
