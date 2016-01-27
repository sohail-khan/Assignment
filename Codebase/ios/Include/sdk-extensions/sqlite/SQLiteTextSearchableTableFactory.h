// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "SQLite.h"
#include "Types.h"
#include "SQLiteFtsTokenizerType.h"

#include <string>
#include <vector>

namespace Eegeo
{
    namespace SQLite
    {
        class SQLiteTextSearchableTableFactory : public Eegeo::NonCopyable
        {
        public:
            // http://www.sqlite.org/fts3.html#tokenizer
            // http://en.wikipedia.org/wiki/Stemming

            
            SQLiteTextSearchableTable* Create(
                                              SQLiteDbConnection& dbConnection,
                                              const std::string& tableName,
                                              const std::vector<std::string>& ftsColumnNames,
                                              const std::vector<float>& ftsColumnRankWeights,
                                              const SQLiteFtsSnippetFormattingConfig& snippetFormattingConfig,
                                              SQLiteFtsTokenizerType tokenizerType);
        };
    }
}