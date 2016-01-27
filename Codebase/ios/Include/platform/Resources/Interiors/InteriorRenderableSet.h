// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include <vector>
#include "Rendering.h"
#include "InteriorsStencilMirrorClearMaterial.h"

namespace Eegeo
{
    namespace Resources
    {
        namespace Interiors
        {
            struct InteriorRenderableSet
            {
                InteriorRenderableSet()
                    : isActive(false)
                {
                }

                bool isActive;
                std::vector<Rendering::Renderables::InteriorFloorRenderable*> interiorFloorRenderables;
                std::vector<Rendering::Renderables::InstancedInteriorFloorRenderable*> instancedInteriorFloorRenderables;
                std::vector<InteriorsStencilMirrorClearRenderable*> stencilMirrorClearRenderables;
            };
        }
    }
}