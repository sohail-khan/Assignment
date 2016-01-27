// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "VectorMathDecl.h"
#include "Camera.h"

namespace Eegeo
{
    namespace Resources
    {
        namespace PlaceNames
        {
            class PlaceNamesTransforms : protected Eegeo::NonCopyable
            {
            private:
                static const float CORRECT_ANGLE_START;
                static const float CORRECT_ANGLE_END;
                static const float CORRECT_ANGLE_RANGE;
                        
            public:
                static float CalculateScale (
                                            float categoryScale,
                                            float placeNameScale,
                                            float environmentScale
                                            );
                
                static void CalculateMVP(const dv3& ecefPosition,
                                         const Camera::RenderCamera& renderCamera,
                                         m44& outModelViewProjection,
                                         float modelScale
                                         );
                
            private:
                static Eegeo::m44 GetTransformForPlace(
                                                       const Eegeo::dv3& ecefPosition,
                                                       const Eegeo::m44& cameraWorld,
                                                       const Eegeo::dv3& cameraEcefPosition,
                                                       float scale
                                                       );
            };
        }
    }
}
