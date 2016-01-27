//  Copyright (c) 2015 eeGeo. All rights reserved.

#pragma once

#include "WorldMeshRenderable.h"
#include "StencilMapLayerMask.h"

namespace Eegeo
{
    namespace Data
    {
        namespace StencilArea
        {
            class StencilAreaRenderable : public Rendering::Renderables::WorldMeshRenderable
            {
            public:
                StencilAreaRenderable(
                                      Rendering::LayerIds::Values layerId,
                                      Rendering::Materials::IMaterial* material,
                                      const Rendering::VertexLayouts::VertexBinding& vertexBinding,
                                      Rendering::Mesh* pMesh,
                                      Eegeo::dv3 ecefPosition,
                                      Rendering::StencilMapLayerMask::Type stencilMapLayerType
                                    );
                
                Eegeo::Rendering::StencilMapLayerMask::Type GetStencilMapLayerType() const { return m_stencilMapLayerType; }
                
            private:
                Eegeo::Rendering::StencilMapLayerMask::Type m_stencilMapLayerType;
            };
        }
    }
}