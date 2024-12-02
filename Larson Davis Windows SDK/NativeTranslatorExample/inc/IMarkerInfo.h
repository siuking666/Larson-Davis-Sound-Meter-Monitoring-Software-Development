/**************************************************************************//**
 * @file IMarkerInfo.h
 * @brief Native Wrapper for Managed type IMarkerInfo.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _IMARKER_INFO_H
#define _IMARKER_INFO_H
namespace LarsonDavis
{
	namespace Native
	{

		class LDAPI IMarkerInfo
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			IMarkerInfo(const IMarkerInfo& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~IMarkerInfo(void);
			virtual StringWrapper Content(void);
			virtual void Content(StringWrapper value);
			virtual int32_t Row(void);
			virtual void Row(int32_t value);
			virtual int32_t Column(void);
			virtual void Column(int32_t value);
			virtual uint32_t UnixTimeStamp(void);
			virtual void UnixTimeStamp(uint32_t value);
			virtual uint64_t UnixTimeStampMs(void);
			virtual void UnixTimeStampMs(uint64_t value);
			virtual StringWrapper Worksheet(void);
			virtual void Worksheet(StringWrapper value);
#ifdef MAKEDLL
		public: // This is for internal use
			IMarkerInfo(){};
			IMarkerInfo(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _IMARKER_INFO_H
