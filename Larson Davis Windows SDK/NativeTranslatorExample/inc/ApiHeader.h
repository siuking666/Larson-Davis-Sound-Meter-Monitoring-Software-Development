/**************************************************************************//**
 * @file ApiHeader.h
 * @brief Import/Export macro and id typedef.
 * @version 1.0.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2021 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/

#pragma once
#ifdef MAKEDLL
#	define LDAPI __declspec(dllexport)
#else
#	define LDAPI __declspec(dllimport)
#endif