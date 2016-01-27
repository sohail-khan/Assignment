// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Command.h"
#include "Commands.h"
#include "IDebugStats.h"
#include "PayloadPool.h"

namespace Eegeo
{
    namespace Debug
    {
        namespace Commands
        {
            namespace Stream
            {
                class StreamStatsCommand :	public Command
                {
                public:
                    StreamStatsCommand(const IDebugStats& debugStats,
                                       const Streaming::PayloadPool& payloadPool);

                    bool TryExecute(
                            const std::vector<std::string>& arguments,
                            const ICommandTerminalOutput& commandTerminal) const;
                private:
                    const IDebugStats& m_debugStats;
                    const Streaming::PayloadPool& m_payloadPool;
                };
            }
        }
    }
}