// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Camera.h"
#include "Space.h"

namespace Eegeo
{
    namespace Camera
    {
        class ICameraJumpController
        {
        public:
            virtual ~ICameraJumpController() {;}
            virtual void JumpTo(const Space::LatLongAltitude& interestPoint, float cameraHeadingDegrees, float cameraDistanceToInterest) = 0;
            virtual void JumpTo(const Space::LatLongAltitude& interestPoint) = 0;
            virtual bool CanJump() const = 0;
        };
    }
}