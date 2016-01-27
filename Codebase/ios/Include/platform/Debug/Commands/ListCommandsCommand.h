// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Command.h"
#include "Commands.h"

namespace Eegeo
{
    namespace Debug
    {
        namespace Commands
        {
            class ListCommandsCommand :	public Command
            {
            public:
                ListCommandsCommand(const CommandRegistry& commandRegistry);
                ~ListCommandsCommand();

                bool TryExecute(
                        const std::vector<std::string>& arguments,
                        const ICommandTerminalOutput& commandTerminal) const;
            private:
                const CommandRegistry& m_commandRegistry;
            };
        }
    }
}