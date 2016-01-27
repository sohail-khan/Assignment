// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "RenderableBase.h"
#include "Rendering.h"
#include "VectorMath.h"

namespace Eegeo
{
    namespace Rendering
    {
        namespace Renderables
        {
            class ModelRenderable : public RenderableBase
            {
            public:
                ModelRenderable(LayerIds::Values layerId,
                                Materials::ModelMaterial& material,
                                Mesh* pMesh,
                                const VertexLayouts::VertexBinding& vertexBinding,
                                Eegeo::dv3 ecefPosition);
                
                ~ModelRenderable();
                
                virtual void UpdateMVP(const Rendering::RenderContext& renderContext, float environmentFlatteningScale);
 
                void SetWorldMat(const m44& worldMat);
                void SetUsesAlpha(bool usesAlpha);
                
                const m44& GetInverseWorldMatrix() const;
                const v3& GetCameraRelativeModelOrigin() const;
                const VertexLayouts::VertexBinding& GetVertexBinding() const;
                
                const float GetAlpha() const { return m_alpha; }
                void SetAlpha(float alpha);
                void SetMaterial(const Materials::IMaterial* pMaterial, VertexLayouts::VertexBindingPool& vertexBindingPool);
                void SetMesh(Mesh* pMesh);
                void OnMaterialChanged(const Rendering::Materials::IMaterial* pMaterial, Rendering::VertexLayouts::VertexBindingPool& vertexBindingPool);
                
                void Render(Rendering::GLState& glState) const;
                
            protected:
                
                void UpdateVertexBinding(Rendering::VertexLayouts::VertexBindingPool& vertexBindingPool);
                
                float m_alpha;
                v3 m_cameraRelativeModelOrigin;
                m44 m_worldMat;
                m44 m_inverseWorldMat;
                
                Mesh* m_pMesh;
            };
        }
    }
}
