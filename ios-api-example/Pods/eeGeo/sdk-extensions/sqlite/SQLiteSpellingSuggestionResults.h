// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "SQLite.h"
#include "SQLiteSpellfixSuggestion.h"

#include <string>
#include <vector>

namespace Eegeo
{
    namespace SQLite
    {
        struct SQLiteSpellFixedQueryTerm
        {
            std::string inputTerm;
            std::vector<SQLiteSpellfixSuggestion> suggestions;
            std::string spellFixedTerm;
        };
        
        struct SQLiteSpellingSuggestionResults
        {
            std::string inputSearchQuery;
            std::vector<SQLiteSpellFixedQueryTerm> spellFixedTerms;
            std::string spellCheckedSearchQuery;
        };
        
    }
}