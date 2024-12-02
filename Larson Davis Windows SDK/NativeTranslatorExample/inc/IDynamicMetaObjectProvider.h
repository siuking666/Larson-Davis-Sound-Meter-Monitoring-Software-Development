/**************************************************************************//**
 * @file IDynamicMetaObjectProvider.h
 * @brief Native Wrapper for Managed type IDynamicMetaObjectProvider.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _IDYNAMIC_META_OBJECT_PROVIDER_H
#define _IDYNAMIC_META_OBJECT_PROVIDER_H
namespace LarsonDavis
{
	namespace Native
	{

		class LDAPI IDynamicMetaObjectProvider
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			IDynamicMetaObjectProvider(const IDynamicMetaObjectProvider& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~IDynamicMetaObjectProvider(void);
#ifdef MAKEDLL
		public: // This is for internal use
			IDynamicMetaObjectProvider(){};
			IDynamicMetaObjectProvider(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _IDYNAMIC_META_OBJECT_PROVIDER_H
