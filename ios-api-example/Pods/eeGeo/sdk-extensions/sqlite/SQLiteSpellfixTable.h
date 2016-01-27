// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once


#include "SQLite.h"
#include "Types.h"
#include "SQLiteSpellfixSuggestion.h"

#include <string>
#include <vector>

namespace Eegeo
{
    namespace SQLite
    {
        class SQLiteSpellfixTable : public Eegeo::NonCopyable
        {
        public:
            SQLiteSpellfixTable(SQLiteDbConnection& dbConnection,
                                const std::string& spellfixTableName);
            
            bool PerformSpellfixMatchQuery(const std::string& term,
                                           const SQLiteSpellfixOptions& options,
                                           std::vector<SQLiteSpellfixSuggestion>& out_spellfixMatches) const;
        private:
            SQLiteDbConnection& m_dbConnection;
            std::string m_spellfixTableName;
        };
    }
}