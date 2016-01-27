// Copyright eeGeo Ltd (2012-2015), All Rights Reserved

#pragma once

#include "Types.h"
#include "IMaterial.h"
#include "Rendering.h"
#include "Lighting.h"
#include "VectorMathDecl.h"
#include "UniformColoredShader.h"
#include <string>

namespace Eegeo
{
    namespace Rendering
    {
        namespace Materials
        {
            class UniformColoredMaterial : private Eegeo::NonCopyable, public IMaterial
            {
            public:
                UniformColoredMaterial (
                        const TMaterialId materialId,
                        const std::string& name,
                        Shaders::UniformColoredShader& shader,
                        const v4& initialColor);

                const TMaterialId GetId() const { return m_id; }
                const Shader& GetShader() const { return m_shader; }
                const std::string& GetName() const { return m_name; }

                void SetState(Rendering::GLState& glState) const;

                void SetColor(const v4& color) { m_color = color; }
                const v4& GetColor() const { return m_color; }

                void SetStatePerRenderable(const Rendering::RenderableBase* renderableBase, Rendering::GLState& glState) const;
            protected:
                const TMaterialId m_id;
                const std::string m_name;
                Shaders::UniformColoredShader & m_shader;
                v4 m_color;
            };
        }
    }
}
