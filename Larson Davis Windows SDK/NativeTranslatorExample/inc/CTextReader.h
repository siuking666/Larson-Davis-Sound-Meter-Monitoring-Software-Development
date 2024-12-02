/**************************************************************************//**
 * @file CTextReader.h
 * @brief Native Wrapper for Managed type TextReader.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _CTEXT_READER_H
#define _CTEXT_READER_H
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI Array_wchar_t;

		class LDAPI CTextReader
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			CTextReader(const CTextReader& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~CTextReader(void);
			void Close(void);
			void Dispose(void);
			int32_t Peek(void);
			int32_t Read(void);
			int32_t Read(std::shared_ptr<Array_wchar_t> buffer, int32_t index, int32_t count);
			StringWrapper ReadToEnd(void);
			int32_t ReadBlock(std::shared_ptr<Array_wchar_t> buffer, int32_t index, int32_t count);
			StringWrapper ReadLine(void);
			static std::shared_ptr<CTextReader> Synchronized(std::shared_ptr<CTextReader> reader);
			static std::shared_ptr<CTextReader> Null(void);
#ifdef MAKEDLL
		public: // This is for internal use
			CTextReader(){};
			CTextReader(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _CTEXT_READER_H
