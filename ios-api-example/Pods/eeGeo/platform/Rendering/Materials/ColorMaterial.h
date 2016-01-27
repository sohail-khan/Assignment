// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "IMaterial.h"
#include "Rendering.h"
#include "ColorShader.h"
#include "Lighting.h"
#include "VectorMathDecl.h"
#include <string>

namespace Eegeo
{
    namespace Rendering
    {
        namespace Materials
        {
            class ColorMaterial : protected Eegeo::NonCopyable, public IMaterial
            {
            public:
                ColorMaterial(const TMaterialId materialId,
                              const std::string& name,
                              Shaders::ColorShader& shader,
                              const v4& initialColor
                               );
                
                const TMaterialId GetId() const { return m_id; }
                const Shader& GetShader() const { return m_shader; }
                const std::string& GetName() const { return m_name; }
                
                void SetState(Rendering::GLState& glState) const;
                
                void SetStatePerRenderable(const Rendering::RenderableBase* renderableBase, Rendering::GLState& glState) const;
                
                void SetColor(v4& color) { m_color = color; }
                const v4& GetColor() const { return m_color; }
                
            protected:
                const TMaterialId m_id;
                const std::string m_name;
                Shaders::ColorShader& m_shader;
                v4 m_color;
            };
        }
    }
}
