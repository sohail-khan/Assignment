// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "RenderableBase.h"
#include "Rendering.h"
#include "LayerIds.h"
#include "VectorMath.h"

namespace Eegeo
{
    namespace Rendering
    {
        namespace Renderables
        {
            class SceneModelRenderable : public RenderableBase
            {
            public:
                SceneModelRenderable(LayerIds::Values layerId,
                                     SceneModels::SceneModelMaterialResource& materialResource,
                                     const VertexLayouts::VertexBinding& vertexBinding,
                                     Eegeo::dv3 ecefPosition);
                SceneModelRenderable(SceneModelRenderable& source);
                
                ~SceneModelRenderable();

                virtual void UpdateMVP(const Rendering::RenderContext& renderContext, float environmentFlatteningScale);
                
                SceneModels::SceneModelMaterialResource& GetMaterialResource() const;
                void SetMaterialResource(SceneModels::SceneModelMaterialResource& materialResource, VertexLayouts::VertexBindingPool& vertexBindingPool);
                
                void SetWorldMat(const m44& worldMat);
                void SetUsesAlpha(bool usesAlpha);
                const float GetAlpha() const { return m_alpha; }
                void SetAlpha(float alpha);
                
                const m44& GetInverseWorldMatrix() const;
                const v3& GetCameraRelativeModelOrigin() const;
                const VertexLayouts::VertexBinding& GetVertexBinding() const;
                
                virtual void SetMaterial(const Rendering::Materials::IMaterial* pMaterial, Rendering::VertexLayouts::VertexBindingPool& vertexBindingPool);
                virtual void OnMaterialChanged(const Rendering::Materials::IMaterial* pMaterial, Rendering::VertexLayouts::VertexBindingPool& vertexBindingPool);
                
                virtual SceneModelRenderable* Clone() = 0;
                
            protected:
                
                virtual void UpdateVertexBinding(Rendering::VertexLayouts::VertexBindingPool& vertexBindingPool) = 0;
                
                float m_alpha;
                v3 m_cameraRelativeModelOrigin;
                m44 m_worldMat;
                m44 m_inverseWorldMat;
                
                SceneModels::SceneModelMaterialResource* m_pMaterialResource;
            };
            
            
            
        }
    }
}