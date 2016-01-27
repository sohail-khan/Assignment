// Copyright eeGeo Ltd (2012-2015), All Rights Reserved

#pragma once

#include "Types.h"
#include "IMaterial.h"
#include "Rendering.h"
#include "Lighting.h"
#include "VectorMathDecl.h"
#include "VertexColoredShader.h"
#include <string>

namespace Eegeo
{
    namespace Rendering
    {
        namespace Materials
        {
            class VertexColoredMaterial : protected Eegeo::NonCopyable, public IMaterial
            {
            public:
                VertexColoredMaterial(
                        const TMaterialId materialId,
                        const std::string& name,
                        Shaders::VertexColoredShader& shader);

                const TMaterialId GetId() const { return m_id; }
                const Shader& GetShader() const { return m_shader; }
                const std::string& GetName() const { return m_name; }

                void SetState(Rendering::GLState& glState) const;

                void SetStatePerRenderable(const Rendering::RenderableBase* renderableBase, Rendering::GLState& glState) const;
            protected:
                const TMaterialId m_id;
                const std::string m_name;
                Shaders::VertexColoredShader& m_shader;
            };
        }
    }
}
