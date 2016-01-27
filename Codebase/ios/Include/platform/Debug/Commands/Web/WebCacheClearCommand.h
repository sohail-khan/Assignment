// Copyright (c) 2015 eeGeo. All rights reserved.

#pragma once

#include "Command.h"
#include "Helpers.h"

namespace Eegeo
{
    namespace Debug
    {
        namespace Commands
        {
            namespace Web
            {
                class WebCacheClearCommand : public Command
                {
                public:
                    WebCacheClearCommand(Helpers::IHttpCache& httpCache);

                    bool TryExecute(
                            const std::vector<std::string>& arguments,
                            const ICommandTerminalOutput& commandTerminal) const;
                private:
                    Helpers::IHttpCache& m_httpCache;
                };

            }
        }
    }
}

