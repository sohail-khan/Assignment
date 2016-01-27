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
            class TextRenderable : public MeshRenderable
            {
            public:
                TextRenderable(
                               LayerIds::Values layerId,
                               Materials::IMaterial* material,
                               const VertexLayouts::VertexBinding& vertexBinding,
                               Rendering::Mesh* pMesh,
                               const Eegeo::dv3& ecefPosition
                               )
                : MeshRenderable(layerId, ecefPosition, material, pMesh, vertexBinding)
                , m_scale(v3::One())
                , m_foregroundColour(v4::Zero())
                , m_shadowColour(v4::Zero())
                , m_outlineColour(v4::Zero())
                {
                }
                
                void SetAlpha(float alpha)
                {
                    m_foregroundColour.SetW(alpha);
                    m_shadowColour.SetW(alpha);
                }
                
                float GetAlpha() const
                {
                    return m_foregroundColour.GetW();
                }
                
                void SetForegroundColour(const v4& rgba) { m_foregroundColour = rgba; }
                const v4& GetForegroundColour() const { return m_foregroundColour; }

                void SetShadowColour(const v4& rgba) { m_shadowColour = rgba; }
                const v4& GetShadowColour() const { return m_shadowColour; }
                
                void SetOutlineColour(const v4& rgba) { m_outlineColour = rgba; }
                const v4& GetOutlineColour() const { return m_outlineColour; }
                
                void SetScale(v3 scale) { m_scale = scale; }
                const v3& GetScale(void) const { return m_scale; }
                                
            protected:
                Eegeo::v3 m_scale;
                Eegeo::v4 m_foregroundColour;
                Eegeo::v4 m_shadowColour;
                Eegeo::v4 m_outlineColour;
            };
        }
    }
}