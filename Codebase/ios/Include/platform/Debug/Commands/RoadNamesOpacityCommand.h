// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Command.h"
#include "Commands.h"
#include "Roads.h"

namespace Eegeo
{
    namespace Debug
    {
        namespace Commands
        {
            namespace Roads
            {
                class RoadNamesOpacityCommand : public Command
                {
                public:
                    RoadNamesOpacityCommand(Resources::Roads::RoadNamesFadeController& roadNamesFadeController);

                    bool TryExecute(
                            const std::vector<std::string>& arguments,
                            const ICommandTerminalOutput& commandTerminal) const;
                private:
                    Resources::Roads::RoadNamesFadeController& m_roadNamesFadeController;
                };
            }
        }
    }
}
