// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "VectorMath.h"

namespace Eegeo
{
    namespace Routes
    {
        namespace Fitting
        {
            namespace NavGraphConforming
            {
                struct NavGraphConformerConfig
                {
                    float conformingRadius;
                    int subdivisions;
                    int splineExtensionVertexCount;
                    int solverMaxOpenSetSize;
                    bool debugLog;
                    int debugLogVerbosity;
                    bool highlightFailedSections;
                    v4 fittingFailedHighlightColor;
                };
            }
        }
    }
}
