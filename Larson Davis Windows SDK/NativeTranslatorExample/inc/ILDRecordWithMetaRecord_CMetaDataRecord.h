/**************************************************************************//**
 * @file ILDRecordWithMetaRecord_CMetaDataRecord.h
 * @brief Native Wrapper for Managed type ILDRecordWithMetaRecord<LarsonDavis::SDK::LDCommonStd::MetaData::MetaDataRecord^>.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ILDRECORD_WITH_META_RECORD_CMETA_DATA_RECORD_H
#define _ILDRECORD_WITH_META_RECORD_CMETA_DATA_RECORD_H
#include <ILDRecord.h>
#include <CMetaDataRecord.h>
#include <EEditBandAction.h>
#include <EBlockTag.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI ILDRecord;
		class LDAPI CMetaDataRecord;
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

		class LDAPI ILDRecordWithMetaRecord_CMetaDataRecord : public virtual ILDRecord
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			ILDRecordWithMetaRecord_CMetaDataRecord(const ILDRecordWithMetaRecord_CMetaDataRecord& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~ILDRecordWithMetaRecord_CMetaDataRecord(void);
			virtual std::shared_ptr<CMetaDataRecord> MetaRec(void);
#ifdef MAKEDLL
		public: // This is for internal use
			ILDRecordWithMetaRecord_CMetaDataRecord(){};
			ILDRecordWithMetaRecord_CMetaDataRecord(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _ILDRECORD_WITH_META_RECORD_CMETA_DATA_RECORD_H
