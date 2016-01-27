// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "IMaterial.h"
#include "IdTypes.h"
#include "Rendering.h"
#include "FireworksShader.h"
#include <string>

namespace Eegeo
{
    namespace Rendering
    {
        namespace Materials
        {
            class FireworksMaterial : protected Eegeo::NonCopyable, public IMaterial
            {
            public:
                FireworksMaterial(const TMaterialId materialId,
                                  const std::string& name,
                                  Shaders::FireworksShader& shader,
                                  TTextureId textureId
                                  );
                
                const TMaterialId GetId() const { return m_id; }
                const Shader& GetShader() const { return m_shader; }
                const std::string& GetName() const { return m_name; }
                
                void SetState(Rendering::GLState& glState) const;
                
                void SetStatePerRenderable(const Rendering::RenderableBase* renderableBase, Rendering::GLState& glState) const;
                
            protected:
                const TMaterialId m_id;
                const std::string m_name;
                Shaders::FireworksShader& m_shader;
                TTextureId m_textureId;
            };
        }
    }
}
