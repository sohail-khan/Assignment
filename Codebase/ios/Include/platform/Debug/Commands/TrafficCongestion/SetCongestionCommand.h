// Copyright (c) 2014 eeGeo. All rights reserved.

#pragma once

#include "Command.h"
#include "ITrafficCongestionService.h"

namespace Eegeo
{
    namespace Debug
    {
        namespace Commands
        {
            namespace TrafficCongestion
            {
                class SetCongestionCommand : public Command
                {
                public:
                    SetCongestionCommand(Eegeo::TrafficCongestion::ITrafficCongestionService& congestionService);

                    bool TryExecute(
                            const std::vector<std::string>& arguments,
                            const ICommandTerminalOutput& commandTerminal) const;

                private:
                    Eegeo::TrafficCongestion::ITrafficCongestionService& m_congestionService;
                };
            }
        }
    }
}

