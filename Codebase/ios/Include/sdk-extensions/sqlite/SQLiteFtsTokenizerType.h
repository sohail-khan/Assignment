// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "SQLite.h"


struct sqlite3;


namespace Eegeo
{
    namespace SQLite
    {
        enum SQLiteFtsTokenizerType
        {
            SQLiteFtsTokenizerType_Simple,
            SQLiteFtsTokenizerType_PorterStemming
        };
    }
}