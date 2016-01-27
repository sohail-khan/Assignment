// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "SQLite.h"
#include "Types.h"

#include <string>


struct sqlite3;

namespace Eegeo
{
    namespace SQLite
    {
        class SQLiteDbConnection : public Eegeo::NonCopyable
        {
        public:
            SQLiteDbConnection();
            
            ~SQLiteDbConnection();
            
            bool Open(const std::string& sqliteDbPathname);
            
            bool Close();
            
            bool IsOpen() const { return m_db != NULL; }
            
            sqlite3* GetDb() const { return m_db; }
            
        private:
            sqlite3* m_db;
        };
    }
}