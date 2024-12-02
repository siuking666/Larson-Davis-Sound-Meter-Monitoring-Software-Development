/**************************************************************************//**
 * @file CJToken.h
 * @brief Native Wrapper for Managed type JToken.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _CJTOKEN_H
#define _CJTOKEN_H
#include <IJsonLineInfo.h>
#include <IDynamicMetaObjectProvider.h>
#include <EJTokenType.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI IJsonLineInfo;
		class LDAPI IDynamicMetaObjectProvider;
		class LDAPI CJsonLoadSettings;
		class LDAPI CJsonSelectSettings;
		class LDAPI CJsonCloneSettings;
		class LDAPI CJsonWriter;
		class LDAPI Array_CJsonConverter;
		class LDAPI CJContainer;

		class LDAPI CJToken : public virtual IJsonLineInfo, public virtual IDynamicMetaObjectProvider
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			CJToken(const CJToken& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~CJToken(void);
			static std::shared_ptr<CJToken> Parse(StringWrapper json);
			static std::shared_ptr<CJToken> Parse(StringWrapper json, std::shared_ptr<CJsonLoadSettings> settings);
			std::shared_ptr<CJToken> SelectToken(StringWrapper path);
			std::shared_ptr<CJToken> SelectToken(StringWrapper path, bool errorWhenNoMatch);
			std::shared_ptr<CJToken> SelectToken(StringWrapper path, std::shared_ptr<CJsonSelectSettings> settings);
			std::shared_ptr<CJToken> DeepClone(void);
			std::shared_ptr<CJToken> DeepClone(std::shared_ptr<CJsonCloneSettings> settings);
			static bool DeepEquals(std::shared_ptr<CJToken> t1, std::shared_ptr<CJToken> t2);
			void Remove(void);
			void Replace(std::shared_ptr<CJToken> value);
			void WriteTo(std::shared_ptr<CJsonWriter> writer, std::shared_ptr<Array_CJsonConverter> converters);
			std::shared_ptr<CJContainer> Parent(void);
			std::shared_ptr<CJToken> Root(void);
			EJTokenType Type(void);
			bool HasValues(void);
			std::shared_ptr<CJToken> Next(void);
			std::shared_ptr<CJToken> Previous(void);
			StringWrapper Path(void);
			std::shared_ptr<CJToken> First(void);
			std::shared_ptr<CJToken> Last(void);
#ifdef MAKEDLL
		public: // This is for internal use
			CJToken(){};
			CJToken(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _CJTOKEN_H
