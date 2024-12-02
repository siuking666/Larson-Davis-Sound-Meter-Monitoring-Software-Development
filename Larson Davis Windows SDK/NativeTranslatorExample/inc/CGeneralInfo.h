/**************************************************************************//**
 * @file CGeneralInfo.h
 * @brief Native Wrapper for Managed type GeneralInfo.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _CGENERAL_INFO_H
#define _CGENERAL_INFO_H
#include <IGeneralInfo.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI IGeneralInfo;

		class LDAPI CGeneralInfo : public virtual IGeneralInfo
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			CGeneralInfo(const CGeneralInfo& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~CGeneralInfo(void);
			CGeneralInfo(void);
			StringWrapper User(void);
			void User(StringWrapper value);
			StringWrapper Location(void);
			void Location(StringWrapper value);
			StringWrapper JobDescription(void);
			void JobDescription(StringWrapper value);
			StringWrapper Note(void);
			void Note(StringWrapper value);
#ifdef MAKEDLL
		public: // This is for internal use
			CGeneralInfo(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _CGENERAL_INFO_H
