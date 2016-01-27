// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include <map>
#include "Command.h"

namespace Eegeo
{
    namespace Debug
    {
        namespace Commands
        {
            class CommandRegistry : protected Eegeo::NonCopyable
            {
            public:
                typedef std::map<std::string, const Command*>::const_iterator CommandIter;
                
                void RegisterCommand(const Command* command);
                bool TryGetCommand(const std::string& commandName, const Command*& outCommand) const;
                void GetCommandList(const std::string& filter, std::vector<std::string>& outCommandList) const;
            private:
                std::map<std::string, const Command*> m_commandNameToCommand;                
            };
        }
    }
}

