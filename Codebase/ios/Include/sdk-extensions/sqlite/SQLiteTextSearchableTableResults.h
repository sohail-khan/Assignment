
// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "SQLite.h"

#include <string>

namespace Eegeo
{
    namespace SQLite
    {
        struct SQLiteTextSearchableTableResults
        {
            std::string inputSearchQuery;
            int resultsPerPage;
            int pageOffset;
            int totalResults;
            int nextPageOffset;
            SQLiteResultCells* resultCells;
            
            SQLiteTextSearchableTableResults()
            : resultsPerPage(0)
            , pageOffset(0)
            , totalResults(0)
            , nextPageOffset(0)
            , resultCells(NULL)
            {
                
            }
        };
    }
}