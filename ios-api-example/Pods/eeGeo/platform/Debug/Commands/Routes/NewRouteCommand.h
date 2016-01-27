//  Copyright (c) 2014 Eegeo Ltd. All rights reserved.

#pragma once
#include "Command.h"
#include "Commands.h"
#include "Routes.h"
#include "ICameraJumpController.h"

namespace Eegeo
{
    namespace Debug
    {
        namespace Commands
        {
            namespace Routes
            {
                class NewRouteCommand : public Eegeo::Debug::Commands::Command
                {
                public:
                    NewRouteCommand(
                                    Eegeo::Routes::IRouteCreator& routeCreator,
                                    Eegeo::Camera::ICameraJumpController& cameraJumpController);
                     bool TryExecute(
                                    const std::vector<std::string>& arguments,
                                    const ICommandTerminalOutput& commandTerminal) const;
                private:
                    Eegeo::Routes::IRouteCreator& m_routeCreator;
                    Eegeo::Camera::ICameraJumpController& m_cameraJumpController;
                };
            }
        }
    }
}