// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "PackedRenderable.h"
#include "LayerIds.h"
#include "Rendering.h"
#include "CullingVolume.h"
#include "VectorMathDecl.h"
#include "AsyncTexturing.h"
#include "IAsyncTexture.h"
#include <string>
#include <map>

namespace Eegeo
{
    namespace Rendering
    {
        namespace Renderables
        {
            class CustomLandmarkRenderable : public PackedRenderable
            {
            public:
                CustomLandmarkRenderable(
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
                                 const std::string& landmarkTextureName)
                : PackedRenderable(
                                   layerId,
                                   material,
                                   pMesh,
                                   pCullingVolumeTree,
                                   vertexBinding,
                                   ecefPosition,
                                   positionBoundsMin,
                                   positionBoundsMax,
                                   uvBoundsMin,
                                   uvBoundsMax)
                , m_landmarkTextureName(landmarkTextureName)
                , m_alpha(1.f)
                , m_originalEcefPosition(ecefPosition)
                {
                }
                
                ~CustomLandmarkRenderable()
                {
                    for (std::map<std::string, Rendering::AsyncTexturing::IAsyncTexture*>::iterator it = m_textureIdsByState.begin();
                         it != m_textureIdsByState.end();
                         ++it)
                    {
                        it->second->Release();
                    }
                }
                
                const std::string& GetLandmarkTextureName() const
                {
                    return m_landmarkTextureName;
                }
                
                void RegisterTextureForState(const std::string& stateName, Rendering::AsyncTexturing::IAsyncTexture& asyncTexture)
                {
                    Eegeo_ASSERT(m_textureIdsByState.find(stateName) == m_textureIdsByState.end(), "state already registered");
                    m_textureIdsByState[stateName] = &asyncTexture;
                }
                
                TTextureId GetTextureForState(const std::string& stateName) const
                {
                    Rendering::AsyncTexturing::IAsyncTexture* pAsyncTexture = m_textureIdsByState.at(stateName);
                    return pAsyncTexture->GetTextureInfo().textureId;
                }
                
                bool ShouldRender() const { return m_alpha > 0.0f; }
                
                const dv3& GetOriginalEcefPosition() const { return m_originalEcefPosition; }
                
                void SetAlpha(float alpha) { m_alpha = alpha; }
                float GetAlpha() const { return m_alpha; }
                
            private:
                const std::string m_landmarkTextureName;
                std::map<std::string, Rendering::AsyncTexturing::IAsyncTexture*> m_textureIdsByState;
                float m_alpha;
                
                const dv3 m_originalEcefPosition;
            };
        }
    }
}
