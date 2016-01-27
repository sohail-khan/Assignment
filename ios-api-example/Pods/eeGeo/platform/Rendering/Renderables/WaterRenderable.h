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
            class WaterRenderable : public PackedRenderable
            {
            public:
                WaterRenderable(
                                 LayerIds::Values layerId,
                                 Materials::IMaterial* material,
                                 Rendering::Mesh* pMesh,
                                 Culling::CullingVolumeTree* pCullingVolumeTree,
                                 const VertexLayouts::VertexBinding& vertexBinding,
                                 Eegeo::dv3 ecefPosition,
                                 Eegeo::v4 positionBoundsMin,
                                 Eegeo::v4 positionBoundsMax,
                                 Eegeo::v2 uvBoundsMin,
                                Eegeo::v2 uvBoundsMax);
                
                const Eegeo::m44& GetModelView() const { return m_modelView; }
                
                virtual void CalcUnpackMVP(const Rendering::RenderContext& renderContext, float environmentFlatteningScale);
            protected:
                Eegeo::m44 m_modelView;
            };
        }
    }
}