/**************************************************************************//**
 * @file CMetaDataRecord.h
 * @brief Native Wrapper for Managed type MetaDataRecord.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _CMETA_DATA_RECORD_H
#define _CMETA_DATA_RECORD_H
#include <IMetaDataRecord.h>
#include <EEditBandAction.h>
#include <EBlockTag.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI IMetaDataRecord;
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
		class LDAPI IRt60DecayMetaBlock;
		class LDAPI List_CRt60DecayInfo;
		class LDAPI CRt60DecayInfo;
		class LDAPI IComparer_CRt60DecayInfo;
		class LDAPI Array_CRt60DecayInfo;
		class LDAPI CSoundRecordMetaBlock;
		class LDAPI IList_CSoundRecordInfo;
		class LDAPI CSoundRecordInfo;
		class LDAPI CManifestMetaBlock;
		class LDAPI IList_CMetaBlockInfo;
		class LDAPI CMetaBlockInfo;

		class LDAPI CMetaDataRecord : public virtual IMetaDataRecord
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			CMetaDataRecord(const CMetaDataRecord& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~CMetaDataRecord(void);
			CMetaDataRecord(void);
			std::shared_ptr<IGeneralMetaBlock> GeneralBlock(void);
			void GeneralBlock(std::shared_ptr<IGeneralMetaBlock> value);
			std::shared_ptr<IEditBandMetaBlock> EditBandBlock(void);
			void EditBandBlock(std::shared_ptr<IEditBandMetaBlock> value);
			std::shared_ptr<IChartMetaBlock> ChartBlock(void);
			void ChartBlock(std::shared_ptr<IChartMetaBlock> value);
			std::shared_ptr<ICommentMetaBlock> MarkersBlock(void);
			void MarkersBlock(std::shared_ptr<ICommentMetaBlock> value);
			std::shared_ptr<IRt60DecayMetaBlock> Rt60DecayBlock(void);
			void Rt60DecayBlock(std::shared_ptr<IRt60DecayMetaBlock> value);
			std::shared_ptr<CSoundRecordMetaBlock> SoundRecordBlock(void);
			void SoundRecordBlock(std::shared_ptr<CSoundRecordMetaBlock> value);
			std::shared_ptr<CManifestMetaBlock> ManifestBlock(void);
			void ManifestBlock(std::shared_ptr<CManifestMetaBlock> value);
			StringWrapper FileName(void);
			void FileName(StringWrapper value);
			bool IsModified(void);
			void IsModified(bool value);
			bool IsReadOnlyFile(void);
			void IsReadOnlyFile(bool value);
			StringWrapper UniqueFileId(void);
			void UniqueFileId(StringWrapper value);
#ifdef MAKEDLL
		public: // This is for internal use
			CMetaDataRecord(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _CMETA_DATA_RECORD_H
