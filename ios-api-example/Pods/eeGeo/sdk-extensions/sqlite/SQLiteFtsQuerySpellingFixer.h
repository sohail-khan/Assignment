// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "SQLite.h"
#include "Types.h"

#include "SQLiteFtsQueryTokenizer.h"
#include "SQLiteSpellFixSuggestion.h"

#include <string>
#include <vector>

namespace Eegeo
{
    namespace SQLite
    {
        class SQLiteFtsQuerySpellingFixer : public Eegeo::NonCopyable
        {
        public:
            SQLiteFtsQuerySpellingFixer(const SQLiteSpellfixTable& spellFixTable, const SQLiteFtsQueryTokenizer& ftsQueryTokenizer);
            
            bool BuildSpellFixedFtsQuery(const std::string inputQueryTerm, const SQLiteSpellfixOptions& options, SQLiteSpellingSuggestionResults& out_results) const;
        private:

            bool BuildSpellFixedToken(const std::string& inputTerm, const SQLiteSpellfixOptions& options, SQLiteSpellFixedQueryTerm& out_queryTerm) const;
        

            const SQLiteSpellfixTable& m_spellFixTable;
            const SQLiteFtsQueryTokenizer& m_ftsQueryTokenizer;
        };
    }
}