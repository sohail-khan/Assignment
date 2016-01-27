// Copyright (c) 2016 eeGeo. All rights reserved.

#pragma once

#include "Command.h"
#include "Helpers.h"
#include "Web.h"

namespace Eegeo
{
    namespace Debug
    {
        namespace Commands
        {
            namespace Web
            {
                class SetWebProxyCommand : public Command
                {
                public:
                    SetWebProxyCommand(Eegeo::Web::IWebProxySettings& webProxySettings);
                    
                    bool TryExecute(
                                    const std::vector<std::string>& arguments,
                                    const ICommandTerminalOutput& commandTerminal) const;
                private:
                    Eegeo::Web::IWebProxySettings& m_webProxySettings;
                };

            }
        }
    }
}