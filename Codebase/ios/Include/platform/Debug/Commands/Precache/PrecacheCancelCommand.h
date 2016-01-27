// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Command.h"
#include "Commands.h"
#include "PrecacheService.h"

namespace Eegeo
{
    namespace Debug
    {
        namespace Commands
        {
            namespace Precache
            {
                class PrecacheCancelCommand : public Command
                {
                public:
                    PrecacheCancelCommand(Eegeo::Web::PrecacheService& precacheService);

                    bool TryExecute(
                            const std::vector<std::string>& arguments,
                            const ICommandTerminalOutput& commandTerminal) const;
                private:
                    Eegeo::Web::PrecacheService& m_precacheService;
                };
            }
        }
    }
}
