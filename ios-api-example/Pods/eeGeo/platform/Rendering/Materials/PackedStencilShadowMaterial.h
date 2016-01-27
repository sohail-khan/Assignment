// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "IMaterial.h"
#include "Rendering.h"
#include "PackedStencilShadowShader.h"
#include <string>

namespace Eegeo
{
    namespace Rendering
    {
        namespace Materials
        {
            class PackedStencilShadowMaterial : protected Eegeo::NonCopyable, public IMaterial
            {
            public:
                PackedStencilShadowMaterial(const TMaterialId materialId, const std::string& name, Shaders::PackedStencilShadowShader& shader);
                
                ~PackedStencilShadowMaterial()
                {
                }
                
                const TMaterialId GetId() const { return m_id; }
                const Shader& GetShader() const { return m_shader; }
                const std::string& GetName() const { return m_name; }
                
                void SetState(Rendering::GLState& glState) const;
                
                void SetStatePerRenderable(const Rendering::RenderableBase* renderableBase, Rendering::GLState& glState) const;
                
            protected:
                const TMaterialId m_id;
                const std::string m_name;
                Shaders::PackedStencilShadowShader& m_shader;
            };
        }
    }
}
