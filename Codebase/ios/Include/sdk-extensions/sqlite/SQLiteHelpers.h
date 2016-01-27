// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "SQLite.h"
#include "SQLiteValueType.h"

#include <string>

struct sqlite3;
struct sqlite3_stmt;

namespace Eegeo
{
    namespace SQLite
    {
        namespace Helpers
        {
            bool ExecSqlCommand(sqlite3 *db, const std::string& command);
            bool DropTableIfExists(sqlite3* db, const std::string& tableName);
            bool ListTableTTY(sqlite3 *db, const std::string& tableName);
            SQLiteValueType SQLite3TypeToValueType(int sqlite3ValueType);
        }
    }
}
