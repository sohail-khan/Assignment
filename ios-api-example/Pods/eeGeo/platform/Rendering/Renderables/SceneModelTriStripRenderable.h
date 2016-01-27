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
            class SceneModelTriStripRenderable : public SceneModelRenderable
            {
            public:
                
                SceneModelTriStripRenderable(LayerIds::Values layerId,
                                             SceneModels::SceneModelMaterialResource& materialResource,
                                             const VertexLayouts::VertexBinding& vertexBinding,
                                             SceneModels::SceneModelTriStripMeshResource& meshResource,
                                             Eegeo::dv3 ecefPosition);
                
                ~SceneModelTriStripRenderable();
                
                virtual void Render(Rendering::GLState& glState) const;
                
                virtual SceneModelRenderable* Clone();
                
            protected:
                
                virtual void UpdateVertexBinding(Rendering::VertexLayouts::VertexBindingPool& vertexBindingPool);
                
            private:
                
                SceneModels::SceneModelTriStripMeshResource& m_meshResource;
            };
        }
    }
}