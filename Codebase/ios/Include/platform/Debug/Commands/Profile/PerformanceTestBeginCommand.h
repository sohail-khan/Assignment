// Copyright (c) 2014 eeGeo. All rights reserved.

#pragma once

#include "Command.h"
#include "Commands.h"
#include "DebugDecl.h"
#include <vector>

namespace Eegeo
{
    namespace Debug
    {
        namespace Commands
        {
            namespace Profile
            {
                class PerformanceTestBeginCommand : public Eegeo::Debug::Commands::Command
                {
                public:
                    PerformanceTestBeginCommand(Eegeo::Debug::Profile::PerformanceTestRunner& perfTests);

                    bool TryExecute(
                            const std::vector<std::string>& arguments,
                            const ICommandTerminalOutput& commandTerminal) const;
                private:
                    Eegeo::Debug::Profile::PerformanceTestRunner& m_performanceTestRunner;
                };
            }
        }
    }
}