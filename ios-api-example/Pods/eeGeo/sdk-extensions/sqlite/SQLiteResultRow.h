// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "SQLite.h"
#include "Types.h"

#include <vector>

namespace Eegeo
{
    namespace SQLite
    {
        
        class SQLiteResultRow : public Eegeo::NonCopyable
        {
        public:
            SQLiteResultRow(const std::vector<SQLiteCellValue*>& cellValues);
            ~SQLiteResultRow();
            
            int ColumnCount() const { return static_cast<int>(m_cellValues.size()); }
            const SQLiteCellValue& Cell(int column) const;
            
        private:
            const std::vector<SQLiteCellValue*> m_cellValues;
        };
    }
}