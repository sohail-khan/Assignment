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
        class SQLiteFtsComponentFactory : public Eegeo::NonCopyable
        {
        public:
            SQLiteFtsComponentFactory(SQLiteTextSearchableTableFactory& textSearchableTableFactory,
                                      SQLiteSpellfixTableFactory& spellFixTableFactory,
                                      SQLiteFtsQueryTokenizer& ftsQueryTokenizer);
            
            SQLiteFtsComponent* Create(SQLiteDbConnection& dbConnection,
                                       const std::string& tableName,
                                       const std::vector<std::string>& ftsColumnNames,
                                       const std::vector<float>& ftsColumnRankWeights,
                                       const SQLiteFtsSnippetFormattingConfig& snippetFormattingConfig,
                                       SQLiteFtsTokenizerType tokenizerType) const;
        private:
            SQLiteTextSearchableTableFactory& m_textSearchableTableFactory;
            SQLiteSpellfixTableFactory& m_spellFixTableFactory;
            SQLiteFtsQueryTokenizer& m_ftsQueryTokenizer;
        };
    }
}