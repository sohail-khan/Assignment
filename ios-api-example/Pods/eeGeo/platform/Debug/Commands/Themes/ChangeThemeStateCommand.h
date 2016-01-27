// Copyright eeGeo Ltd 2015, All Rights Reserved

#pragma once

#include "Command.h"
#include "Commands.h"
#include "ICityThemesService.h"

namespace Eegeo
{
    namespace Debug
    {
        namespace Commands
        {
            namespace Themes
            {
                class ChangeThemeStateCommand : public Command
                {
                public:
                    ChangeThemeStateCommand(Resources::CityThemes::ICityThemesService& cityThemeService);
                    
                    bool TryExecute(
                                    const std::vector<std::string>& arguments,
                                    const ICommandTerminalOutput& commandTerminal) const;
                private:
                    Resources::CityThemes::ICityThemesService& m_cityThemeService;
                };
            }
        }
    }
}
