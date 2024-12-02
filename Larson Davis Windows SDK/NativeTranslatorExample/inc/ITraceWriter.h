/**************************************************************************//**
 * @file ITraceWriter.h
 * @brief Native Wrapper for Managed type ITraceWriter.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _ITRACE_WRITER_H
#define _ITRACE_WRITER_H
#include <ETraceLevel.h>
namespace LarsonDavis
{
	namespace Native
	{

		class LDAPI ITraceWriter
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			ITraceWriter(const ITraceWriter& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~ITraceWriter(void);
			virtual ETraceLevel LevelFilter(void);
#ifdef MAKEDLL
		public: // This is for internal use
			ITraceWriter(){};
			ITraceWriter(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _ITRACE_WRITER_H
