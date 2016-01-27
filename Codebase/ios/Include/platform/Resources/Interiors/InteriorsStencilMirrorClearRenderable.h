// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Interiors.h"
#include "RenderableBase.h"

namespace Eegeo
{
    namespace Resources
    {
        namespace Interiors
        {
            class InteriorsStencilMirrorClearRenderable : public Rendering::RenderableBase
            {
            public:
                InteriorsStencilMirrorClearRenderable(
                               const Rendering::Renderables::InteriorRenderable& mirrorRenderable,
                               Rendering::Materials::IMaterial* pMaterial,
                               Rendering::Mesh* pSharedMesh,
                               const Rendering::VertexLayouts::VertexBinding& vertexBinding
                               );
                
                virtual ~InteriorsStencilMirrorClearRenderable();

                virtual void Render(Rendering::GLState& glState) const;
                
                virtual const Rendering::Renderables::InteriorRenderable& GetMirrorRenderable() const { return m_mirrorRenderable; }
                
                virtual void UpdateSortKey();
                
            private:
                Rendering::Mesh* m_pSharedMesh;
                const Rendering::Renderables::InteriorRenderable& m_mirrorRenderable;
            };
        }
    }
}