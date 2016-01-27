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
            class EchoCommand :	public Command
            {
            public:
                EchoCommand();
                virtual ~EchoCommand();

                bool TryExecute(
                        const std::vector<std::string>& arguments,
                        const ICommandTerminalOutput& commandTerminal) const;
            };
        }
    }
}
