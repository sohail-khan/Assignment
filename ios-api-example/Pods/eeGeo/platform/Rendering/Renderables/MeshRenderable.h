// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "RenderableBase.h"
#include "LayerIds.h"
#include "VectorMathDecl.h"
#include "Rendering.h"
#include "VertexBindingPool.h"
#include "Mesh.h"
#include "IMaterial.h"
#include "Shader.h"

namespace Eegeo
{
    namespace Rendering
    {
        namespace Renderables
        {
            class MeshRenderable : public RenderableBase
            {
            public:
                MeshRenderable(
                               LayerIds::Values layerId,
                               Eegeo::dv3 ecefPosition,
                               Materials::IMaterial* material,
                               Rendering::Mesh* pMesh,
                               const Rendering::VertexLayouts::VertexBinding& vertexBinding
                               );
                
                virtual ~MeshRenderable();
                    
                virtual void OnMaterialChanged(const Rendering::Materials::IMaterial* pMaterial, Rendering::VertexLayouts::VertexBindingPool& vertexBindingPool);
                
                virtual void Render(Rendering::GLState& glState) const;
                
                Rendering::Mesh& GetMesh() { return *m_pMesh; }
                
            protected:

                void UpdateVertexBinding(Rendering::VertexLayouts::VertexBindingPool& vertexBindingPool)
                {
                    SetVertexBinding(vertexBindingPool.GetVertexBinding(GetMesh().GetVertexLayout(), GetMaterial()->GetShader().GetVertexAttributes()));
                }
                
                Mesh* m_pMesh;
            };
        }
    }
}
