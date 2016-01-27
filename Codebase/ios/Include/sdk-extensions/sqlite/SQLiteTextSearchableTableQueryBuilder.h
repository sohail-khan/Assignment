// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "SQLite.h"
#include "Types.h"

#include <string>


namespace Eegeo
{
    namespace SQLite
    {
        class SQLiteTextSearchableTableQueryBuilder : public Eegeo::NonCopyable
        {
        public:
            SQLiteTextSearchableTableQueryBuilder(const std::string& tableName,
                                                  const std::string& ftsTableName,
                                                  const std::string& ftsAuxTableName,
                                                  const std::string& ftsColumnNames,
                                                  const std::string& ftsColumnRankWeights,
                                                  const std::string& snippetFormattingStartMatch,
                                                  const std::string& snippetFormattingEndMatch,
                                                  const std::string& snippetFormattingElipsis);
            
            SQLiteTableQuery BuildQuery(const SQLiteDbConnection& dbConnection, const std::string& searchSyntaxQuery, int resultsPerPage, int pageOffset) const;
            SQLiteTableQuery BuildCountQuery(const SQLiteDbConnection& dbConnection, const std::string& searchSyntaxQuery) const;

        private:
            const std::string m_tableName;
            const std::string m_ftsTableName;
            const std::string m_ftsAuxTableName;
            const std::string m_ftsColumnNames;
            const std::string m_ftsColumnRankWeights;
            const std::string m_snippetFormattingStartMatch;
            const std::string m_snippetFormattingEndMatch;
            const std::string m_snippetFormattingElipsis;
        };
    }
}