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
            namespace Stream
            {
                class StreamListCommand : public Command
                {
                public:
                    StreamListCommand(IDebugStats& debugStats);

                    bool TryExecute(
                            const std::vector<std::string>& arguments,
                            const ICommandTerminalOutput& commandTerminal) const;
                private:
                    IDebugStats& m_debugStats;
                };
            }
        }
    }
}