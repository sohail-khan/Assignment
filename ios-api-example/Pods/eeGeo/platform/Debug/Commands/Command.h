// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include <vector>
#include <string>
#include "Commands.h"
#include "Types.h"

namespace Eegeo
{
    namespace Debug
    {
        namespace Commands
        {
            class Command : protected Eegeo::NonCopyable
            {
            public:
                Command (const std::string& name, const std::string& help, const std::string& usage);
                virtual ~Command() {};
                
                const std::string& Name() const { return m_name; };
                const std::string& Help() const { return m_help; };
                const std::string& Usage() const { return m_usage; };
                
                virtual bool TryExecute(
                        const std::vector<std::string>& arguments,
                        const ICommandTerminalOutput& commandTerminal) const = 0;

            private:
                std::string m_name;
                std::string m_help;
                std::string m_usage;
            };
            
        }
    }
}