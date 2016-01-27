// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "SQLite.h"

#include <string>


namespace Eegeo
{
    namespace SQLite
    {
        enum FtsQueryTokenType
        {
            FtsQueryTokenType_None,
            FtsQueryTokenType_Keyword,
            FtsQueryTokenType_Operator,
            FtsQueryTokenType_Term
        };
        
        
        struct SQLiteFtsQueryToken
        {
            SQLiteFtsQueryToken()
            : m_offset(0)
            , m_type(FtsQueryTokenType_None) {}
            
            SQLiteFtsQueryToken(const std::string& value, FtsQueryTokenType tokenType, size_t offset)
            : m_value(value)
            , m_type(tokenType)
            , m_offset(offset) {}
            
            const std::string& Str() const { return m_value; }
            FtsQueryTokenType Type() const { return m_type; }
            size_t Offset() const { return m_offset; }
        private:
            std::string m_value;
            FtsQueryTokenType m_type;
            size_t m_offset;
        };
    }
}