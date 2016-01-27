//  Copyright (c) 2014 Eegeo Ltd. All rights reserved.

#pragma once

#include "Command.h"
#include "Profile.h"
#include "DebugDecl.h"

namespace Eegeo
{
    namespace Debug
    {
        namespace Commands
        {
            namespace Profile
            {
                class PerformanceTestRegisterSplineCommand : public Eegeo::Debug::Commands::Command
                {
                public:
                    PerformanceTestRegisterSplineCommand(Eegeo::Debug::Profile::PerformanceTestRunner& perfTestRunner);

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