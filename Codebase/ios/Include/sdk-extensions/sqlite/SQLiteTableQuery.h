// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "SQLite.h"

#include <string>

namespace Eegeo
{
    namespace SQLite
    {
        class SQLiteTableQuery
        {
        public:
            
            static SQLiteTableQuery MakeSelect(const SQLiteDbConnection& dbConnection, const std::string& selectStatement);
            
            std::string Str() const { return m_query; }
            
            bool Execute(SQLiteResultCells*& out_pResult) const;
            
        private:
            SQLiteTableQuery(const SQLiteDbConnection& dbConnection, const std::string& query);
            
            const SQLiteDbConnection& m_dbConnection;
            const std::string m_query;
        };
    }
}