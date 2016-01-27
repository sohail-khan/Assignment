// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "GlobeCamera.h"

namespace Eegeo
{
    namespace Camera
    {
        namespace GlobeCamera
        {
            struct GpsGlobeCameraComponentConfiguration
            {
                //! touch pan-swipe sensitivity threshold to cancel GPS mode
                float panToUnlockThreshold;
                
                //! default absolute bearing in degrees (clockwise from North) of camera when transitioning to GPS mode
                float defaultGpsBearing;
                
                //! distance of camera to GPS location when transitioning to GPS mode
                float defaultGpsDistanceToInterest;
                
                //! \return a GpsGlobeCameraComponentConfiguration instance with fields set to default values
                static GpsGlobeCameraComponentConfiguration CreateDefault();
            };
        }
    }
}