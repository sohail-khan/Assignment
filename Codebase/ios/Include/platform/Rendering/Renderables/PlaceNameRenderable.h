// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "TextRenderable.h"
#include "LayerIds.h"
#include "Rendering.h"
#include "VectorMathDecl.h"

namespace Eegeo
{
    namespace Resources
    {
        namespace PlaceNames
        {
            class PlaceNameRenderable : public Eegeo::Rendering::Renderables::TextRenderable
            {
            public:
                PlaceNameRenderable (
                                     Rendering::LayerIds::Values layerId,
                                     Rendering::Materials::IMaterial* material,
                                     const Rendering::VertexLayouts::VertexBinding& vertexBinding,
                                     Rendering::Mesh* pMesh,
                                     const Eegeo::dv3& ecefPosition
                                     )
                : TextRenderable(layerId, material, vertexBinding, pMesh, ecefPosition)
                {
                }
            };
        }
    }
}
