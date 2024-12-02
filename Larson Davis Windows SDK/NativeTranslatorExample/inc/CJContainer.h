/**************************************************************************//**
 * @file CJContainer.h
 * @brief Native Wrapper for Managed type JContainer.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _CJCONTAINER_H
#define _CJCONTAINER_H
#include <CJToken.h>
#include <IList_CJToken.h>
#include <ITypedList.h>
#include <IBindingList.h>
#include <EJTokenType.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI CJToken;
		class LDAPI IList_CJToken;
		class LDAPI ITypedList;
		class LDAPI IBindingList;
		class LDAPI CJsonWriter;
		class LDAPI CJsonLoadSettings;
		class LDAPI CJsonSelectSettings;
		class LDAPI CJsonCloneSettings;
		class LDAPI Array_CJsonConverter;

		class LDAPI CJContainer : public CJToken, public virtual IList_CJToken, public virtual ITypedList, public virtual IBindingList
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			CJContainer(const CJContainer& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~CJContainer(void);
			std::shared_ptr<CJsonWriter> CreateWriter(void);
			void RemoveAll(void);
			bool HasValues(void);
			std::shared_ptr<CJToken> First(void);
			std::shared_ptr<CJToken> Last(void);
			int32_t Count(void);
#ifdef MAKEDLL
		public: // This is for internal use
			CJContainer(){};
			CJContainer(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _CJCONTAINER_H
