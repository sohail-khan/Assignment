// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "MeshRenderable.h"
#include "LayerIds.h"
#include "Rendering.h"
#include "VectorMath.h"

namespace Eegeo
{
    namespace Rendering
    {
        namespace Renderables
        {
            class WorldMeshRenderable : public MeshRenderable
            {
            public:
                WorldMeshRenderable(
                                  LayerIds::Values layerId,
                                  Materials::IMaterial* material,
                                  const VertexLayouts::VertexBinding& vertexBinding,
                                  Rendering::Mesh* pMesh,
                                  Eegeo::dv3 ecefPosition
                                    );
                
                virtual void UpdateMVP(const Rendering::RenderContext& renderContext, float environmentFlatteningScale);
                
            protected:
                Eegeo::v3 m_cameraRelativeModelOrigin;
            };
        }
    }
}