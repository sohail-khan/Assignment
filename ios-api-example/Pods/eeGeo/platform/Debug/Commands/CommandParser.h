// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include <string>
#include <vector>

namespace Eegeo
{
    namespace Debug
    {
        namespace Commands
        {
            struct ParsedCommand
            {
                std::string commandName;
                std::vector<std::string> args;
                std::string originalText;
            };
            
            class CommandParser : protected Eegeo::NonCopyable
            {
            public:
                bool TryParse(const std::string& text, ParsedCommand& outCommand) const;
            };
        }
    }
}