// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Interiors.h"
#include "VectorMath.h"
#include <string>

namespace Eegeo
{
    namespace Resources
    {
        namespace Interiors
        {
            struct InteriorsConfiguration
            {
                InteriorsConfiguration()
                : CameraDistanceMax(0.f)
                , CameraDistanceMin(0.f)
                , CameraDistanceInitial(0.f)
                , CameraFovDegrees(0.f)
                , CameraPitchDegrees(0.f)
                , CameraZoomScale(0.f)
                , InitialTransitionTargetFovDegrees(0.f)
                , InitialTransitionTargetPitchDegrees(0.f)
                , InitialTransitionDuration(0.f)
                , EntryTransitionDuration(0.f)
                , ExitTransitionDuration(0.f)
                , CameraJumpTransitionThreshold(0.f)
                , LabelGlyphColor(v3::Zero())
                , LabelOutlineColor(v3::Zero())
                {}
                
                float CameraDistanceMax;
                float CameraDistanceMin;
                float CameraDistanceInitial;
                float CameraFovDegrees;
                float CameraPitchDegrees;
                float CameraZoomScale;
                float InitialTransitionTargetFovDegrees;
                float InitialTransitionTargetPitchDegrees;
                float InitialTransitionDuration;
                float EntryTransitionDuration;
                float ExitTransitionDuration;
                float CameraJumpTransitionThreshold;
                std::string PinTexturePathWithoutExtension;
                std::string PinTextureFileExtension;
                std::string LabelFontTextureFilename;
                v3 LabelGlyphColor;
                v3 LabelOutlineColor;
            };
        }
    }
}

