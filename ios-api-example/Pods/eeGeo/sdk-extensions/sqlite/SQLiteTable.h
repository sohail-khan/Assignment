// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "SQLite.h"
#include "Types.h"

#include <string>


namespace Eegeo
{
    namespace SQLite
    {
        class SQLiteTable : public Eegeo::NonCopyable
        {
        public:
            SQLiteTable(const std::string& tableName, SQLiteDbConnection& dbConnection);
            
            virtual ~SQLiteTable() {;}
            
            virtual std::string GetTableName() const { return m_tableName; }

            virtual SQLiteDbConnection& GetDbConnection() const { return m_dbConnection; }
            
        private:
            std::string m_tableName;
            SQLiteDbConnection& m_dbConnection;
        };
    }
}