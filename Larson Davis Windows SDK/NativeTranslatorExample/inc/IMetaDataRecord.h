/**************************************************************************//**
 * @file IMetaDataRecord.h
 * @brief Native Wrapper for Managed type IMetaDataRecord.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _IMETA_DATA_RECORD_H
#define _IMETA_DATA_RECORD_H
#include <EEditBandAction.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI IGeneralMetaBlock;
		class LDAPI CGeneralInfo;
		class LDAPI IEditBandMetaBlock;
		class LDAPI SortedList_int32_t_CEditBandInfo;
		class LDAPI CEditBandInfo;
		class LDAPI IComparer_int32_t;
		class LDAPI IDictionary_int32_t_CEditBandInfo;
		class LDAPI IList_int32_t;
		class LDAPI IList_CEditBandInfo;
		class LDAPI IChartMetaBlock;
		class LDAPI IList_CChartInfo;
		class LDAPI CChartInfo;
		class LDAPI ICommentMetaBlock;
		class LDAPI List_CMarkerInfo;
		class LDAPI CMarkerInfo;
		class LDAPI IComparer_CMarkerInfo;
		class LDAPI Array_CMarkerInfo;

		class LDAPI IMetaDataRecord
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			IMetaDataRecord(const IMetaDataRecord& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~IMetaDataRecord(void);
			virtual std::shared_ptr<IGeneralMetaBlock> GeneralBlock(void);
			virtual void GeneralBlock(std::shared_ptr<IGeneralMetaBlock> value);
			virtual std::shared_ptr<IEditBandMetaBlock> EditBandBlock(void);
			virtual void EditBandBlock(std::shared_ptr<IEditBandMetaBlock> value);
			virtual std::shared_ptr<IChartMetaBlock> ChartBlock(void);
			virtual void ChartBlock(std::shared_ptr<IChartMetaBlock> value);
			virtual std::shared_ptr<ICommentMetaBlock> MarkersBlock(void);
			virtual void MarkersBlock(std::shared_ptr<ICommentMetaBlock> value);
			virtual StringWrapper FileName(void);
			virtual void FileName(StringWrapper value);
			virtual bool IsModified(void);
			virtual void IsModified(bool value);
			virtual bool IsReadOnlyFile(void);
			virtual void IsReadOnlyFile(bool value);
			virtual StringWrapper UniqueFileId(void);
			virtual void UniqueFileId(StringWrapper value);
#ifdef MAKEDLL
		public: // This is for internal use
			IMetaDataRecord(){};
			IMetaDataRecord(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _IMETA_DATA_RECORD_H
