/**************************************************************************//**
 * @file IGeneralInfo.h
 * @brief Native Wrapper for Managed type IGeneralInfo.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _IGENERAL_INFO_H
#define _IGENERAL_INFO_H
namespace LarsonDavis
{
	namespace Native
	{

		class LDAPI IGeneralInfo
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			IGeneralInfo(const IGeneralInfo& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~IGeneralInfo(void);
			virtual StringWrapper User(void);
			virtual void User(StringWrapper value);
			virtual StringWrapper Location(void);
			virtual void Location(StringWrapper value);
			virtual StringWrapper JobDescription(void);
			virtual void JobDescription(StringWrapper value);
			virtual StringWrapper Note(void);
			virtual void Note(StringWrapper value);
#ifdef MAKEDLL
		public: // This is for internal use
			IGeneralInfo(){};
			IGeneralInfo(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _IGENERAL_INFO_H
