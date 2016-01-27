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
            class InteriorHighlightRenderable : public InteriorRenderable
            {
            public:
                
                InteriorHighlightRenderable(LayerIds::Values layerId,
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
                                        const float interiorTerrainHeight,
                                        const bool affectedByFlattening,
                                        bool ownsMesh);
                
                ~InteriorHighlightRenderable();
                
                void SetDiffuseColor(const v4& diffuseColor);
                v4 GetDiffuseColor() const;

                RenderState CalcRenderState(const Rendering::RenderContext& renderContext, float environmentFlatteningScale) const;
                
                void SetRenderState(const RenderState& renderState) { m_renderState = renderState; }
                RenderState GetRenderState() const { return m_renderState; }
                
                void SetModelTransform(const m44& modelToLocalEcefTransform);

                void SetTranslucency(bool usesTranslucency);
                
                void SetStencilMirrorType(Resources::Interiors::InteriorsStencilMirrorType stencilMirrorType);
                
                void SetStencilMirrorClearColor(const v4& stencilMirrorClearColor);
                
                void OnMaterialChanged(const Rendering::Materials::IMaterial* pMaterial, Rendering::VertexLayouts::VertexBindingPool& vertexBindingPool);
                
                bool UpdateVisibility(const Eegeo::Geometry::Frustum& viewFrustum, Culling::CullingVolumeVisibilityUpdater& visibilityUpdater, float environmentScale);

                
            private:
                m44 CalcEnvironmentFlatteningTransform(const dv3& cameraLocationEcef, float environmentFlatteningScale) const;
                
                m44 CalcFlattenedModelTransform(const m44& modelTransform, const m44& envFlattenTransform) const;
                
                // mutable canonical state
                m44 m_modelTransform;
                v4 m_diffuseColor;
                
                // mutable derived state
                RenderState m_renderState;
            };
        }
    }
}
