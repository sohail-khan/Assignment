// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

namespace Eegeo
{
    namespace Debug
    {
        namespace Commands
        {
            class Command;
            class CommandBuffer;
            struct ParsedCommand;
            class CommandParser;
            class CommandProcessor;
            class CommandRegistry;
            class CommandTerminal;
            
            class ICommandTerminalOutput;
            
            class EchoCommand;
            class HelpCommand;
            class ListCommandsCommand;
        }
    }
}