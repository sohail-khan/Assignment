// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "SQLite.h"
#include "Types.h"

#include <string>
#include <vector>

namespace Eegeo
{
    namespace SQLite
    {
        
        class SQLiteSpellfixTableFactory : public Eegeo::NonCopyable
        {
        public:
            SQLiteSpellfixTableFactory()
            {
                
            }
            
            
            SQLiteSpellfixTable* Create(
                                              SQLiteDbConnection& dbConnection,
                                              const std::string& tableName,
                                              const std::vector<std::string>& ftsColumnNames);

        };
    }
}