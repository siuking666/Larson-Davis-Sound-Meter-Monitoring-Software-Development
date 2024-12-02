/**************************************************************************//**
 * @file SModifiedDataSpartan_t.h
 * @brief Native Wrapper for Managed type ModifiedDataSpartan_t.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _SMODIFIED_DATA_SPARTAN_T_H
#define _SMODIFIED_DATA_SPARTAN_T_H
#include <ISupportByteArrayConversion.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI ISupportByteArrayConversion;
		struct LDAPI SOverallDataSpartan_t;

		struct LDAPI SModifiedDataSpartan_t : public virtual ISupportByteArrayConversion
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			SModifiedDataSpartan_t(const SModifiedDataSpartan_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~SModifiedDataSpartan_t(void);
			SModifiedDataSpartan_t(void);
			std::shared_ptr<SOverallDataSpartan_t> overallData(void);
			void overallData(std::shared_ptr<SOverallDataSpartan_t> value);
			double runtime(void);
			void runtime(double value);
#ifdef MAKEDLL
		public: // This is for internal use
			SModifiedDataSpartan_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _SMODIFIED_DATA_SPARTAN_T_H
