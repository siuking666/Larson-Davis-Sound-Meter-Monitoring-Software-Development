/**************************************************************************//**
 * @file IDictionary_int32_t_CEditBandInfo.h
 * @brief Native Wrapper for Managed type IDictionary<System::Int32, LarsonDavis::SDK::LDCommonStd::MetaData::EditBandInfo^>.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _IDICTIONARY_INT32_T_CEDIT_BAND_INFO_H
#define _IDICTIONARY_INT32_T_CEDIT_BAND_INFO_H
#include <CEditBandInfo.h>
#include <EEditBandAction.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI CEditBandInfo;

		class LDAPI IDictionary_int32_t_CEditBandInfo
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			IDictionary_int32_t_CEditBandInfo(const IDictionary_int32_t_CEditBandInfo& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~IDictionary_int32_t_CEditBandInfo(void);
			virtual bool ContainsKey(int32_t key);
			virtual void Add(int32_t key, std::shared_ptr<CEditBandInfo> value);
			virtual bool Remove(int32_t key);
			virtual bool TryGetValue(int32_t key, std::shared_ptr<CEditBandInfo>& value);
			virtual std::shared_ptr<CEditBandInfo> Item(int32_t key);
			virtual void Item(int32_t key, std::shared_ptr<CEditBandInfo> value);
#ifdef MAKEDLL
		public: // This is for internal use
			IDictionary_int32_t_CEditBandInfo(){};
			IDictionary_int32_t_CEditBandInfo(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _IDICTIONARY_INT32_T_CEDIT_BAND_INFO_H
