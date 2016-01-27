// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"

#include <string>
#include <vector>

namespace Eegeo
{
    namespace Debug
    {
        namespace Commands
        {
            class ICommandTerminalOutput
            {
            public:
                virtual ~ICommandTerminalOutput() { };
                virtual void Write(const std::string& str) const = 0;
            };
            
            class CommandTerminal : public ICommandTerminalOutput, protected Eegeo::NonCopyable
            {
            public:
                void AddOutput(ICommandTerminalOutput& output);
                void RemoveOutput(ICommandTerminalOutput& output);
                void Write(const std::string& str) const;
            private:
                std::vector<ICommandTerminalOutput*> m_outputs;
            };
        }
    }
}