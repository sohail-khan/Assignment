// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "PackedRenderable.h"
#include "LayerIds.h"
#include "Rendering.h"
#include "Culling.h"
#include "VectorMath.h"
#include <vector>

namespace Eegeo
{
    namespace Rendering
    {
        namespace Renderables
        {
            class PackedShadowRenderable : public PackedRenderable
            {
            public:
                PackedShadowRenderable(
                                       LayerIds::Values layerId,
                                       Materials::IMaterial* material,
                                       Rendering::Mesh* pMesh,
                                       Culling::CullingVolumeTree* pCullingVolumeTree,
                                       const VertexLayouts::VertexBinding& vertexBinding,
                                       Eegeo::dv3 ecefPosition,
                                       Eegeo::v4 positionBoundsMin,
                                       Eegeo::v4 positionBoundsMax);
                
                v3 GetExtrusionUnpack() const;
                
                virtual void CalcUnpackMVP(const Rendering::RenderContext& renderContext, float environmentFlatteningScale);
                
            private:
                v3 m_extrusionUnpack;
            };
        }
    }
}