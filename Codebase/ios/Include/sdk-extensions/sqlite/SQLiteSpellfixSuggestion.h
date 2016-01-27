// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "SQLite.h"

#include <string>

namespace Eegeo
{
    namespace SQLite
    {
        struct SQLiteSpellfixSuggestion
        {
            std::string Suggestion;
            int Distance;
            int Score;
            int Rank;
            
            SQLiteSpellfixSuggestion()
            : Distance(0)
            , Score(0)
            , Rank(0)
            {
                
            }
        };
    }
}