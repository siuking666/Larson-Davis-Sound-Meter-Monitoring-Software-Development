/**************************************************************************//**
 * @file CMarkerInfo.h
 * @brief Native Wrapper for Managed type MarkerInfo.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _CMARKER_INFO_H
#define _CMARKER_INFO_H
#include <IMarkerInfo.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI IMarkerInfo;

		class LDAPI CMarkerInfo : public virtual IMarkerInfo
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			CMarkerInfo(const CMarkerInfo& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~CMarkerInfo(void);
			CMarkerInfo(void);
			CMarkerInfo(StringWrapper content, int32_t row, int32_t column, uint32_t timeStamp, uint64_t timeStampMs, StringWrapper worksheet);
			StringWrapper Content(void);
			void Content(StringWrapper value);
			int32_t Row(void);
			void Row(int32_t value);
			int32_t Column(void);
			void Column(int32_t value);
			uint32_t UnixTimeStamp(void);
			void UnixTimeStamp(uint32_t value);
			uint64_t UnixTimeStampMs(void);
			void UnixTimeStampMs(uint64_t value);
			StringWrapper Worksheet(void);
			void Worksheet(StringWrapper value);
#ifdef MAKEDLL
		public: // This is for internal use
			CMarkerInfo(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _CMARKER_INFO_H
