// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "SceneModelNode.h"
#include "Rendering.h"
#include "VectorMathDecl.h"
#include "LayerIds.h"
#include <vector>
#include <string>

namespace Eegeo
{
    namespace Rendering
    {
        namespace SceneModels
        {
            class SceneModelRenderableNode : public SceneModelNode
            {
            public:
                
                SceneModelRenderableNode(std::string name, Renderables::SceneModelRenderable* pRenderable);
                ~SceneModelRenderableNode();
                
                Renderables::SceneModelRenderable* GetRenderable() const { return m_pRenderable; }
                
                virtual void SetLayer(Rendering::LayerIds::Values layerId);
                virtual void SetDepthTestingRecursive(bool enabled);
                
                SceneModelMaterialResource& GetMaterialResource() const;
                void SetMaterialResource(SceneModelMaterialResource& materialResource, Rendering::VertexLayouts::VertexBindingPool& vertexBindingPool);
                
                virtual void UpdateTransforms(const dv3& ecefOrigin, const m44& parentTransform, bool dirtyParent);
                
                virtual void VisitForRendering(ISceneModelNodeRenderVisitor &visitor, const Rendering::RenderContext &renderContext, Eegeo::Rendering::RenderQueue &renderQueue);

                virtual SceneModelNode* Clone(SceneModelNode* pNewParent);
                
                void SetDepthRangeRecursive(float near, float far);
                
            private:
                
                Renderables::SceneModelRenderable* m_pRenderable;
            };
        }
    }
}