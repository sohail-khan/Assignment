// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

// latlongdistance

#include "SQLite.h"
#include "Types.h"

#include <string>


namespace Eegeo
{
    namespace SQLite
    {
        class SQLiteLatLongQueryBuilder : public Eegeo::NonCopyable
        {
        public:
            SQLiteLatLongQueryBuilder(const std::string& latitudeColumnName, const std::string& longitudeColumnName);
            
            SQLiteTableQuery BuildQuery_SelectColumnsFromTableWithinRadius(const std::string& columns, const SQLiteTable& table, double latitudeDegrees, double longitudeDegrees, const std::string& constraints, double maxDistanceMetres, bool orderByDistance, int maxResults) const;
            
            SQLiteTableQuery BuildQuery_SelectColumnsAndDistanceFromTableWithinRadius(const std::string& columns, const SQLiteTable& table, double latitudeDegrees, double longitudeDegrees, const std::string& constraints, double maxDistanceMetres, bool orderByDistance, int maxResults) const;

        private:
            const std::string m_latitudeColumnName;
            const std::string m_longitudeColumnName;
        };
    }
}