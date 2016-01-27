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
                class MemStatsCommand : public Command
                {
                public:
                    MemStatsCommand(const Debug::IDebugStats& debugStats);

                    bool TryExecute(
                            const std::vector<std::string>& arguments,
                            const ICommandTerminalOutput& commandTerminal) const;
                private:
                    const Debug::IDebugStats& m_debugStats;
                };
            }
        }
    }
}