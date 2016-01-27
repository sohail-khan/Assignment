// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "SQLite.h"
#include "ICallback.h"

#include <string>

namespace Eegeo
{
    namespace SQLite
    {
        struct SQLiteDbWebLoaderResponse
        {
            bool succeeded;
            std::string fullyQualifiedDbPathname;
        };
        
        template <typename TCallbackContext>
        class TSQLiteDbWebLoaderCompletedHandler : public Eegeo::Helpers::TCallback1<TCallbackContext, const Eegeo::SQLite::SQLiteDbWebLoaderResponse&>
        {
        public:
            typedef Eegeo::Helpers::TCallback1<TCallbackContext, const Eegeo::SQLite::SQLiteDbWebLoaderResponse&> BaseType;
            
            TSQLiteDbWebLoaderCompletedHandler(TCallbackContext* callbackContext, typename BaseType::TCallTarget callbackPtr)
            : BaseType(callbackContext, callbackPtr)
            {
            }
        };
    }
}