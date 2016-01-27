//  Copyright (c) 2015 Eegeo Ltd. All rights reserved.

#pragma once

#include "Command.h"
#include "Commands.h"
#include "Routes.h"

namespace Eegeo
{
    namespace Debug
    {
        namespace Commands
        {
            namespace Routes
            {
                class RouteFittingCommand : public Eegeo::Debug::Commands::Command
                {
                public:
                    RouteFittingCommand(
                                        Eegeo::Routes::IRouteCreator& routeCreator);
                    bool TryExecute(
                                    const std::vector<std::string>& arguments,
                                    const ICommandTerminalOutput& commandTerminal) const;
                private:
                    Eegeo::Routes::IRouteCreator& m_routeCreator;
                };
            }
        }
    }
}