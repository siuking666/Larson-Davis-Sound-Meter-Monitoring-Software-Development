/**************************************************************************//**
 * @file EPreserveReferencesHandling.h
 * @brief Native Wrapper for Managed type PreserveReferencesHandling.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _EPRESERVE_REFERENCES_HANDLING_H
#define _EPRESERVE_REFERENCES_HANDLING_H
namespace LarsonDavis
{
	namespace Native
	{
		enum class EPreserveReferencesHandling
		{
			None = 0,
			Objects = 1,
			Arrays = 2,
			All = 3,
		};
	}
}
#endif // _EPRESERVE_REFERENCES_HANDLING_H
