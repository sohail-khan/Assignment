// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "SQLite.h"
#include "SQLiteValueType.h"
#include "Types.h"

#include <string>
#include <vector>


namespace Eegeo
{
    namespace SQLite
    {

        
        class SQLiteCellValue
        {
        public:
            explicit SQLiteCellValue(SQLiteValueType valueType, const int integerVal, const double realVal, const std::string& textVal);
            
            SQLiteValueType GetType() const { return m_type; }
            int AsInteger() const { return m_integerVal; }
            double AsReal() const { return m_realVal; }
            std::string AsText() const { return m_textVal; }

        private:
            SQLiteValueType m_type;
            int m_integerVal;
            double m_realVal;
            std::string m_textVal;
        };
        
        

    }
}