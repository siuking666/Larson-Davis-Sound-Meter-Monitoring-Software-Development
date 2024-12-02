/**************************************************************************//**
 * @file SGenericLookup_t.h
 * @brief Native Wrapper for Managed type GenericLookup_t.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _SGENERIC_LOOKUP_T_H
#define _SGENERIC_LOOKUP_T_H
namespace LarsonDavis
{
	namespace Native
	{

		struct LDAPI SGenericLookup_t
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			SGenericLookup_t(const SGenericLookup_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~SGenericLookup_t(void);
			SGenericLookup_t(void);
			int32_t id(void);
			void id(int32_t value);
			StringWrapper str(void);
			void str(StringWrapper value);
			int32_t val(void);
			void val(int32_t value);
#ifdef MAKEDLL
		public: // This is for internal use
			SGenericLookup_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _SGENERIC_LOOKUP_T_H
