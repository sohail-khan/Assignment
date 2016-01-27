// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Commands.h"
#include "CommandCallback.h"
#include "Types.h"
#include <vector>

namespace Eegeo
{
    namespace Debug
    {
        namespace Commands
        {
            class CommandProcessor : protected Eegeo::NonCopyable
            {
            public:
                CommandProcessor(
                                 CommandBuffer& commandBuffer,
                                 const CommandParser& commandParser,
                                 const CommandRegistry& commandRegistry,
                                 const CommandTerminal& commandTerminal);
                
                bool Update();
                
                void AddCommandCompletedCallback(ICommandCallback& callback);
                void RemoveCommandCompletedCallback(ICommandCallback& callback);
            private:
                const CommandRegistry& m_commandRegistry;
                const CommandParser& m_commandParser;
                const CommandTerminal& m_commandTerminal;
                CommandBuffer& m_commandBuffer;
                std::vector<ICommandCallback*> m_callbacks;
            };
        }
    }
}

