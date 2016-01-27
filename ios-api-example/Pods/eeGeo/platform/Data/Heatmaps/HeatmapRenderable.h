//  Copyright (c) 2015 eeGeo. All rights reserved.

#pragma once

#include "WorldMeshRenderable.h"
#include "StencilMapLayerMask.h"

namespace Eegeo
{
    namespace Data
    {
        namespace Heatmaps
        {
            class HeatmapRenderable : public Rendering::Renderables::WorldMeshRenderable
            {
            public:
                HeatmapRenderable(
                                      Rendering::LayerIds::Values layerId,
                                      Rendering::Materials::IMaterial* material,
                                      const Rendering::VertexLayouts::VertexBinding& vertexBinding,
                                      Rendering::Mesh* pMesh,
                                      Eegeo::dv3 ecefPosition,
                                      const Rendering::TTextureId& heatmapTextureId,
                                      const Rendering::TTextureId& gradientTextureId,
                                      Eegeo::Rendering::StencilMapLayerMask::Type stencilMapLayerType
                                 );
                
                const Rendering::TTextureId& GetHeatmapTextureId() const { return m_heatmapTextureId; }
                const Rendering::TTextureId& GetGradientsTextureId() const { return m_gradientTextureId; }
                
                const float GetMinValueOffset() const { return m_minValueOffset; }
                const float GetMaxValueScale() const { return m_maxValueScale; }
                const float GetAlpha() const { return m_alpha; }
                
                void SetMinValueOffset(const float& offset) { m_minValueOffset = offset; }
                void SetMaxValueScale(const float& scale) { m_maxValueScale = scale; }
                void SetAlpha(const float& alpha) { m_alpha = alpha; }
                
                const Eegeo::Rendering::StencilMapLayerMask::Type& GetStencilMapLayerType() const { return m_stencilMapLayerType; }
                
            private:
                Eegeo::Rendering::StencilMapLayerMask::Type m_stencilMapLayerType;

                const Rendering::TTextureId m_heatmapTextureId;
                const Rendering::TTextureId m_gradientTextureId;
                float m_minValueOffset;
                float m_maxValueScale;
                float m_alpha;
            };
        }
    }
}