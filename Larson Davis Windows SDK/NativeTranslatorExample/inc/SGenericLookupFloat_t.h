/**************************************************************************//**
 * @file SGenericLookupFloat_t.h
 * @brief Native Wrapper for Managed type GenericLookupFloat_t.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _SGENERIC_LOOKUP_FLOAT_T_H
#define _SGENERIC_LOOKUP_FLOAT_T_H
namespace LarsonDavis
{
	namespace Native
	{

		struct LDAPI SGenericLookupFloat_t
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			SGenericLookupFloat_t(const SGenericLookupFloat_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~SGenericLookupFloat_t(void);
			SGenericLookupFloat_t(void);
			int32_t id(void);
			void id(int32_t value);
			StringWrapper str(void);
			void str(StringWrapper value);
			float val(void);
			void val(float value);
#ifdef MAKEDLL
		public: // This is for internal use
			SGenericLookupFloat_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _SGENERIC_LOOKUP_FLOAT_T_H
