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
        namespace FtsMethods
        {

            bool BuildFtsTables(SQLiteDbConnection& dbConnection,
                                const std::string& tableName,
                                const std::string& ftsTableName,
                                const std::string& ftsAuxTableName,
                                const std::vector<std::string>& ftsColumnNames,
                                SQLiteFtsTokenizerType tokenizerType);
        }
    }
}