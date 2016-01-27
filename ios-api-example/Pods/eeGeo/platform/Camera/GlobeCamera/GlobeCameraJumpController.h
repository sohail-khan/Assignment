// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "ICameraJumpController.h"
#include "GlobeCamera.h"

namespace Eegeo
{
    namespace Camera
    {
        namespace GlobeCamera
        {
            class GlobeCameraJumpController : public ICameraJumpController
            {
            public:
                GlobeCameraJumpController(GpsGlobeCameraController& cameraController);
                virtual ~GlobeCameraJumpController() {;}
                virtual void JumpTo(const Space::LatLongAltitude& interestPoint, float cameraHeadingDegrees, float cameraDistanceToInterest);
                virtual void JumpTo(const Space::LatLongAltitude& interestPoint);
                virtual bool CanJump() const;
            private:
                GpsGlobeCameraController& m_cameraController;
            };
        }
    }
}