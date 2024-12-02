/**************************************************************************//**
 * @file Array_CJToken.h
 * @brief Native Wrapper for Managed type cli::array<Newtonsoft::Json::Linq::JToken^, 1>.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ARRAY_CJTOKEN_H
#define _ARRAY_CJTOKEN_H
#include <CArray.h>
#include <IList_CJToken.h>
#include <CJToken.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI CArray;
		class LDAPI IList_CJToken;
		class LDAPI CJToken;

		class LDAPI Array_CJToken : public CArray, public virtual IList_CJToken
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			Array_CJToken(const Array_CJToken& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~Array_CJToken(void);
			void Set(int32_t arg0, std::shared_ptr<CJToken> arg1);
			std::shared_ptr<CJToken> Get(int32_t arg0);
			Array_CJToken(int32_t arg0);
#ifdef MAKEDLL
		public: // This is for internal use
			Array_CJToken(){};
			Array_CJToken(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _ARRAY_CJTOKEN_H
