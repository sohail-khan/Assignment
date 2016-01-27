// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Interiors.h"
#include "Rendering.h"


namespace Eegeo
{
    namespace Resources
    {
        namespace Interiors
        {
            class InteriorsStencilMirrorClearRenderableFactory : private Eegeo::NonCopyable
            {
            public:
                InteriorsStencilMirrorClearRenderableFactory(
                                                        InteriorsStencilMirrorClearMaterial& material,
                                                        Rendering::Mesh* pFullScreenQuadMesh,
                                                        Rendering::VertexLayouts::VertexBindingPool& vertexBindingPool
                                                        );

                virtual ~InteriorsStencilMirrorClearRenderableFactory() {;}
                
                virtual InteriorsStencilMirrorClearRenderable* CreateFor(const Rendering::Renderables::InteriorRenderable& mirrorRenderable) const;
            private:
                InteriorsStencilMirrorClearMaterial& m_material;
                Rendering::Mesh* m_pFullScreenQuadMesh;
                Rendering::VertexLayouts::VertexBindingPool& m_vertexBindingPool;
            };
        }
    }
}