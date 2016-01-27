// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Interiors.h"
#include "InteriorMaterialData.h"
#include "VectorMath.h"
#include "Rendering.h"
#include "Culling.h"
#include "LayerIds.h"


namespace Eegeo
{
    namespace Resources
    {
        namespace Interiors
        {
            namespace Builder
            {
                struct InteriorRenderableCreationData
                {
                public:
                    InteriorRenderableCreationData(const Interiors::InteriorMaterialData& interiorMaterialData,
                                                   Rendering::LayerIds::Values layerId,
                                                   int floorIndex,
                                                   const dv3& ecefOrigin,
                                                   const v2& uvMin,
                                                   const v2& uvMax,
                                                   const v4& vertexMin,
                                                   const v4& vertexMax,
                                                   Rendering::Mesh* pMesh,
                                                   Culling::CullingVolumeTree* pCullingVolumeTree);
                    
                    InteriorMaterialData GetInteriorMaterialData() const;
                    Rendering::LayerIds::Values GetLayerId() const;
                    int GetFloorIndex() const;
                    dv3 GetEcefOrigin() const;
                    v2 GetUvMin() const;
                    v2 GetUvMax() const;
                    v4 GetVertexMin() const;
                    v4 GetVertexMax() const;
                    Rendering::Mesh* GetMesh() const;
                    Culling::CullingVolumeTree* GetCullingVolumeTree() const;
                    
                private:
                    const Interiors::InteriorMaterialData m_interiorMaterialData;
                    const Rendering::LayerIds::Values m_layerId;
                    const int m_floorIndex;
                    const dv3 m_ecefOrigin;
                    const v2 m_uvMin;
                    const v2 m_uvMax;
                    const v4 m_vertexMin;
                    const v4 m_vertexMax;
                    Rendering::Mesh* m_pMesh;
                    Culling::CullingVolumeTree* m_pCullingVolumeTree;
                };
            }
        }
    }
}