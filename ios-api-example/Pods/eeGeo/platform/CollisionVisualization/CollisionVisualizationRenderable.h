// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once


#include "RenderableBase.h"
#include "Types.h"
#include "Collision.h"
#include "CollisionVisualization.h"
#include "Rendering.h"
#include "SingleSphere.h"

#include <string>

namespace Eegeo
{
    namespace CollisionVisualization
    {
        class CollisionVisualizationRenderable : public Eegeo::Rendering::RenderableBase
        {
        public:
            CollisionVisualizationRenderable(Rendering::Mesh* pMesh,
                                             Rendering::LayerIds::Values layerId,
                                             const dv3& ecefPosition,
                                             const Rendering::Materials::IMaterial& material,
                                             const Rendering::VertexLayouts::VertexBinding& vertexBinding,
                                             const Eegeo::Geometry::SingleSphere& boundingSphere,
                                             const Eegeo::v4& initialColor,
                                             bool depthTest,
                                             bool depthWrite,
                                             bool depthBias,
                                             bool alphaBlend);
            
            virtual ~CollisionVisualizationRenderable();
            
            virtual m44 CalcModelViewProjection(const dv3& ecefCameraPosition, const m44& viewProjection, const float environmentFlatteningScale) const;
            
            virtual void Render(Rendering::GLState& glState) const;
            
            virtual void OnMaterialChanged(const Rendering::Materials::IMaterial* pMaterial, Eegeo::Rendering::VertexLayouts::VertexBindingPool& vertexBindingPool);

            virtual const v4& GetColor() const { return m_color; }
            virtual bool IsDepthTest() const { return m_depthTest; }
            virtual bool IsDepthWrite() const { return m_depthWrite; }
            virtual bool IsDepthBias() const { return m_depthBias; }
            virtual bool IsAlphaBlend() const { return m_alphaBlend; }
            
            virtual void SetColor(const v4& color) { m_color = color; }
            virtual void SetDepthTest(bool enabled) { m_depthTest = enabled; }
            virtual void SetDepthWrite(bool enabled) { m_depthWrite = enabled; }
            virtual void SetDepthBias(bool enabled) { m_depthBias = enabled; }
            virtual void SetAlphaBlend(bool enabled) { m_alphaBlend = enabled; }
            
            virtual Eegeo::Geometry::SingleSphere GetBoundingSphere() const { return m_boundingSphere; }
            
        private:
            Rendering::Mesh* m_pMesh;
            const Eegeo::Geometry::SingleSphere m_boundingSphere;
            v4 m_color;
            bool m_depthTest;
            bool m_depthWrite;
            bool m_depthBias;
            bool m_alphaBlend;
        };
    }
}