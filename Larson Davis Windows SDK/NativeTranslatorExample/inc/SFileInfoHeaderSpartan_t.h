/**************************************************************************//**
 * @file SFileInfoHeaderSpartan_t.h
 * @brief Native Wrapper for Managed type FileInfoHeaderSpartan_t.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _SFILE_INFO_HEADER_SPARTAN_T_H
#define _SFILE_INFO_HEADER_SPARTAN_T_H
#include <ISupportByteArrayConversion.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI ISupportByteArrayConversion;

		struct LDAPI SFileInfoHeaderSpartan_t : public virtual ISupportByteArrayConversion
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			SFileInfoHeaderSpartan_t(const SFileInfoHeaderSpartan_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~SFileInfoHeaderSpartan_t(void);
			SFileInfoHeaderSpartan_t(void);
			StringWrapper name(void);
			void name(StringWrapper value);
			int32_t tag(void);
			void tag(int32_t value);
			int32_t ver(void);
			void ver(int32_t value);
			int32_t size(void);
			void size(int32_t value);
			int32_t crc(void);
			void crc(int32_t value);
#ifdef MAKEDLL
		public: // This is for internal use
			SFileInfoHeaderSpartan_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _SFILE_INFO_HEADER_SPARTAN_T_H
