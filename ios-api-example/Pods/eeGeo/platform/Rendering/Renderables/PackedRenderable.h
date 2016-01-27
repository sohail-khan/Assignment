// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "CulledMeshRenderable.h"
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
            class PackedRenderable : public CulledMeshRenderable
            {
            public:
                PackedRenderable(
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
                
                virtual void CalcUnpackMVP(const Rendering::RenderContext& renderContext, float environmentFlatteningScale);
                
                const Eegeo::v2& GetUVBoundsMin() const { return m_uvBoundsMin; }
                const Eegeo::v2& GetUVBoundsMax() const { return m_uvBoundsMax; }
                const Eegeo::v4& GetPositionBoundsMin() const { return m_positionBoundsMin; }
                const Eegeo::v4& GetPositionBoundsMax() const { return m_positionBoundsMax; }

                const Eegeo::v3& GetCameraRelativeModelOrigin() const { return m_cameraRelativeModelOrigin; }
                
            protected:
                Eegeo::v4 m_positionBoundsMin;
                Eegeo::v4 m_positionBoundsMax;
                
                Eegeo::v2 m_uvBoundsMin;
                Eegeo::v2 m_uvBoundsMax;
                
                Eegeo::v3 m_cameraRelativeModelOrigin;
            };
        }
    }
}