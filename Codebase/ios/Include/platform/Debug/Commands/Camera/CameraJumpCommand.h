// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Command.h"
#include "Commands.h"
#include "ICameraJumpController.h"

namespace Eegeo
{
    namespace Debug
    {
        namespace Commands
        {
            namespace Camera
            {
                class CameraJumpCommand : public Command
                {
                public:
                    CameraJumpCommand(Eegeo::Camera::ICameraJumpController& cameraJumpController);

                    bool TryExecute(
                            const std::vector<std::string>& arguments,
                            const ICommandTerminalOutput& commandTerminal) const;
                private:
                    Eegeo::Camera::ICameraJumpController& m_cameraJumpController;
                };
            }
        }
    }
}