/**************************************************************************//**
 * @file SGps_t.h
 * @brief Native Wrapper for Managed type Gps_t.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _SGPS_T_H
#define _SGPS_T_H
#include <ISupportByteArrayConversion.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI ISupportByteArrayConversion;
		struct LDAPI Sdegmin;

		struct LDAPI SGps_t : public virtual ISupportByteArrayConversion
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			SGps_t(const SGps_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~SGps_t(void);
			SGps_t(void);
			std::shared_ptr<Sdegmin> latitude(void);
			void latitude(std::shared_ptr<Sdegmin> value);
			std::shared_ptr<Sdegmin> longitude(void);
			void longitude(std::shared_ptr<Sdegmin> value);
			float altitude(void);
			void altitude(float value);
			uint32_t time(void);
			void time(uint32_t value);
			uint32_t date(void);
			void date(uint32_t value);
			uint16_t flags(void);
			void flags(uint16_t value);
#ifdef MAKEDLL
		public: // This is for internal use
			SGps_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _SGPS_T_H
