// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "SQLite.h"


namespace Eegeo
{
    namespace SQLite
    {
        struct SQLiteSpellfixOptions
        {
            int MaxSpellfixSuggestions;
            int MaxSpellfixDistance;
            int MaxAltSpellfixDistanceWhenExactMatchFound;
            int LogVerbosity;
            
            SQLiteSpellfixOptions();
            
            static SQLiteSpellfixOptions Default();
        };
    }
}