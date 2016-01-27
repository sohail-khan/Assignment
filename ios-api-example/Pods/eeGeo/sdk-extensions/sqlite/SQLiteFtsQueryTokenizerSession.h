// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "SQLite.h"
#include "Types.h"
#include "SQLiteFtsQueryToken.h"

#include <string>




namespace Eegeo
{
    namespace SQLite
    {
        struct SQLiteFtsQueryTokenizerSession
        {
            SQLiteFtsQueryTokenizerSession(const SQLiteFtsQueryTokenizer& tokenizer, const std::string& s);
            bool Advance();
            
            const std::string& InputString() const { return m_inputString; }
            const SQLiteFtsQueryToken& CurrentToken() const { return m_currentToken; }
            bool IsInQuotedPhrase() const { return m_inQuotedPhrase; }
            
        private:
            void SetToken(const SQLiteFtsQueryToken& token);
            
            const SQLiteFtsQueryTokenizer& m_tokenizer;
            const std::string m_inputString;
            SQLiteFtsQueryToken m_currentToken;
            bool m_inQuotedPhrase;
        };
    }
}