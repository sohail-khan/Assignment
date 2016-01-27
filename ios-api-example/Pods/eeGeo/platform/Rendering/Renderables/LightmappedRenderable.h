// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Graphics.h"
#include "PackedRenderable.h"
#include "LayerIds.h"
#include "Rendering.h"
#include "CullingVolume.h"
#include "VectorMathDecl.h"
#include <vector>
#include "GLHelpers.h"

namespace Eegeo
{
    namespace Rendering
    {
        namespace Renderables
        {
            class LightmappedRenderable : public PackedRenderable
            {
            public:
                LightmappedRenderable(
                                      LayerIds::Values layerId,
                                      Materials::IMaterial* material,
                                      Rendering::Mesh* pMesh,
                                      Culling::CullingVolumeTree* pCullingVolumeTree,
                                      const VertexLayouts::VertexBinding& vertexBinding,
                                      Eegeo::dv3 ecefPosition,
                                      Eegeo::v4 positionBoundsMin,
                                      Eegeo::v4 positionBoundsMax,
                                      Eegeo::v2 uvBoundsMin,
                                      Eegeo::v2 uvBoundsMax,
                                      TTextureId lightmapId)
                : PackedRenderable(layerId, material, pMesh, pCullingVolumeTree, vertexBinding, ecefPosition, positionBoundsMin, positionBoundsMax, uvBoundsMin, uvBoundsMax)
                , m_lightmapId(lightmapId)
                , m_ownsLightmapTexture(false)
                {
                }
                
                ~LightmappedRenderable()
                {
                    if (m_ownsLightmapTexture && m_lightmapId > 0)
                    {
                        Eegeo::Helpers::GLHelpers::LockGL contextLock;
                        Eegeo_GL(glDeleteTextures(1, &m_lightmapId));
                        m_lightmapId = 0;
                    }
                }
           
                TTextureId GetLightmapTextureId() const { return m_lightmapId; }
                void SetLightmapTextureId(TTextureId lightmapId, bool ownsLightmap)
                {
                    m_lightmapId = lightmapId;
                    m_ownsLightmapTexture = ownsLightmap;
                }
                
            private:
                TTextureId m_lightmapId;
                bool m_ownsLightmapTexture;
            };
        }
    }
}
