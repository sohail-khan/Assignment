//  Copyright (c) 2014 Eegeo Ltd. All rights reserved.

#pragma once
#include "Command.h"
#include "Commands.h"
#include "PlaceNames.h"

namespace Eegeo
{
    namespace Debug
    {
        namespace Commands
        {
            namespace PlaceNames
            {
                class PlaceNamesEnableCommand : public Eegeo::Debug::Commands::Command
                {
                public:
                    PlaceNamesEnableCommand(Resources::PlaceNames::PlaceNamesViewFilter& placeNamesViewFilter);
                    
                    bool TryExecute(
                                    const std::vector<std::string>& arguments,
                                    const ICommandTerminalOutput& commandTerminal) const;
                private:
                    Resources::PlaceNames::PlaceNamesViewFilter& m_placeNamesViewFilter;
                };
            }
        }
    }
}