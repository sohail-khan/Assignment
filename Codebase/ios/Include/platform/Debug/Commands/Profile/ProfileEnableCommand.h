//  Copyright (c) 2014 Eegeo Ltd. All rights reserved.

#pragma once

#include "Command.h"
#include "Profile.h"

namespace Eegeo
{
    namespace Debug
    {
        namespace Commands
        {
            namespace Profile
            {
                class ProfileEnableCommand : public Eegeo::Debug::Commands::Command
                {
                public:
                    ProfileEnableCommand(Eegeo::Debug::Profile::Profiler& profiler);
                    bool TryExecute(
                                    const std::vector<std::string>& arguments,
                                    const ICommandTerminalOutput& commandTerminal) const;
                private:
                    Eegeo::Debug::Profile::Profiler& m_profiler;
                };
            }
        }
    }
}