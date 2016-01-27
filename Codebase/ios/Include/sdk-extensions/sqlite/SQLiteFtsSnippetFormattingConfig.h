// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "SQLite.h"

#include <string>


namespace Eegeo
{
    namespace SQLite
    {
        // http://www.sqlite.org/fts3.html#section_4_2
        struct SQLiteFtsSnippetFormattingConfig
        {
            std::string StartMatch;
            std::string EndMatch;
            std::string Elipsis;
            
            static SQLiteFtsSnippetFormattingConfig Default();
        };
    }
}