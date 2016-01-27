// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Interiors.h"
#include "CulledMeshRenderable.h"
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
            class InteriorRenderable : public CulledMeshRenderable
            {
            public:
                struct RenderState
                {
                    RenderState()
                    : m_cameraLocationEcef(dv3::Zero())
                    , m_positionUnpackTransform(m44::CreateIdentity())
                    , m_positionModelTransform(m44::CreateIdentity())
                    , m_normalModelTransform(m44::CreateIdentity())
                    , m_viewTransform(m44::CreateIdentity())
                    , m_projectionTransform(m44::CreateIdentity())
                    , m_worldToEcefTangentTransform(m44::CreateIdentity())
                    , m_environmentFlatteningTransform(m44::CreateIdentity())
                    {}
                    
                    
                    RenderState(const dv3& cameraLocationEcef,
                                const m44& positionUnpackTransform,
                                const m44& positionModelTransform,
                                const m44& normalModelTransform,
                                const m44& viewTransform,
                                const m44& projectionTransform,
                                const m44& worldToEcefTangentTransform,
                                const m44& environmentFlatteningTransform)
                    : m_cameraLocationEcef(cameraLocationEcef)
                    , m_positionUnpackTransform(positionUnpackTransform)
                    , m_positionModelTransform(positionModelTransform)
                    , m_normalModelTransform(normalModelTransform)
                    , m_viewTransform(viewTransform)
                    , m_projectionTransform(projectionTransform)
                    , m_worldToEcefTangentTransform(worldToEcefTangentTransform)
                    , m_environmentFlatteningTransform(environmentFlatteningTransform)
                    {}
                    
                    dv3 CameraLocationEcef() const { return m_cameraLocationEcef; }
                    m44 PositionUnpackTransform() const { return m_positionUnpackTransform; }
                    m44 PositionModelTransform() const { return m_positionModelTransform; }
                    m44 NormalModelTransform() const { return m_normalModelTransform; }
                    m44 ViewTransform() const { return m_viewTransform; }
                    m44 ProjectionTransform() const { return m_projectionTransform; }
                    m44 WorldToEcefTangentTransform() const { return m_worldToEcefTangentTransform; }
                    m44 EnvironmentFlatteningTransform() const { return m_environmentFlatteningTransform; }
                    
                    m44 UnpackModel() const;
                    m44 UnpackMVP() const;
                    v3 WorldViewDirection() const;
                    
                private:
                    dv3 m_cameraLocationEcef;
                    m44 m_positionUnpackTransform;
                    m44 m_positionModelTransform;
                    m44 m_normalModelTransform;
                    m44 m_viewTransform;
                    m44 m_projectionTransform;
                    m44 m_worldToEcefTangentTransform;
                    m44 m_environmentFlatteningTransform;
                };
                
                
                InteriorRenderable(LayerIds::Values layerId,
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
                
                virtual ~InteriorRenderable();
                
                const std::string& GetRenderableId() const;
                
                void SetBrightness(const float brightness);
                void SetAlpha(float alpha);
                float GetBrightness() const { return m_brightness; }
                float GetAlpha() const { return m_alpha; }
                v4 GetColor() const;
                bool NeedsStencilMirrorDuplicates() const { return m_stencilMirrorType == Resources::Interiors::StencilMirror_Mirror; }
                bool IsStencilMirrorMask() const { return m_stencilMirrorType == Resources::Interiors::StencilMirror_Mask; }
                Resources::Interiors::InteriorsStencilMirrorType GetStencilMirrorType() const { return m_stencilMirrorType; }
                v4 GetStencilMirrorClearColor() const;
                bool NeedsDepthSort() const;
                float GetInteriorTerrainHeight() const { return m_interiorTerrainHeight; }
                
                int GetFloorIndex() const { return m_floorIndex; }
                
                const Eegeo::v2& GetUVBoundsMin() const { return m_uvBoundsMin; }
                const Eegeo::v2& GetUVBoundsMax() const { return m_uvBoundsMax; }
                const Eegeo::v4& GetPositionBoundsMin() const { return m_positionBoundsMin; }
                const Eegeo::v4& GetPositionBoundsMax() const { return m_positionBoundsMax; }
                
                RenderState CalcRenderState(const Rendering::RenderContext& renderContext, float environmentFlatteningScale) const;
                
                void SetRenderState(const RenderState& renderState) { m_renderState = renderState; }
                RenderState GetRenderState() const { return m_renderState; }
                
                void SetModelTransform(const m44& modelToLocalEcefTransform);
                
                void SetMaterialIsTranslucent(bool materialIsTranslucent);

                void SetSortKeyTranslucency(bool depthSorted);
                
                void SetStencilMirrorType(Resources::Interiors::InteriorsStencilMirrorType stencilMirrorType);
                
                void SetStencilMirrorClearColor(const v3& stencilMirrorClearColor);
                
                bool UpdateVisibility(const Eegeo::Geometry::Frustum& viewFrustum, Culling::CullingVolumeVisibilityUpdater& visibilityUpdater, float environmentScale);

                u32 CalcSortKeyDepthOpaque() const;
                
                static u32 CalcSortKeyDepthOpaque(int floorIndex, Resources::Interiors::InteriorsStencilMirrorType stencilMirrorType);
                
                u32 CalcSortKeyDepthBlended(int drawOrderDepth) const;
                
                static u32 CalcSortKeyDepthBlended(int floorIndex, Resources::Interiors::InteriorsStencilMirrorType stencilMirrorType, int drawOrderDepth);
                
                bool IsAffectedByFlattening() const { return m_affectedByFlattening; }
                
            protected:
                m44 CalcPositionUnpack() const;
                
            private:
                
                m44 CalcEnvironmentFlatteningTransform(const dv3& cameraLocationEcef, float environmentFlatteningScale) const;
                
                m44 CalcFlattenedModelTransform(const m44& modelTransform, const m44& envFlattenTransform) const;
                
                // const state
                const Eegeo::v4 m_positionBoundsMin;
                const Eegeo::v4 m_positionBoundsMax;
                
                const Eegeo::v2 m_uvBoundsMin;
                const Eegeo::v2 m_uvBoundsMax;
                
                const std::string m_renderableId;
                const int m_floorIndex;
                const float m_interiorTerrainHeight;
                const bool m_affectedByFlattening;
                const bool m_ownsMesh;
                
                // mutable canonical state
                m44 m_modelTransform;
                v3 m_stencilMirrorClearColor;
                float m_brightness;
                float m_alpha;
                Resources::Interiors::InteriorsStencilMirrorType m_stencilMirrorType;
                bool m_materialIsTranslucent;
                
                // mutable derived state
                RenderState m_renderState;
            };
        }
    }
}