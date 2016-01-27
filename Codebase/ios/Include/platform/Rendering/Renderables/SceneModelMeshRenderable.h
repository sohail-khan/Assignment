// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "SceneModelRenderable.h"
#include "Rendering.h"

namespace Eegeo
{
    namespace Rendering
    {
        namespace Renderables
        {
            class SceneModelMeshRenderable : public SceneModelRenderable
            {
            public:
                
                SceneModelMeshRenderable(LayerIds::Values layerId,
                                         SceneModels::SceneModelMaterialResource& materialResource,
                                         const VertexLayouts::VertexBinding& vertexBinding,
                                         SceneModels::SceneModelMeshResource& meshResource,
                                         Eegeo::dv3 ecefPosition);
                
                SceneModelMeshRenderable();
                
                ~SceneModelMeshRenderable();
                
                virtual void Render(Rendering::GLState& glState) const;
                
                SceneModels::SceneModelMeshResource& GetMeshResource() const { return m_meshResource; }
                
                virtual SceneModelRenderable* Clone();
                
            protected:
                
                virtual void UpdateVertexBinding(Rendering::VertexLayouts::VertexBindingPool& vertexBindingPool);
                
            private:
                
                SceneModels::SceneModelMeshResource& m_meshResource;
            };
        }
    }
}