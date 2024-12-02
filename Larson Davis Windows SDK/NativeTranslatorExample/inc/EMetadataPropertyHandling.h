/**************************************************************************//**
 * @file EMetadataPropertyHandling.h
 * @brief Native Wrapper for Managed type MetadataPropertyHandling.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _EMETADATA_PROPERTY_HANDLING_H
#define _EMETADATA_PROPERTY_HANDLING_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class EMetadataPropertyHandling
		{
			Default = 0,
			ReadAhead = 1,
			Ignore = 2,
		};
	}
}
#endif // _EMETADATA_PROPERTY_HANDLING_H
