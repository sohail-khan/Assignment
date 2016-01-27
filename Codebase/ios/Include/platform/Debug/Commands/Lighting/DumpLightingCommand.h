// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Command.h"
#include "Commands.h"
#include "LightingCommand.h"
#include "ThemeStateController.h"

namespace Eegeo
{
    namespace Debug
    {
        namespace Commands
        {
            namespace Lighting
            {
                class DumpLightingCommand : public LightingCommand
                {
                public:
                    DumpLightingCommand(Resources::CityThemes::ThemeStateController& themeStateController);
                    
                    bool TryExecute(const std::vector<std::string>& arguments,
                                    const ICommandTerminalOutput& commandTerminal) const;
                };
            }
        }
    }
}