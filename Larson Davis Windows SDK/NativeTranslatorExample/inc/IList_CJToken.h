/**************************************************************************//**
 * @file IList_CJToken.h
 * @brief Native Wrapper for Managed type IList<Newtonsoft::Json::Linq::JToken^>.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ILIST_CJTOKEN_H
#define _ILIST_CJTOKEN_H
#include <CJToken.h>
#include <EJTokenType.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI CJToken;
		class LDAPI CJsonLoadSettings;
		class LDAPI CJsonSelectSettings;
		class LDAPI CJsonCloneSettings;
		class LDAPI CJsonWriter;
		class LDAPI Array_CJsonConverter;
		class LDAPI CJContainer;

		class LDAPI IList_CJToken
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			IList_CJToken(const IList_CJToken& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~IList_CJToken(void);
			virtual int32_t IndexOf(std::shared_ptr<CJToken> item);
			virtual void Insert(int32_t index, std::shared_ptr<CJToken> item);
			virtual void RemoveAt(int32_t index);
			virtual std::shared_ptr<CJToken> Item(int32_t index);
			virtual void Item(int32_t index, std::shared_ptr<CJToken> value);
			virtual int32_t Count(void);
#ifdef MAKEDLL
		public: // This is for internal use
			IList_CJToken(){};
			IList_CJToken(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _ILIST_CJTOKEN_H
