// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "MeshRenderable.h"
#include "LayerIds.h"
#include "VectorMathDecl.h"
#include "Rendering.h"
#include "CullingVolumeTree.h"
#include "IndexBufferRange.h"
#include "Geometry.h"
#include "CullingVolumeTree.h"
#include <vector>

namespace Eegeo
{
    namespace Rendering
    {
        namespace Renderables
        {
            class CulledMeshRenderable : public MeshRenderable
            {
            public:
                CulledMeshRenderable(
                               LayerIds::Values layerId,
                               Eegeo::dv3 ecefPosition,
                               Materials::IMaterial* material,
                               Rendering::Mesh* pMesh,
                               Culling::CullingVolumeTree* pCullingVolumeTree,
                               const Rendering::VertexLayouts::VertexBinding& vertexBinding);
                
                //! \deprecated
                CulledMeshRenderable(
                                     LayerIds::Values layerId,
                                     Eegeo::dv3 ecefPosition,
                                     Materials::IMaterial* material,
                                     Rendering::Mesh* pMesh,
                                     const std::vector<Culling::CullingVolume>& cullingVolumes,
                                     const Rendering::VertexLayouts::VertexBinding& vertexBinding
                                     );
                
                virtual ~CulledMeshRenderable();
                
                const bool UpdateVisibility(const Rendering::RenderContext& renderContext, const Eegeo::Geometry::Frustum& frustum, Culling::CullingVolumeVisibilityUpdater& visibilityUpdater, float environmentScale);
                
                void SetVisible();
                
                void SetInvisible();
                
                const bool HasVisibleElements() const
                {
                    return m_visibleIndexRanges.empty() == false;
                }
                
                const std::vector<Culling::IndexBufferRange>& GetVisibleIndexRanges() const
                {
                    return m_visibleIndexRanges;
                }
                
                virtual void Render(Rendering::GLState& glState) const;
                
            protected:
                void InitialiseVisibleIndexRanges();
            
                Culling::CullingVolumeTree* m_pCullingVolumeTree;
                std::vector<Culling::IndexBufferRange> m_visibleIndexRanges;
            };
        }
    }
}