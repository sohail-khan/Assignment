// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "SQLite.h"


namespace Eegeo
{
    namespace SQLite
    {
        enum SQLiteValueType
        {
            SQLiteValueType_Invalid,
            SQLiteValueType_Integer,
            SQLiteValueType_Real,
            SQLiteValueType_Text
        };
    }
}