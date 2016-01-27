// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "SQLite.h"

#include "Types.h"
#include "SQLiteTable.h"
#include "SQLiteTextSearchableTableOffsetInfo.h"

#include <string>
#include <vector>

namespace Eegeo
{
    namespace SQLite
    {
        class SQLiteTextSearchableTable : public SQLiteTable
        {
        public:
            SQLiteTextSearchableTable(const std::string& tableName,
                                      SQLiteDbConnection& dbConnection,
                                      const SQLiteTextSearchableTableQueryBuilder* pQueryBuilder);
            virtual ~SQLiteTextSearchableTable();
            
            virtual bool Find(const std::string& searchSyntaxQuery, int resultsPerPage, int pageOffset, SQLiteTextSearchableTableResults& out_results) const;
            
            static bool ParseOffsets(const std::string& offsetsText, std::vector<SQLiteTextSearchableTableOffsetInfo>& out_offsets);
        private:
            bool PerformCountQuery(const std::string& searchSyntaxQuery, int& out_totalCount) const;
            
            const SQLiteTextSearchableTableQueryBuilder* m_pQueryBuilder;
        };
        
        

        
        

        
        
    }
}