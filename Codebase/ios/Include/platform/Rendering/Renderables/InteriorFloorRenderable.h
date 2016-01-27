// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Interiors.h"
#include "InteriorRenderable.h"
#include "LayerIds.h"
#include "Rendering.h"
#include "Culling.h"
#include "VectorMath.h"
#include "InteriorsStencilMirrorType.h"

#include <vector>
#include <string>

namespace Eegeo
{
    namespace Rendering
    {
        namespace Renderables
        {
           class InteriorFloorRenderable : public InteriorRenderable
            {
            public:
                
                InteriorFloorRenderable(LayerIds::Values layerId,
                                        int floorIndex,
                                        Materials::IMaterial* material,
                                        Rendering::Mesh* pMesh,
                                        Culling::CullingVolumeTree* pCullingVolumeTree,
                                        const VertexLayouts::VertexBinding& vertexBinding,
                                        Eegeo::dv3 ecefLocalOrigin,
                                        Eegeo::v4 positionBoundsMin,
                                        Eegeo::v4 positionBoundsMax,
                                        Eegeo::v2 uvBoundsMin,
                                        Eegeo::v2 uvBoundsMax,
                                        const std::string& renderableId,
                                        const Resources::Interiors::IInteriorsMaterialAssignmentObserver& materialAssignmentObserver,
                                        const float interiorTerrainHeight,
                                        const bool affectedByFlattening,
                                        bool ownsMesh);
                
                ~InteriorFloorRenderable();
               
                bool NeedsStencilMirrorDuplicates() const { return GetStencilMirrorType() == Resources::Interiors::StencilMirror_Mirror; }
                bool IsStencilMirrorMask() const { return GetStencilMirrorType() == Resources::Interiors::StencilMirror_Mask; }
                
                v4 GetStencilMirrorClearColor() const;
                
                RenderState CalcRenderState(const Rendering::RenderContext& renderContext, float environmentFlatteningScale) const;
                
                void SetModelTransform(const m44& modelToLocalEcefTransform);
                
                void SetStencilMirrorClearColor(const v3& stencilMirrorClearColor);
                
                void OnMaterialChanged(const Rendering::Materials::IMaterial* pMaterial, Rendering::VertexLayouts::VertexBindingPool& vertexBindingPool);
                
                bool UpdateVisibility(const Eegeo::Geometry::Frustum& viewFrustum, Culling::CullingVolumeVisibilityUpdater& visibilityUpdater, float environmentScale);

                u32 CalcSortKeyDepthOpaque() const;
                
                static u32 CalcSortKeyDepthOpaque(int floorIndex, Resources::Interiors::InteriorsStencilMirrorType stencilMirrorType); 
                
            private:
                
                m44 CalcEnvironmentFlatteningTransform(const dv3& cameraLocationEcef, float environmentFlatteningScale) const;
                
                m44 CalcFlattenedModelTransform(const m44& modelTransform, const m44& envFlattenTransform) const;
                
                // const state
                const Resources::Interiors::IInteriorsMaterialAssignmentObserver& m_materialAssignmentObserver;
                
                // mutable canonical state
                m44 m_modelTransform;
                v3 m_stencilMirrorClearColor;
            };
        }
    }
}