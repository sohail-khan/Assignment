// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "SQLite.h"
#include "Types.h"
#include "SQLiteFtsQueryTokenizerSession.h"

#include <string>
#include <vector>

namespace Eegeo
{
    namespace SQLite
    {
        /*! \brief Allow parsing of phrase queries using SQLite FTS Advanced Query Syntax: http://www.sqlite.org/fts3.html#section_3_1
         */
        class SQLiteFtsQueryTokenizer : public Eegeo::NonCopyable
        {
        public:
            static SQLiteFtsQueryTokenizer* Create();
            
            SQLiteFtsQueryTokenizer(const std::string& delimiters,
                                    const std::string& operators,
                                    const std::string& retainedTermPunctuation,
                                    const std::vector<std::string>& keywords);
        
            SQLiteFtsQueryTokenizerSession Begin(const std::string& s) const;
        
            bool GetNextToken(const SQLiteFtsQueryTokenizerSession& session, SQLiteFtsQueryToken& out_token) const;
            
            bool IsQuote(const SQLiteFtsQueryToken& token) const;
        private:
            bool IsOperator(const char c) const;
            bool IsKeyword(const std::string& s) const;
            bool IsDelimiter(const char c) const;
            bool IsNegateOperatorAt(const std::string& s, bool isInQuotedPhrase, size_t pos) const;
        
            const std::string m_delimiters;
            const std::string m_operators;
            const std::string m_delimitersAndOperators;
            const std::string m_nonIgnoredCharacters;
            const std::vector<std::string> m_keywords;
        };

    }
}