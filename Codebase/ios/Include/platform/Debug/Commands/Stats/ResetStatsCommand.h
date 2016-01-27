// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Command.h"
#include "Commands.h"
#include "IDebugStats.h"

namespace Eegeo
{
    namespace Debug
    {
        namespace Commands
        {
            namespace Stats
            {
                class ResetStatsCommand : public Command
                {
                public:
                    ResetStatsCommand(Debug::IDebugStats& debugStats);

                    bool TryExecute(
                            const std::vector<std::string>& arguments,
                            const ICommandTerminalOutput& commandTerminal) const;
                private:
                    Debug::IDebugStats& m_debugStats;
                };
            }
        }
    }
}