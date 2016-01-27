//  Copyright (c) 2014 Eegeo Ltd. All rights reserved.

#pragma once
#include "Command.h"
#include "Commands.h"
#include "Profiler.h"

namespace Eegeo
{
    namespace Debug
    {
        namespace Commands
        {
            namespace Profile
            {
                class ProfileShowCommand : public Eegeo::Debug::Commands::Command
                {
                public:
                    ProfileShowCommand(Eegeo::Debug::Profile::Profiler& profiler);
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