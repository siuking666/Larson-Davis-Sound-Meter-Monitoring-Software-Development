/**************************************************************************//**
 * @file Collection_CJsonConverter.h
 * @brief Native Wrapper for Managed type Collection<Newtonsoft::Json::JsonConverter^>.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _COLLECTION_CJSON_CONVERTER_H
#define _COLLECTION_CJSON_CONVERTER_H
#include <IList_CJsonConverter.h>
#include <IList.h>
#include <CJsonConverter.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI IList_CJsonConverter;
		class LDAPI IList;
		class LDAPI CJsonConverter;
		class LDAPI Array_CJsonConverter;

		class LDAPI Collection_CJsonConverter : public virtual IList_CJsonConverter, public virtual IList
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			Collection_CJsonConverter(const Collection_CJsonConverter& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~Collection_CJsonConverter(void);
			void Add(std::shared_ptr<CJsonConverter> item);
			void Clear(void);
			void CopyTo(std::shared_ptr<Array_CJsonConverter> array, int32_t index);
			bool Contains(std::shared_ptr<CJsonConverter> item);
			int32_t IndexOf(std::shared_ptr<CJsonConverter> item);
			bool Remove(std::shared_ptr<CJsonConverter> item);
			void RemoveAt(int32_t index);
			void Insert(int32_t index, std::shared_ptr<CJsonConverter> item);
			Collection_CJsonConverter(void);
			Collection_CJsonConverter(std::shared_ptr<IList_CJsonConverter> list);
			int32_t Count(void);
			std::shared_ptr<CJsonConverter> Item(int32_t index);
			void Item(int32_t index, std::shared_ptr<CJsonConverter> value);
#ifdef MAKEDLL
		public: // This is for internal use
			Collection_CJsonConverter(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _COLLECTION_CJSON_CONVERTER_H
