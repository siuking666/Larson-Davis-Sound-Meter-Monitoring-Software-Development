/**************************************************************************//**
 * @file CJsonContract.h
 * @brief Native Wrapper for Managed type JsonContract.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _CJSON_CONTRACT_H
#define _CJSON_CONTRACT_H
namespace LarsonDavis
{
	namespace Native
	{
		struct LDAPI Nullable_bool;
		class LDAPI CJsonConverter;
		class LDAPI IList_CSerializationCallback;
		class LDAPI CSerializationCallback;
		class LDAPI IList_CSerializationErrorCallback;
		class LDAPI CSerializationErrorCallback;

		class LDAPI CJsonContract
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			CJsonContract(const CJsonContract& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~CJsonContract(void);
			std::shared_ptr<Nullable_bool> IsReference(void);
			void IsReference(std::shared_ptr<Nullable_bool> value);
			std::shared_ptr<CJsonConverter> Converter(void);
			void Converter(std::shared_ptr<CJsonConverter> value);
			std::shared_ptr<CJsonConverter> InternalConverter(void);
			std::shared_ptr<IList_CSerializationCallback> OnDeserializedCallbacks(void);
			std::shared_ptr<IList_CSerializationCallback> OnDeserializingCallbacks(void);
			std::shared_ptr<IList_CSerializationCallback> OnSerializedCallbacks(void);
			std::shared_ptr<IList_CSerializationCallback> OnSerializingCallbacks(void);
			std::shared_ptr<IList_CSerializationErrorCallback> OnErrorCallbacks(void);
			bool DefaultCreatorNonPublic(void);
			void DefaultCreatorNonPublic(bool value);
#ifdef MAKEDLL
		public: // This is for internal use
			CJsonContract(){};
			CJsonContract(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _CJSON_CONTRACT_H
