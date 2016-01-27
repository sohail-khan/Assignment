// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "GlobeCamera.h"

namespace Eegeo
{
    namespace Camera
    {
        namespace GlobeCamera
        {
            //! Configuration constants for GlobeCameraTouchController
            struct GlobeCameraTouchControllerConfiguration
            {
                //! threshold defining minimum pan velocity in order for inertia to be applied after a pan gesture is released
                float panDeadZone;
                
                //! time constant controlling decay of pan inertia after releasing a pan gesture
                float panDecayNormal;
                
                //! time constant controlling decay of pan inertia after releasing a pan gesture, in "heavily damped" mode
                float panDecayHeavilyDamped;
                
                //! maximum pan velocity
                float panInertiaMax;
                
                //! time constant controlling decay of rotation inertia after releasing a rotation gesture
                float rotationDecay;
                
                //! maximum rotation velocity, radians per second
                float rotationMaxVelocity;
                
                //! time constant controlling decay of zoom inertia after releasing a pinch-zoom gesture
                float zoomDecay;

                //! touch sensitivity scale for tilt touch input
                float tiltScale;
                
                //! maximum difference between vertical screen coordinates of touch points in order for tilt
                //! gesture to succeed, measured in inches of device screen size (relative to devices DPI value in ScreenProperties)
                float tiltThreshold;
                
                //! \return a GlobeCameraTouchControllerConfiguration instance with fields set to default values
                static GlobeCameraTouchControllerConfiguration CreateDefault();
            };
        }
    }
}
