// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "VectorMathDecl.h"
#include "Camera.h"
#include "Geometry.h"

namespace Eegeo
{
    namespace Helpers
    {
        namespace TransformHelpers
        {
            void ComputeModelViewProjectionFacingCamera(const dv3& ecefPosition, const Camera::RenderCamera& renderCamera, m44& outModelViewProjection);

            void ComputeModelViewProjectionFacingCamera(const dv3& ecefPosition, const Camera::RenderCamera& renderCamera, m44& outModelViewProjection, float modelScale);
            
            v3 TransformModelSpaceToViewSpace(const v3& modelPosition, const m44& modelViewProjection);
            
            v2 TransformViewSpaceToScreenSpace(const v3& viewSpacePosition, float viewportWidth, float viewportHeight);
            
            v3 TransformModelSpaceToScreenSpace(const v3& modelPosition, const m44& modelViewProjection, float viewportWidth, float viewportHeight);
            
            float ComputeModelScaleForConstantScreenSize(const Camera::RenderCamera& renderCamera, const dv3& objectEcefPosition);
            float ComputeModelScaleForConstantScreenSizeWithVerticalFoV(const Camera::RenderCamera& renderCamera, const dv3& objectEcefPosition);
            
            Eegeo::m44 CreatePlanarReflection(const Eegeo::Geometry::Plane& plane);
        }
    }
}
