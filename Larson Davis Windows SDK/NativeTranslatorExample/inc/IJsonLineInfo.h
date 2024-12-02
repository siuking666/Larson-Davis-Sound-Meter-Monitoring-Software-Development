/**************************************************************************//**
 * @file IJsonLineInfo.h
 * @brief Native Wrapper for Managed type IJsonLineInfo.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _IJSON_LINE_INFO_H
#define _IJSON_LINE_INFO_H
namespace LarsonDavis
{
	namespace Native
	{

		class LDAPI IJsonLineInfo
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			IJsonLineInfo(const IJsonLineInfo& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~IJsonLineInfo(void);
			virtual bool HasLineInfo(void);
			virtual int32_t LineNumber(void);
			virtual int32_t LinePosition(void);
#ifdef MAKEDLL
		public: // This is for internal use
			IJsonLineInfo(){};
			IJsonLineInfo(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _IJSON_LINE_INFO_H
