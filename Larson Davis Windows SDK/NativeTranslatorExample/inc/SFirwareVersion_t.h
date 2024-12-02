/**************************************************************************//**
 * @file SFirwareVersion_t.h
 * @brief Native Wrapper for Managed type FirwareVersion_t.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _SFIRWARE_VERSION_T_H
#define _SFIRWARE_VERSION_T_H
#include <ISupportByteArrayConversion.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI ISupportByteArrayConversion;

		struct LDAPI SFirwareVersion_t : public virtual ISupportByteArrayConversion
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			SFirwareVersion_t(const SFirwareVersion_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~SFirwareVersion_t(void);
			SFirwareVersion_t(void);
			int32_t major(void);
			void major(int32_t value);
			int32_t minor(void);
			void minor(int32_t value);
			int32_t build(void);
			void build(int32_t value);
			StringWrapper date(void);
			void date(StringWrapper value);
			StringWrapper time(void);
			void time(StringWrapper value);
			StringWrapper ver(void);
			void ver(StringWrapper value);
#ifdef MAKEDLL
		public: // This is for internal use
			SFirwareVersion_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _SFIRWARE_VERSION_T_H
