// This file may be included by any module that wants a complete list of types defined
#include <stdint.h>
#include <string>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI IEnableLogger;
		class LDAPI CEventArgs;
		class LDAPI CPropertyChangingEventArgs;
		class LDAPI IReactiveObject;
		class LDAPI IReactivePropertyChangedEventArgs_IReactiveObject;
		class LDAPI IObserver_IReactivePropertyChangedEventArgs_IReactiveObject;
		class LDAPI IObservable_IReactivePropertyChangedEventArgs_IReactiveObject;
		class LDAPI IReactiveNotifyPropertyChanged_IReactiveObject;
		class LDAPI IHandleObservableErrors;
		class LDAPI CReactiveObject;
		struct LDAPI SUnit;
		class LDAPI IObserver_SUnit;
		class LDAPI IObservable_SUnit;
		class LDAPI CViewModelActivator;
		class LDAPI IActivatableViewModel;
		class LDAPI IActivatableReactiveObject;
		class LDAPI ICleanup;
		class LDAPI CReactiveObservableBase;
		enum class ETypeCode;
		class LDAPI IConvertible;
		class LDAPI IList;
		class LDAPI IList_int32_t;
		class LDAPI Array_int32_t;
		class LDAPI IList_int64_t;
		class LDAPI Array_int64_t;
		class LDAPI IComparer;
		class LDAPI CArray;
		class LDAPI IList_StringWrapper;
		class LDAPI Array_StringWrapper;
		enum class ETimeSpanStyles;
		struct LDAPI STimeSpan;
		enum class EDateTimeKind;
		enum class EDateTimeStyles;
		enum class EDayOfWeek;
		struct LDAPI SDateTime;
		enum class ECalibrationType;
		class LDAPI ISupportByteArrayConversion;
		class LDAPI IList_float;
		class LDAPI Array_float;
		struct LDAPI SCalData2_t;
		enum class EPreampType;
		class LDAPI CCalibration;
		enum class EParseError : uint32_t;
		enum class EMeterType;
		struct LDAPI SPTBInfo_t;
		class LDAPI ILDRecord;
		class LDAPI CLDRecordBase;
		enum class EBlockTag;
		class LDAPI IMetaBlock;
		class LDAPI IGeneralInfo;
		class LDAPI CGeneralInfo;
		class LDAPI IGeneralMetaBlock;
		enum class EEditBandAction;
		class LDAPI IEditBandInfo;
		class LDAPI CEditBandInfo;
		class LDAPI IDictionary_int32_t_CEditBandInfo;
		class LDAPI IDictionary;
		class LDAPI IComparer_int32_t;
		class LDAPI IList_CEditBandInfo;
		class LDAPI SortedList_int32_t_CEditBandInfo;
		class LDAPI IEditBandMetaBlock;
		class LDAPI IChartInfo;
		class LDAPI CChartInfo;
		class LDAPI IList_CChartInfo;
		class LDAPI IChartMetaBlock;
		class LDAPI IMarkerInfo;
		class LDAPI CMarkerInfo;
		class LDAPI IList_CMarkerInfo;
		class LDAPI IComparer_CMarkerInfo;
		class LDAPI Array_CMarkerInfo;
		class LDAPI List_CMarkerInfo;
		class LDAPI ICommentMetaBlock;
		class LDAPI IMetaDataRecord;
		class LDAPI IRt60DecayInfo;
		class LDAPI CRt60DecayInfo;
		class LDAPI IList_CRt60DecayInfo;
		class LDAPI IComparer_CRt60DecayInfo;
		class LDAPI Array_CRt60DecayInfo;
		class LDAPI List_CRt60DecayInfo;
		class LDAPI IRt60DecayMetaBlock;
		class LDAPI IMetaBlockInfo;
		class LDAPI CMetaBlockInfo;
		class LDAPI ISoundRecordInfo;
		class LDAPI CSoundRecordInfo;
		class LDAPI IList_CSoundRecordInfo;
		class LDAPI ISoundRecordMetaBlock;
		class LDAPI CSoundRecordMetaBlock;
		class LDAPI IList_CMetaBlockInfo;
		class LDAPI IManifestMetaBlock;
		class LDAPI CManifestMetaBlock;
		class LDAPI CMetaDataRecord;
		class LDAPI ILDRecordWithMetaRecord_CMetaDataRecord;
		enum class EMeasureType;
		enum class EMeasureSubType;
		class LDAPI CMeasureBase;
		enum class ERt60RecType;
		enum class ERt60Method;
		enum class ERt60QualityIndicator;
		enum class ERt60SamplePeriod;
		enum class ERt60DataPoint;
		struct LDAPI SRt60TimeSample_t;
		class LDAPI IList_SRt60TimeSample_t;
		class LDAPI Array_SRt60TimeSample_t;
		struct LDAPI SRt60DataLimits_t;
		class LDAPI IList_SRt60DataLimits_t;
		class LDAPI Array_SRt60DataLimits_t;
		struct LDAPI SRt60ByTime_t;
		struct LDAPI SRt60CalcLines_t;
		struct LDAPI SRaHeader_t;
		struct LDAPI SRt60SampleData_t;
		class LDAPI IList_SRt60SampleData_t;
		class LDAPI Array_SRt60SampleData_t;
		struct LDAPI SRt60Sample_t;
		class LDAPI IList_uint8_t;
		class LDAPI Array_uint8_t;
		struct LDAPI SRt60Average_t;
		struct LDAPI SRt60SampleLimits_t;
		struct LDAPI SRt60Record_t;
		class LDAPI CMeasureRt60;
		struct LDAPI SDataLimitsEDT_t;
		class LDAPI IList_SDataLimitsEDT_t;
		class LDAPI Array_SDataLimitsEDT_t;
		struct LDAPI SRt60Data_t;
		class LDAPI Array_int32_t_2;
		struct LDAPI SRT60_QI_t;
		struct LDAPI SEventTHWind_t;
		struct LDAPI SEventTHRecord_t;
		class LDAPI IList_SEventTHRecord_t;
		class LDAPI Array_SEventTHRecord_t;
		class LDAPI CEventTimeHistoryManager;
		struct LDAPI SEventTriggerInfo_t;
		struct LDAPI SEventLevelInfo_t;
		struct LDAPI SEventWeatherInfo_t;
		class LDAPI CEventInfo;
		enum class EDetectorNdx : uint8_t;
		enum class EDetectorId : uint8_t;
		enum class EFftLevel;
		enum class EVsqConvert;
		enum class EFftRegressionRange;
		enum class EFftToneSeekDelta;
		enum class EFftWindow;
		enum class EWeightingNdx : uint8_t;
		enum class EPeakWeightId : uint8_t;
		enum class ERmsWeightId : uint8_t;
		enum class ERt60Bandwidth;
		enum class ERt60MeasurementGrade;
		enum class ERt60GradeSetting;
		enum class ERt60NoiseType;
		enum class EFrequency;
		enum class ETimeHistoryPeriod;
		class LDAPI IList_uint32_t;
		class LDAPI Array_uint32_t;
		struct LDAPI SWeatherData_t;
		enum class ELabelFormat;
		enum class EUnitType;
		struct LDAPI SLevelTs_t;
		struct LDAPI SDetectorTs_t;
		struct LDAPI SLevel_t;
		struct LDAPI SDetector_t;
		class LDAPI IList_SDetector_t;
		class LDAPI Array_SDetector_t;
		struct LDAPI Sslm2;
		struct LDAPI SSpectraInfo_t;
		enum class ETHOptionId;
		enum class ETHOptionType;
		struct LDAPI SstTHItemInfo_t;
		class LDAPI IList_SstTHItemInfo_t;
		class LDAPI Array_float_2;
		class LDAPI CTimeHistoryRecord;
		class LDAPI IList_CTimeHistoryRecord;
		class LDAPI CTimeHistoryManager;
		enum class ETHOptionFlag;
		struct LDAPI SstTHOptionInfo_t;
		class LDAPI IList_SstTHOptionInfo_t;
		class LDAPI Array_SstTHOptionInfo_t;
		class LDAPI List_int32_t;
		class LDAPI ITuple;
		struct LDAPI ValueTuple_int32_t_StringWrapper;
		class LDAPI IList_ValueTuple_int32_t_StringWrapper;
		class LDAPI IComparer_ValueTuple_int32_t_StringWrapper;
		class LDAPI Array_ValueTuple_int32_t_StringWrapper;
		class LDAPI List_ValueTuple_int32_t_StringWrapper;
		class LDAPI CTimeHistoryOptions;
		enum class EUnitConversion;
		struct LDAPI Sset_Enum;
		struct LDAPI Sset_UnsignedInt;
		struct LDAPI Sset_Int;
		struct LDAPI Sset_FloatArray11;
		struct LDAPI Sset_FloatArray13;
		struct LDAPI Sset_String;
		struct LDAPI Sset_Float;
		class LDAPI IList_Sset_Enum;
		class LDAPI Array_Sset_Enum;
		class LDAPI IList_Sset_String;
		class LDAPI Array_Sset_String;
		struct LDAPI SUserPreferences_t;
		enum class EWeatherEnable;
		enum class EWindDirection;
		class LDAPI CMarineMammalsSummaryData;
		class LDAPI CMarineMammalsData;
		class LDAPI IList_CMarineMammalsData;
		class LDAPI IComparer_CMarineMammalsData;
		class LDAPI Array_CMarineMammalsData;
		class LDAPI List_CMarineMammalsData;
		struct LDAPI SFirwareVersion_t;
		class LDAPI IList_Sset_Float;
		class LDAPI Array_Sset_Float;
		struct LDAPI Sset_IPAddr;
		struct LDAPI Sset_ByteString;
		struct LDAPI SSystemSettings_t;
		struct LDAPI SMetrics_t;
		struct LDAPI SSystemMetrics_t;
		class LDAPI IList_CEventInfo;
		struct LDAPI SEnvPreampInfo_t;
		struct LDAPI SEnvPreampData_t;
		struct LDAPI SDoseCriteria_t;
		class LDAPI IList_SDoseCriteria_t;
		class LDAPI Array_SDoseCriteria_t;
		struct LDAPI Sdegmin;
		struct LDAPI SGps_t;
		struct LDAPI SRtaRecord_t;
		class LDAPI CMeasureRta;
		struct LDAPI SOverload_t;
		struct LDAPI SEventCounts_t;
		class LDAPI IList_SEventCounts_t;
		class LDAPI Array_SEventCounts_t;
		class LDAPI CIntervalInfo;
		class LDAPI IList_CIntervalInfo;
		enum class EIntegrationMethod;
		struct LDAPI SLoggedData_t;
		struct LDAPI SSessionLog_t;
		enum class EActionCause : uint16_t;
		class LDAPI CRunRecord;
		class LDAPI IList_CRunRecord;
		enum class EAudioFormat;
		class LDAPI CSoundRecord;
		class LDAPI IList_CSoundRecord;
		class LDAPI CSessionLog;
		class LDAPI IList_SCalData2_t;
		class LDAPI Array_SCalData2_t;
		struct LDAPI SCalCheckHistory_t;
		class LDAPI IList_Array_SCalData2_t;
		class LDAPI Array_Array_SCalData2_t;
		struct LDAPI SCalHistoryTypes_t;
		class LDAPI IList_SCalHistoryTypes_t;
		class LDAPI Array_SCalHistoryTypes_t;
		struct LDAPI SCalHistory2_t;
		struct LDAPI SDailyNoise_t;
		struct LDAPI SEventTriggerConfig_t;
		class LDAPI IList_SEventTriggerConfig_t;
		enum class EFftFrequencySpan;
		enum class EFftLines;
		enum class EFftRunMode;
		struct LDAPI SFftInfo_t;
		struct LDAPI SFftLevels_t;
		struct LDAPI SFftTriggerInfo_t;
		struct LDAPI SFftRecord_t;
		class LDAPI CToneInfo;
		class LDAPI IList_CToneInfo;
		enum class EFftTonalityStandard;
		class LDAPI CMeasureFft;
		class LDAPI IList_CMeasureFft;
		struct LDAPI SSlmLnInfo_t;
		struct LDAPI Sset_TableFloatsLNS;
		struct LDAPI Sset_EnumFloats;
		class LDAPI IList_Sset_EnumFloats;
		class LDAPI Array_Sset_EnumFloats;
		struct LDAPI SMeasControls_t;
		enum class EInstrumentMode;
		enum class EObaBandwidth;
		enum class EObaRange;
		struct LDAPI SCalData_t;
		class LDAPI IList_SCalData_t;
		class LDAPI Array_SCalData_t;
		struct LDAPI SCalHistory_t;
		enum class EPartitionType;
		enum class ERoomType;
		class LDAPI CRoomBase;
		class LDAPI IList_CMeasureRt60;
		class LDAPI Array_CMeasureRt60;
		class LDAPI CRoomRx;
		class LDAPI CRoomTx;
		class LDAPI CPartition;
		enum class ERandomCorrection;
		enum class ERt60RunTime;
		enum class EHeaterState;
		class LDAPI ISlmRecord;
		class LDAPI IAgencyApprovalInfo;
		class LDAPI CSlmRecord;
		class LDAPI CSpartanMetaRecord;
		class LDAPI ILDRecordWithMetaRecord_CSpartanMetaRecord;
		enum class ETimeHistoryMetricFlags : uint32_t;
		enum class EMetricId;
		class LDAPI CX21MetricMeta;
		class LDAPI IList_CX21MetricMeta;
		enum class ETimeHistoryMetricFlags_B2 : uint32_t;
		enum class ETimeHistoryMetricFlags_B3 : uint32_t;
		enum class ETimeHistoryMetricFlags_B4 : uint32_t;
		enum class ESpartanFileBlockVersion;
		enum class ETimeHistoryFlags : uint32_t;
		struct LDAPI Nullable_uint32_t;
		class LDAPI IComparer_float;
		class LDAPI List_float;
		class LDAPI IList_IConvertible;
		class LDAPI IComparer_IConvertible;
		class LDAPI Array_IConvertible;
		class LDAPI List_IConvertible;
		class LDAPI CTimeHistoryEntry_t;
		class LDAPI IList_CTimeHistoryEntry_t;
		enum class EFreqWeighting_t;
		enum class EDetectorSelect_t;
		enum class EPeakWeighting_t;
		enum class EPropOnOff_t;
		enum class EDoseMode_t;
		class LDAPI IList_wchar_t;
		class LDAPI Array_wchar_t;
		struct LDAPI SString16_t;
		enum class EExchangeRateId_t;
		enum class EDosAlarmSrc_t;
		enum class EPropObaSetting_t;
		enum class ETimerMode_t;
		enum class EContModeInterval_t;
		struct LDAPI SString64_t;
		enum class EMinMaxSelect_t;
		struct LDAPI SMeasSettingsSpartan_t;
		class LDAPI IList_SDetectorTs_t;
		class LDAPI Array_SDetectorTs_t;
		struct LDAPI SObaData48Bins_t;
		struct LDAPI SExceedanceDataRecordSpartan_t;
		class LDAPI IList_SExceedanceDataRecordSpartan_t;
		class LDAPI Array_SExceedanceDataRecordSpartan_t;
		struct LDAPI SExcdDataSpartan_t;
		struct LDAPI SLnDataSpartan_t;
		struct LDAPI STwa_t;
		class LDAPI IList_STwa_t;
		class LDAPI Array_STwa_t;
		struct LDAPI SOverallDataSpartan_t;
		struct LDAPI SBlockHeaderSpartan_t;
		struct LDAPI SOverloadInfo_t;
		struct LDAPI SOverloadSpartan_t;
		class LDAPI IList_SLevelTs_t;
		class LDAPI Array_SLevelTs_t;
		struct LDAPI SDetectorTs2_t;
		class LDAPI IList_SDetectorTs2_t;
		class LDAPI Array_SDetectorTs2_t;
		struct LDAPI SMeasAnyDataSpartan_t;
		struct LDAPI SBlockFooterSpartan_t;
		struct LDAPI SMeasHistSpartan_t;
		class LDAPI Array_int64_t_2;
		class LDAPI CSpartanInterval;
		class LDAPI IList_CSpartanInterval;
		class LDAPI CSpartanSoundRecord;
		class LDAPI IList_CSpartanSoundRecord;
		enum class ESpartanSLogType : uint16_t;
		enum class ESpartanSLogCause : uint16_t;
		class LDAPI CSessionLogEntry_t;
		class LDAPI IList_CSessionLogEntry_t;
		struct LDAPI Nullable_float;
		class LDAPI ISpartanRecord;
		class LDAPI IJsonLineInfo;
		class LDAPI IDynamicMetaObjectProvider;
		enum class EReferenceLoopHandling;
		enum class EMissingMemberHandling;
		enum class EObjectCreationHandling;
		enum class ENullValueHandling;
		enum class EDefaultValueHandling;
		enum class EJsonToken;
		struct LDAPI Nullable_bool;
		struct LDAPI Nullable_uint8_t;
		struct LDAPI Nullable_wchar_t;
		struct LDAPI Nullable_SDateTime;
		struct LDAPI SDateTimeOffset;
		struct LDAPI Nullable_SDateTimeOffset;
		struct LDAPI Nullable_double;
		struct LDAPI Nullable_int64_t;
		struct LDAPI Nullable_int8_t;
		struct LDAPI Nullable_int16_t;
		struct LDAPI Nullable_STimeSpan;
		struct LDAPI Nullable_uint64_t;
		struct LDAPI Nullable_uint16_t;
		enum class EWriteState;
		enum class EFormatting;
		enum class EDateFormatHandling;
		enum class EDateTimeZoneHandling;
		enum class EStringEscapeHandling;
		enum class EFloatFormatHandling;
		class LDAPI CJsonWriter;
		class LDAPI CJsonConverter;
		class LDAPI IList_CJsonConverter;
		enum class EPreserveReferencesHandling;
		enum class ETypeNameHandling;
		enum class EMetadataPropertyHandling;
		enum class EFormatterAssemblyStyle;
		enum class ETypeNameAssemblyFormatHandling;
		enum class EConstructorHandling;
		class LDAPI CSerializationCallback;
		class LDAPI IList_CSerializationCallback;
		class LDAPI CErrorContext;
		class LDAPI CSerializationErrorCallback;
		class LDAPI IList_CSerializationErrorCallback;
		class LDAPI CJsonContract;
		class LDAPI IContractResolver;
		class LDAPI IEqualityComparer;
		class LDAPI IReferenceResolver;
		enum class ETraceLevel;
		class LDAPI ITraceWriter;
		class LDAPI CSerializationBinder;
		class LDAPI ISerializationBinder;
		class LDAPI CErrorEventArgs;
		class LDAPI EventHandler_CErrorEventArgs;
		enum class EDateParseHandling;
		enum class EFloatParseHandling;
		class LDAPI CJsonSerializerSettings;
		class LDAPI CTextReader;
		class LDAPI Array_CJsonConverter;
		class LDAPI Collection_CJsonConverter;
		class LDAPI CJsonConverterCollection;
		class LDAPI CJsonSerializer;
		enum class ECommentHandling;
		enum class ELineInfoHandling;
		enum class EDuplicatePropertyNameHandling;
		class LDAPI CJsonLoadSettings;
		class LDAPI CJsonSelectSettings;
		class LDAPI CJsonCloneSettings;
		enum class EJTokenType;
		class LDAPI CJToken;
		class LDAPI IList_CJToken;
		class LDAPI ITypedList;
		enum class EListSortDirection;
		class LDAPI IBindingList;
		enum class EMergeArrayHandling;
		enum class EMergeNullValueHandling;
		enum class EStringComparison;
		class LDAPI CJsonMergeSettings;
		class LDAPI CJContainer;
		class LDAPI Array_CJToken;
		struct LDAPI SFileInfoHeaderSpartan_t;
		struct LDAPI SManifestEntrySpartan_t;
		struct LDAPI SManifestBlockSpartan_t;
		enum class EDateFormatSpartan_t;
		enum class ELanguage;
		enum class EDecimalFormat;
		enum class EDosAutoOff_t;
		struct LDAPI SString32_t;
		struct LDAPI SString256_t;
		struct LDAPI SSysSettingsSpartan_t;
		struct LDAPI SModifiedDataSpartan_t;
		struct LDAPI SPrePostCalSpartan_v2_t;
		struct LDAPI SDeviceInfoSpartan_t;
		class LDAPI CSpartanRecord;
		enum class EServiceResponse;
		class LDAPI CSlmLegacy;
		enum class EFormatType;
		struct LDAPI SRt60ColInfo_t;
		struct LDAPI SGenericLookup_t;
		class LDAPI IList_SGenericLookup_t;
		class LDAPI Array_SGenericLookup_t;
		struct LDAPI SGenericLookupFloat_t;
		class LDAPI IList_SGenericLookupFloat_t;
		class LDAPI Array_SGenericLookupFloat_t;
		struct LDAPI SFilterFreqInfo_t;
		class LDAPI IList_SFilterFreqInfo_t;
		class LDAPI Array_SFilterFreqInfo_t;
		class LDAPI IList_SRt60ColInfo_t;
		class LDAPI Array_SRt60ColInfo_t;
		struct LDAPI SRt60ColOrder_t;
		class LDAPI IList_SRt60ColOrder_t;
		class LDAPI Array_SRt60ColOrder_t;
		struct LDAPI SIsoGrades_t;
		class LDAPI IList_SIsoGrades_t;
		class LDAPI Array_SIsoGrades_t;
		class LDAPI CSlmConstants;
		enum class ESpartanFileBlock;
		class LDAPI IList_ESpartanFileBlock;
		class LDAPI Array_ESpartanFileBlock;
		class LDAPI CSpartanConstants;
		class LDAPI CLDConstants;

	}
}