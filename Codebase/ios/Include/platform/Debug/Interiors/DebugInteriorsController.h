// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Interiors.h"
#include "GpsGlobeCameraController.h"

namespace Eegeo
{
    namespace Debug
    {
        namespace Interiors
        {
            class DebugInteriorsController
            {
            public:
                DebugInteriorsController(Resources::Interiors::IInteriorController& interiorController);
                ~DebugInteriorsController();
                
                void ExitInterior();
                void UpFloor();
                void DownFloor();
                bool IsInteriorModeEnabled() const;
                
            private:
 
                Resources::Interiors::IInteriorController& m_controller;
            };
        }
    }
}
