/**************************************************************************//**
 * @file Translator.h
 * @brief Native function to acces the translation functionality.
 * @version 1.0.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2021 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/

#pragma once
#include <EServiceResponse.h>

namespace LarsonDavis
{
   namespace Native
   {
      enum RecordType
      {
         RecType_Unknown,
         RecType_SlmFile,
         RecType_FftFile,
         RecType_Rt60File,
         RecType_SpaFile,
         RecType_X21File
      };

      class ILDRecord;

      class LDAPI CTranslatorException
      {
      public:
         CTranslatorException(StringWrapper typeName, StringWrapper message, StringWrapper stackTrace);
         CTranslatorException(const CTranslatorException& other);
         virtual ~CTranslatorException();
         StringWrapper ManagedTypeName;
         StringWrapper Message;
         StringWrapper StackTrace;
      };

      class LDAPI CTranslationResult
      {
      public:
         CTranslationResult();
         CTranslationResult(const CTranslationResult& other);
         virtual ~CTranslationResult();
         std::shared_ptr<ILDRecord>* pRecords;
         uint32_t RecordCount;
         EServiceResponse Response;
         RecordType Type;
      };

      LDAPI std::shared_ptr<CTranslationResult> Translate(const wchar_t* pFileName);
   }
}