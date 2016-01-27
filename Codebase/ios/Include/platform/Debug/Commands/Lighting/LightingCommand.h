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
                class LightingCommand : public Command
                {
                public:
                    LightingCommand
                    (
                     Resources::CityThemes::ThemeStateController& themeStateController,
                     const std::string& commandName,
                     const std::string& help,
                     const std::string& usage
                    );
                    
                protected:
                    Resources::CityThemes::CityThemeState& GetThemeState() const;
                    
                private:
                    Resources::CityThemes::ThemeStateController& m_themeStateController;
                };
            }
        }
    }
}