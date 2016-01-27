// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "SQLite.h"

namespace Eegeo
{
    namespace SQLite
    {
    
        // http://www.sqlite.org/fts3.html#offsets
        struct SQLiteTextSearchableTableOffsetInfo
        {
            int ColumnNumber;
            int TermNumber;
            int ByteOffset;
            int MatchingTermByteSize;
            
            SQLiteTextSearchableTableOffsetInfo()
            : ColumnNumber(0)
            , TermNumber(0)
            , ByteOffset(0)
            , MatchingTermByteSize(0)
            {
                
            }
            
        };
    }
}