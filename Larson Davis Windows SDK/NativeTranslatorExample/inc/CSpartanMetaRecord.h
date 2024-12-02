/**************************************************************************//**
 * @file CSpartanMetaRecord.h
 * @brief Native Wrapper for Managed type SpartanMetaRecord.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _CSPARTAN_META_RECORD_H
#define _CSPARTAN_META_RECORD_H
#include <IMetaDataRecord.h>
#include <EEditBandAction.h>
#include <ECalibrationType.h>
#include <EPreampType.h>
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
		class LDAPI CCalibration;
		struct LDAPI SDateTime;
		struct LDAPI SCalData2_t;
		class LDAPI Array_float;

		class LDAPI CSpartanMetaRecord : public virtual IMetaDataRecord
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			CSpartanMetaRecord(const CSpartanMetaRecord& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~CSpartanMetaRecord(void);
			std::shared_ptr<CSpartanMetaRecord> ReadFromFile(StringWrapper path);
			bool ClearFromFile(StringWrapper filePath);
			bool WriteToFile(void);
			bool WriteToFile(StringWrapper path);
			CSpartanMetaRecord(void);
			std::shared_ptr<IGeneralMetaBlock> GeneralBlock(void);
			void GeneralBlock(std::shared_ptr<IGeneralMetaBlock> value);
			std::shared_ptr<IEditBandMetaBlock> EditBandBlock(void);
			void EditBandBlock(std::shared_ptr<IEditBandMetaBlock> value);
			std::shared_ptr<IChartMetaBlock> ChartBlock(void);
			void ChartBlock(std::shared_ptr<IChartMetaBlock> value);
			std::shared_ptr<ICommentMetaBlock> MarkersBlock(void);
			void MarkersBlock(std::shared_ptr<ICommentMetaBlock> value);
			std::shared_ptr<CCalibration> PostCal(void);
			void PostCal(std::shared_ptr<CCalibration> value);
			StringWrapper FileName(void);
			void FileName(StringWrapper value);
			bool IsModified(void);
			void IsModified(bool value);
			bool IsReadOnlyFile(void);
			void IsReadOnlyFile(bool value);
			StringWrapper Version(void);
			void Version(StringWrapper value);
			StringWrapper UniqueFileId(void);
			void UniqueFileId(StringWrapper value);
			StringWrapper AppVersion(void);
#ifdef MAKEDLL
		public: // This is for internal use
			CSpartanMetaRecord(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _CSPARTAN_META_RECORD_H
