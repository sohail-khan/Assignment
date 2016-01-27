// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "WorldMeshRenderable.h"
#include "LayerIds.h"
#include "IdTypes.h"
#include "Rendering.h"
#include "VectorMathDecl.h"
#include "Graphics.h"
#include "GLHelpers.h"

namespace Eegeo
{
    namespace Rendering
    {
        namespace Renderables
        {
            class UniqueTextureRenderable : public WorldMeshRenderable
            {
            public:
                UniqueTextureRenderable(
                                  LayerIds::Values layerId,
                                  Materials::IMaterial* material,
                                  const VertexLayouts::VertexBinding& vertexBinding,
                                  Rendering::Mesh* pMesh,
                                  TTextureId textureId,
                                  Eegeo::dv3 ecefPosition)
                : WorldMeshRenderable(layerId, material, vertexBinding, pMesh, ecefPosition)
                , m_textureId(textureId)
                {
                }
                
                ~UniqueTextureRenderable()
                {
                    if (m_textureId > 0)
                    {
                        Eegeo::Helpers::GLHelpers::LockGL contextLock;
                        Eegeo_GL(glDeleteTextures(1, &m_textureId));
                        m_textureId = 0;
                    }
                }

                const TTextureId GetTextureId() const { return m_textureId; }
                
            protected:
                TTextureId m_textureId;
            };
        }
    }
}
