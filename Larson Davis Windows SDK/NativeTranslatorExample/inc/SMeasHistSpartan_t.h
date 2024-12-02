/**************************************************************************//**
 * @file SMeasHistSpartan_t.h
 * @brief Native Wrapper for Managed type MeasHistSpartan_t.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _SMEAS_HIST_SPARTAN_T_H
#define _SMEAS_HIST_SPARTAN_T_H
#include <ISupportByteArrayConversion.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI ISupportByteArrayConversion;
		struct LDAPI SBlockHeaderSpartan_t;
		struct LDAPI SMeasAnyDataSpartan_t;
		struct LDAPI SBlockFooterSpartan_t;
		struct LDAPI SLnDataSpartan_t;

		struct LDAPI SMeasHistSpartan_t : public virtual ISupportByteArrayConversion
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			SMeasHistSpartan_t(const SMeasHistSpartan_t& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~SMeasHistSpartan_t(void);
			SMeasHistSpartan_t(void);
			std::shared_ptr<SBlockHeaderSpartan_t> measRecordHeader(void);
			void measRecordHeader(std::shared_ptr<SBlockHeaderSpartan_t> value);
			std::shared_ptr<SBlockHeaderSpartan_t> measAnyDataHeader(void);
			void measAnyDataHeader(std::shared_ptr<SBlockHeaderSpartan_t> value);
			std::shared_ptr<SMeasAnyDataSpartan_t> measAnyData(void);
			void measAnyData(std::shared_ptr<SMeasAnyDataSpartan_t> value);
			std::shared_ptr<SBlockFooterSpartan_t> measAnyDataFooter(void);
			void measAnyDataFooter(std::shared_ptr<SBlockFooterSpartan_t> value);
			std::shared_ptr<SBlockHeaderSpartan_t> measLnDataHeader(void);
			void measLnDataHeader(std::shared_ptr<SBlockHeaderSpartan_t> value);
			std::shared_ptr<SLnDataSpartan_t> measLnData(void);
			void measLnData(std::shared_ptr<SLnDataSpartan_t> value);
			std::shared_ptr<SBlockFooterSpartan_t> measLnDataFooter(void);
			void measLnDataFooter(std::shared_ptr<SBlockFooterSpartan_t> value);
			std::shared_ptr<SBlockFooterSpartan_t> measRecordFooter(void);
			void measRecordFooter(std::shared_ptr<SBlockFooterSpartan_t> value);
#ifdef MAKEDLL
		public: // This is for internal use
			SMeasHistSpartan_t(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _SMEAS_HIST_SPARTAN_T_H
