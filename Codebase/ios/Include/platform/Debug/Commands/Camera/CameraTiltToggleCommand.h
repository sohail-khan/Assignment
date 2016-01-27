// Copyright (c) 2014 eeGeo. All rights reserved.

#pragma once

#include "Command.h"
#include "GlobeCamera.h"

namespace Eegeo
{
    namespace Debug
    {
        namespace Commands
        {
            namespace Camera
            {
                class CameraTiltToggleCommand : public Command
                {
                public:
                    CameraTiltToggleCommand(Eegeo::Camera::GlobeCamera::GlobeCameraController& globeCameraController);

                    bool TryExecute(
                            const std::vector<std::string>& arguments,
                            const ICommandTerminalOutput& commandTerminal) const;
                private:
                    Eegeo::Camera::GlobeCamera::GlobeCameraController& m_globeCameraController;
                };
            }
        }
    }
}