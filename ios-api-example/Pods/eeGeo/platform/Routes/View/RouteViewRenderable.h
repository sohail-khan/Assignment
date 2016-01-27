// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "MeshRenderable.h"
#include "Rendering.h"
#include "VectorMathDecl.h"

namespace Eegeo
{
    namespace Routes
    {
        namespace View
        {
            class RouteViewRenderable : public Rendering::Renderables::MeshRenderable
            {
            public:
                RouteViewRenderable(
                                      Rendering::LayerIds::Values layerId,
                                      Rendering::Materials::IMaterial* material,
                                      const Rendering::VertexLayouts::VertexBinding& vertexBinding,
                                      Rendering::Mesh* pMesh,
                                      const Eegeo::dv3& ecefPosition
                                      )
                : MeshRenderable(layerId, ecefPosition, material, pMesh, vertexBinding)
                , m_thickness(0.f)
                , m_altitudeFade(0.f)
                , m_depthTestEnabled(false)
                , m_wireframe(false)
                {
                    
                }
                
                virtual void Render(Rendering::GLState& glState) const;
                
                void SetThickness(float thickness) { m_thickness = thickness; }
                void SetAltitudeFade(float fade) { m_altitudeFade = fade; }
                void SetDepthTestEnabled(bool depthTestEnabled) { m_depthTestEnabled = depthTestEnabled; }
                
                float GetThickness() const { return m_thickness; }
                float GetAltitudeFade() const { return m_altitudeFade; }
                bool IsDepthTestEnabled() const { return m_depthTestEnabled; }
                void SetWireframe(bool enabled) { m_wireframe = enabled; }
            private:
                float m_thickness;
                float m_altitudeFade;
                bool m_depthTestEnabled;
                bool m_wireframe;
            };
        }
    }
}