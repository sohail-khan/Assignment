// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "SQLite.h"
#include "Types.h"
#include "SQLiteTable.h"
#include "StringHelpers.h"
#include "SQLiteTableQuery.h"

#include <string>
#include <sstream>
#include <vector>

namespace Eegeo
{
    namespace SQLite
    {
        inline std::string ToSqlStringLiteral(const std::string& s)
        {
            return "'" + s + "'";
        }
        
        inline std::string EscapedQueryString(const std::string& inputQuery)
        {
            std::string escapedInputQuery(inputQuery);
            Eegeo::Helpers::SearchReplace(escapedInputQuery, "'", "''");
            return escapedInputQuery;
        }

        inline SQLiteTableQuery
        MakeQuery_Select(const SQLiteTable& table, const std::string& columns)
        {
            std::stringstream ss;
            ss << columns << " FROM " << table.GetTableName();
            return SQLiteTableQuery::MakeSelect(table.GetDbConnection(), ss.str());
        }
        
        inline SQLiteTableQuery
        MakeQuery_SelectAll(const SQLiteTable& table)
        {
            return MakeQuery_Select(table, "*");
        }
        
        inline SQLiteTableQuery
        MakeQuery_Count(const SQLiteTable& table)
        {
            return MakeQuery_Select(table, "COUNT(*)");
        }
        
        template <typename TValue>
        inline SQLiteTableQuery
        MakeQuery_SelectColumnsFromTableWhereXEqualsY(
                                                      const std::string& columns,
                                                      const SQLiteTable& table,
                                                      const std::string& X,
                                                      const TValue& Y)
        {
            std::stringstream ss;
            ss << columns << " FROM " << table.GetTableName() << " WHERE " << X << "=" << Y;
            return SQLiteTableQuery::MakeSelect(table.GetDbConnection(), ss.str());
        }
        
        template <typename TValue>
        inline SQLiteTableQuery
        MakeQuery_CountAllFromTableWhereXEqualsY(const SQLiteTable& table, const std::string& X, const TValue& Y)
        {
            return MakeQuery_SelectColumnsFromTableWhereXEqualsY("COUNT(*)", table, X, Y);
        }
        
        
        template <typename TValue>
        inline SQLiteTableQuery
        MakeQuery_SelectColumnsFromTableWhereXInY(
                                  const std::string& columns,
                                  const SQLiteTable& table,
                                  const std::string& X,
                                  const std::vector<TValue>& Y)
        {
            std::stringstream ss;
            ss << columns << " FROM " << table.GetTableName() << " WHERE " << X << " IN (" << Join(Y, ", ") << ")";
            return SQLiteTableQuery::MakeSelect(table.GetDbConnection(), ss.str());
        }
        
        template <typename TValue>
        inline SQLiteTableQuery
        MakeQuery_CountAllFromTableWhereXInY(const SQLiteTable& table, const std::string& X, const std::vector<TValue>& Y)
        {
            return MakeQuery_SelectColumnsFromTableWhereXInY("COUNT(*)", table, X, Y);
        }
        
    }
}