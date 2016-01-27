// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "IMaterial.h"
#include "IdTypes.h"
#include "BatchedSpriteShader.h"
#include "Rendering.h"
#include "TextureMinifyType.h"
#include <string>

namespace Eegeo
{
    namespace Rendering
    {
        namespace Materials
        {
            /*!
             * \brief Material for drawing alpha-blended, batched sprites.
            */
            class BatchedSpriteMaterial : protected Eegeo::NonCopyable, public IMaterial
            {
            public:
                BatchedSpriteMaterial(const TMaterialId materialId,
                                      const std::string& name,
                                      Shaders::BatchedSpriteShader& shader,
                                      TTextureId textureId,
                                      TextureMinifyType textureMinifyType = Rendering::TextureMinify_Linear
                                      );
                 
                const TMaterialId GetId() const { return m_id; }
                const Shader& GetShader() const { return m_shader; }
                const std::string& GetName() const { return m_name; }
 
                void SetState(Rendering::GLState& glState) const;
                
                void SetStatePerRenderable(const Rendering::RenderableBase* renderableBase, Rendering::GLState& glState) const;
                
            protected:
                const TMaterialId m_id;
                const std::string m_name;
                Shaders::BatchedSpriteShader& m_shader;
                TTextureId m_textureId;
                TextureMinifyType m_textureMinifyType;
            };
        }
    }
}
