// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "SQLite.h"
#include "Types.h"

#include <vector>


namespace Eegeo
{
    namespace SQLite
    {
        class SQLiteResultCells : public Eegeo::NonCopyable
        {
        public:
            static SQLiteResultCells* Create(int rowCount, int columnCount, const std::vector<SQLiteCellValue*>& rowMajorCells);
            
            SQLiteResultCells(int columnCount, const std::vector<SQLiteResultRow*>& rows);
            ~SQLiteResultCells();
            
            int RowCount() const { return static_cast<int>(m_rowValues.size()); }
            int ColumnCount() const { return m_columnCount; }
            
            const SQLiteResultRow& Row(int row) const;
            const SQLiteCellValue& Cell(int row, int column) const;
            
        private:
            const int m_columnCount;
            
            const std::vector<SQLiteResultRow*> m_rowValues;
        };
    }
}