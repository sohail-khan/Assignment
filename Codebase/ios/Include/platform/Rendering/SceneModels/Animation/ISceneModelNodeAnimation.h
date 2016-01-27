// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "VectorMath.h"

namespace Eegeo
{
    namespace Rendering
    {
        namespace SceneModels
        {
            class ISceneModelNodeAnimation
            {
            public:
                
                virtual ~ISceneModelNodeAnimation() {}
                
                virtual void GetTransformForFrame(float frameTime, m44& out_transform) const = 0;
                
                virtual ISceneModelNodeAnimation* Clone() = 0;
            };
        }
    }
}
