/**************************************************************************//**
 * @file IList_CSpartanInterval.h
 * @brief Native Wrapper for Managed type IList<LarsonDavis::SDK::LDCommonStd::Legacy::SpartanInterval^>.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ILIST_CSPARTAN_INTERVAL_H
#define _ILIST_CSPARTAN_INTERVAL_H
#include <CSpartanInterval.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI CSpartanInterval;
		struct LDAPI SMeasHistSpartan_t;
		struct LDAPI SBlockHeaderSpartan_t;
		struct LDAPI SMeasAnyDataSpartan_t;
		struct LDAPI SBlockFooterSpartan_t;
		struct LDAPI SLnDataSpartan_t;
		class LDAPI Array_float;
		class LDAPI Array_float_2;
		class LDAPI Array_int64_t_2;
		class LDAPI Array_int64_t;
		struct LDAPI SOverloadSpartan_t;

		class LDAPI IList_CSpartanInterval
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			IList_CSpartanInterval(const IList_CSpartanInterval& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~IList_CSpartanInterval(void);
			virtual int32_t IndexOf(std::shared_ptr<CSpartanInterval> item);
			virtual void Insert(int32_t index, std::shared_ptr<CSpartanInterval> item);
			virtual void RemoveAt(int32_t index);
			virtual std::shared_ptr<CSpartanInterval> Item(int32_t index);
			virtual void Item(int32_t index, std::shared_ptr<CSpartanInterval> value);
			virtual int32_t Count(void);
#ifdef MAKEDLL
		public: // This is for internal use
			IList_CSpartanInterval(){};
			IList_CSpartanInterval(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _ILIST_CSPARTAN_INTERVAL_H
