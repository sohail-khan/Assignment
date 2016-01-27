// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "GlobeCamera.h"

namespace Eegeo
{
    namespace Camera
    {
        namespace GlobeCamera
        {
            struct GlobeCameraTouchSettings
            {
                bool RotateEnabled;
                bool PanEnabled;
                bool ZoomEnabled;
                bool TiltEnabled;
                
                void EnableAll()
                {
                    RotateEnabled = true;
                    PanEnabled = true;
                    ZoomEnabled = true;
                    TiltEnabled = true;
                }

                static GlobeCameraTouchSettings CreateDefault()
                {
                    GlobeCameraTouchSettings settings;

                    settings.RotateEnabled = true;
                    settings.PanEnabled = true;
                    settings.ZoomEnabled = true;
                    settings.TiltEnabled = true;

                    return settings;
                }
            };
        }
    }
}