#pragma once
#include <ApiHeader.h>

namespace LarsonDavis
{
   namespace Native
   {
      class LDAPI StringWrapper
      {
      public:
         StringWrapper(const wchar_t* pStr);
         StringWrapper(const StringWrapper& other);
         virtual ~StringWrapper();
         const wchar_t* operator*() const;
      private:
         const wchar_t* m_string;
      };
   }
}