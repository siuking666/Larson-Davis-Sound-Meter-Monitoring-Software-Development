/**************************************************************************//**
 * @file ILDRecordWithMetaRecord_CSpartanMetaRecord.h
 * @brief Native Wrapper for Managed type ILDRecordWithMetaRecord<LarsonDavis::SDK::LDCommonStd::MetaData::SpartanMetaRecord^>.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ILDRECORD_WITH_META_RECORD_CSPARTAN_META_RECORD_H
#define _ILDRECORD_WITH_META_RECORD_CSPARTAN_META_RECORD_H
#include <ILDRecord.h>
#include <CSpartanMetaRecord.h>
#include <EEditBandAction.h>
#include <ECalibrationType.h>
#include <EPreampType.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI ILDRecord;
		class LDAPI CSpartanMetaRecord;
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
		class LDAPI CCalibration;
		struct LDAPI SDateTime;
		struct LDAPI SCalData2_t;
		class LDAPI Array_float;

		class LDAPI ILDRecordWithMetaRecord_CSpartanMetaRecord : public virtual ILDRecord
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			ILDRecordWithMetaRecord_CSpartanMetaRecord(const ILDRecordWithMetaRecord_CSpartanMetaRecord& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~ILDRecordWithMetaRecord_CSpartanMetaRecord(void);
			virtual std::shared_ptr<CSpartanMetaRecord> MetaRec(void);
#ifdef MAKEDLL
		public: // This is for internal use
			ILDRecordWithMetaRecord_CSpartanMetaRecord(){};
			ILDRecordWithMetaRecord_CSpartanMetaRecord(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _ILDRECORD_WITH_META_RECORD_CSPARTAN_META_RECORD_H
