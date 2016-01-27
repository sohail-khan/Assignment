// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "RenderableBase.h"
#include "LayerIds.h"
#include "Rendering.h"
#include "VectorMath.h"

namespace Eegeo
{
    namespace Rendering
    {
        namespace Renderables
        {
            class BasicRenderable : public RenderableBase
            {
            public:
                BasicRenderable
                (
                 Rendering::LayerIds::Values layerId,
                 Rendering::Materials::IMaterial* pMaterial
                 )
                : RenderableBase(layerId, dv3(0,0,0), pMaterial)
                {
                }
            };
        }
    }
}
